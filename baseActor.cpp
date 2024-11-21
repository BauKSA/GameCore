#include<iostream>

#include "BaseActor.h"

void BaseActor::add_system(GenericSystem* system) {
	systems.push_back(system);
}

void BaseActor::move(directions dir) {
	switch (dir) {
	case UP:
		y -= vspeed;
		break;
	case DOWN:
		y += vspeed;
		break;
	case RIGHT:
		x += hspeed;
		break;
	case LEFT:
		x -= hspeed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::set_movement(directions dir, bool key_pressed) {
	switch (dir) {
	case UP:
		mup = key_pressed;
		break;
	case DOWN:
		mdown = key_pressed;
		break;
	case RIGHT:
		mright = key_pressed;
		break;
	case LEFT:
		mleft = key_pressed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::tick() {
	for (size_t i = 0; i < systems.size(); i++) {
		systems.at(i)->update();
	}

	if (mup && !mdown) {
		move(UP);
	}

	if (mdown && !mup) {
		move(DOWN);
	}

	if (mright && !mleft) {
		move(RIGHT);
	}

	if (mleft && !mright) {
		move(LEFT);
	}
}