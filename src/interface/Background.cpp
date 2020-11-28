

		void Background::init(std::string F, int W, int H)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			backgroundTexture.loadFromFile("content/interface/" + File);
			sprite.setTexture(backgroundTexture);
		}

		void Background::reSize()
		{
			multiplierX = WindowWidth / SizeXTexture;
			multiplierY = WindowHeight / SizeYTexture;
			if (multiplierX > multiplierY)
			{
				multiplier = multiplierX;
			}
			else
			{
				multiplier = multiplierY;
			}
			sprite.setScale(multiplier, multiplier);
		}

		void Background::setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

		void Background::drawBackground(sf::RenderWindow *window)
		{
			window->draw(sprite);
		}
