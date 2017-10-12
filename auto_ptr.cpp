#include <iostream>

//RAII - resource acqusition is initialization

struct A {
	A() {std::cout << "A constructed" << std::endl;}
	~A() {std::cout << "A destructed" << std::endl;}
};


//std::unique_ptr (начиная с С++11) запрещено копирование, разрешено перемещение


class SmartPointer {
public:
	SmartPointer(); // Конструктор по умолчанию
	SmartPointer(A * a); // Конструктор с захватом ресурса
	
	//Разрушающее копирование
	//std::auto_ptr (запрещён начиная с C++11)
	SmartPointer(SmartPointer & ptr); //Конструктор копирования
	SmartPointer(SmartPointer && ptr); //Конструткор перемещения (опционально)
	SmartPointer& operator=(SmartPointer & ptr); //Операция присваивания
	SmartPointer& operator=(SmartPointer && ptr); //Операция перемещения (опционально)
	
	A * get(); //вернуть указатель
	A * reset(A * other); //осободить старый, записать новый
	A * release(); //отдать владение
	
	A * operator->();
	A & operator*();
	operator bool();
	
	~SmartPointer(); //Деструктор
private:
	A * a_ = nullptr;
};


SmartPointer::SmartPointer() {}


SmartPointer::SmartPointer(A * a) : a_(a) {}


SmartPointer::SmartPointer(SmartPointer & ptr) : a_(ptr.a_){
	ptr.a_ = nullptr;
}


SmartPointer::~SmartPointer() {
		std::cout << "SmartPointer destructor!!!111" << std::endl;
		delete a_;
}


SmartPointer& SmartPointer::operator=(SmartPointer & ptr) {
	if (this != & ptr){
		a_ = reset(ptr.release());
	}
	return *this;
}


A * SmartPointer::get(){
	return a_;
}


A * SmartPointer::reset(A * other){
	if (a_ != nullptr){
		delete a_;
	}
	a_ = other;
	return a_;
}


A * SmartPointer::release(){
	A * tmp = a_;
	a_ = nullptr;
	return tmp;	
	
}


A * SmartPointer::operator->(){
	return a_;
}


A & SmartPointer::operator*(){
	return *(a_);	
}


SmartPointer::operator bool(){
	if (a_ == nullptr){
		return false;
	}
	return true;
}
	

void f() {
	throw 1;
}


void x() {
	
}


void g() {
	SmartPointer ptr(new A);
	f();
}


int main() {
	try {
		g();	
	} catch (int x) {
		std::cout << "Caught x = " << x << std::endl;	
	}
}