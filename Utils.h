#pragma once
#include<vector>
#include<string>
#include<chrono>
#include<SFML/Graphics.hpp>

#ifndef _UTILS_
#define _UTILS_

constexpr unsigned int SCREEN_WIDTH = 640; //640
constexpr unsigned int SCREEN_HEIGHT = 360; //360

constexpr unsigned int WORLD_WIDTH = 1500;
constexpr unsigned int WORLD_HEIGHT = 1500;

constexpr float FRAME_RATE = 0.15f;

constexpr float JUMP = 5.0f;
constexpr float MIN_STEP = .25;
constexpr float MAX_STEP = 8;

enum class Directions {
	UP = 1,
	DOWN = 2,
	RIGHT = 3,
	LEFT = 4
};

enum class Collision {
	NONE = 0,
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 4
};

struct Sprite {
	int width;
	int height;
	sf::Texture texture;
	sf::Sprite frame;
};

struct Animation {
	std::string name;
	int size;
	std::vector<std::shared_ptr<Sprite>> frames;
};

struct AnimationPaths {
	std::string name;
	std::vector<std::string> paths;
};

#endif // !_UTILS_