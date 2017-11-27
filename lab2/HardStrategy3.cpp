#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class HardStrategy3 : public Strategy {
public:	
	void strategy( const Deck &deck, Hand hand, const bool first, int * position, int * hand_weight, std::string &name, bool &gold_winner ) override {
		std::cout << "HardStrategy3 is started" << std::endl;
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r( "hardstrategy3", []() -> Strategy * { return new HardStrategy3; } );
}
