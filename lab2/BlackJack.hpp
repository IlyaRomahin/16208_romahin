#ifndef HEADER_MY_BLACKJACK
#define HEADER_MY_BLACKJACK

#include <vector>
#include <string>
#include <memory>

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
  int weight = 0;
  bool _ace = false;
private:
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
  int weight = 0;	
  int _size = 0;
  int ace_counter = 0;
private:	
  size_t static const defaultCapacity = 12;
  size_t capacity = defaultCapacity;
};

class Dealer {
public:	
  Dealer();
  ~Dealer();	
  Deck deck;
  int pos_in_deck = 0;
  size_t number_1 = 0;
  size_t number_2 = 0;
  bool gold_point_1 = false;
  bool gold_point_2 = false;
  bool f = false;
  std::string name_1;
  std::string name_2; 
  Hand hand_1;
  Hand hand_2;
};

class Strategy {
public:
	virtual void strategy( Dealer & dealer, const bool first ) = 0;
	
	virtual ~Strategy() {}
};

class Game {
public:	
  Game();
  ~Game();
  void who_is_winner( Dealer & dealer );
  void detailed( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count );
  void fast( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count );
  void tournament( std::vector< std::unique_ptr<Strategy> > &strats, const size_t count );
  struct Tmp {
    size_t counter = 0;
    std::string name;
    Tmp() {}
    ~Tmp() {}
  };
  std::vector< Tmp > victories;
  private:
    size_t static const defaultCapacity = 128;
    size_t capacity = defaultCapacity;
};

#endif
