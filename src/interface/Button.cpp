


		void Button::init(std::string F, int W, int H, int X, int Y)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			SizeXButton = W;
			SizeYButton = H;
			ButtonPositionX = X;
			ButtonPositionY = Y;
			buttonTexture.loadFromFile("content/interface/" + File);
			sprite.setTexture(buttonTexture);
			sprite.setPosition(sf::Vector2f(ButtonPositionX, ButtonPositionY));

			SizeXButton = (SizeXTexture / 2);
			SizeYButton = (SizeYTexture / 2);
			sprite.setScale(0.5f, 0.5f);
		}

		void Button::drawButton(sf::RenderWindow *window)
		{
			//sprite.setPosition(sf::Vector2f(ButtonPositionX, ButtonPositionY));
			window->draw(sprite);
		}
		//void Button::drawButton()
		//{
		//	sprite.setPosition(sf::Vector2f(ButtonPositionX, ButtonPositionY));

	//	}
		void Button::newButtonPosition(int ButtonNumberDown)
		{
			if ((WindowWidth >= 850) && (WindowHeight >= 740))// размер минимального окна ставим вручную
			{
				SizeXButton = SizeXTexture;
				SizeYButton = SizeYTexture;
				sprite.setScale(1.0f, 1.0f);
			}
			else
			{
				SizeXButton = (SizeXTexture / 2);
				SizeYButton = (SizeYTexture / 2);
				sprite.setScale(0.5f, 0.5f);
			}
			ButtonPositionX = ((WindowWidth - SizeXButton) / 2);
			ButtonPositionY = WindowHeight - ((SizeYButton + 10) * ButtonNumberDown);
			sprite.setPosition(sf::Vector2f(ButtonPositionX, ButtonPositionY));
		}
		bool Button::isPressed(int MousePosX, int MousePosY)
		{

			if (((MousePosX > ButtonPositionX) && (MousePosX < (ButtonPositionX + SizeXButton))) && ((MousePosY > ButtonPositionY) && (MousePosY < (ButtonPositionY + SizeYButton))))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		void Button::setPosition(int buttonXAdd, int buttonYAdd)
		{
			ButtonPositionX = buttonXAdd;
			ButtonPositionY = buttonYAdd;
		}
		void Button::setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}


