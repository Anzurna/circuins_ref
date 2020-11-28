
	void Slider::init(std::string F1, int W1, int H1,std::string F2,int W2, int H2, int X, int Y)
	{
		FileScale = F1;
		FilePointer = F2;
		scaleXTexture = W1;
		scaleYTexture = H1;
		pointerXTexture = W2;
		pointerYTexture = H2;
		sliderXPosition = X;
		sliderYPosition = Y;
		scaleTexture.loadFromFile("content/interface/" + FileScale);
		scaleSprite.setTexture(scaleTexture);
		pointerTexture.loadFromFile("content/interface/" + FilePointer);
		pointerSprite.setTexture(pointerTexture);
		pointerSprite.setOrigin(W2/2, H2/2);
		scaleXPosition = X;
		scaleYPosition = Y;
		pointerXPosition = X;
		pointerYPosition = Y + (scaleYTexture/2);
		scaleSprite.setPosition(scaleXPosition, scaleYPosition);
		pointerSprite.setPosition(pointerXPosition, pointerYPosition);
	}

	bool Slider::isPressed(int MousePosX, int MousePosY)
	{
		if (((MousePosX > sliderXPosition) && (MousePosX < (sliderXPosition + scaleXTexture))) &&
			((MousePosY > (sliderYPosition -((pointerYTexture - scaleYTexture)/2))) && (MousePosY < (sliderYPosition +((pointerYTexture - scaleYTexture)/2)+ scaleYTexture))))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	int Slider::newValue(int MousePosX)
	{
		pointerSprite.setPosition(MousePosX,(sliderYPosition + (scaleYTexture/2)));
		Value = ((MousePosX-scaleXPosition)*100)/(scaleXTexture);
		std::cout << Value << std::endl;
		return Value;
	}
	void Slider::setPointerPosition(int Value)
	{
		pointerSprite.setPosition((scaleXPosition + ((scaleXTexture / 100) * Value)),(sliderYPosition + (scaleYTexture/2)));
	}
	void Slider::drawSlider(sf::RenderWindow *window)
	{
		window->draw(scaleSprite);
		window->draw(pointerSprite);
	}
	void Slider::setNewPosition(int X, int Y)
	{
		scaleXPosition = X;
		scaleYPosition = Y;
		pointerXPosition = X;
		pointerYPosition = Y + (scaleYTexture/2);
		scaleSprite.setPosition(scaleXPosition, scaleYPosition);
		pointerSprite.setPosition((scaleXPosition + ((scaleXTexture / 100) * Value)),(sliderYPosition + (scaleYTexture/2)));
	}
