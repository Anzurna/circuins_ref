class Enemy : public Character
{
	public:
	Enemy(){};
	Enemy(float, float, sf::Texture&);
	~Enemy(){};
	void move();
	void move(float, float);
	void behave(std::list<Movable*>& allMovingObjects, sf::Vector2f target, float dt);
	void setID(unsigned int id) { this -> ID = id;};
	void handle(std::list<Movable*>& list, std::list<Movable*>::iterator&, float);
	void dropKey(std::list<Movable*>& list);
	void setHasKey() { this -> m_hasKey = true;};
	void draw(sf::RenderWindow*);
	//void setPosition(float x, float y);
	private:
	int behaviour;
	bool isActive;
	unsigned int ID;
	bool m_hasKey;

};