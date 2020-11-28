#include "Main.hpp"

int main() {

	MainMenu mainMenu(720, 1280 );

	sf::RenderWindow window(sf::VideoMode(mainMenu.getWindowsWidth(), mainMenu.getWindowsHeight()), "Circuins",sf::Style::Close | sf::Style::Resize);

	window.setFramerateLimit(60);

#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif


	sf::Event evnt;
	GlobalContext glob;
	SoundProducer sp;
	sp.setVolume(glob);//установка значения звука
	sp.playMusic("ZapTwoTone2");// вызов звука по названию
	//sp.soundShoot();//вызов выстрела
	while (window.isOpen()) {

		while (window.pollEvent(evnt)) {

			mainMenu.newWindowSize(evnt.size.width, evnt.size.height);



			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Escape)
			{
				mainMenu.disableSettingAndCreditsWindow();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (!mainMenu.settingWindow.getSettingEnabled() && !mainMenu.creditsWindow.getCreditsEnabled())
				{
					if (mainMenu.exit.isPressed(mousePos.x, mousePos.y))
					{
						return 1;
					}
					if (mainMenu.credits.isPressed(mousePos.x, mousePos.y))
					{
						mainMenu.enableCredits();
					}
					if (mainMenu.setting.isPressed(mousePos.x, mousePos.y))
					{
						mainMenu.enableSetting();

					}
					if (mainMenu.play.isPressed(mousePos.x, mousePos.y))
					{
						GameState newGameState(1280, 720);
						glob.setGameStateActive(true);
							if (glob.getIsGameStateActive())
							{
								newGameState.handle(evnt, window,  glob);
							}
					}
				}
				if (mainMenu.settingWindow.getSettingEnabled())
				{
					if (mainMenu.slider.isPressed(mousePos.x, mousePos.y))
					{
						mainMenu.newValueVolume(mousePos.x);
					}
				}
			}

		switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					mainMenu.newElementPosition(1280, 720);
					break;
				default:
				break;
			}
		}
/* 		window.setView(
					sf::View(
						sf::Vector2f(640, 320),
						sf::Vector2f(1280, 720)
						)
					) */;

		if(!glob.getIsGameStateActive())
		{

		window.clear();
/* 		window.setView(sf::View(
						sf::Vector2f(640, 360),
						sf::Vector2f(1280, 720)
						)); */
		mainMenu.menuDraw(&window);
		window.display();
		}
	}

	return 0;
}


