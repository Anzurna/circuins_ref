class Character : public Movable
{
	public:

	virtual ~Character(){};
	virtual void fire(std::list<Movable*>& allBullets, sf::Vector2i target);
	virtual float getPosX();
	virtual float getPosY();
	virtual int getHP() {return this -> HP;};
	virtual void changeHP(int amount);
	virtual void setHP(int amount);
	virtual void draw(sf::RenderWindow *);
	//void setPosition(float, float);

	protected:
	Character();

	sf::Texture m_bulletTexture;
	sf::Texture m_bulletTexture2;

	int HP;
	int maxHP;
	sf::RectangleShape hpBar;
	float m_timer1;
	bool flag = true;

};

