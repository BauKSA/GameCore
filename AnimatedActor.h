#pragma once
#include<vector>
#include<string>
#include<memory>

#include "Actor.h"
#include "Utils.h"

#ifndef _ANIMATEDACTOR_
#define _ANIMATEDACTOR_

class AnimatedActor : public Actor {
protected:
	std::vector<std::shared_ptr<Animation>> animations;
	std::shared_ptr<Animation> current_animation;
	size_t current_frame;
	float frame_time;
public:
	AnimatedActor(std::string name, float x, float y, float depth = 1.0f) :
		Actor(name, x, y, depth),
		current_animation(nullptr), current_frame(0), frame_time(0.0f) {
	}

	virtual void initialize(std::vector<AnimationPaths> paths);
	void set_sprite(std::shared_ptr<Animation> animation);

	void set_animation(std::string name);
	void next_animation_sprite();
	std::string get_animation()const { return current_animation->name; }

	virtual void tick(float delta_time) override;
	void update(float delta_time);
};

#endif // !_ANIMATEDACTOR_