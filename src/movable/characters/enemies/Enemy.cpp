Enemy::Enemy(float x, float y, sf::Texture& tx) {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	m_speed = 5;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;
	isActive = false;
	m_type = 2;
	HP = 500;
	maxHP = 500;
	m_hasKey = true;
	//m_hasKey = false;
	this -> m_shape.setTexture(&tx);
	this -> m_shape.setPosition(x, y);

//	alignHelper.setFillColor(sf::Color::Green);
//  alignHelper.setSize(sf::Vector2f(40.0f, 5.0f));
}
/* void Enemy::setPosition(float x, float y)
{
	return this -> characterShape.setPosition(x, y);
} */

void Enemy::behave(std::list<Movable*>& allMovingObjects, sf::Vector2f target, float dt)
{
	srand(time(0));
	int o;
	o = ((rand()+ this -> ID + rand())%5) +1;
	 this -> m_timer1 += dt;
	if (abs(target.x - (this -> getPosition().x)) < 1000 &&
			abs(target.y - (this -> getPosition().y)) < 1000 && !(isActive))  {
				this -> isActive = true;
	}
	 if (this -> isActive) {
		if (abs(target.x - (this -> getPosition().x)) > 300 &&
			abs(target.y - (this -> getPosition().y)) > 300) {
			this -> calculateSpeedAndRotation({(int)target.x, (int)target.y},
							{(int)this ->getPosition().x, (int)this ->getPosition().y});
			this -> setRotation(m_movementData.degrees);
		}
		if (abs(target.x - (this -> getPosition().x)) < 800 &&
			abs(target.y - (this -> getPosition().y)) < 800) {
				switch(o) {
					case 3:
						this -> move(m_movementData.speed.y + (rand()%3), -m_movementData.speed.x);
						break;
					case 4:
						this -> move(-m_movementData.speed.y + (rand()%3), m_movementData.speed.x);
						break;
					case 5:
						this -> move(-m_movementData.speed.x + (rand()%3), -m_movementData.speed.y);
						break;
					case 2:
						this -> move(m_movementData.speed.x + (rand()%3), m_movementData.speed.y);
						break;
					default:
						break;
				}
			}
		if (m_timer1 > 0.3)	{//		if (Time > 1.0) {
			if (abs(target.x - this -> getPosition().x) < 800 &&
			abs(target.y - this -> getPosition().y) < 800) {
				this ->fire(allMovingObjects, {(int)target.x,
								(int)target.y});
			}
				this -> m_timer1 = 0;
			}
	 }

}
void Enemy::move()
{
	this -> m_shape.move(this -> m_movementData.speed.x, this -> m_movementData.speed.y);
}
void Enemy::move(float x, float y)
{
	this -> m_shape.move(x, y);
}

void Enemy::handle(std::list<Movable*>& list, std::list<Movable*>::iterator& iter, float)
{
	if (this -> getHP() <=100) {
		if (this -> m_hasKey) {
			this -> dropKey(list);
			this -> m_hasKey = false;
		}
	}
	if (this -> getHP() <=0) {
		this -> ~Enemy();
		iter = list.erase(iter);
	}
}
void Enemy::dropKey(std::list<Movable*>& list)
{
	Key *tempKey = new Key();
	list.push_back(tempKey);
	list.back() -> setPosition(this -> getPosition());
}
void Enemy::draw(sf::RenderWindow *window)
{

	hpBar.setSize(sf::Vector2f((this -> getHP()/5), 6));
	hpBar.setPosition(this -> getPosX(), this -> getPosY()+60);

	if (this -> isActive) {
	window -> draw( this -> m_shape);
	window -> draw(hpBar);
	}
}

