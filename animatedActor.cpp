#include<string>

#include "AnimatedActor.h"

void AnimatedActor::initialize_sprite(std::vector<std::string> paths) {
	Animation* _animated_sprite = new Animation();
	_animated_sprite->name = "default";

	if (paths.size() < 1) {
		const std::string error = "Can't read paths in " + name;
		al_show_native_message_box(nullptr, "Error", "Error initializing", error.c_str(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}

	for (int i = 0; i < paths.size(); i++) {
		ALLEGRO_BITMAP* frame = al_load_bitmap(paths.at(i).c_str());

		if (!frame) {
			const std::string error = "Can't initialize sprite in " + name;
			al_show_native_message_box(nullptr, "Error", "Error initializing", error.c_str(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		}

		Sprite* sprite = new Sprite();
		sprite->frame = frame;
		sprite->height = al_get_bitmap_height(frame);
		sprite->width = al_get_bitmap_width(frame);

		_animated_sprite->frames.push_back(sprite);
	}

	_animated_sprite->size = _animated_sprite->frames.size();

	animated_sprite = _animated_sprite;
	sprite = animated_sprite->frames.at(0);
}

void AnimatedActor::tick(float delta_time) {
	BaseActor::tick();
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
	if (current_frame + 1 >= animated_sprite->size) {
		current_frame = 0;
	} else {
		current_frame++;
	}

	if (!animated_sprite->frames.at(current_frame)) return;
	sprite = animated_sprite->frames.at(current_frame);
}