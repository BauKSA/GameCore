#include<iostream>
#include "SpriteActor.h"

void SpriteActor::draw(int flags) {
	if (!sprite->frame) {
		std::cerr << "Image charging failed for " << name << std::endl;
	}

	al_draw_bitmap(sprite->frame, x, y, flags);
}

void SpriteActor::initialize_sprite(std::string path) {
	ALLEGRO_BITMAP* frame = al_load_bitmap(path.c_str());
	if (!frame) {
		const std::string error = "Can't initialize sprite in " + name;
		al_show_native_message_box(nullptr, "Error", "Error initializing", error.c_str(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}

	Sprite* spr = new Sprite();

	spr->frame = frame;
	spr->height = al_get_bitmap_height(frame);
	spr->width = al_get_bitmap_width(frame);

	sprite = spr;
}