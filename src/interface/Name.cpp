
		void Name::init(std::string F, int W, int H, int X, int Y)
		{
			File = F;
			SizeXTexture = W;
			SizeYTexture = H;
			NameXPosition = X;
			NameYPosition = Y;
			nameTexture.loadFromFile("content/interface/" + File);
			sprite.setTexture(nameTexture);
			sprite.setPosition(sf::Vector2f(NameXPosition, NameYPosition));
		}

		void Name::drawName(sf::RenderWindow *window)
		{
			//sprite.setPosition(sf::Vector2f(NameXPosition, NameYPosition));
			window->draw(sprite);
		}

		void Name::newNamePosition()
		{
			if ((WindowWidth >= 900) && (WindowHeight >= 630))// размер минимального окна ставим вручную
			{
				SizeXName = SizeXTexture;
				SizeYName = SizeYTexture;
				sprite.setScale(1.0f, 1.0f);
			}
			else
			{
				SizeXName = (SizeXTexture / 2);
				SizeYName = (SizeYTexture / 2);
				sprite.setScale(0.5f, 0.5f);
			}

			NameXPosition = ((WindowWidth - SizeXName) / 2);
			NameYPosition = 20;
			sprite.setPosition(sf::Vector2f(NameXPosition, NameYPosition));
		}

		void Name::setPosition(int nameXAdd, int nameYAdd)
		{
			NameXPosition = nameXAdd;
			NameYPosition = nameYAdd;
		}
		void Name::setWindowSize(int sizeX, int sizeY)
		{
			WindowWidth = sizeX;
			WindowHeight = sizeY;
		}

