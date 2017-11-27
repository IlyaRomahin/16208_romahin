#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class EasyStrategy3 : public Strategy {
public:	
	void strategy( const Deck &deck, Hand hand, const bool first, int * position, int * hand_weight, std::string &name, bool &gold_winner ) override {
		std::cout << "EasyStrategy3 is started" << std::endl;
		name = "EasyStrategy3";
		int i = 2;
		if ( first ) {
		  hand.hand_data[ 0 ] = deck.deck_data[ 0 ];
		  hand.hand_data[ 1 ] = deck.deck_data[ 1 ];
		  * hand_weight += hand.hand_data[ 0 ].weight;
		  * hand_weight += hand.hand_data[ 1 ].weight;
		  hand._size = 2;
		  if ( hand.hand_data[ 0 ]._ace ) {
			hand.ace_counter++;
		  }
		  if ( hand.hand_data[ 1 ]._ace ) {
			hand.ace_counter++;
		  }
		}
		else {
		  hand.hand_data[ 0 ] = deck.deck_data[ 2 ];	
		  hand.hand_data[ 1 ] = deck.deck_data[ 3 ];
		  * hand_weight += hand.hand_data[ 0 ].weight;
		  * hand_weight += hand.hand_data[ 1 ].weight;
		  hand._size = 2;
		  if ( hand.hand_data[ 0 ]._ace ) {
			hand.ace_counter++;
		  }
		  if ( hand.hand_data[ 1 ]._ace ) {
			hand.ace_counter++;
		  }
		}
		if ( hand.ace_counter == 2) {
		  gold_winner = true;
		}
		while ( * hand_weight < 17 ) {	
		  hand.hand_data[ i ] = deck.deck_data[ i + 2 + * position ];
		  * hand_weight += hand.hand_data[ i ].weight;
		  if ( hand.hand_data[ i ]._ace ) {
			hand.ace_counter++;
		  }
		  if ( * hand_weight > 21 && hand.ace_counter > 0 ) {
			* hand_weight -= 10;
			hand.ace_counter--;  
		  }
		  hand._size++;
		  i++;
		}
		* position = i;
		for ( i = 0; i < hand._size; ++i ) {
		  std::cout << hand.hand_data[ i ].value << " " << hand.hand_data[ i ].suit << " " << hand.hand_data[ i ].weight << std::endl;
		}
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string >::get_instance()->
	regist3r( "easystrategy3", []() -> Strategy * { return new EasyStrategy3; } );
}
