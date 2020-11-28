void Pathfinder::init(MapHandler& MapHndl) {
	n = MapHndl.allVertex.size(); //размер динмаической матрицы весов - число вертексов на число вертексов
	g = new int* [n];
	for (int i = 0; i < n; i++)
	{
		g[i] = new int[n];
	}
	//заполнение матрицы весов
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			//по умолчанию значение каждого нового элемента равно 0 (если это не оговорить, то будт заполнен неизвестным мхом)
			g[i][j]=0;
			// пробегаем по спискам связности:
			// для элемента i-ой строки j-ого столбца если ИД i-ого элемента содержится в списке связности для j-ого элемента
			for (unsigned int k = 0; k < MapHndl.allVertex[i].getConnectionCodesVectorSize(); k++) {
				if (MapHndl.allVertex[j].getID() == MapHndl.allVertex[i].getConnectionCode(k)) {
				//тогда между вершинами считается расстояние и помещается  в матрицу в i-ую строчку, j-ый столбец
				int katet1 = pow((MapHndl.allVertex[j].getCordX()) - MapHndl.allVertex[i].getCordX(),2);
				int katet2 = pow((MapHndl.allVertex[j].getCordY()) - MapHndl.allVertex[i].getCordY(),2);
				int sqrr=sqrt(katet1+katet2);
				g[i][j] = sqrr;
				}
			}

		}
	}

	//просто вывод матрицы в консоль для проверки ее правильности
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//std::cout << "index i = "<<i<<"index j = "<<j<<" Znachenie: "<<g[i][j] << " ";
			std::cout<<" "<<g[i][j];
		}
			std::cout << std::endl;
	}

}


std::vector<int> Pathfinder::algorithmDijkstra(int start, int finish){
	std::cout<<"Znachenie n = "<<n<<std::endl;
	int inf = 30000;// размер бесконечности. Да-да, оказывается, она такая!))
	//далее идет описание алгоритма Дейкстры и использование для его структур
	//это инопланетные технологии, описать, как это работает, может только сам Дейкстра
	std::vector <int> d(n, inf);
	std::vector p(n, -1);
	std::vector <bool> used(n);
	//int start = 0, finish = 4;
	int mn, u;
	d[start] = 0;
		for (int i = 0; i < n; ++i) {
			mn = inf, u = -1;
			for (int j = 0; j < n; ++j)
				if (!used[j] && d[j] < mn)
					mn = d[j], u = j;
			used[u] = true;
			for (int j = 0; j < n; ++j)
				if (d[j] > d[u] + g[u][j] && g[u][j] > 0)
					d[j] = d[u] + g[u][j], p[j] = u;
		}
	std::cout<<"TRY"<<n<<std::endl;
	std::vector <int> v;
		if (p[finish] == -1)
			std::cout << "No way\n";
		else {
			for (int u = finish; u != -1; u = p[u])
				v.push_back(u);
			reverse(v.begin(), v.end());
		}
return v;
	}

