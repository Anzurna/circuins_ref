
	void Setting::init(std::string F1, std::string F2,int W, int H, int WX, int HX, int SX, int SY)
	{
		FileWindow = F1;
		FileText = F2;
		settingWidth = W;
		settingHeight = H;
		windowWidth = WX;
		windowHeight = HX;
		sliderXPosition = SX;
		sliderYPosition = SY;

		windowTexture.loadFromFile("content/interface/" + FileWindow);
		windowSprite.setTexture(windowTexture);
		textTexture.loadFromFile("content/interface/" + FileText);
		textSprite.setTexture(textTexture);
		slider.init("Scale.png", 500, 30, "pointer.png", 40, 50, (((windowWidth - settingWidth)/2) + sliderXPosition), (((windowHeight - settingHeight)/2) + sliderYPosition));
		windowSprite.setPosition((windowWidth - settingWidth)/2, (windowHeight - settingHeight)/2);
		textSprite.setPosition((windowWidth - settingWidth)/2, (windowHeight - settingHeight)/2);
	}

	void Setting::drawSetting(sf::RenderWindow *window)
	{
		window->draw(windowSprite);
		window->draw(textSprite);
	}
	void Setting::newSettingPosition(int windowWidth, int windowHeight)
	{
		windowSprite.setPosition((windowWidth - settingWidth)/2, (windowHeight - settingHeight)/2);
		textSprite.setPosition((windowWidth - settingWidth)/2, (windowHeight - settingHeight)/2);
		slider.setNewPosition((windowWidth - settingWidth)/2 + sliderXPosition, (windowHeight - settingHeight)/2 + sliderYPosition);
	}
	bool Setting::sliderIsPressed(int X, int Y)
	{
		return slider.isPressed(X, Y);
	}

