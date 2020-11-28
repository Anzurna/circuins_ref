
class Player : public Character
{
	public:
	Player();
	//Player(int team, int HP){this -> m_team = team;};
	~Player() {};

	void DrawPlayer(sf::RenderWindow *window);
	void move(float speedX, float speedY);
	void moveSelf(float speedX,float speedY);
	void moveClick(sf::RenderWindow& , sf::View, float targetX,float targetY);
	void moveToVertex( sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view);
	std::vector<int> moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl,
										  sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder );
	float getTargX();
	float getTargY();
	float getPreviousX();
	float getPreviousY();
	Movable::MovementData calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position);

	sf::Vector2i getTransformedPosition();
	void move(sf::RenderWindow& window, sf::View view);
	void move(sf::RenderWindow& window, sf::View view, int& ia);

	void move(sf::RenderWindow& window, sf::View view, MapHandler& mapHandl, float dt);
	std::vector<int> getPath() { return this -> m_path; };
	void eventListener(sf::Event &event, sf::RenderWindow& window, MapHandler& MapHndl,
						   sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder);
	void realTimeListener();

	void setTargX(float);
	void setTargY(float);
	void addKey() { this -> keys += 1; };
	void destroyKeys() { this -> keys =0; };
	int getAmountOfKeys() {return this -> keys; };
	void draw(sf::RenderWindow*);
	//void setPosition(float, float);

	bool getIsPathExists() { return this -> isPathExists; };
	void setHasWon(bool w) { this -> win = w; };
	bool getHasWon() { return this -> win; };
	private:
	sf::RectangleShape playFig;
	sf::Texture PlayerTexture;
	sf::RectangleShape alignHelper;
	float previousPointX;
	float previousPointY;
	bool win;
	float speedToLeftX;
	float speedToLeftY;

	float speedToRightX;
	float speedToRightY;

	int m_step;
	bool isPathExists;
	sf::Vector2i transformedPlayerPosition;
	std::vector<int> m_path;

	sf::Texture e;
	int keys;
};
