#include<string>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include "Utils.h"

#ifndef _GENERICSPRITE_
#define _GENERICSPRITE_

class GenericSprite {
protected:
	std::string name;
	float x;
	float y;
	Sprite* sprite;
public:
	GenericSprite(std::string _name, float _x, float _y) :
		x(_x), y(_y), name(_name) {
		sprite = nullptr;
	}

	virtual void initialize_sprite(std::vector<std::string> animation_paths) {};
	virtual void initialize_sprite(std::string path);

	void draw(int flags = 0);

	float get_x() const { return x; }
	float get_y() const { return y; }
	std::string get_name() const { return name; }

	~GenericSprite() {
		al_destroy_bitmap(sprite->frame);
	}
};

#endif // !_GENERICSPRITE_