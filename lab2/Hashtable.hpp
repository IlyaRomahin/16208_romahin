#ifndef HEADER_MY_HASH_TABLE
#define HEADER_MY_HASH_TABLE

#include <limits>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

/*typedef std::string Key;

struct Value {
  unsigned age = 0;
  unsigned weight = 0;
};*/

template < class TKey, class TValue >
struct Tmp {
  TKey key;
  TValue val;
  Tmp<TKey, TValue>(const TKey &k, const TValue &v) : key(k), val(v) {}
};

template < class TKey, class TValue >
class HashTable {
public:
		
  HashTable() { data.resize(defaultCapacity, std::list<Tmp<TKey, TValue>>()); }

  ~HashTable() {}

  HashTable(const HashTable &b) : capacity(b.capacity), _size(b._size), data(b.data) {}

  // Обменивает значения двух хэш-таблиц.
  // Подумайте, зачем нужен этот метод, при наличии стандартной функции
  // std::swap.
  void swap(HashTable &b) {
    std::swap(b._size, _size);
    std::swap(b.capacity, capacity);
    std::swap(b.data, data);  
  }

  HashTable &operator=(const HashTable &b) {
	if (this != &b) {
      if (b._size != _size) {
        data.clear();
        data.resize(capacity, std::list<Tmp<TKey, TValue>>());
        _size = b._size;
        capacity = b.capacity;
      }
      std::copy(b.data.begin(), b.data.begin() + b.capacity, data.begin());
    }
    return *this;  
  }

  // Очищает контейнер.
  void clear() {
	_size = 0;
    capacity = defaultCapacity;
    data.clear();  
  }
  // Удаляет элемент по заданному ключу.
  bool erase(const TKey &k) {
	unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> &lst = data.at(pos);
    if (!lst.empty()) {
      for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
          lst.erase(it);
          return true;
        }
      }
    }
    return false;  
  }
  // Вставка в контейнер. Возвращаемое значение - успешность вставки.
  bool insert(const TKey &k, const TValue &v) {
	unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> &lst = data.at(pos);
    if (!lst.empty()) {
      for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
          it->val = v;
          return true;
        }
      }
    }
    (data[pos]).push_front(Tmp<TKey, TValue>(k, v));
    _size++;
    if (_size > (capacity / half)) {
      rehashing();
    }
    return true;  
  }

  // Проверка наличия значения по заданному ключу.
  bool contains(const TKey &k) const {
	unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> lst = data.at(pos);
    if (!lst.empty()) {
      for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
          return true;
        }
      }
    }
    return false;  
  }

  // Возвращает значение по ключу. Небезопасный метод.
  // В случае отсутствия ключа в контейнере, следует вставить в контейнер
  // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
  TValue &operator[](const TKey &k) {
	unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> &lst = data.at(pos);
    if (!lst.empty()) {
      for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (it->key == k) {
          return (it->val);
        }
      }
    }
    insert(k, TValue());
    return (*this)[k];
  }	  

  // Возвращает значение по ключу. Бросает исключение при неудаче.
  TValue &at(const TKey &k) {
    unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> &lst = data.at(pos);
    for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        return (it->val);
      }
    }
    throw std::out_of_range("out_of_range");  
  }	  

  const TValue &at(const TKey &k) const {
	unsigned pos = HashFoo(k);
    std::list<Tmp<TKey, TValue>> lst = data.at(pos);
    for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        return (it->val);
      }
    }
    throw std::out_of_range("out_of_range");  
  }

  size_t size() const { return _size; }

  bool empty() const { return _size == 0; }

  friend bool operator==(const HashTable &a, const HashTable &b) {
	if (a.capacity != b.capacity || a._size != b._size) {
      return false;
    }
    for (size_t i = 0; i < a.capacity; ++i) {
      std::list<Tmp<TKey, TValue>> lst = a.data.at(i);
      if (!lst.empty()) {
        for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
          if (!b.contains(it->key)) {
            return false;
          }
        }
      }
    }
    return true;  
  }

  friend bool operator!=(const HashTable &a, const HashTable &b) { return !(a == b); }

private:
  unsigned static const defaultCapacity = 19;
  std::vector<std::list<Tmp<TKey, TValue>>> data;
  size_t _size = 0;
  size_t capacity = defaultCapacity;
  unsigned static const half = 2;

  void rehashing() {
	std::vector<std::list<Tmp<TKey, TValue>>> buf = data;
    data.clear();
    _size = 0;
    if (capacity > (std::numeric_limits<std::size_t>::max() / half)) {
      capacity = std::numeric_limits<std::size_t>::max();
    } else {
      capacity *= half;
    }
    data.resize(capacity, std::list<Tmp<TKey, TValue>>());
    for (size_t i = 0; i < (capacity / half); ++i) {
      std::list<Tmp<TKey, TValue>> &lst = buf.at(i);
      if (!lst.empty()) {
        for (typename std::list<Tmp<TKey, TValue>>::iterator it = lst.begin(); it != lst.end(); ++it) {
          insert(it->key, it->val);
        }
      }
    }  
  }

  size_t HashFoo(const TKey &k) const {
    size_t hash = 0;
    for (int i = 0; i < k.length(); ++i) {
      hash += (size_t)(k[i] - 'A');
    }
    return hash % capacity;  
  }
};

#endif
