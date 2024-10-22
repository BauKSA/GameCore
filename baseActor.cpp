#include<iostream>

#include "BaseActor.h"

void BaseActor::move(directions dir) {
	switch (dir) {
	case UP:
		y -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	case RIGHT:
		x += speed;
		break;
	case LEFT:
		x -= speed;
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