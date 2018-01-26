#include "BlackJack.hpp"
#include "Factory.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <memory>

Card::Card() {}

Card::~Card() {}

Card::Card( const Card &b ) : weight( b.weight ), suit( b.suit ), value( b.value ) {}

Card::Card( const std::string &v, const std::string &s ) : value( v ), suit( s ) {	
  if ( v == jack || v == queen || v == king ) {
    weight = dec;	
  }
  else if ( v == ace ) {
	weight = dec + 1;
	_ace = true;  
  }
  else if ( stoi( v ) && stoi( v ) >= two && stoi( v ) <= dec ) {
    weight = stoi( v );	  
  }
  else {	
    throw std::invalid_argument( "invalid_argument" );
  }
  if ( s != spades && s != hearts && s != clubs && s != diamonds ) {
	throw std::invalid_argument( "invalid_argument" );  
  }
}

Card &Card::operator=( const Card &b ) {
  if ( this != &b )	{
    weight = b.weight;
	_ace = b._ace;
	value = b.value;
	suit = b.suit;  
  }
  return *this;
}

bool operator==( const Card &a, const Card &b ) {
  if ( a.weight == b.weight && a._ace == b._ace && a.value == b.value && a.suit == b.suit )	{
	return true;  
  }
  return false;	
}

bool operator!=( const Card &a, const Card &b ) { return !( a == b ); }

Deck::Deck() { 
  deck_data.resize( defaultCapacity, Card() );
    for ( size_t i = 0; i < 9; ++i ) {
      deck_data[ i ] = Card( std::to_string( i + 2 ), "spades" );
   	  deck_data[ i + 9 ] = Card( std::to_string( i + 2 ), "hearts" );
	  deck_data[ i + 18 ] = Card( std::to_string( i + 2 ), "clubs" );
	  deck_data[ i + 27 ] = Card( std::to_string( i + 2 ), "diamonds" ); 
    }
    deck_data[ 36 ] = Card( "jack", "spades" );
	deck_data[ 37 ] = Card( "queen", "spades" );
	deck_data[ 38 ] = Card( "king", "spades" );
	deck_data[ 39 ] = Card( "ace", "spades" );
	deck_data[ 40 ] = Card( "jack", "hearts" );
	deck_data[ 41 ] = Card( "queen", "hearts" );
	deck_data[ 42 ] = Card( "king", "hearts" );
	deck_data[ 43 ] = Card( "ace", "hearts" );
	deck_data[ 44 ] = Card( "jack", "clubs" );
	deck_data[ 45 ] = Card( "queen", "clubs" );
	deck_data[ 46 ] = Card( "king", "clubs" );
	deck_data[ 47 ] = Card( "ace", "clubs" );
    deck_data[ 48 ] = Card( "jack", "diamonds" );
	deck_data[ 49 ] = Card( "queen", "diamonds" );
	deck_data[ 50 ] = Card( "king", "diamonds" );
	deck_data[ 51 ] = Card( "ace", "diamonds" );
}

Deck::~Deck() {}

Deck::Deck( const Deck &b ) : _size( b._size ), capacity( b.capacity ), deck_data( b.deck_data ) {}

Deck &Deck::operator=( const Deck &b ) {
  if ( this != &b ) {
	if ( capacity != b.capacity ) {
	  capacity = b.capacity;
	  deck_data.clear();	
	  deck_data.resize( capacity, Card() );
	}	
	_size = b._size ;
	std::copy( b.deck_data.begin(), b.deck_data.begin() + b.capacity, deck_data.begin() ); 
  }
  return *this;	  
}

void Deck::shuffle() {
  	srand( time( NULL ) );
    for ( size_t i = 0; i < capacity; ++i ) {
	  size_t number = rand() % 52;
	  if ( i != number ) {
	    std::swap( deck_data[ i ], deck_data[ number ] );
	  }
	}
}

Hand::Hand() { hand_data.resize( defaultCapacity, Card() ); }

Hand::~Hand() {}

Hand::Hand( const Hand &b ) : _size( b._size ), capacity( b.capacity ), hand_data( b.hand_data ),
							  ace_counter( b.ace_counter ), weight( b.weight ) {}

Dealer::Dealer() {}

Dealer::~Dealer() {}

void Game::who_is_winner( Dealer & dealer ) {
  if ( ( ( dealer.hand_1.weight > dealer.hand_2.weight && dealer.hand_1.weight < 22 ) ||
  	 ( dealer.hand_1.weight < 22 && dealer.hand_2.weight > 21 ) || ( dealer.gold_point_1 ) )
  	 && ( !dealer.gold_point_2 ) ) {
		victories[ dealer.number_1 ].counter++;
		victories[ dealer.number_1 ].name = dealer.name_1;
		std::cout << dealer.name_1 << " is winner!" << std::endl;
  }
  if ( ( ( dealer.hand_2.weight > dealer.hand_1.weight && dealer.hand_2.weight < 22 ) ||
  	 ( dealer.hand_2.weight < 22 && dealer.hand_1.weight > 21 ) || ( dealer.gold_point_2 ) ) &&
  	 ( !dealer.gold_point_1 ) ) {
		victories[ dealer.number_2 ].counter++;
		victories[ dealer.number_2 ].name = dealer.name_2;
		std::cout << dealer.name_2 << " is winner!" << std::endl;
  }
  if ( dealer.hand_1.weight > 21 && dealer.hand_2.weight > 21 ) {
	std::cout << "There is no winner!" << std::endl;
  }
  else if ( dealer.hand_1.weight == dealer.hand_2.weight ) {
       	 std::cout << "Draw!" << std::endl;  
       }
}

Game::Game() { victories.resize( defaultCapacity, Tmp() ); }

Game::~Game() {}

void Game::detailed( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count ) {
  std::cout << "Detailed mode is started" << std::endl;
  std::string buf;
  int max = 0;
  int pos = 0;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  Dealer dealer;
	  dealer.deck.shuffle();
	  std::getline( std::cin, buf );
      strats[ i ]->strategy( dealer, true );
	  std::cout << "Hand`s weight = " << dealer.hand_1.weight << std::endl;
	  std::getline( std::cin, buf );
      strats[ j ]->strategy( dealer, false );
	  std::cout << "Hand`s weight = " << dealer.hand_2.weight << std::endl;
	  std::cout << std::endl;
	  who_is_winner( dealer );
	}
  }
  for ( int i = 0; i < count; ++i ) {
    if ( max < victories[ i ].counter ) {
  	  max = victories[ i ].counter;
	  pos = i;
	}
  }
  if ( max != 0 ) {
  	std::cout << std::endl;
  	std::cout << victories[ pos ].name << " is the absolute winner!!!" << std::endl;
  }	
}

void Game::fast( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count ) {
  std::cout << "Fast mode is started" << std::endl;
  int max = 0;
  int pos = 0;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  Dealer dealer;	
	  dealer.deck.shuffle();
	  dealer.f = true;
	  std::cout << std::endl;
      strats[ i ]->strategy( dealer, true );
	  std::cout << "First hand`s weight = " << dealer.hand_1.weight << std::endl;
	  std::cout << std::endl;
      strats[ j ]->strategy( dealer, false );
	  std::cout << "Second hand`s weight = " << dealer.hand_2.weight << std::endl;
	  std::cout << std::endl;
	  who_is_winner( dealer );
	}
  }
  for ( int i = 0; i < count; ++i ) {
    if ( max < victories[ i ].counter ) {
  	  max = victories[ i ].counter;
	  pos = i;
	}
  }
  if ( max != 0 ) {
  	std::cout << std::endl;
    std::cout << victories[ pos ].name << " is the awesome winner!!!" << std::endl;
  }
}

void Game::tournament( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count ) {
  std::cout << "Tournament mode is started" << std::endl;
  int max = 0;
  int pos = 0;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  Dealer dealer;
	  dealer.deck.shuffle();
	  std::cout << std::endl;
      strats[ i ]->strategy( dealer, true );
	  std::cout << "Hand`s weight = " << dealer.hand_1.weight << std::endl;
	  std::cout << std::endl;
      strats[ j ]->strategy( dealer, false );
	  std::cout << "Hand`s weight = " << dealer.hand_2.weight << std::endl;
	  std::cout << std::endl;
	  who_is_winner( dealer );
	}
  }
  for ( int i = 0; i < count; ++i ) {
    if ( max < victories[ i ].counter ) {
  	  max = victories[ i ].counter;
	  pos = i;
	}
  }
  if ( max != 0 ) {
  	std::cout << std::endl;
    std::cout << victories[ pos ].name << " is the winner of tournament!!!" << std::endl;
  }
}

int main( int argc, char *argv[] ) {
		
	Game game;
	
	std::vector< std::unique_ptr<Strategy> > strats;

	if ( argc < 4 ) {
	  std::cout << "Please give me players!" << std::endl;
	  return -1;
	}

	std::cout << std::endl;
	
	Factory< Strategy, Strategy*(*)(), std::string > * f = Factory< Strategy, Strategy*(*)(), std::string >::get_instance(); 

	for ( int i = 2; i < argc; ++i ){
	  strats.emplace_back( f->create( argv[ i ] ) );	
	}
	
	if ( std::string( argv[ 1 ] ) == "detailed" ) {
	  game.detailed( strats, argc - 2 );	
	}
	
	if ( ( argc == 4 && std::string( argv[ 1 ] ) != "tournament" && std::string( argv[ 1 ] ) != "detailed" ) || std::string( argv[ 1 ] ) == "fast" ) {
	  game.fast( strats, argc - 2 );	
	}
	
	if ( ( argc > 4 && std::string( argv[ 1 ] ) != "fast" && std::string( argv[ 1 ] ) != "detailed" ) || std::string( argv[ 1 ] ) == "tournament" ) {
	  game.tournament( strats, argc - 2 );	
	}
	
}
