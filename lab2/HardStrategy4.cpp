#include <algorithm>
#include <iostream>
#include "Strategy.hpp"
#include "Factory.hpp"	
	
class HardStrategy4 : public Strategy {
public:	
	void strategy( int x, int y ) override {
		std::cout << "HardStrategy4 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r( "hardstrategy4", []() -> Strategy * { return new HardStrategy4; } );
}
