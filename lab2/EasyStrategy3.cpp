#include <algorithm>
#include <iostream>
#include "Strategy.hpp"
#include "Factory.hpp"	
	
class EasyStrategy3 : public Strategy {
public:	
	void strategy( int x, int y ) override {
		std::cout << "EasyStrategy3 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory<Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r("easystrategy3", []() -> Strategy * { return new EasyStrategy3; });
}
