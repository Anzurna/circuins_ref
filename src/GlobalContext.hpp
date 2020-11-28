class GlobalContext {
	public:
	GlobalContext();
	~GlobalContext(){};
	bool getIsGameStateActive() { return this -> IsGameStateActive;}
	void setGameStateActive(bool condition) { this -> IsGameStateActive = condition; }
	float getVolume(){return this -> volume;}

	private:
	bool IsGameStateActive;
	float volume;

};