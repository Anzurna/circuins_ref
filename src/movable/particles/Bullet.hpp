class Bullet : public Movable {

	public:
	Bullet();
	Bullet (sf::Texture* texture, int team);
	~Bullet(){};
	void setPosition(sf::Vector2f);
	void draw(sf::RenderWindow*);
	void move(sf::Vector2f );
	void move();
	void setRotation(float degrees);
	void setRotation();
	void handle(std::list<Movable*>& list, std::list<Movable*>::iterator&, float dt);
	sf::Vector2f getPosition() { return this -> m_shape.getPosition(); };
	int getTeam() { return this -> m_team; };
	bool getIsHit() { return isHit; };
	void setIsHit() {this -> isHit = true; };




	private:

	sf::RectangleShape m_shape;
	sf::Texture m_texture;
	int m_team;
	float m_timer;
	float m_maxRange;
	bool isHit;


};