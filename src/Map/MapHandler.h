

class MapHandler
{
	public:

	MapHandler();
	~MapHandler() {};
	void drawMap(sf::RenderWindow* window);
	void drawParallax(sf::RenderWindow*);
	std::vector<Vertex>  getVertexArray();
	Vertex getVertexArrayElement(unsigned int index);

	private:


	sf:: Texture mapTile1;

	sf:: Texture parallaxTile1;
	sf:: Texture victoryImageT;

	sf::RectangleShape mapTile_1;

	sf::RectangleShape victoryImage;

	sf::RectangleShape parallaxTile_1;

	std::vector<std::vector<sf::RectangleShape>> allPaper;
	public:

	std::vector<Vertex> allVertex;


};