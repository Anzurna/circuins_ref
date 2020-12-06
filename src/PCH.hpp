#ifndef PRECOMPILED_HEADER_HPP
#define PRECOMPILED_HEADER_HPP

#define _USE_MATH_DEFINES

#ifndef _DEBUG
	#ifndef NDEBUG
		#define NDEBUG
	#endif
#endif // _DEBUG

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Raspberry Pi
#ifdef SFML_SYSTEM_LINUX
	#ifdef __arm__
		#define SFML_SYSTEM_PI
	#endif
#endif // SFML SYSTEM_LINUX

// Typical stdafx.h
#include <algorithm>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

// Additional C/C++ libs
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <functional>
#include <iomanip>
#include <mutex>
#include <random>
#include <sstream>
#include <thread>
#include <type_traits>



// Windows
#ifdef _WIN32
	#ifndef UNICODE
		#define UNICODE
	#endif

	#ifndef _UNICODE
		#define _UNICODE
	#endif

	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif // _WIN32

// Utils
#include "Utility/Types.hpp"

// Macros
#define _UNUSED(x) (void)(x)

#endif // PRECOMPILED_HEADER_HPP

struct speedAndRotation {
		sf::Vector2f speed;
		float degrees;
	};
#include "GlobalContext.hpp"
#include "engine/engine_data.h"
#include "interface/Button.hpp"
#include "interface/Name.hpp"
#include "interface/Background.hpp"
#include "interface/Slider.hpp"
#include "interface/Setting.hpp"
#include "interface/Credits.hpp"
#include "interface/MainMenu.hpp"

#include "Map/Vertex.h"
#include "Map/MapHandler.h"
#include "mapredactor/MapRedactor.h"
#include "SoundProducer/SoundProducer.h"
#include "inf/GridInfo.h"



#include "movable/Movable.hpp"
#include "Map/Pathfinder.h"
#include "movable/particles/Bullet.hpp"
#include "movable/particles/Key.hpp"

#include "movable/characters/Character.hpp"
#include "movable/characters/enemies/Enemy.hpp"
#include "movable/characters/player/Player.h"

#include "gamestate/GameState.hpp"


