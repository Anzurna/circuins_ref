class MainMenu
{
	private:
	int WINDOWS_HEIGHT;
	int WINDOWS_WIDTH;
	int WindowSizeX;
	int WindowSizeY;
	int Volume;

	public:
	Setting settingWindow;
	Credits creditsWindow;
	Button setting;
	Button credits;
	Button play;
	Button exit;
	Name name;
	Background background;
	Slider slider;
	std::fstream VolumeFile;

public:
	MainMenu(int WH, int WW);
	int getWindowsHeight();
	int getWindowsWidth();

	void newWindowSize(int X, int Y);
	void disableSettingAndCreditsWindow();
	void enableSetting();
	void enableCredits();
	void newValueVolume(int X);
	void newElementPosition(int X, int Y);
	void menuDraw(sf::RenderWindow *window);
	void ListenToEvents(yag::EngineData&, const sf::Vector2i&);
};




