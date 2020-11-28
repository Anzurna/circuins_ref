Player::Player() {
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;
	m_step = 0;
	m_type = 0;
	keys = 0;
	win = false;
	this -> m_texture.loadFromFile("content/CharSprites/basic2.png");
	maxHP = 500;
	this -> m_shape.setTexture(&m_texture);

//	alignHelper.setFillColor(sf::Color::Green);
//  alignHelper.setSize(sf::Vector2f(40.0f, 5.0f));
}
/*
Player::Player(int team, int HP)
{
	speedToNextPointX = 0.0f;
	speedToNextPointY = 0.0f;
	previousPointX = 0.0;
	previousPointY = 0.0;
	m_TargetX = 0.0;
	m_TargetY = 0.0;
	TotalSpeed = 2;

	PlayerTexture.loadFromFile("content/CharSprites/Golden/1small.png");
	playFig.setTexture(&PlayerTexture);
	this -> m_team = team;
	this -> HP = 500;
} */
float Player::getPreviousX()
{
	return (this->previousPointX);
}

float Player::getPreviousY()
{
	return (this->previousPointY);
}

float Player::getTargX()
{
	return (this->m_TargetX);
}

float Player::getTargY()
{
	return (this->m_TargetY);
}



sf::Vector2i Player::getTransformedPosition()
{
	return (this->transformedPlayerPosition);
}

void Player::setTargX(float X)
{
	this->m_TargetX = X;
}
void Player::setTargY(float Y)
{
	this->m_TargetY = Y;
}
/* void Player::setPosition(float x, float y)
{
	this -> characterShape.setPosition(x, y);
} */




// Дублирование кода в двух функциях, следует отрефакторить
void Player::moveClick(sf::RenderWindow& window, sf::View view, float targetX,float targetY)
{
			transformedPlayerPosition = window.mapCoordsToPixel( m_shape.getPosition() , view );
			previousPointX = transformedPlayerPosition.x;
			previousPointY = transformedPlayerPosition.y;
			m_TargetX = targetX;
			m_TargetY = targetY;
			xLength = m_TargetX - previousPointX;
			yLength = m_TargetY - previousPointY;
			Vector = sqrt(pow((targetX - previousPointX),2) + pow((targetY - previousPointY),2));
			speedToNextPointX = TotalSpeed * 3 * (xLength / Vector);
			speedToNextPointY = TotalSpeed * 3 * (yLength / Vector);

			float degrees = atan2(xLength, -yLength) *(180/M_PI) - 90; // Рабочая строчка НЕ ТРОГАТЬ
			m_shape.setRotation(degrees);
			std::cout << degrees << std::endl;
			//alignHelper.setRotation(degrees);
/* 			if (abs(xLength) < 4 && abs(yLength) < 4) {
				speedToNextPointX = speedToNextPointY = 0;
			} */
			//playFig.move(speedToNextPointX,speedToNextPointY);
			/* while (true abs(transformedPlayerPosition.x - targetX) >= 15 && abs(transformedPlayerPosition.y - targetY)>=15 ){

			} */
}

void Player::move(sf::RenderWindow& window, sf::View view, int& ia)
{
	transformedPlayerPosition = window.mapCoordsToPixel( playFig.getPosition() , view );
	previousPointX = transformedPlayerPosition.x;
	previousPointY = transformedPlayerPosition.y;
	xLength = m_TargetX - previousPointX;
	yLength = m_TargetY - previousPointY;

	if (abs(xLength) < 15 && abs(yLength) < 15 && (ia == (int)m_path.size())) {
		speedToNextPointX = speedToNextPointY = 0;
		ia = 0;
		this -> isPathExists = false;
		m_path.clear();
	} else if (abs(xLength) < 15 && abs(yLength) < 15 && ia < (int)m_path.size()) {
		ia++;
	} else  {
		playFig.move(speedToNextPointX,speedToNextPointY);
	}
	std::cout << isPathExists << "  "  << std::endl;
}
void Player::move(sf::RenderWindow& window, sf::View view, MapHandler& mapHandl, float dt)
 {
	if ( m_step < (int)m_path.size() && this -> isPathExists){
		this -> moveClick(window, view, mapHandl.allVertex[m_path[m_step]].getTransformedVertexPosition().x,
		mapHandl.allVertex[m_path[m_step]].getTransformedVertexPosition().y);
	}

	transformedPlayerPosition = window.mapCoordsToPixel( m_shape.getPosition() , view );
	previousPointX = transformedPlayerPosition.x;
	previousPointY = transformedPlayerPosition.y;
	xLength = m_TargetX - previousPointX;
	yLength = m_TargetY - previousPointY;

	if ((abs(xLength) < 15) && (abs(yLength) < 15) && (m_step == (int)m_path.size())) {
		speedToNextPointX = speedToNextPointY = 0;
		m_step = 0;
		this -> isPathExists = false;
		m_path.clear();
	} else if ((abs(xLength) < 15) && (abs(yLength) < 15) && (m_step < (int)m_path.size())) {
		m_step++;
	} else  {
		m_shape.move(speedToNextPointX * 5 *(1+dt), speedToNextPointY * 5* (1+dt));
	}
	std::cout << isPathExists << "  "  << std::endl;
}

// Этот большой цикл занимается тем, что двигает нашего игрока между вершинами
// Позже следует внести изменения и выделить его в отдельный независимый кусок кода, потому как идентичный алгоритм будет
// использован для всех прочих неигровых персонажей.
// Имеет место(24.11.19) нарушение инкапсуляции — вектор из вершин, который содержится в экземпляре класса MapHandler
// доступен всем. Это связано с тем, что при возвращении через геттер мне не удалось заставить все это работать.
// Предложения приветствуются.

// Принцип работы цикла:
// 1. Пробегает весь вектор с вершинами
// 2. Если игрок касается вершины (метод checkIsOn класса Vertex), то
// 3. Проверяет кликнута ли какая-либо вершина
// 4. Если кликнута — проверяет, содержится ли она в списке доступных для перемещения(связанных) вершин.
// Для 4 надо вызвать Дейкстру
// 5. Если так, то пасует данные вершины методу MoveClick
/* void Player::moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder ){
	for (unsigned int i = 0; i < MapHndl.allVertex.size(); i++) {
		if (MapHndl.allVertex[i].checkIsOn(this -> getTransformedPosition())) {
			for (unsigned int a = 0; a < MapHndl.allVertex.size(); a++) {
				if (MapHndl.allVertex[a].checkIsClicked(window, mousePos, view)) {
					m_path = pathfinder.algorithmDijkstra(MapHndl.allVertex[i].getID()-1,MapHndl.allVertex[a].getID()-1);
					for (unsigned int j = 1; j<m_path.size(); j++){
						std::cout<< m_path[j] << ' ';
					for (unsigned int k = 0; k < MapHndl.allVertex[i].getConnectionCodesVectorSize(); k++) {

						if (MapHndl.allVertex[a].getID() == MapHndl.allVertex[i].getConnectionCode(k)) {
							this -> moveClick(window, view,
											MapHndl.allVertex[a].getTransformedVertexPosition().x,
											MapHndl.allVertex[a].getTransformedVertexPosition().y);
						}
					}
					}
				}
			}
		}
	}
} */
std::vector<int> Player::moveToVertex(sf::RenderWindow& window, MapHandler& MapHndl, sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder ){
	for (unsigned int i = 0; i < MapHndl.allVertex.size(); i++) {
		if (MapHndl.allVertex[i].checkIsOn(this -> getTransformedPosition())) {
			for (unsigned int a = 0; a < MapHndl.allVertex.size(); a++) {
				if (MapHndl.allVertex[a].checkIsClicked(window, mousePos, view)) {
					m_path = pathfinder.algorithmDijkstra(MapHndl.allVertex[i].getID()-1, MapHndl.allVertex[a].getID()-1);
				}
			}
		}
	}
	for (unsigned int j = 1; j<m_path.size(); j++){
						std::cout << "Path: " << m_path[j] <<std::endl;
	}
	return m_path;
}
/*
 void Player::moveSelf(float speedX,float speedY)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: Enter))
		{
			playFig.setPosition(10.0f, 10.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: A))
		{
			playFig.move(-speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: W))
		{
			playFig.move(0.0f , -speedY );
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: D))
		{
			playFig.move(speedX, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key:: S))
		{
			playFig.move(0.0f, speedY);
		}
}
*/

void Player::eventListener(sf::Event &event, sf::RenderWindow& window, MapHandler& MapHndl,
						   sf::Vector2i mousePos, sf::View view, Pathfinder& pathfinder)
{
	sf::Vector2i transformedMousePosition;
	transformedMousePosition.x  = (int)(window.mapPixelToCoords( mousePos, view ).x);
	transformedMousePosition.y  = (int)(window.mapPixelToCoords( mousePos, view ).y);
	this -> calculateSpeedAndRotation(transformedMousePosition, {(int)(getPosition().x), (int)(getPosition().y)});
	m_shape.setRotation(m_movementData.degrees);
	if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::R) {
						this -> setPosition(6000.0f, 6000.0f);
	}
	if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::L) {
						this -> setPosition(2000.0f, 2000.0f);
	}
	if (event.type == sf::Event::MouseButtonReleased && (event.mouseButton.button ==  sf::Mouse::Right)) {
				this -> moveToVertex( window, MapHndl, mousePos, view, pathfinder);
				this -> isPathExists = true;
	}
		if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::R) {
			this -> setPosition( this -> getPosition().x - 100, this -> getPosition().y);
	}


}
Movable::MovementData Player::calculateSpeedAndRotation(sf::Vector2i target, sf::Vector2i position)
{

			xLength = target.x - position.x;
			yLength = target.y - position.y;
			Vector = sqrt(pow(xLength,2)
					+ pow(yLength,2));
			float fspeedToNextPointX = 10 * (xLength / Vector);
			float fspeedToNextPointY = 10 * (yLength / Vector);

			float degrees = atan2(xLength, -yLength) *(180/M_PI) - 90;

			speedToLeftX = 10 * (xLength/ -Vector);
			speedToLeftY = 10 * (-yLength/ -Vector);
/* 			float VectorLeft = sqrt(pow(xLength,2)
					+ pow(-target.y - position.y,2));
			float VectorRight = sqrt(pow(-target.x - position.x,2)
					+ pow(yLength,2));


			speedToRightX = 10 * ((-target.x - position.x)/ VectorRight);
			speedToRightY = 10 * ((target.y - position.x)/ VectorRight); */
			if (abs(xLength) < 10 && abs(yLength) < 10) {
				fspeedToNextPointX = 0;
				fspeedToNextPointY = 0;
			}


			this ->  m_movementData.speed.x = fspeedToNextPointX;
			this ->  m_movementData.speed.y = fspeedToNextPointY;
			this ->  m_movementData.degrees = degrees;
			std::cout << "tx " << target.x << "ty " << target.y << std::endl;
			return m_movementData;


}
void Player::realTimeListener()
{
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::W)) {

		m_shape.move(m_movementData.speed.x, m_movementData.speed.y);
		isPathExists = false;

	}

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {

		m_shape.move(m_movementData.speed.y, -m_movementData.speed.x);
	}
	if  (sf::Keyboard::isKeyPressed (sf::Keyboard::S)) {

		m_shape.move(-m_movementData.speed.x, -m_movementData.speed.y);
	}
	if  (sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {

		m_shape.move(-m_movementData.speed.y, m_movementData.speed.x);
	}
}

void Player::move(float speedX, float speedY)
{
	this -> m_shape.move(speedX, speedY);
}
void Player::draw(sf::RenderWindow *window)
{
	hpBar.setSize(sf::Vector2f((this -> getHP()/5), 6));
	hpBar.setPosition(this -> getPosX(), this -> getPosY()+60);

	window -> draw(this -> m_shape);
	window -> draw( this -> hpBar);
}