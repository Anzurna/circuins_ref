class GlobalContext {
	public:
	GlobalContext();
	~GlobalContext(){};
	bool getIsGameStateActive() { return this -> is_gamestate_active_;}
	void setGameStateActive(bool condition) { this -> is_gamestate_active_ = condition; }
	float getVolume(){return this -> volume_;}

	private:
	bool is_gamestate_active_;
	float volume_;

};