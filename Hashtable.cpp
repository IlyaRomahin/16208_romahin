#include <iostream>
#include <assert.h>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

typedef std::string Key;

struct Value {
	unsigned age = 0;
	unsigned weight = 0;
};

struct Tmp {
	Key key;
	Value val;
};


class HashTable{
private:
	unsigned static const defaultCapacity = 19;
	std::vector<std::list<Tmp>> data;
	size_t _size = 0;
	size_t capacity;
	size_t HashFoo (const Key& k) const;
public:
	HashTable();
	~HashTable();

	HashTable(unsigned);

	// Обменивает значения двух хэш-таблиц.
	// Подумайте, зачем нужен этот метод, при наличии стандартной функции
	// std::swap.
	void swap(HashTable& b);

	HashTable& operator=(const HashTable& b);
		
	// Очищает контейнер.
	void clear();
	// Удаляет элемент по заданному ключу.
	bool erase(const Key& k);
	// Вставка в контейнер. Возвращаемое значение - успешность вставки.
	bool insert(const Key& k, const Value& v);

	// Проверка наличия значения по заданному ключу.
	bool contains(const Key& k);

	// Возвращает значение по ключу. Небезопасный метод.
	// В случае отсутствия ключа в контейнере, следует вставить в контейнер
	// значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
	struct Value& operator[](const Key& k);

	// Возвращает значение по ключу. Бросает исключение при неудаче.
	struct Value& at(const Key& k);
	const struct Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(HashTable & a, HashTable & b);
	friend bool operator!=(HashTable & a, HashTable & b);
};



size_t HashTable::HashFoo(const Key& k) const{
	return 15 % capacity;
}



HashTable::HashTable(){
	data.resize(defaultCapacity, std::list<Tmp>());
}



HashTable::~HashTable(){
	data.clear();
}



HashTable::HashTable(unsigned capacity){
	data.resize(capacity, std::list<Tmp>());
}



void HashTable::swap(HashTable& b){
	std::swap(b._size, _size);
	std::swap(b.capacity, capacity);
	std::swap(b.data, data);
}



size_t HashTable::size() const{
	return _size;
}



bool HashTable::empty() const{
	return _size == 0;
}



Value& HashTable::at(const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);	
	if (lst.size() < 1) {
		throw "empty_list";
	}
	for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
			return (it->val); 
		} 
	}
	throw "Nothing_good";
	Value *v = new Value;
	insert(k, *v);
return *v;
}



bool HashTable::contains(const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
    		return true;
		}
	}
	return false;
}



bool HashTable::erase(const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
			lst.erase(it);
		}
	}
	return false;
}
	
	
	
/*
const Value& HashTable::at(const Key& k) const{
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);	
	if (lst.GetSize() < 1) {
		throw "empty_list";
	}
	for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
			return (it->val); 
		}
	}
	throw "Nothing_good";
	Value *v = new Value;
	insert(k, *v);
return *v;
}
*/


void HashTable::clear(){
	data.clear();
}

	

Value& HashTable::operator[](const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
	if (it->key == k){
    	return (it->val);
		} 
	}
	Value *v = new Value;
	insert(k, *v);
return *v;
}



bool HashTable::insert(const Key& k, const Value& v){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	if (!lst.empty()) {
		for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if(it->key == k){
				it->val = v;
    			return true;
			}
		}
	}
	Tmp *value = new Tmp;
	value->val = v;
	value->key = k;
	(data[pos]).push_front(*value);
	_size++;	
	return true;
}



HashTable& HashTable::operator=(const HashTable& b){
	if (this != & b){
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
		


bool operator==(HashTable & a, HashTable & b){
		std::list<Tmp>& lst1 = a.data[0];
		std::list<Tmp>& lst2 = b.data[0];
		return true;
}



bool operator!=(HashTable & a, HashTable & b){
	return !(a==b);
}



int main(){
	
	
}