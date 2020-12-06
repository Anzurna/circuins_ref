#include "Main.hpp"

int main() {

	MainMenu mainMenu(720, 1280);
	yag::EngineData engine_data;

	engine_data.GetGameWindow().setFramerateLimit(60);

	#ifdef SFML_SYSTEM_WINDOWS
		__windowsHelper.setIcon(engine_data.GetGameWindow().getSystemHandle());
	#endif

	static GlobalContext glob;
	SoundProducer sp;
	sp.setVolume(glob);//установка значения звука
	sp.playMusic("ZapTwoTone2");// вызов звука по названию
	//sp.soundShoot();//вызов выстрела
	while (engine_data.GetGameWindow().isOpen()) {
		while (engine_data.GetGameWindow().pollEvent(engine_data.GetGameEvent())) {

			mainMenu.newWindowSize(engine_data.GetGameEvent().size.width,
			 											 engine_data.GetGameEvent().size.height);

			if (engine_data.GetGameEvent().type == sf::Event::KeyPressed &&
					engine_data.GetGameEvent().key.code ==  sf::Keyboard::Escape)
			{
				mainMenu.disableSettingAndCreditsWindow();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(engine_data.GetGameWindow());
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
								newGameState.handle(engine_data.GetGameEvent(), engine_data.GetGameWindow(), glob);
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

		switch (engine_data.GetGameEvent().type) {
				case sf::Event::Closed:
					engine_data.GetGameWindow().close();
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

		if(!glob.getIsGameStateActive()) {
			engine_data.GetGameWindow().clear();
	/* 		window.setView(sf::View(
							sf::Vector2f(640, 360),
							sf::Vector2f(1280, 720)
							)); */
			mainMenu.menuDraw(&engine_data.GetGameWindow());
			engine_data.GetGameWindow().display();
		}
	}
	return 0;
}


