class Movable {




	public:

	struct MovementData {
		sf::Vector2f speed; // x,y speed to target
		float degrees; // Rotation to target
	};


	virtual Movable::MovementData calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position);
	virtual void setTeam(int team) { this -> m_team = team; };
	virtual void setPosition(float x, float y);
	virtual void setPosition(sf::Vector2f);
	virtual int getTeam() { return this -> m_team; };
	virtual sf::Vector2f getPosition() { return this -> m_shape.getPosition(); };
	virtual void draw(sf::RenderWindow*){};
	virtual void move(){};
	virtual void changeHP(int){};
	virtual void setRotation(float);
	virtual int getType(){return this -> m_type;};
	virtual void setType(int type) {this -> m_type = type;};
	virtual ~Movable(){};
	virtual int getHP(){ return 1;};
	virtual void handle(std::list<Movable*>&, std::list<Movable*>::iterator&, float ) {};
	virtual void behave(std::list<Movable*>&, sf::Vector2f, float) {};
	virtual bool getIsHit() { return 0; };
	virtual void setIsHit() {};



	protected:

	float speedToNextPointX;
	float speedToNextPointY;
	float xLength;
	float yLength;
	float m_TargetX;
	float m_TargetY;
	float Vector;
	float TotalSpeed;
	int m_team;
	int m_type;
	float m_speed;
	sf::Texture m_texture;
	sf::RectangleShape m_shape;
	MovementData m_movementData;



	// Define for yourself — is it transformed or not!



};