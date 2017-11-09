#ifndef HEADER_MY_BLACKJACK
#define HEADER_MY_BLACKJACK

#include <vector>
#include <string>

class Card {
public:
  Card();
  ~Card();	
  Card( const Card &b );
  Card( const std::string &v, const std::string &s );
  Card &operator=( const Card &b );	
  friend bool operator==( const Card &a, const Card &b );
  friend bool operator!=( const Card &a, const Card &b );
  std::string value;
  std::string suit;	
private:	
  int weight = 0;
  bool _ace = false;
  bool used = false;	
  const std::string spades = "spades";
  const std::string hearts = "hearts";
  const std::string clubs = "clubs";
  const std::string diamonds = "diamonds";
  const std::string	ace = "ace";
  const std::string	king = "king";
  const std::string	queen = "queen";
  const std::string	jack = "jack";	
  const int dec = 10;
  const int two = 2;	
};

class Deck {	
public:
  Deck();
  ~Deck();
  Deck( const Deck &b );
  Deck &operator=( const Deck &b );
  void shuffle();	
  std::vector< Card > deck_data;	
private:
  size_t static const defaultCapacity = 52;
  size_t _size = 0;
  size_t capacity = defaultCapacity;
};

class Hand {
public:	
  Hand();
  ~Hand();
  Hand( const Hand &b );	
  std::vector< Card > hand_data;		
private:
  size_t static const defaultCapacity = 10;
  size_t _size = 0;
  size_t capacity = defaultCapacity;
};

class Enemy {
public:
  Enemy();
  ~Enemy();
private:
  Hand e_hand;
  size_t victory_conter = 0;
  Card first_card = e_hand.hand_data[ 0 ];	
};

class Dealer {
  Dealer();
  ~Dealer();
  void distribution( Deck &b );
};

#endif
