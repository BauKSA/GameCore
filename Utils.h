#pragma once
#include<vector>
#include<string>
#include<chrono>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>

#ifndef _UTILS_
#define _UTILS_

constexpr float SCREEN_WIDTH = 400;
constexpr float SCREEN_HEIGHT = 300;

constexpr float WORLD_WIDTH = 1500;
constexpr float WORLD_HEIGHT = 1500;

constexpr float FRAME_RATE = .25;

enum directions {
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4
};

struct Sprite {
	int width;
	int height;
	ALLEGRO_BITMAP* frame;
};

struct Animation {
	std::string name;
	int size;
	std::vector<Sprite*> frames;
};

#endif // !_UTILS_