void Vertex::init(int ID, cords self, std::vector<unsigned int> connectionVector)
{
	m_ID = ID;
	selfCords = self;
	for (unsigned int i = 0; i < connectionVector.size(); i++){
		m_connectionCodes.push_back(connectionVector[i]);
	}
	isVisible=false;
	mouseIsOn=false;
	graphicVertex.setFillColor(sf::Color::Cyan);
	graphicVertex.setRadius(60.0f);
	graphicVertex.setOrigin(30.0f, 30.0f);
	graphicVertex.setPosition(this-> selfCords.m_x, this-> selfCords.m_y);
}
bool Vertex::checkIsOn(sf::Vector2i position)
{
	if (abs((position.x) - (this -> transformedVertexPosition.x)) <= 60
	&& abs((position.y) - (this -> transformedVertexPosition.y)) <= 60) {
		return (this -> characterIsOn = true);
	} else {
		return (this -> characterIsOn = false);
	};
}
bool Vertex::checkIsClicked(sf::RenderWindow& window, sf::Vector2i mousePos, sf::View view)
{
	transformedMousePosition = window.mapPixelToCoords( {mousePos.x, mousePos.y} , view );
	if (abs((mousePos.x) - (this -> transformedVertexPosition.x)) <= 60
		&& abs((mousePos.y) - (this -> transformedVertexPosition.y)) <= 60) {
		this -> mouseIsOn = true;
	} else {
		this -> mouseIsOn = false;
	}
	return (this -> mouseIsOn );
}

void Vertex::draw(sf::RenderWindow* window, sf::View view)
{
	transformedVertexPosition = window -> mapCoordsToPixel( graphicVertex.getPosition(), view );
	if (isVisible) { window -> draw(graphicVertex); }
	if (mouseIsOn){
		graphicVertex.setFillColor(sf::Color::Red);
	} else if (characterIsOn){
		graphicVertex.setFillColor(sf::Color::Yellow);
	} else {
		graphicVertex.setFillColor(sf::Color::Cyan);
	}
}



bool Vertex::toggleVisibility()
{
	this -> isVisible = (this -> isVisible ? false : true);
	return isVisible;
}

bool Vertex::setIsMovable(bool b) {
	isMovable=b;
	return isMovable;
}

bool Vertex::setIsConnectable(bool c) {
	isConnectable=c;
	return isConnectable;
}

void Vertex::addConnection(int number) {
	this->m_connectionCodes.push_back(number);
}

void Vertex::Colorise() {
	graphicVertex.setFillColor(sf::Color::Green);
}


void Vertex::setPosition(sf::Vector2i mousePos)
{
	selfCords.m_x = mousePos.x;
	selfCords.m_y = mousePos.y;
	graphicVertex.setPosition(this-> selfCords.m_x, this-> selfCords.m_y);
}

void Vertex::setPosition (float a,float b) {
	graphicVertex.setPosition(a,b);
}
void Vertex::MoveCircle (float a,float b) {
	graphicVertex.move(a,b);
}
float Vertex::getPosX() {
	return graphicVertex.getPosition().x;
}

float Vertex::getPosY() {
	return graphicVertex.getPosition().y;
}



