#include<string>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include "Utils.h"

#ifndef _SPRITEACTOR_
#define _SPRITEACTOR_

class SpriteActor {
protected:
	std::string name;
	Sprite* sprite;
	float x;
	float y;
public:
	SpriteActor(std::string _name, float _x, float _y) :
		x(_x), y(_y), name(_name) {
		sprite = nullptr;
	}

	virtual void initialize_sprite(std::string path);

	void draw(int flags = 0);

	float get_x() const { return x; }
	float get_y() const { return y; }

	float get_width() const { return sprite ? sprite->width : 0.0f; }
	float get_height() const { return sprite ? sprite->height : 0.0f; }

	std::string get_name() const { return name; }

	~SpriteActor() {
		if (sprite) al_destroy_bitmap(sprite->frame);
	}
};

#endif // !_SPRITEACTOR_