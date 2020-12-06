#include "Main.hpp"

int main() {

	MainMenu mainMenu(720, 1280);
	yag::EngineData engine_data;
	const sf::Vector2i& mouse_position = sf::Mouse::getPosition(engine_data.GetGameWindow());
	engine_data.GetGameWindow().setFramerateLimit(60);

	#ifdef SFML_SYSTEM_WINDOWS
		__windowsHelper.setIcon(engine_data.GetGameWindow().getSystemHandle());
	#endif

	static GlobalContext game_data;
	SoundProducer sp;
	sp.setVolume(game_data);//установка значения звука
	sp.playMusic("ZapTwoTone2");// вызов звука по названию
	//sp.soundShoot();//вызов выстрела
	while (engine_data.GetGameWindow().isOpen()) {
		while (engine_data.GetGameWindow().pollEvent(engine_data.GetGameEvent())) {
					mainMenu.ListenToEvents(engine_data, mouse_position);
				}
			}

		if (engine_data.GetGameEvent().type == sf::Event::Closed) {
				engine_data.GetGameWindow().close();
		}
		if (engine_data.GetGameEvent().type == sf::Event::Resized) {
					mainMenu.newElementPosition(1280, 720);
		}

		if(!game_data.getIsGameStateActive()) {
			engine_data.GetGameWindow().clear();
			mainMenu.menuDraw(&engine_data.GetGameWindow());
			engine_data.GetGameWindow().display();
		}
	return 0;
}


