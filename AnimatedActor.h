#pragma once
#include<vector>
#include<string>
#include<memory>

#include "MovableActor.h"
#include "Utils.h"

#ifndef _ANIMATEDACTOR_
#define _ANIMATEDACTOR_

class AnimatedActor : public MovableActor {
protected:
	std::vector<std::shared_ptr<Animation>> animations;
	std::shared_ptr<Animation> current_animation;
	size_t current_frame;
	float frame_time;
public:
	AnimatedActor(std::string name, float x, float y, float speed, float depth = 1.0f) :
		MovableActor(name, x, y, speed, depth),
		current_animation(nullptr), current_frame(0), frame_time(0.0f) {
	}

	void initialize(std::vector<AnimationPaths> paths);
	void set_sprite(std::shared_ptr<Animation> animation);

	void set_animation(std::string name);
	void next_animation_sprite();

	void tick(float delta_time) override;
	void update(float delta_time);
};

#endif // !_ANIMATEDACTOR_