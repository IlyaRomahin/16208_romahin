#include "BlackJack.hpp"
#include "Factory.hpp"
#include <iostream>
#include <exception>

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

Hand::Hand( const Hand &b ) : _size( b._size ), capacity( b.capacity ), hand_data( b.hand_data ) {}

Game::Game() {}

Game::~Game() {}

void Game::detailed( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Detailed mode is started" << std::endl;
  victory.resize( count, Tmp() );
  int max = 0;
  int pos = 0;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();
	  int * hand_weight_1 = new int;
	  int * hand_weight_2 = new int;
	  int * position = new int;
	  * hand_weight_1 = 0;
	  * hand_weight_2 = 0;
	  * position = 0;
	  std::string name_1;
	  std::string name_2;
	  bool gold_winner_1 = false;
	  bool gold_winner_2 = false;
      strats[ i ]->strategy( deck, Hand(), true, position, hand_weight_1, name_1, gold_winner_1 );
	  std::cout << * hand_weight_1 << std::endl;
      strats[ j ]->strategy( deck, Hand(), false, position, hand_weight_2, name_2, gold_winner_2 );
	  std::cout << * hand_weight_2 << std::endl;
	  if ( ( ( * hand_weight_1 > * hand_weight_2 && * hand_weight_1 < 22 ) || ( * hand_weight_1 < 22 && * hand_weight_2 > 21 ) || ( gold_winner_1 ) )
		 && ( !gold_winner_2 ) ) {
		victory[ i ].counter++;
		victory[ i ].name = name_1;
		std::cout << name_1 << " is winner!" << std::endl;
	  }
	  if ( ( ( * hand_weight_2 > * hand_weight_1 && * hand_weight_2 < 22 ) || ( * hand_weight_2 < 22 && * hand_weight_1 > 21 ) || ( gold_winner_2 ) )
		 && ( !gold_winner_1 ) ) {
		victory[ j ].counter++;
		victory[ j ].name = name_2;
		std::cout << name_2 << " is winner!" << std::endl;
	  }
	  if ( ( * hand_weight_1 > 21 && * hand_weight_2 > 21 ) || ( * hand_weight_1 == * hand_weight_2 ) ) {
		std::cout << "Draw!" << std::endl;
	  }
	  delete hand_weight_1;
	  delete hand_weight_2;
	  delete position;
	}
  }
  for ( int i = 0; i < count - 1; ++i ) {
    if ( max < victory[ i ].counter ) {
  	  max = victory[ i ].counter;
	  pos = i;
	}
  }
  std::cout << victory[ pos ].name << " is absolute winner!!!" << std::endl;
}

void Game::fast( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Fast mode is started" << std::endl;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();
	  int * hand_weight_1 = new int;
	  int * hand_weight_2 = new int;
	  int * position = new int;
	  * hand_weight_1 = 0;
	  * hand_weight_2 = 0;
	  * position = 0;
	  std::string name_1;
	  std::string name_2;
	  bool gold_winner_1 = false;
	  bool gold_winner_2 = false;
      strats[ i ]->strategy( deck, Hand(), true, position, hand_weight_1, name_1, gold_winner_1 );
	  std::cout << * hand_weight_1 << std::endl;
      strats[ j ]->strategy( deck, Hand(), false, position, hand_weight_2, name_2, gold_winner_2 );
	  std::cout << * hand_weight_2 << std::endl;
	  if ( ( ( * hand_weight_1 > * hand_weight_2 && * hand_weight_1 < 22 ) || ( * hand_weight_1 < 22 && * hand_weight_2 > 21 ) || ( gold_winner_1 ) )
		 && ( !gold_winner_2 ) ) {
		std::cout << name_1 << " is winner!" << std::endl;
	  }
	  if ( ( ( * hand_weight_2 > * hand_weight_1 && * hand_weight_2 < 22 ) || ( * hand_weight_2 < 22 && * hand_weight_1 > 21 ) || ( gold_winner_2 ) )
		 && ( !gold_winner_1 ) ) {
		std::cout << name_2 << " is winner!" << std::endl;
	  }
	  if ( ( * hand_weight_1 > 21 && * hand_weight_2 > 21 ) || ( * hand_weight_1 == * hand_weight_2 ) ) {
		std::cout << "Draw!" << std::endl;
	  }
	  delete hand_weight_1;
	  delete hand_weight_2;
	  delete position;
	}
  }
}

void Game::tournament( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Tournament mode is started" << std::endl;
  victory.resize( count, Tmp() );
  int max = 0;
  int pos = 0;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();
	  int * hand_weight_1 = new int;
	  int * hand_weight_2 = new int;
	  int * position = new int;
	  * hand_weight_1 = 0;
	  * hand_weight_2 = 0;
	  * position = 0;
	  std::string name_1;
	  std::string name_2;
	  bool gold_winner_1 = false;
	  bool gold_winner_2 = false;
      strats[ i ]->strategy( deck, Hand(), true, position, hand_weight_1, name_1, gold_winner_1 );
	  std::cout << * hand_weight_1 << std::endl;
      strats[ j ]->strategy( deck, Hand(), false, position, hand_weight_2, name_2, gold_winner_2 );
	  std::cout << * hand_weight_2 << std::endl;
	  if ( ( ( * hand_weight_1 > * hand_weight_2 && * hand_weight_1 < 22 ) || ( * hand_weight_1 < 22 && * hand_weight_2 > 21 ) || ( gold_winner_1 ) )
		 && ( !gold_winner_2 ) ) {
		victory[ i ].counter++;
		victory[ i ].name = name_1;
		std::cout << name_1 << " is winner!" << std::endl;
	  }
	  if ( ( ( * hand_weight_2 > * hand_weight_1 && * hand_weight_2 < 22 ) || ( * hand_weight_2 < 22 && * hand_weight_1 > 21 ) || ( gold_winner_2 ) )
		 && ( !gold_winner_1 ) ) {
		victory[ j ].counter++;
		victory[ j ].name = name_2;
		std::cout << name_2 << " is winner!" << std::endl;
	  }
	  if ( ( * hand_weight_1 > 21 && * hand_weight_2 > 21 ) || ( * hand_weight_1 == * hand_weight_2 ) ) {
		std::cout << "Draw!" << std::endl;
	  }
	  delete hand_weight_1;
	  delete hand_weight_2;
	  delete position;
	}
  }
  for ( int i = 0; i < count - 1; ++i ) {
    if ( max < victory[ i ].counter ) {
  	  max = victory[ i ].counter;
	  pos = i;
	}
  }
  std::cout << victory[ pos ].name << " is winner of tournament!!!" << std::endl;
}

int main( int argc, char *argv[] ) {
		
	Game game;
	
	std::vector< Strategy * > strats;

	if ( argc < 3 ) {
	  std::cout << "Please give me players!" << std::endl;
	  return -1;
	}
	
	Factory< Strategy, Strategy*(*)(), std::string > * f = Factory< Strategy, Strategy*(*)(), std::string >::get_instance(); 

	for ( int i = 1; i < argc; ++i ){
	  strats.push_back( f->create( argv[ i ] ) );	
	}
	
	if ( argc == 4 ) {
	  game.detailed( strats, argc - 1 );	
	}
	
	if ( argc == 3 ) {
	  game.fast( strats, argc - 1 );	
	}
	
	if ( argc > 4 ) {
	  game.tournament( strats, argc - 1 );	
	}
	
	for ( Strategy * st : strats ) {
	  delete st;
	}
	
}
