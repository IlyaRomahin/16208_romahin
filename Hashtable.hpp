#ifndef HEADER_MY_HASH_TABLE
#define HEADER_MY_HASH_TABLE

#include <list>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

typedef std::string Key;

struct Value {
	unsigned age = 0;
	unsigned weight = 0;
};


struct Tmp {
	Key key;
	Value val;
	Tmp(const Key& k, const Value& v) : key (k), val (v) {}
};

class HashTable{
public:
	HashTable();
	~HashTable();

	HashTable(const HashTable& b);

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
	bool contains(const Key& k) const;

	// Возвращаеhalfт значение по ключу. Небезопасный метод.
	// В случае отсутствия ключа в контейнере, следует вставить в контейнер
	// значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
	Value& operator[](const Key& k);

	// Возвращает значение по ключу. Бросает исключение при неудаче.
	Value& at(const Key& k);
	const Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable & a, const HashTable & b);
	friend bool operator!=(const HashTable & a, const HashTable & b);
	
private:
	unsigned static const defaultCapacity = 19;
	std::vector<std::list<Tmp>> data;
	size_t _size = 0;
	size_t capacity = defaultCapacity;
	size_t HashFoo (const Key& k) const;
	unsigned static const half = 2;
	void rehashing();
};

#endif
