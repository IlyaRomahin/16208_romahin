#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class HardStrategy4 : public Strategy {
public:	
	void strategy( const Deck &deck, Hand hand, const bool first ) override {
		std::cout << "HardStrategy4 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r( "hardstrategy4", []() -> Strategy * { return new HardStrategy4; } );
}
