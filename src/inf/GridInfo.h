//#include <Main.hpp>

class GridInfo
{
public:
	GridInfo();
	~GridInfo(){};
	void showInfo(sf::RenderWindow* window, sf::RectangleShape* player, sf::Vector2i m_mousePos,
				  float m_targetX, float m_TargetY, float m_previousPointX, float m_previousPointY);
private:
	sf::Text text1;
	sf::Text text2;

	sf::Font font;

	std::string xPosition;
	std::string yPosition;
	std::string truncatedTargetX;
	std::string truncatedTargetY;
	std::string truncatedPrevX;
	std::string truncatedPrevY;
};