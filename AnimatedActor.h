#pragma once
#include<vector>
#include<string>

#include "BaseActor.h"
#include "Utils.h"

#ifndef _ANIMATEDACTOR_
#define _ANIMATEDACTOR_

class AnimatedActor : public BaseActor {
protected:
	std::vector<Animation*> animations;
	Animation* current_animation;
	size_t current_frame;
	float frame_time;
public:
	AnimatedActor(std::string name, float x, float y, float speed) :
		BaseActor(name, x, y, speed),
		current_animation(nullptr), current_frame(0), frame_time(0.0f) {
	}

	void initialize(std::vector<AnimationPaths> paths);
	void set_sprite(Animation* animation);

	void set_animation(std::string name);
	void next_animation_sprite();

	void tick(float delta_time) override;
	void update(float delta_time);

	~AnimatedActor() {
		for (Animation* animation : animations) {
			delete animation;
		}

		animations.clear();
	}
};

#endif // !_ANIMATEDACTOR_