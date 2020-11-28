
//#include <Main.hpp>

GridInfo::GridInfo()
{

	font.loadFromFile("content/Roboto-Light.ttf");

	text1.setFont(font);
	text1.setFillColor(sf::Color::Green);
	text1.setCharacterSize(10);		//Установка параметров текста
	text1.setPosition(470.0f, 0.0f);

	text2.setFont(font);
	text2.setFillColor(sf::Color::Green);
	text2.setCharacterSize(10);
	text2.setPosition(970.0f, 16.0f); //Установка параметров текста

}

void GridInfo::showInfo(sf::RenderWindow* window,
						sf::RectangleShape* player,
						sf::Vector2i m_mousePos,
						float m_targetX, float m_targetY,
						float m_previousPointX, float m_previousPointY)
{

	xPosition = std::to_string(player -> getPosition().x);
	xPosition.erase ( xPosition.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
	yPosition = std::to_string(player -> getPosition().y);
	yPosition.erase ( yPosition.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
	/* if ((m_targetX > 1) && (m_targetY > 1))
	{
		truncatedTargetX = std::to_string(m_targetX);
		truncatedTargetY.erase ( truncatedTargetX.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
		truncatedTargetY = std::to_string(m_targetY);
		truncatedTargetY.erase ( truncatedTargetY.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
	}
	if ((m_previousPointX > 1 ) && (m_previousPointY > 1))
	{
		truncatedPrevX = std::to_string(m_previousPointX);
		truncatedPrevX.erase ( truncatedPrevX.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
		truncatedPrevY = std::to_string(m_previousPointY);
		truncatedPrevY.erase ( truncatedPrevY.find_last_not_of('0') + 1, std::string::npos ); // Обрезание нулей
	} */
	text1.setString("X player: " + xPosition + "  " + "Y player: " + yPosition);

	text2.setString(
		"X mouse: " + std::to_string(m_mousePos.x) + "  " +
		"Y mouse: " + std::to_string(m_mousePos.y) +
		"\n" +
		"TargetX " + std::to_string(m_targetX) +
		"TargetY " + std::to_string(m_targetY) +
		"\n" +
		"prevX " + std::to_string(m_previousPointX) +
		"prevY " + std::to_string(m_previousPointY));

	text1.setPosition((player -> getPosition().x) + 500, (player -> getPosition().y) - 300);
	text2.setPosition((player -> getPosition().x) + 500, (player -> getPosition().y) - 284);
	window -> draw(text1);
	window -> draw(text2);

}