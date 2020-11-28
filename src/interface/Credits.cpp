
	void Credits::init(std::string F1, std::string F2,int W, int H, int WX, int HX)
	{
		FileWindow = F1;
		FileText = F2;
		creditsWidth = W;
		creditsHeight = H;
		windowWidth = WX;
		windowHeight = HX;

		windowTexture.loadFromFile("content/interface/" + FileWindow);
		windowSprite.setTexture(windowTexture);
		textTexture.loadFromFile("content/interface/" + FileText);
		textSprite.setTexture(textTexture);
		windowSprite.setPosition((windowWidth - creditsWidth)/2, (windowHeight - creditsHeight)/2);
		textSprite.setPosition((windowWidth - creditsWidth)/2, (windowHeight - creditsHeight)/2);
	}

	void Credits::drawCredits(sf::RenderWindow *window)
	{
		window->draw(windowSprite);
		window->draw(textSprite);
	}
	void Credits::newCreditsPosition(int windowWidth, int windowHeight)
	{
		windowSprite.setPosition((windowWidth - creditsWidth)/2, (windowHeight - creditsHeight)/2);
		textSprite.setPosition((windowWidth - creditsWidth)/2, (windowHeight - creditsHeight)/2);
	}

