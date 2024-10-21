#include<string>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#ifndef _GENERICSPRITE_
#define _GENERICSPRITE_

class GenericSprite {
protected:
	std::string name;
	float x;
	float y;
	ALLEGRO_BITMAP* sprite;
public:
	GenericSprite(std::string _name, float _x, float _y, std::string sprite_path) :
		x(_x), y(_y), name(_name) {
		ALLEGRO_BITMAP* _sprite = al_load_bitmap(sprite_path.c_str());
		sprite = _sprite;
	}

	void draw(int flags = 0);

	float get_x() const { return x; }
	float get_y() const { return y; }

	~GenericSprite() {
		al_destroy_bitmap(sprite);
	}
};

#endif // !_GENERICSPRITE_