#pragma once
#include<vector>
#include<string>

#include "AnimatedActor.h"

#ifndef _COMPLEXANIMATEDACTOR_
#define _COMPLEXANIMATEDACTOR_

struct AnimationPaths {
	std::string name;
	std::vector<std::string> paths;
};

class ComplexAnimatedActor : public AnimatedActor {
protected:
	std::vector<Animation*> animations;
public:
	ComplexAnimatedActor(std::string name, float x, float y, float speed) :
		AnimatedActor(name, x, y, speed) {}

	void initialize_sprite(std::vector<AnimationPaths> paths);
	void set_animation(std::string name);
};

#endif // !_COMPLEXANIMATEDACTOR_
