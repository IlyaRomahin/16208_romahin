#include "Hashtable.hpp"

size_t HashTable::HashFoo(const Key &k) const {
  size_t hash = 0;
  for (int i = 0; i < k.length(); ++i) {
    hash += (size_t)(k[i] - 'A');
  }
  return hash % capacity;
}

void HashTable::rehashing() {
  std::vector<std::list<Tmp>> buf = data;
  data.clear();
  _size = 0;
  if (capacity > (std::numeric_limits<std::size_t>::max() / half)) {
    capacity = std::numeric_limits<std::size_t>::max();
  } else {
    capacity *= half;
  }
  data.resize(capacity, std::list<Tmp>());
  for (size_t i = 0; i < (capacity / half); ++i) {
    std::list<Tmp> &lst = buf.at(i);
    if (!lst.empty()) {
      for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
        insert(it->key, it->val);
      }
    }
  }
}

HashTable::HashTable() { data.resize(defaultCapacity, std::list<Tmp>()); }

HashTable::~HashTable() {}

HashTable::HashTable(const HashTable &b)
    : capacity(b.capacity), _size(b._size), data(b.data) {}

void HashTable::swap(HashTable &b) {
  std::swap(b._size, _size);
  std::swap(b.capacity, capacity);
  std::swap(b.data, data);
}

size_t HashTable::size() const { return _size; }

bool HashTable::empty() const { return _size == 0; }

Value &HashTable::at(const Key &k) {
  unsigned pos = HashFoo(k);
  std::list<Tmp> &lst = data.at(pos);
  for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
    if (it->key == k) {
      return (it->val);
    }
  }
  throw std::out_of_range("out_of_range");
}

bool HashTable::contains(const Key &k) const {
  unsigned pos = HashFoo(k);
  std::list<Tmp> lst = data.at(pos);
  if (!lst.empty()) {
    for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        return true;
      }
    }
  }
  return false;
}

bool HashTable::erase(const Key &k) {
  unsigned pos = HashFoo(k);
  std::list<Tmp> &lst = data.at(pos);
  if (!lst.empty()) {
    for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        lst.erase(it);
        return true;
      }
    }
  }
  return false;
}

const Value &HashTable::at(const Key &k) const {
  unsigned pos = HashFoo(k);
  std::list<Tmp> lst = data.at(pos);
  for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
    if (it->key == k) {
      return (it->val);
    }
  }
  throw std::out_of_range("out_of_range");
}

void HashTable::clear() {
  _size = 0;
  capacity = defaultCapacity;
  data.clear();
}

Value &HashTable::operator[](const Key &k) {
  unsigned pos = HashFoo(k);
  std::list<Tmp> &lst = data.at(pos);
  if (!lst.empty()) {
    for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        return (it->val);
      }
    }
  }
  Value v;
  Value &val = v;
  insert(k, val);
  return val;
}

bool HashTable::insert(const Key &k, const Value &v) {
  unsigned pos = HashFoo(k);
  std::list<Tmp> &lst = data.at(pos);
  if (!lst.empty()) {
    for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
      if (it->key == k) {
        it->val = v;
        return true;
      }
    }
  }
  (data[pos]).push_front(Tmp(k, v));
  _size++;
  if (_size > (capacity / half)) {
    rehashing();
  }
  return true;
}

HashTable &HashTable::operator=(const HashTable &b) {
  if (this != &b) {
    if (b._size != _size) {
      data.clear();
      data.resize(capacity, std::list<Tmp>());
      _size = b._size;
      capacity = b.capacity;
    }
    std::copy(b.data.begin(), b.data.begin() + b.capacity, data.begin());
  }
  return *this;
}

bool operator==(const HashTable &a, const HashTable &b) {
  if (a.capacity != b.capacity || a._size != b._size) {
    return false;
  }
  for (size_t i = 0; i < a.capacity; ++i) {
    std::list<Tmp> lst = a.data.at(i);
    if (!lst.empty()) {
      for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (!b.contains(it->key)) {
          return false;
        }
      }
    }
  }
  return true;
}

bool operator!=(const HashTable &a, const HashTable &b) { return !(a == b); }
