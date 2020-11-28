

MapHandler::MapHandler()
{
	mapTile1.loadFromFile("content/MapTiles/entireMap.png");
	mapTile_1.setSize(sf::Vector2f(7000.0f,7000.0f));
	mapTile_1.setPosition(sf::Vector2f(2500.0f, 2500.0f));
	mapTile_1.setTexture(&mapTile1);

	parallaxTile1.loadFromFile("content/MapTiles/testparallax.png");
	parallaxTile_1.setSize(sf::Vector2f(1920.0f,1080.0f));
	parallaxTile_1.setTexture(&parallaxTile1);
	parallaxTile_1.setPosition(0.0f, 0.0f);

	victoryImageT.loadFromFile("content/MapTiles/victoryImage.png");
	victoryImage.setSize(sf::Vector2f(1000.0f,1000.0f));
    victoryImage.setTexture(&victoryImageT);
	victoryImage.setPosition(700.0f, 500.0f);


	allPaper.resize(10, std::vector<sf::RectangleShape>{10});
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			allPaper[i][k].setTexture(&parallaxTile1);
			allPaper[i][k].setSize(sf::Vector2f(1920.0f,1080.0f));
			allPaper[i][k].setPosition(i*1920, k*1080);
		}
	}
}

void MapHandler::drawMap(sf::RenderWindow* window)
{
	window -> draw(mapTile_1);
	window -> draw(victoryImage);
}
void MapHandler::drawParallax(sf::RenderWindow* window)
{
	window -> draw(parallaxTile_1);
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++)

			window -> draw(allPaper[i][k]);
	}
}

std::vector<Vertex> MapHandler::getVertexArray()
{
	return this -> allVertex;
}
Vertex MapHandler::getVertexArrayElement(unsigned int index)
{
	return this -> allVertex[index];
}

