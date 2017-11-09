class Strategy { // Интерфейс
public:
	virtual void strategy( int x, int y ) = 0;
	
	virtual ~Strategy() {}
};