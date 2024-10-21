#pragma once
#include<vector>
#include<string>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>

#ifndef _UTILS_

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

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
