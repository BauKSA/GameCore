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

	std::cout << "Moving actor " << name << " to pos: " << x << ", " << y << std::endl;
}