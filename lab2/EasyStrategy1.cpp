#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class EasyStrategy1 : public Strategy {
public:	
	void strategy( const Deck &deck, Hand hand, const bool first ) override {
		std::cout << "EasyStrategy1 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string >::get_instance()->
	regist3r( "easystrategy1", []() -> Strategy * { return new EasyStrategy1; } );
}
