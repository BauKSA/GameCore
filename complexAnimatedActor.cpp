#include "ComplexAnimatedActor.h"

void ComplexAnimatedActor::initialize_sprite(std::vector<AnimationPaths> paths) {
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
			sprite->height = al_get_bitmap_height(frame);

			animation->frames.push_back(sprite);
		}

		animation->size = animation->frames.size();
		animations.push_back(animation);

		if (animation->name == "default") {
			AnimatedActor::initialize_sprite(animation);
			has_default = true;
		}
	}

	if (!has_default) AnimatedActor::initialize_sprite(animations.at(0));
}

void ComplexAnimatedActor::set_animation(std::string animation_name) {
	for (Animation* animation : animations) {
		if (animation->name == animation_name) {
			AnimatedActor::initialize_sprite(animation);
		}
	}
}