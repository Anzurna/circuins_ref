class Credits
{

	int creditsWidth;
	int creditsHeight;
	int windowWidth;
	int windowHeight;

	public:
	bool isCreditsEnabled = false;
	std::string FileWindow;
	std::string FileText;
	sf::Texture windowTexture;
	sf::Sprite windowSprite;
	sf::Texture textTexture;
	sf::Sprite textSprite;

	Credits() {};

	~Credits() {};

	void init(std::string F1, std::string F2,int W, int H, int WX, int HX);

	void drawCredits(sf::RenderWindow *window);

	void newCreditsPosition(int windowWidth, int windowHeight);

	bool getCreditsEnabled() {return isCreditsEnabled;}

	void setCreditsEnabled(bool condition) { this -> isCreditsEnabled = condition; }

};