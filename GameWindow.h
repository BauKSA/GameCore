#pragma once
#include<SFML/Graphics.hpp>
#include "Utils.h"

#ifndef _GAMEWINDOW_
#define _GAMEWINDOW_

class GameWindow {
public:
	static sf::RenderWindow& window() {
		static sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GameCore");
		return window;
	}
};

#endif // !_GAMEWINDOW_
