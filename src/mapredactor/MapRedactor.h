class MapRedactor
{
	private:
	int redactcount;
	int concount;
	bool setconn;
	bool redact;
	bool create;
	bool connect;
	bool drawconnect;
	unsigned int index;
	sf::Vector2f TransformedmousePos;
	std::string initStr; //считываемая строка из файла
	std::string connStr;//часть строки, хранящаая коды соединений
	std::string init2;
	std::vector<unsigned int> connectionCodes;
	std::ofstream out;//файл для записи

	int firstSpace;//позиция вхождения символа "|"
	int secondSpace;
	float number;
	int code;
	float xcord;
	float ycord;

	public:
	MapRedactor();
	~MapRedactor() {};
	void EventListener(sf::Event &event,sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View);
	void SetRedact(sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view);
	void MoveRedact(MapHandler& MapHndl,float speedx, float speedy);
	void Reset(MapHandler& MapHndl);
	void SetConnectBasis (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view);
	void DrawConnection (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view);
	void WriteFile(MapHandler& MapHndl,std::string filename);
	void ReadFile(MapHandler& MapHndl,std::string filename);
	void SetVertex(sf::RenderWindow& window,MapHandler& MapHndl,int ID, sf::Vector2i mousePos,
	std::vector<unsigned int> connectionVector,sf::View view);

};