namespace Yaga {

	class EngineData {
	public:
		EngineData()
			: window_(sf::VideoMode(1280, 720), "Circuins", sf::Style::Close | sf::Style::Resize)
			{}
		~EngineData(){};
		sf::Event& GetGameEvent() { return this -> event_; };
		sf::RenderWindow& GetGameWindow() { return this -> window_; };
	private:
		sf::RenderWindow window_;
		sf::Event event_;
};
}
namespace yag = Yaga;