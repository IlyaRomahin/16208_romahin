#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class EasyStrategy4 : public Strategy {
public:	
	void strategy( const Deck &deck, Hand hand, const bool first ) override {
		std::cout << "EasyStrategy4 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r( "easystrategy4", []() -> Strategy * { return new EasyStrategy4; } );
}
