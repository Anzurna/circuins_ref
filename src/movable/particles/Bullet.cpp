Bullet::Bullet ()
{
	m_texture.loadFromFile("content/particles/red1.png");
	this -> m_shape.setTexture(&m_texture);
	this -> m_shape.setSize({100.0f, 100.0f});
	this -> m_maxRange = 600;


}
Bullet::Bullet (sf::Texture*, int team)
{
	m_texture.loadFromFile("content/particles/pBullet1.png");
	//this -> m_shape.setTexture(texture);
	this -> m_shape.setTexture(&m_texture);
	this -> m_shape.setSize({60.0f, 15.0f});
	this -> m_team = team;
	this -> setType(1);
		m_speed = 10;
	isHit = false;

}

void Bullet::setPosition(sf::Vector2f position)
{
	this -> m_shape.setPosition(position.x, position.y);
}

void Bullet::draw(sf::RenderWindow* window)
{
	window -> draw(this -> m_shape);
}

void Bullet::move(sf::Vector2f speed)
{
	this -> m_shape.move(speed.x, speed.y);
}

void Bullet::move()
{
	this -> m_shape.move(this -> m_movementData.speed.x*1.5, this -> m_movementData.speed.y*1.5);
}

void Bullet::setRotation(float degrees) { this -> m_shape.setRotation(degrees); }
void Bullet::setRotation() { this -> m_shape.setRotation(m_movementData.degrees); }

void Bullet::handle(std::list<Movable*>& list, std::list<Movable*>::iterator& iter, float dt)
{
	this -> m_timer +=dt;
	if ( this -> m_timer > 3) {
		this -> m_movementData.speed.x = 0;
		this -> m_movementData.speed.y = 0;
		this -> ~Bullet();
		list.erase(iter--);
	}
}