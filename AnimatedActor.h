#pragma once
#include<vector>
#include<string>
#include "BaseActor.h"

#ifndef _ANIMATEDACTOR_
#define _ANIMATEDACTOR_

class AnimatedActor : public BaseActor {
protected:
	Animation* animated_sprite;
public:
	AnimatedActor(std::string name, float x, float y, float speed) :
		BaseActor(name, x, y, speed) {
		animated_sprite = nullptr;
	}

	void initialize_sprite(std::vector<std::string> animation_paths) override;

};

#endif // !_ANIMATEDACTOR_
