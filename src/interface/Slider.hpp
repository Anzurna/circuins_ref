class Slider
{
	int sliderXPosition;
	int sliderYPosition;
	int scaleXTexture;
	int scaleYTexture;
	int scaleXPosition;
	int scaleYPosition;
	int pointerXTexture;
	int pointerYTexture;
	int pointerXPosition;
	int pointerYPosition;
	int Value;
	public:

	std::string FileScale;
	std::string FilePointer;
	sf::Texture scaleTexture;
	sf::Sprite scaleSprite;
	sf::Texture pointerTexture;
	sf::Sprite pointerSprite;

	Slider() {}

	~Slider() {}

	void init(std::string F1, int W1, int H1,std::string F2,int W2, int H2, int X, int Y);

	bool isPressed(int MousePosX, int MousePosY);

	int newValue(int MousePosX);

	void setPointerPosition(int Value);

	void drawSlider(sf::RenderWindow *window);

	void setNewPosition(int X, int Y);


};