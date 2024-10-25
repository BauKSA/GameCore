#pragma once
#include<vector>
#include<string>
#include "BaseActor.h"

#ifndef _ANIMATEDACTOR_
#define _ANIMATEDACTOR_

class AnimatedActor : public BaseActor {
protected:
	Animation* animated_sprite;
	size_t current_frame;
	float frame_time;
public:
	AnimatedActor(std::string name, float x, float y, float speed) :
		BaseActor(name, x, y, speed) {
		animated_sprite = nullptr;
		current_frame = 0;
		frame_time = 0;
	}

	void initialize_sprite(Animation* animation);
	void initialize_sprite(std::vector<std::string> animation_paths) override;
	void tick(float delta_time) override;
	void update(float delta_time);

	void next_animation_sprite();
};

#endif // !_ANIMATEDACTOR_
