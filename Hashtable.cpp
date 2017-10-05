#include "Hashtable.hpp"


size_t HashTable::HashFoo(const Key& k) const{
	size_t hash = 0;
	for (int i = 0; i < k.length(); ++i){
		hash += (size_t)(k[i] - 'A'); 
	}
	return hash % capacity;
}


void HashTable::rehashing(){
	std::vector<std::list<Tmp>> buf;
	buf.resize(capacity, std::list<Tmp>());
	std::copy(data.begin(), data.begin() + capacity, buf.begin());
	data.clear();
	_size = 0;
	if (capacity > (UINT_MAX / 2)){
		capacity = UINT_MAX;
	}
	else {
		capacity *= 2;	
	}
	data.resize(capacity, std::list<Tmp>());
	for (size_t i = 0; i < (capacity / 2); ++i){
		std::list<Tmp>& lst = buf.at(i);
		if (!lst.empty()){
			for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
				insert(it->key, it->val);
			}
		}	
	}
	buf.clear();
}


HashTable::HashTable(){
	data.resize(defaultCapacity, std::list<Tmp>());
}



HashTable::~HashTable(){
	data.clear();
}



HashTable::HashTable(const HashTable& b){
	capacity = b.capacity;
	_size = b._size;
	data.resize(capacity, std::list<Tmp>());
	std::copy(b.data.begin(), b.data.begin() + capacity, data.begin());
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
	if (lst.empty()){
		throw "Empty list";
	}
	for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
			return (it->val); 
		} 
	}
	throw "Nothing good";
}



bool HashTable::contains(const Key& k) const{
	unsigned pos = HashFoo(k);
	std::list<Tmp> lst = data.at(pos);
	if (!lst.empty()){
		for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if (it->key == k){
    			return true;
			}
		}
	}
	return false;
}



bool HashTable::erase(const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	if (!lst.empty()){
		for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if (it->key == k){
				lst.erase(it);
				return true;
			}
		}
	}
	return false;
}
	
	
	

const Value& HashTable::at(const Key& k) const{
	unsigned pos = HashFoo(k);
	std::list<Tmp> lst = data.at(pos);
	if (lst.empty()){
		throw "Empty list";
	}
	for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
			return (it->val); 
		}
	}
	throw "Nothing good";
}



void HashTable::clear(){
	_size = 0;
	capacity = defaultCapacity;
	data.clear();
}

	

Value& HashTable::operator[](const Key& k){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	if (!lst.empty()){
		for (std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (it->key == k){
    		return (it->val);
			} 
		}
	}
	Value *v = new Value;
	insert(k, *v);
return *v;
}



bool HashTable::insert(const Key& k, const Value& v){
	unsigned pos = HashFoo(k);
	std::list<Tmp>& lst = data.at(pos);
	if (!lst.empty()){
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
	if (_size > (capacity / 2)){
		rehashing();	
	}
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
		


bool operator==(const HashTable & a, const HashTable & b){
	if (a.capacity != b.capacity || a._size != b._size){
		return false;	
	}
	for (size_t i = 0; i < a.capacity; ++i){
		std::list<Tmp> lst = a.data.at(i);
		if (!lst.empty()){
			for(std::list<Tmp>::iterator it = lst.begin(); it != lst.end(); ++it) {
				if (!b.contains(it->key)){
					return false;
				}
			}
		}
	}
	return true;
}



bool operator!=(const HashTable & a, const HashTable & b){
	return !(a==b);
}