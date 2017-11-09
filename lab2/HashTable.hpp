#ifndef H_MY_HASH_TABLE
#define H_MY_HASH_TABLE

#include <limits>
#include <stdexcept>
#include <string>
#include <algorithm>

typedef std::string Key;

template <class T> class HashTable;
template <class T> bool operator==(const HashTable<T> &, const HashTable<T> &);
template <class T> bool operator!=(const HashTable<T> &, const HashTable<T> &);

template <class T> class HashTable {
public:
  HashTable();
  explicit HashTable(const size_t startSize);
  ~HashTable();
  HashTable(const HashTable &);
  void swap(HashTable &a);

  HashTable &operator=(const HashTable &a);

  // clear container
  void clear();

  // erase element with key
  bool erase(const Key &k);

  // Вставка в контейнер. Возвращаемое значение - успешность вставки.
  bool insert(const Key &k, const T &v);

  // Проверка наличия значения по заданному ключу.
  bool contains(const Key &k) const;

  // Возвращает значение по ключу. Небезопасный метод.
  // В случае отсутствия ключа в контейнере, следует вставить в контейнер
  // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
  T &operator[](const Key &k);

  // Возвращает значение по ключу. Бросает исключение при неудаче.
  T &at(const Key &k);
  const T &at(const Key &k) const;

  size_t size() const;
  bool empty() const;
  friend bool operator==<>(const HashTable<T> &, const HashTable<T> &);
  friend bool operator!=<>(const HashTable<T> &, const HashTable<T> &);

private:
  static const int startCapacity = 32;
  static const int growFactor = 2;
  static const int overflowFactor = 2;
  size_t capacity = startCapacity;
  size_t totalElements = 0;
  size_t firstHashFoo(const Key &) const;
  size_t secondHashFoo(const Key &) const;

  void reHashing();
  
  struct Table {
    bool isUse = false;
    bool wasUsed = false;
    T data;
    Key key;
    friend bool operator==(const Table &a, const Table &b) {
      if (a.data != b.data || a.isUse != b.isUse || a.wasUsed != b.wasUsed ||
          a.key != b.key)
        return false;
      return true;
    }
    void set(const T &v, const Key k) {
      data = v;
      key = k;
      wasUsed = isUse = true;
    }
    inline void clear() {
      key = "";
      data = 0;
      wasUsed = isUse = false;
    }
    friend bool operator!=(const Table &a, const Table &b) { return !(a == b); }
  } * table;
};

template <class T> HashTable<T>::HashTable() { table = new Table[capacity]; }
template <class T> HashTable<T>::HashTable(const size_t startSize) {

  if (startSize >= std::numeric_limits<size_t>::max() / growFactor) { //numeric_limits
    throw std::overflow_error("overflowConstr");
  }
  while (capacity <= startSize) {
    capacity *= growFactor;
  }
  table = new Table[capacity];
}
template <class T> HashTable<T>::~HashTable() { delete[] table; }
template <class T> void HashTable<T>::clear() {
  totalElements = 0;
  std::for_each ( table, table + capacity, [](Table &t){ t.clear(); });
}

template <class T> HashTable<T>::HashTable(const HashTable &a) {
  capacity = a.capacity;
  totalElements = a.totalElements;
  table = new Table[capacity];
  std::copy(a.table, a.table + capacity, table);
}
template <class T> void HashTable<T>::swap(HashTable &a) {
  std::swap(table, a.table);
  std::swap(capacity, a.capacity);
  std::swap(totalElements, a.totalElements);
}
template <class T> HashTable<T> &HashTable<T>::operator=(const HashTable &a) {
  if (this != &a) {
    delete[] table;
    capacity = a.capacity;
    totalElements = a.totalElements;
    table = new Table[capacity];
    std::copy(a.table, a.table + capacity, table);
  }
  return *this;
}
template <class T> bool HashTable<T>::erase(const Key &k) {
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].key != k) {
    hash = (hash + secondHash) % capacity;
    if (hash == firstHash || !table[hash].wasUsed) {
      return false;
    }
  }
  totalElements--;
  table[hash].clear();
  table[hash].wasUsed = true;
  return true;
}
template <class T> bool HashTable<T>::insert(const Key &k, const T &v) {
  if (totalElements >= capacity / overflowFactor) {
    reHashing();
  }
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].isUse) {
    hash = (hash + secondHash) % capacity;
  }
  totalElements++;
  table[hash].set(v, k);
  return true;
}
template <class T> void HashTable<T>::reHashing() {
  if (capacity >= std::numeric_limits<size_t>::max() / 2) {
    throw std::overflow_error("overflow");
  }
  Table *buf = table;
  table = new Table[capacity * growFactor];
  capacity *= growFactor;
  totalElements = 0;
  for (int i = 0; i < capacity / growFactor; i++) {
    if (buf[i].isUse) {
      insert(buf[i].key, buf[i].data);
    }
  }
  delete[] buf;
}
template <class T> bool HashTable<T>::contains(const Key &k) const {
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].key != k) {
    hash = (hash + secondHash) % capacity;
    if (hash == firstHash || !table[hash].wasUsed) {
      return false;
    }
  }
  return true;
}
template <class T> T &HashTable<T>::operator[](const Key &k) {
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].key != k) {
    hash = (hash + secondHash) % capacity;
    if (hash == firstHash || !table[hash].wasUsed) {
      insert(k, T());
      return (*this)[k];
    }
  }
  return table[hash].data;
}
template <class T> T &HashTable<T>::at(const Key &k) {
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].key != k) {
    hash = (hash + secondHash) % capacity;
    if (hash == firstHash || !table[hash].wasUsed) {
      throw std::out_of_range("no such el");
    }
  }
  return table[hash].data;
}
template <class T> const T &HashTable<T>::at(const Key &k) const {
  size_t firstHash = firstHashFoo(k);
  size_t secondHash = secondHashFoo(k);
  size_t hash = firstHash;
  while (table[hash].key != k) {
    hash = (hash + secondHash) % capacity;
    if (hash == firstHash || !table[hash].wasUsed) {
      throw std::out_of_range("no such el");
    }
  }
  return table[hash].data;
}
template <class T> size_t HashTable<T>::size() const { return totalElements; }
template <class T> bool HashTable<T>::empty() const { return !(totalElements); }
template <class T>
bool operator==(const HashTable<T> &a, const HashTable<T> &b) {
  if (a.totalElements != b.totalElements) {
    return false;
  }
  for (int i = 0; i < a.capacity; i++) {
    if (!b.contains(a.table[i].key)) {
      return false;
    }
  }
  return true;
}
template <class T>
bool operator!=(const HashTable<T> &a, const HashTable<T> &b) {
  return !(a == b);
}
template <class T> size_t HashTable<T>::firstHashFoo(const Key &k) const {
  size_t hash = 0;
  for (int i = 0; i < k.length(); i++) {
    hash += (size_t)k[i];
  }
  return hash %= capacity;
}
template <class T> size_t HashTable<T>::secondHashFoo(const Key &k) const {
  size_t hash = 0;
  for (int i = 0; i < k.length(); i++) {
    hash += (size_t)k[i];
  }
  hash %= (capacity - 1);
  hash += ((hash + 1) % 2);
  return hash;
}

#endif
