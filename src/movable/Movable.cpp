Movable::MovementData Movable::calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position)
{
	 		m_TargetX = target.x;
			m_TargetY = target.y;
			xLength = m_TargetX - position.x;
			yLength = m_TargetY - position.y;
			Vector = sqrt(pow((m_TargetX - position.x),2)
					+ pow(m_TargetY - position.y,2));
			speedToNextPointX = m_speed * (xLength / Vector);
			speedToNextPointY = m_speed * (yLength / Vector);

			float degrees = atan2(xLength, -yLength) *(180/M_PI) - 90;

			this ->  m_movementData.speed.x = speedToNextPointX;
			this ->  m_movementData.speed.y = speedToNextPointY;
			this ->  m_movementData.degrees = degrees;

			std::cout << "tx " << target.x << "ty " << target.y << std::endl;
			return m_movementData;
}
void Movable::setPosition(float x, float y)
{
	this -> m_shape.setPosition(x, y);
}

void Movable::setPosition(sf::Vector2f pos)
{
	this -> m_shape.setPosition(pos);
}
void Movable::setRotation(float degrees)
{
		this -> m_shape.setRotation(degrees);
}