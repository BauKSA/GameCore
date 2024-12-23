#include<string>

#include "AnimatedActor.h"

void AnimatedActor::initialize(std::vector<AnimationPaths> paths) {
	bool has_default = false;

	for (size_t i = 0; i < paths.size(); i++) {
		std::shared_ptr<Animation> animation = std::make_shared<Animation>();
		animation->name = paths.at(i).name;

		for (std::string path : paths.at(i).paths) {
			sprite = Actor::initialize(path);

			animation->frames.push_back(sprite);
		}

		animation->size = animation->frames.size();
		animations.push_back(animation);
	}

	for (size_t i = 0; i < animations.size(); i++) {
		if (animations.at(i)->name == "default") {
			has_default = true;
			set_sprite(animations.at(0));
		}
	}

	if (!has_default) set_sprite(animations.at(0));
}

void AnimatedActor::set_sprite(std::shared_ptr<Animation> animation) {
	current_animation = animation;
	sprite = current_animation->frames.at(0);
}

void AnimatedActor::tick(float delta_time) {
	update(delta_time);
}

void AnimatedActor::update(float delta_time) {
	frame_time += delta_time;
	if (frame_time >= FRAME_RATE) {
		frame_time = 0;
		next_animation_sprite();
	}
}

void AnimatedActor::next_animation_sprite() {
	if (current_frame + 1 >= current_animation->size) {
		current_frame = 0;
	}
	else {
		current_frame++;
	}

	if (!current_animation->frames.at(current_frame)) return;
	sprite = current_animation->frames.at(current_frame);
}

void AnimatedActor::set_animation(std::string name) {
	for (std::shared_ptr<Animation> animation : animations) {
		if (animation->name == name) {
			set_sprite(animation);
		}
	}
}