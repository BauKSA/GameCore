#include<string>

#include "AnimatedActor.h"

void AnimatedActor::initialize(std::vector<AnimationPaths> paths) {
	bool has_default = false;

	for (size_t i = 0; i < paths.size(); i++) {
		Animation* animation = new Animation;
		animation->name = paths.at(i).name;

		for (std::string path : paths.at(i).paths) {
			ALLEGRO_BITMAP* frame = al_load_bitmap(path.c_str());

			if (!frame) {
				const std::string error = "Can't initialize sprite in " + name;
				al_show_native_message_box(nullptr, "Error", "Error initializing", error.c_str(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
			}

			Sprite* sprite = new Sprite;
			sprite->frame = frame;
			sprite->width = al_get_bitmap_width(frame);
			sprite->height = al_get_bitmap_height(frame) + 1;

			animation->frames.push_back(sprite);
		}

		animation->size = animation->frames.size();
		animations.push_back(animation);

		if (animation->name == "default") {
			set_sprite(animation);
			has_default = true;
		}
	}

	if (!has_default) set_sprite(animations.at(0));
}

void AnimatedActor::set_sprite(Animation* animation) {
	current_animation = animation;
	sprite = current_animation->frames.at(0);
}

void AnimatedActor::tick(float delta_time) {
	BaseActor::tick(delta_time);
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
	} else {
		current_frame++;
	}

	if (!current_animation->frames.at(current_frame)) return;
	sprite = current_animation->frames.at(current_frame);
}

void AnimatedActor::set_animation(std::string name) {
	for (Animation* animation : animations) {
		if (animation->name == name) {
			set_sprite(animation);
		}
	}
}