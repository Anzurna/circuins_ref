Character::Character()
{
	hpBar.setOrigin(50.0f, 3.0f);
	hpBar.setFillColor(sf::Color::Red);
	m_shape.setSize(sf::Vector2f(300,300));
	m_shape.setOrigin(150.0f,150.0f);
	HP = 0;
	//m_texture.loadFromFile("content/CharSprites/basic2.png");
	m_type = 2;
	//m_shape.setTexture(&m_texture);
	this -> m_bulletTexture.loadFromFile("content/particles/pBullet1.png");
	m_bulletTexture2.loadFromFile("content/particles/pBullet2.png");
}


void Character::fire(std::list<Movable*>& allBullets, sf::Vector2i target)
{
	//Bullet *tempBullet;
/* 	if (flag) {

		flag = false;
	} else {
		tempBullet = new Bullet(&m_bulletTexture2, m_team);
		flag = true;
	} */
	//tempBullet = new Bullet(&m_bulletTexture, m_team);
	allBullets.push_back(new Bullet(&m_bulletTexture, m_team));
	allBullets.back() -> setPosition(this -> getPosition());
	allBullets.back() -> calculateSpeedAndRotation(target,
	 {(int)this -> getPosX(), (int)this -> getPosY()});
	allBullets.back() -> setRotation(allBullets.back() -> calculateSpeedAndRotation(target,
	 {(int)this -> getPosX(), (int)this -> getPosY()}).degrees);
	// tempBullet = 0;

}
float Character::getPosX()
{
	return (this -> m_shape.getPosition().x);
}

float Character::getPosY()
{
	return (this -> m_shape.getPosition().y);
}
void Character::changeHP(int amount)
{
	if ((this -> HP > 0) && (this -> HP < maxHP-amount))
		this -> HP +=amount;
}
void Character::setHP(int amount)
{
	this -> HP = amount;
}

void Character::draw(sf::RenderWindow *window)
{

	hpBar.setSize(sf::Vector2f((this -> getHP()/5), 6));
	hpBar.setPosition(this -> getPosX(), this -> getPosY()+60);

	window -> draw(this -> m_shape);
	window -> draw( this -> hpBar);
}

/* void Character::setPosition(float x, float y)
{
	this -> characterShape.setPosition(x, y);
} */