

 class Vertex
{
	private:
		struct cords{
			int m_x;
			int m_y;
		};
		cords selfCords;
		unsigned int m_ID;
		sf::CircleShape m_circle;
		//std::vector<Vertex> connected[];
		bool characterIsOn;
		sf::CircleShape graphicVertex;
		std::vector<unsigned int> m_connectionCodes;
		sf::Vector2i transformedVertexPosition;
		sf::Vector2f transformedMousePosition;
		bool mouseIsOn;
		bool isVisible;
		bool isMovable;
		bool isConnectable;

	public:
		Vertex(){};
		void init(int ID, cords self, std::vector<unsigned int>connectionVector);
		~Vertex(){};
		unsigned int getID() { return this -> m_ID; }
		bool getIsClicked() { return this -> mouseIsOn;}
		bool checkIsOn(/* sf::RectangleShape* player,  */sf::Vector2i position);
		bool checkIsMovable() {return this->isMovable;};
		bool checkIsConnectable() {return this->isConnectable;};
		void draw(sf::RenderWindow* window, sf::View view);
		void addConnection(int number);
		void Colorise();
		bool checkIsClicked(sf::RenderWindow& window, sf::Vector2i mousePos, sf::View view);
		unsigned int getConnectionCode(int count) { return this ->  m_connectionCodes[count]; }
		unsigned int getConnectionCodesVectorSize() { return this -> m_connectionCodes.size(); }
		sf::Vector2i getTransformedVertexPosition() { return this -> transformedVertexPosition; }
		bool toggleVisibility();
		bool setIsMovable(bool b);
		bool setIsConnectable(bool c);
		void setPosition(sf::Vector2i);
		void setPosition (float a,float b);
		float getPosX();
		float getPosY();
		void MoveCircle(float a,float b);
		int getCordX(){return this->selfCords.m_x;}
		int getCordY(){return this->selfCords.m_y;}




};