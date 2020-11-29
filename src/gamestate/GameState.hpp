class GameState {
	public:
	GameState(int width, int height);
	~GameState(){};
	void handle(sf::Event&, sf::RenderWindow&, /* sf::Vector2i&, */ GlobalContext& glob);
	bool getIsGameStateActive() { return this -> IsGameStateActive;}
	void setGameStateActive(bool condition) { this -> IsGameStateActive = condition; }
	void zoom(sf:: View& view, sf::Event& evnt);
	//void drawScene(sf::RenderWindow& window);

	private:

	MapHandler mapHandl; //Создание карты
	MapRedactor mapRedct;
	GridInfo infotable;

	bool toggleParallax = true;
	bool toggleCentering = true;
	bool mapRed=false;
	int m_width;
	int m_height;
	bool IsGameStateActive = false;
	sf::View view;
	sf::View parallaxView;
	Pathfinder m_pathfinder(MapHandler&);

	// std::list<Movable*> allMovingObjects,
	// 					iterToPlayer,
	// 					drawingIter,
	// 					collisionIter1,
	// 					collisionIter2;
	// std::list<Movable*>::iterator iterToPlayer;
	// std::list<Movable*>::iterator drawingIter;
	// std::list<Movable*>::iterator collisionIter1;
	// std::list<Movable*>::iterator collisionIter2;
};