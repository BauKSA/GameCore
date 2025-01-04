#include<iostream>
#include<cmath>

#include "MovableActor.h"

void MovableActor::add_component(std::shared_ptr<Component<MovableActor>> component) {
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
		if (std::find(collision.begin(), collision.end(), Collision::RIGHT) != collision.end()) {
			break;
		}

		x += std::abs(hspeed);
		break;
	case Directions::LEFT:
		if (std::find(collision.begin(), collision.end(), Collision::LEFT) != collision.end()) {
			break;
		}

		x -= std::abs(hspeed);
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
		if (mright == key_pressed) return;
		mright = key_pressed;
		break;
	case Directions::LEFT:
		if (mleft == key_pressed) return;
		mleft = key_pressed;
		break;
	case Directions::UP:
		if (mup == key_pressed) return;
		mup = key_pressed;
		break;
	case Directions::DOWN:
		if (mdown == key_pressed) return;
		mdown = key_pressed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void MovableActor::tick(float delta_time) {
	AnimatedActor::tick(delta_time);

	for (size_t i = 0; i < components.size(); i++) {
		components.at(i)->tick(delta_time, *this);
	}

	if (hspeed < -speed) hspeed = -speed;
	if (hspeed > speed) hspeed = speed;

	if (vspeed <= 0 && jumping) { jumping = false; falling = true; }

	if (std::find(collision.begin(), collision.end(), Collision::DOWN) != collision.end() && !jumping) {
		vspeed = 0;
		falling = false;
	}
	else if (std::find(collision.begin(), collision.end(), Collision::DOWN) == collision.end() && vspeed == 0) {
		vspeed = 0.00000000001f;
	}

	if (vspeed > 0 && !mup) move(Directions::UP);
	else if (vspeed < 0 && !mdown) move(Directions::DOWN);

	if (std::abs(hspeed) < 0.2f && !mleft && !mright) hspeed = 0;

	if (mright && !mleft) {
		hspeed += acceleration * delta_time;
	}
	else if (mleft && !mright) {
		hspeed -= acceleration * delta_time;
	}

	if (mright && mleft) return;

	if (hspeed < 0) {
		if (!mright && !mleft) hspeed += friction * delta_time;
		move(Directions::LEFT);
	}

	else if (hspeed > 0) {
		if (!mright && !mleft) hspeed -= friction * delta_time;
		move(Directions::RIGHT);
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

void MovableActor::set_collider(std::shared_ptr<Actor> actor, Collision col, float dif) {
	switch (col) {
	case Collision::RIGHT:
		hspeed = 0;
		break;
	case Collision::LEFT:
		hspeed = 0;
		break;
	default:
		break;
	}

	Actor::set_collider(actor, col, dif);
}