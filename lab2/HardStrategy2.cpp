#include <algorithm>
#include <iostream>
#include "BlackJack.hpp"
#include "Factory.hpp"	
	
class HardStrategy2 : public Strategy {
public:	
	void strategy( Dealer &dealer, const bool first ) override {
		if ( !dealer.f ) {
		  std::cout << "HardStrategy2 is started" << std::endl;
		}  
		int i = 2;
		if ( first ) {
		  dealer.name_1 = "HardStrategy2";
		  dealer.number_1 = 5;
		  dealer.hand_1.hand_data[ 0 ] = dealer.deck.deck_data[ 0 ];
		  dealer.hand_1.hand_data[ 1 ] = dealer.deck.deck_data[ 1 ];
		  dealer.hand_1.weight += dealer.hand_1.hand_data[ 0 ].weight;
		  dealer.hand_1.weight += dealer.hand_1.hand_data[ 1 ].weight;
		  dealer.hand_1._size = 2;
		  if ( dealer.hand_1.hand_data[ 0 ]._ace ) {
			 dealer.hand_1.ace_counter++;
		  }
		  if ( dealer.hand_1.hand_data[ 1 ]._ace ) {
			 dealer.hand_1.ace_counter++;
		  }
		  if ( dealer.hand_1.ace_counter == 2) {
		     dealer.gold_point_1 = true;
		  }
		  while ( ( dealer.hand_1.weight < 12 && ( dealer.deck.deck_data[ 2 ].value == "2" || dealer.deck.deck_data[ 2 ].value == "3"
		    || dealer.deck.deck_data[ 2 ].value == "4" || dealer.deck.deck_data[ 2 ].value == "5"
		    || dealer.deck.deck_data[ 2 ].value == "6" ) ) || dealer.hand_1.weight < 11 ) {
		    dealer.hand_1.hand_data[ i ] = dealer.deck.deck_data[ i + dealer.pos_in_deck ];
		    dealer.hand_1.weight += dealer.hand_1.hand_data[ i ].weight;
		    if ( dealer.hand_1.hand_data[ i ]._ace ) {
		  	   dealer.hand_1.ace_counter++;
		    }
		    if ( dealer.hand_1.weight > 21 && dealer.hand_1.ace_counter > 0 ) {
		   	   dealer.hand_1.weight -= 10;
			   dealer.hand_1.ace_counter--;  
		    }
		    dealer.hand_1._size++;
		    i++;
		  }
		  dealer.pos_in_deck = i;
		  if ( !dealer.f ) {
		    for ( i = 0; i < dealer.hand_1._size; ++i ) {
		      std::cout << dealer.hand_1.hand_data[ i ].value << " " << dealer.hand_1.hand_data[ i ].suit << ", card`s weight = " << dealer.hand_1.hand_data[ i ].weight << std::endl;
		    }
		  }  
		}
		else {
		  dealer.name_2 = "HardStrategy2";
		  dealer.number_2 = 5;
		  dealer.hand_2.hand_data[ 0 ] = dealer.deck.deck_data[ 2 ];
		  dealer.hand_2.hand_data[ 1 ] = dealer.deck.deck_data[ 3 ];
		  dealer.hand_2.weight += dealer.hand_2.hand_data[ 0 ].weight;
		  dealer.hand_2.weight += dealer.hand_2.hand_data[ 1 ].weight;
		  dealer.hand_2._size = 2;
		  if ( dealer.hand_2.hand_data[ 0 ]._ace ) {
			 dealer.hand_2.ace_counter++;
		  }
		  if ( dealer.hand_2.hand_data[ 1 ]._ace ) {
			 dealer.hand_2.ace_counter++;
		  }
		  if ( dealer.hand_2.ace_counter == 2) {
		     dealer.gold_point_2 = true;
		  }
		  while ( ( dealer.hand_2.weight < 12 && ( dealer.deck.deck_data[ 0 ].value == "2" || dealer.deck.deck_data[ 0 ].value == "3"
		    || dealer.deck.deck_data[ 0 ].value == "4" || dealer.deck.deck_data[ 0 ].value == "5"
		    || dealer.deck.deck_data[ 0 ].value == "6" ) ) || dealer.hand_2.weight < 11 ) {
		    dealer.hand_2.hand_data[ i ] = dealer.deck.deck_data[ i + 2 + dealer.pos_in_deck ];
		    dealer.hand_2.weight += dealer.hand_2.hand_data[ i ].weight;
		    if ( dealer.hand_2.hand_data[ i ]._ace ) {
		  	   dealer.hand_2.ace_counter++;
		    }
		    if ( dealer.hand_2.weight > 21 && dealer.hand_2.ace_counter > 0 ) {
		   	   dealer.hand_2.weight -= 10;
			   dealer.hand_2.ace_counter--;  
		    }
		    dealer.hand_2._size++;
		    i++;
		  }
		  dealer.pos_in_deck = i;
		  if ( !dealer.f ) {
		    for ( i = 0; i < dealer.hand_2._size; ++i ) {
		      std::cout << dealer.hand_2.hand_data[ i ].value << " " << dealer.hand_2.hand_data[ i ].suit << ", card`s weight = " << dealer.hand_2.hand_data[ i ].weight << std::endl;
		    }
		  } 
		}
	}	
};

namespace {
bool b = 
Factory< Strategy, Strategy*(*)(), std::string>::get_instance()->
	regist3r( "hardstrategy2", []() -> Strategy * { return new HardStrategy2; } );
}
