class SoundProducer
{
	private:

	sf::Music music; //объект класса Music, характеризуется тем, что считывает музыку прямо из файла в поток, не загружаю в буфер
	float volume; //уровень громкости из GlobalContext
	sf::SoundBuffer bufferShooting; // статично выделенный буфер под часто используемую стрельбу
	sf::Sound soundShooting; //сама мелодия, если эту переменную инициализировать внутри  void soundShoot - не работает

	public:
	SoundProducer();
	~SoundProducer(){};
	void setVolume(GlobalContext &glob); //установить значение громкости из глобального контекста
	void playMusic(std::string name); //проиграть музыку по "название"
	void soundShoot (); //звук выстрела

};