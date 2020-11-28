
//Алгоритм редактирования карты
//=======================ИНСТРУКЦИЯ===========================================================================================
//||  1.Нажать backspace                                                                                                    ||
//||  2. Выбрать точку и нажать по ней левой кнопкой мыши                                                                   ||
//||   3. Перемещать выбранную точку стрелками                                                                              ||
//||   4. !!!!После всех перемещений нажать T - это промежуточное действие для всех операций, не только перемещенич!!!!     ||
//||   5. Можно переходить к следующей точке                                                                                ||
//||   6. Чтобы сохранить в файл - нажать Z                                                                                 ||
//||   7. Чтобы загрузить карту из файла - нажать Y                                                                         ||
//||   8. Чтобы добавить соединение между вершинами - выбрать ту вершину, к                                                 ||
//||   хотим добавить соединения, нажать U, кликнуть левой кнопкой по вершине                                               ||
//||   Затем жмем B, прокликиваем вершины, которые добавляем в соединение                                                   ||
//||   После всех операций жмем T                                                                                           ||
//||   9.Чтобы задать новую вершину, нажать Q и щелкнуть мышкой в месте размещения                                          ||
//===========================================================================================================================
MapRedactor::MapRedactor()
{
	redactcount=0;
	concount=0;
	setconn=false;
	redact=false;
	create=false;
	connect=false;
	drawconnect=false;
	index=0;
}

void MapRedactor::EventListener(sf::Event &event,sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view) {
if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left)) {
			this->SetRedact(window,MapHndl,mousePos,view);
		}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Left)) {
          this->MoveRedact(MapHndl,-10.0f,0.0f);
	}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up)) {
         this->MoveRedact(MapHndl,0.0f,-10.0f);
	}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down)) {
          this->MoveRedact(MapHndl,0.0f,10.0f);
	}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right)) {
          this->MoveRedact(MapHndl,10.0f,0.0f);
	}
	//Создание новой точки
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Q)) {
			connect=false;
			if (create==true) create=false; else create=true;
		}
    //Задание базиса соединения(точки)
		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::U)) {
			create=false;
			if (connect==true) connect=false; else connect=true;
		}
		//прибавление точек к базису
		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::B)) {
			create=false;
			connect=false;
			if	(drawconnect==false) drawconnect=true; else drawconnect=false;

		}

		if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left)) {
			if (create==true) this->SetVertex(window,MapHndl,0,mousePos,{},view);
			else if (connect==true) this->SetConnectBasis(MapHndl,window,mousePos,view);
			else if (drawconnect==true) this->DrawConnection(MapHndl,window,mousePos,view);
		}

		//После передвижения пользователем какой то точки - принятие изменений и сброс свойств isMovable
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::T)) {
		this->Reset(MapHndl);
	}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z)) {
		this->WriteFile(MapHndl,"C:\\SFMLprojects\\myproject\\content\\map.txt");
	}

	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Y)) {
		this->ReadFile(MapHndl,"C:\\SFMLprojects\\myproject\\content\\map.txt");
	}

}
//Задание точке свойства перемещаемости
void MapRedactor::SetRedact(sf::RenderWindow& window, MapHandler& MapHndl,sf::Vector2i mousePos,sf::View view) {
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)) {
					MapHndl.allVertex[i].setIsMovable(true);
					redactcount+=1; //Счетчик перемещаемых точек(должно быть не более одной)
				}
	}
}
//Сброс всех параметров
void MapRedactor::Reset (MapHandler& MapHndl) {
	redactcount=0;
	concount=0;
	setconn=false;
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
		MapHndl.allVertex[i].setIsMovable(false);
		MapHndl.allVertex[i].setIsConnectable(false);
	}
}


//Задание базовой точки для соединения с другими вершинами
void MapRedactor::SetConnectBasis (MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view) {

	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)&&(concount<1)) {
					concount+=1;
					MapHndl.allVertex[i].setIsConnectable(true);//Добавление к точке свойства соединяемости
					MapHndl.allVertex[i].Colorise();//Выделение цветом для визуализации
					index=i;//Запоминаем индекс точки
					break;

				}
	}
}
//Задание соединений с базовой точкой
void MapRedactor::DrawConnection(MapHandler& MapHndl,sf::RenderWindow& window,sf::Vector2i mousePos,sf::View view) {
	for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsClicked(window,mousePos,view)&&(i!=index)) {
	if (MapHndl.allVertex[index].checkIsConnectable()==true) {//Если точка доступна для соединения, то ..
	MapHndl.allVertex[index].addConnection(i+1);//Взаимное добавление связи у двух точек
	MapHndl.allVertex[i].addConnection(index+1);//
	}
}
	}
}

//Перемещение точек в пределах карты
void MapRedactor::MoveRedact(MapHandler& MapHndl,float speedx,float speedy) {
		for (unsigned int i=0; i<=MapHndl.allVertex.size();i++) {
if (MapHndl.allVertex[i].checkIsMovable()==true && redactcount<2) {//Перемещать можно только одну точку
	MapHndl.allVertex[i].MoveCircle(speedx,speedy);
			}
			}

}

//Создание новой вершины
void MapRedactor::SetVertex(sf::RenderWindow& window,MapHandler& MapHndl,int ID, sf::Vector2i mousePos,
std::vector<unsigned int> connectionVector,sf::View view)
{	ID=MapHndl.allVertex.size();//Задание параметров новой точки
	TransformedmousePos=window.mapPixelToCoords({mousePos.x,mousePos.y} ,view);
	int xcord=TransformedmousePos.x;
	int ycord=TransformedmousePos.y;
	Vertex *Vertexobj = new Vertex;
	Vertexobj->init(ID,{},{});
	MapHndl.allVertex.push_back(*Vertexobj);//Добавление пустого элемента в массив
	MapHndl.allVertex[MapHndl.allVertex.size()-1].init(ID,{xcord,ycord},connectionVector);//Инициализация добавленного элемента
	MapHndl.allVertex[MapHndl.allVertex.size()-1].toggleVisibility();
	delete Vertexobj;
}

//Запись в файл
void MapRedactor::WriteFile(MapHandler& MapHndl,std::string filename) {
	std::string connection = "";
	/*std::ofstream out;*/
	out.open(filename);
	if (out.is_open()) {

	for (unsigned int i=0; i<MapHndl.allVertex.size();i++) {
		out<<i+1<<" "<<MapHndl.allVertex[i].getPosX()<<" "<<MapHndl.allVertex[i].getPosY()<<"|";
		for (unsigned int j=0; j<MapHndl.allVertex[i].getConnectionCodesVectorSize();j++) {
			out<<MapHndl.allVertex[i].getConnectionCode(j)<<" ";
		}
		out<<std::endl;
	}

}
}
//Чтение файла
void MapRedactor::ReadFile(MapHandler& MapHndl,std::string filename) {

std::ifstream file (filename);

 if (!file)
 {
 std::cout << "Файл не открыт\n\n";
 }

 else {
	 while(getline(file, initStr)){ // пока не достигнут конец файла класть очередную строку в переменную  initStr
	   std::stringstream(initStr)>>number>>xcord>>ycord;//запись первых трех параметров вертекса
	   firstSpace=initStr.find_first_of("|")+1;
	   secondSpace=initStr.length();
	   connStr=initStr.substr(firstSpace,secondSpace-firstSpace);//образание первой части строки
	   std::istringstream is( connStr );
      std::vector<std::string> tokens;
	   std::copy( std::istream_iterator<std::string>( is ),
               std::istream_iterator<std::string>(),
               std::back_inserter( tokens ) ); //парсинг строки с пробелами
			    for ( const auto &s : tokens ) {
					std::stringstream(s)>>code;//перевод из строки в int
					connectionCodes.push_back(code);//запись в массив соединений
				}

	   Vertex *Vertexobj = new Vertex; //cсздание вершины без параметров для инициализации
	Vertexobj->init(number,{(int)xcord,(int)ycord},connectionCodes);
	MapHndl.allVertex.push_back(*Vertexobj);
	MapHndl.allVertex[MapHndl.allVertex.size()-1].init(number,{(int)xcord,(int)ycord},connectionCodes);
		connectionCodes.clear();//очистка массива соединений
		delete Vertexobj;//удаление указателя на вектор(вершину)


    }

 }

}
