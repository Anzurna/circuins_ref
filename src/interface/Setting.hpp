class Setting
{

	int settingWidth;
	int settingHeight;
	int windowWidth;
	int windowHeight;
	int sliderXPosition;
	int sliderYPosition;
	bool isSettingEnabled = false;
	public:
	Slider slider;
	std::string FileWindow;
	std::string FileText;
	sf::Texture windowTexture;
	sf::Sprite windowSprite;
	sf::Texture textTexture;
	sf::Sprite textSprite;

	Setting(){}

	~Setting(){}

	void init(std::string F1, std::string F2,int W, int H, int WX, int HX, int SX, int SY);

	void drawSetting(sf::RenderWindow *window);

	void newSettingPosition(int windowWidth, int windowHeight);

	bool getSettingEnabled() {return isSettingEnabled;}

	void setSettingEnabled(bool condition) { this -> isSettingEnabled = condition; }

	bool sliderIsPressed(int X, int Y);

};