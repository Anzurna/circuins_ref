GameState::GameState(int width, int height)
{
	m_width = width;
	m_height = height;
	IsGameStateActive = true;

	view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(m_width, m_height));

	parallaxView.setCenter(sf::Vector2f(1256.0f, 1256.0f));
	parallaxView.setSize(sf::Vector2f(500, 500));
	view.zoom(1.5f);
	parallaxView.zoom(0.3f);
}



void GameState::handle(sf::Event& evnt, sf::RenderWindow& window, /* sf::Vector2i& mousePos, */ GlobalContext& glob)
{
	sf::RectangleShape test(sf::Vector2f(40.0f, 40.0f));
	MapRedactor mp;
	mp.ReadFile(mapHandl, ".\\content\\map.txt");
	Pathfinder m_pathfinder(mapHandl);
	std::list<Movable*> allMovingObjects;
	std::list<Movable*>::iterator iterToPlayer;
	std::list<Movable*>::iterator drawingIter;
	std::list<Movable*>::iterator collisionIter1;
	std::list<Movable*>::iterator collisionIter2;
	sf::Texture testTexture;
	testTexture.loadFromFile("content/CharSprites/enemy1.png");

	srand(time(0));
	//int random;
	//random = ((rand())%13);
	//const Movable* toPlayer;

	SoundProducer soundProd;
	sf::Clock clock;
	float Time = 0;
	float Time2 = 0;
	float Time3 = 0;

	std::vector<Enemy> enemies;
	for (int l = 0; l < 9; l++) {
		enemies.push_back(Enemy(2700.0f+40*l, 2700.0f, testTexture));
		//enemies.back().setPosition(2700.0f, 2700.0f);
		enemies[l].setID((l + (rand())%13 + 1));
		enemies[l].setHP(500);
		enemies[l].setTeam(2);
		enemies[l].setHasKey();
	}
	for (int o = 0; o < 9; o++) {
		enemies.push_back(Enemy((2864.0f+40*o*(rand()%8 + 1)), 5100.0f, testTexture));
		//enemies[o].setPosition(2864.0f, 5100.0f);
		enemies[o].setID((o + (rand())%13 + 1));
		enemies[o].setHP(500);
		enemies[o].setTeam(2);
		enemies[o].setHasKey();
	}
	for (int s = 0; s < 9; s++) {
		enemies.push_back(Enemy(3164.0f, (8633.0f+40*s*(rand()%6 + 1)), testTexture));
		//enemies[s].setPosition(3164.0f, 8633.0f);
		enemies[s].setID((s + (rand())%13 + 1));
		enemies[s].setHP(500);
		enemies[s].setTeam(2);
		enemies[s].setHasKey();
	}
	for (int m = 0; m < 9; m++) {
		enemies.push_back(Enemy((4490.0f+40*m*(rand()%4 + 1)), 7720.0f, testTexture));
		//enemies[m].setPosition(4490.0f, 7720.0f);
		enemies[m].setID((m + (rand())%13 + 1));
		enemies[m].setHP(500);
		enemies[m].setTeam(2);
		enemies[m].setHasKey();
	}
	for (int n = 0; n < 9; n++) {
		enemies.push_back(Enemy(8240.0f, 7718.0f+40*n, testTexture));
		//enemies[n].setPosition(8240.0f, 7718.0f);
		enemies[n].setID((n + (rand())%13 + 1));
		enemies[n].setHP(500);
		enemies[n].setTeam(2);
		enemies[n].setHasKey();
	}
	for (int a = 0; a < 9; a++) {
		enemies.push_back(Enemy(8953.0f+40 * a, 9300.0f, testTexture));
		//enemies[a].setPosition(8953.0f, 9300.0f);
		enemies[a].setID((a + (rand())%13 + 1));
		enemies[a].setHP(500);
		enemies[a].setTeam(2);
		enemies[a].setHasKey();
	}
 	for (int j = 0; j < 9; j++) {
		enemies.push_back(Enemy(8129.0f, 2904.0f+40*j,  testTexture));
		//enemies[j].setPosition(8129.0f, 2904.0f+40*j);
		enemies[j].setID((j + (rand())%13 + 1));
		enemies[j].setHP(500);
		enemies[j].setTeam(2);
		enemies[j].setHasKey();
	}
	for (int u = 0; u < 54; u++) {
		//std::cout <<"size" << enemies.size() <<std::endl;
		allMovingObjects.push_back(&enemies[u]);
	}

	Player mainPlayer;
	allMovingObjects.push_back(&mainPlayer);
	mainPlayer.setPosition(6000, 6000);
	mainPlayer.setHP(500);
	view.setCenter(6000, 6000);

	Player healer;
	allMovingObjects.push_back(&healer);
	healer.setPosition(6300, 6000);
	healer.setHP(500);

	while (glob.getIsGameStateActive()) {
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt)) {
			if (!mainPlayer.getHasWon()) {
				this -> zoom(view, evnt);
			}

			//Place event listeners here
			if (mapRed) {
				mapRedct.listenToEvents(evnt, window, mapHandl, mousePos1, view);
			}
			mainPlayer.eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			//eventListener(evnt, window, mapHandl, mousePos1, view, m_pathfinder);
			// Заняты клавиши R, L и ПКМ (12.12.19)
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Escape) {
				toggleCentering = false;
				mainPlayer.setHasWon(false);
				view.setCenter(640, 360);
				//view.setSize(1280, 720);
				for (drawingIter = allMovingObjects.begin();
					 drawingIter != allMovingObjects.end(); drawingIter++) {
						(**drawingIter).Movable::~Movable();
					}
				allMovingObjects.clear();
				glob.setGameStateActive(false);
				}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Tilde) {
				for (unsigned int i = 0; i < mapHandl.allVertex.size(); i++) {
					mapHandl.allVertex[i].toggleVisibility();
				}
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::P) {
				toggleParallax = (toggleParallax ? false : true);
			}
			if (evnt.type == sf::Event::KeyPressed && evnt.key.code ==  sf::Keyboard::Space) {
				toggleCentering = (toggleCentering ? false : true);

			}
					//Нажать backspace чтобы вызвать редактор карты
		 	if (evnt.type==sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Backspace) {
			 	if (mapRed==false) mapRed=true; else mapRed=false;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (Time3 > 0.1) {
				sf::Vector2i transformedMousePosition;
				transformedMousePosition.x  = (int)(window.mapPixelToCoords( mousePos1, view ).x);
				transformedMousePosition.y  = (int)(window.mapPixelToCoords( mousePos1, view ).y);
				mainPlayer.fire(allMovingObjects, transformedMousePosition);
				soundProd.soundShoot();
				Time3 = 0;
			}
		}

		if (mainPlayer.getHP() <= 0) {
			mainPlayer.destroyKeys();
			mainPlayer.setPosition(6000, 6000);
			mainPlayer.setHP(500);
		}

		if (mousePos1.x > m_width - 20) { // Перемещение видов, позже бует вынесено в отдельный объект
			view.move(25.0f, 0.0f);

		} else if (mousePos1.x < 20) {
			view.move(-25.0f, 0.0f);

		} else if (mousePos1.y < 20) {
			view.move(0.0f, -25.0f);

		} else if (mousePos1.y > m_height - 20) {
			view.move(0.0f, 25.0f);
		}

		if (mainPlayer.getAmountOfKeys() == 1) {
			mainPlayer.setHasWon(true);
		}


		for (collisionIter1 = allMovingObjects.begin(); collisionIter1 != allMovingObjects.end(); ++collisionIter1) {
			for (collisionIter2 = allMovingObjects.begin(); collisionIter2 != allMovingObjects.end(); ++collisionIter2) {
				if ((abs((**collisionIter1).getPosition().x - ((**collisionIter2).getPosition().x)) < 50) &&
					abs((**collisionIter1).getPosition().y - ((**collisionIter2).getPosition().y)) < 50) {
					if ((**collisionIter1).getTeam() != (**collisionIter2).getTeam()) {
						if ((**collisionIter2).getType() == 1 && ((**collisionIter1).getType() != (1 || 3))) {
							(**collisionIter1).changeHP(-50);
							(**collisionIter2).Movable::~Movable();
							allMovingObjects.erase(collisionIter2--);
						}
					}
					if ((**collisionIter1).getType() == 0 && ((**collisionIter2).getType() == 3 )) {
						mainPlayer.addKey();
						(**collisionIter2).Movable::~Movable();
						allMovingObjects.erase(collisionIter2--);
					}
/* 				if ((**collisionIter1).getType() == 2 && ((**collisionIter1).getHP() <= 0)) {
					(**collisionIter1).Movable::~Movable();
					allMovingObjects.erase(collisionIter1--);
				} */


				}
			}
		}
		if ((abs(mainPlayer.getPosition().x - healer.getPosition().x) < 200) &&
				(abs(mainPlayer.getPosition().y - healer.getPosition().y)) < 200) {
					mainPlayer.changeHP(Time*10);
		}
				//infotable.showInfo(&window, &player, mousePos,  Figure1.getTargX(), Figure1.getTargY(),
							//	   Figure1.getPreviousX(), Figure1.getPreviousY());
		mainPlayer.realTimeListener();

		window.clear();
		//window.setView(parallaxView);

		if (toggleParallax) { mapHandl.drawParallax(&window); }
		if (toggleCentering) { view.setCenter(mainPlayer.getPosition()); }
		window.setView(view);
		mapHandl.drawMap(&window);

		//std::cout << speedToNextPointX << " " << speedToNextPointY << std::endl;
		for (drawingIter = allMovingObjects.begin(); drawingIter != allMovingObjects.end(); ++drawingIter) {
			(**drawingIter).behave(allMovingObjects, mainPlayer.getPosition(), clock.getElapsedTime().asSeconds());
			(**drawingIter).handle(allMovingObjects, drawingIter, clock.getElapsedTime().asSeconds());
			(**drawingIter).draw(&window);
			(**drawingIter).move();
		}
		if (mainPlayer.getIsPathExists()){
			mainPlayer.move(window, view, mapHandl, clock.getElapsedTime().asSeconds());
		}

		for (unsigned int i = 0; i < mapHandl.getVertexArray().size(); i++ ) {
			mapHandl.allVertex[i].draw(&window, view);
		}
		window.display();
		Time += clock.getElapsedTime().asSeconds();
		Time2 += clock.getElapsedTime().asSeconds();
		Time3 += clock.getElapsedTime().asSeconds();
		 if (Time > 1)
			Time = 0;
		clock.restart();

		if (mainPlayer.getHasWon()) {

			view.setCenter(1200.0f, 1000.0f);
			view.zoom(1.0f);
			toggleCentering = false;

		}
	}
}

void GameState::zoom(sf:: View& view, sf::Event& evnt)
{
				if(evnt.type == sf::Event::MouseWheelScrolled){
					float mainViewZoomParam = 1;
					view.zoom(mainViewZoomParam);
					if ((mainViewZoomParam >= 0.5) && ((mainViewZoomParam <= 1.5))) {
						if(evnt.mouseWheelScroll.delta > 0){

						//mainViewZoomParam = mainViewZoomParam + evnt.mouseWheelScroll.delta/60;
						mainViewZoomParam = (mainViewZoomParam - 0.07);
						//i++;
						//if (i>10) break;
						//view.zoom(1+(evnt.mouseWheelScroll.delta)/60);
						view.zoom(mainViewZoomParam);
						mainViewZoomParam=1;
				}

				if(evnt.mouseWheelScroll.delta < 0) {
					//mainViewZoomParam = mainViewZoomParam + evnt.mouseWheelScroll.delta/60;
					mainViewZoomParam = (mainViewZoomParam + 0.07);
					//view.zoom(1+(evnt.mouseWheelScroll.delta)/60);
					//i++;
					//if (i>10) break;
					view.zoom(mainViewZoomParam);
					mainViewZoomParam=1;
				}
			}
			else if (mainViewZoomParam < 0.5) mainViewZoomParam = 0.5;
			else if (mainViewZoomParam > 1.5) mainViewZoomParam = 1.5;
			//view.zoom(mainViewZoomParam);
		//view.zoom(mainViewZoomParam);

		}
}