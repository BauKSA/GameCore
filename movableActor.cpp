#include<iostream>
#include<cmath>

#include "MovableActor.h"

void MovableActor::add_component(std::shared_ptr<Component> component) {
	components.push_back(component);
}

void MovableActor::move(Directions dir) {
	if (!movement) return;
	const float speed = vspeed > MAX_STEP ? MAX_STEP : vspeed;

	float rot = sprite->frame.getRotation();
	float rad = rot * (PI / 180.0f);
	float dx = rotation == 0 ? hspeed : std::cos(rad) * hspeed;
	float dy = rotation == 0 ? speed : std::sin(rad) * speed;

	switch (dir) {
	case Directions::UP:
		y -= std::abs(dy);
		break;
	case Directions::DOWN:
		y += std::abs(dy);
		break;
	case Directions::RIGHT:
		x += std::abs(dx);
		break;
	case Directions::LEFT:
		x -= std::abs(dx);
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}

	sprite->frame.setPosition(x, y);
}

void MovableActor::set_movement(Directions dir, bool key_pressed) {
	switch (dir) {
	case Directions::RIGHT:
		mright = key_pressed;
		break;
	case Directions::LEFT:
		mleft = key_pressed;
		break;
	case Directions::UP:
		mup = key_pressed;
		break;
	case Directions::DOWN:
		mdown = key_pressed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void MovableActor::tick(float delta_time) {
	for (size_t i = 0; i < components.size(); i++) {
		components.at(i)->tick(delta_time, *this);
	}

	if (vspeed <= 0 && jumping) jumping = false;

	if (std::find(collision.begin(), collision.end(), Collision::DOWN) != collision.end() && !jumping)
		vspeed = 0;
	else if(std::find(collision.begin(), collision.end(), Collision::DOWN) == collision.end() && vspeed == 0)
		vspeed = 0.00000000001f;

	/*
	if (rotation != 0) {
		sprite->frame.rotate(rotation);
	}
	else {
		float current_rotation = sprite->frame.getRotation();
		float target = round(current_rotation / 90.0f) * 90.0f;
		while (current_rotation != target) {
			current_rotation = sprite->frame.getRotation();
			float smooth = current_rotation + (target - current_rotation) * .5f; // 0.1 controla la velocidad
			sprite->frame.setRotation(smooth);
			sprite->frame.setPosition(x, y);
			if (std::abs(current_rotation - target) < 0.5f) current_rotation = target;
		}
		stabilizing = false;
	}
	*/

	if (vspeed > 0 && !mup) move(Directions::UP);
	else if (vspeed < 0 && !mdown) move(Directions::DOWN);

	if (mright && !mleft && std::find(collision.begin(), collision.end(), Collision::RIGHT) == collision.end()) {
		move(Directions::RIGHT);
	}

	if (mleft && !mright && std::find(collision.begin(), collision.end(), Collision::LEFT) == collision.end()) {
		move(Directions::LEFT);
	}
}

void MovableActor::jump() {
	if (vspeed < 0 || jumping) return;

	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), Collision::DOWN);
	if (it != collision.end())
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;

	vspeed = JUMP;
	jumping = true;
}