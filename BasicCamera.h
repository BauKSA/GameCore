#pragma once
#include<string>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>

#include"BaseActor.h"

#ifndef _BASICCAMERA_
#define _BASICCAMERA_

struct Dimensions {
	float right;
	float left;
	float up;
	float down;
};

class BasicCamera {
protected:
	std::string name;
	float x;
	float y;
	float zoom;
	BaseActor* actor;

	void update_xy_to_screen();
	void apply();
	void draw_margins() const;
public:
	BasicCamera(std::string _name, BaseActor* _actor, float _zoom) :
		name(_name), actor(_actor), zoom(_zoom) {
		x = actor->get_x();
		y = actor->get_y();

		al_init_primitives_addon();
	}

	void set_actor_position();
};

#endif // !_BASICCAMERA_