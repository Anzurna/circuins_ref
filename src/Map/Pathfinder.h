class Pathfinder
{
	private:
	int n;//размерность динамической матрицы весов
	int** g;//сам динамический массив

	public:
	friend class Player;
	Pathfinder(){};
	~Pathfinder(){};
	std::vector<int> algorithmDijkstra(int start, int finish);
	void init(MapHandler& MapHndl);
};