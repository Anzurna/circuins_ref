
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




