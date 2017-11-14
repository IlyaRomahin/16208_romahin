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
	    std::swap( deck_data[i], deck_data[number] );
	  }
	}	
}

Hand::Hand() { hand_data.resize( defaultCapacity, Card() ); }

Hand::~Hand() {}

Hand::Hand( const Hand &b ) : _size( b._size ), capacity( b.capacity ), hand_data( b.hand_data ) {}

Enemy::Enemy() {}

Enemy::~Enemy() {}

Game::Game() {}

Game::~Game() {}

void Game::detailed( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Detailed mode is started" << std::endl;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();	
      strats[ i ]->strategy( deck, Hand(), true );
      strats[ j ]->strategy( deck, Hand(), false );
	}
  }
}

void Game::fast( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Fast mode is started" << std::endl;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();
      strats[ i ]->strategy( deck, Hand(), true );
      strats[ j ]->strategy( deck, Hand(), false );
	}
  }
}

void Game::tournament( std::vector< Strategy * > &strats, const size_t count ) {
  std::cout << "Tournament mode is started" << std::endl;
  for ( size_t i = 0; i < count - 1; ++i ) {
	for ( size_t j = i + 1; j < count; ++j ) {
	  deck.shuffle();
      strats[ i ]->strategy( deck, Hand(), true );
      strats[ j ]->strategy( deck, Hand(), false );
	}
  }
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
