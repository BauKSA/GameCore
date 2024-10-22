#include<string>
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "GenericSprite.h"
#include "Utils.h"

#ifndef _BASEACTOR_
#define _BASEACTOR_

class BaseActor: public GenericSprite {
protected:
	float speed;
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;
public:
	BaseActor(std::string name, float x, float y, float _speed) :
		GenericSprite(name, x, y), speed(_speed) {
		mup = false;
		mdown = false;
		mright = false;
		mleft = false;
	};

	void initialize_sprite(std::string path) override { GenericSprite::initialize_sprite(path); }

	void move(directions dir);
	void set_movement(directions dir, bool key_pressed = true);
	virtual void tick();
};

#endif // !_BASEACTOR_