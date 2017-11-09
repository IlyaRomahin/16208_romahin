#include <algorithm>
#include <iostream>
#include "Strategy.hpp"
#include "Factory.hpp"	
	
class EasyStrategy4 : public Strategy {
public:	
	void strategy( int x, int y ) override {
		std::cout << "EasyStrategy4 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory<Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r("easystrategy4", []() -> Strategy * { return new EasyStrategy4; });
}
