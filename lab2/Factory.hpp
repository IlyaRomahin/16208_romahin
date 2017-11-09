#include "Hashtable.hpp"

template < class Product >
class DefaultErrorPolicy {
public:
	static Product * error() {
		return nullptr;
	}
};

template< class Product,
		  class Creator,
		  class ID,
		  class ErrorPolicy = DefaultErrorPolicy< Product > >
class Factory {
public:
	static
	Factory * get_instance() {
		static Factory f;
		return &f;
	}	
	
	Product * create( const ID& id ) {
		if ( !( strategies.contains( id ) ) ) {
			return ErrorPolicy::error();
		}
			return strategies[ id ]();
	}
	bool regist3r( const ID& id, Creator creator ) {
		strategies[ id ] = creator;
		return true;
	}
	
private:
	HashTable< ID, Creator > strategies;
};
