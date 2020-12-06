MainMenu::MainMenu(int WH, int WW)
{
	WINDOWS_HEIGHT = WH;
	WINDOWS_WIDTH = WW;
	settingWindow.init("dopWindow.png", "sound.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT, 50, 100);
	creditsWindow.init("dopWindow.png", "authors.png", 700, 700, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	exit.init("exit.png", 600, 200, 290, 610);
	setting.init("settings.png", 600, 200, 290, 390);
	credits.init("credits.png", 600, 200, 290, 500);
	play.init("start.png", 600, 200, 290, 280);
	name.init("logo.png", 700, 200, 290, 20);
	background.init("parallaxNB.png", 1920, 1080);
	slider.init("Scale.png", 500, 30, "pointer.png", 40, 50, 500, 270);
	background.setWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
	background.reSize();

	VolumeFile.open("src/Volume.txt");
	VolumeFile >> Volume;
	slider.setPointerPosition(Volume);
	VolumeFile.close();

	background.reSize();
}
int MainMenu::getWindowsHeight()
{
	return WINDOWS_HEIGHT;
}
int MainMenu::getWindowsWidth()
{
	return WINDOWS_WIDTH;
}
void MainMenu::newWindowSize(int X, int Y)
{
	exit.setWindowSize(X, Y);
	setting.setWindowSize(X, Y);
	play.setWindowSize(X, Y);
	credits.setWindowSize(X, Y);
	name.setWindowSize(X, Y);
	background.setWindowSize(X, Y);
}
void MainMenu::disableSettingAndCreditsWindow()
{
	settingWindow.setSettingEnabled(false);
	creditsWindow.setCreditsEnabled(false);
}
void MainMenu::enableSetting()
{
	settingWindow.setSettingEnabled(true);
	settingWindow.slider.setNewPosition(500,100);
}
void MainMenu::enableCredits()
{
	creditsWindow.setCreditsEnabled(true);
}
void MainMenu::newValueVolume(int X)
{
	VolumeFile.open("src/Volume.txt");
	VolumeFile <<slider.newValue(X) << std::endl;
	VolumeFile.close();
}
void MainMenu::newElementPosition(int X, int Y)
{
	exit.newButtonPosition(1);
	setting.newButtonPosition(3);
	play.newButtonPosition(4);
	credits.newButtonPosition(2);
	name.newNamePosition();
	settingWindow.newSettingPosition(X, Y);
	background.reSize();
}
void MainMenu::menuDraw(sf::RenderWindow *window)
{
	background.drawBackground(window);
	if (!settingWindow.getSettingEnabled() && !creditsWindow.getCreditsEnabled())
	{
		exit.drawButton(window);
		setting.drawButton(window);
		credits.drawButton(window);
		play.drawButton(window);
		name.drawName(window);
	}
	if (settingWindow.getSettingEnabled())
	{
		settingWindow.drawSetting(window);
		slider.drawSlider(window);
	}
	if (creditsWindow.getCreditsEnabled())
	{
		creditsWindow.drawCredits(window);
	}
}
void MainMenu::ListenToEvents(yag::EngineData& engine_data, const sf::Vector2f& mouse_position)
{
	this -> newWindowSize(engine_data.GetGameEvent().size.width,
			 								  engine_data.GetGameEvent().size.height);
	if (engine_data.GetGameEvent().type == sf::Event::KeyPressed &&
			engine_data.GetGameEvent().key.code ==  sf::Keyboard::Escape) {
			this -> disableSettingAndCreditsWindow();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!this -> settingWindow.getSettingEnabled() && !this -> creditsWindow.getCreditsEnabled())	{
				if (this -> exit.isPressed(mouse_position.x, mouse_position.y)) {
						return 1;
					}
					if (this -> credits.isPressed(mouse_position.x, mouse_position.y)) {
						this -> enableCredits();
					}
					if (this -> setting.isPressed(mouse_position.x, mouse_position.y)) {
						this -> enableSetting();
					}
					if (this -> play.isPressed(mouse_position.x, mouse_position.y)) {
						GameState newGameState(1280, 720);
						glob.setGameStateActive(true);
						if (glob.getIsGameStateActive()){
							newGameState.handle(engine_data.GetGameEvent(), engine_data.GetGameWindow(), glob);
						}
					}
				}
				if (this -> settingWindow.getSettingEnabled())
				{
					if (this -> slider.isPressed(mouse_position.x, mouse_position.y))
					{
						this -> newValueVolume(mouse_position.x);
					}
}




