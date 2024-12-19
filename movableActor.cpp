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

	if (std::find(collision.begin(), collision.end(), Collision::DOWN) != collision.end() && jumping && gravity) {
		jumping = false;
		disable_gravity();
		set_movement(Directions::DOWN, false);
		rotation = 0;
		stabilizing = true;
	}
	else if (std::find(collision.begin(), collision.end(), Collision::DOWN) == collision.end() && !jumping) {
		jumping = true;
		enable_gravity();
	}

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

	if (mup && !mdown) {
		move(Directions::UP);
	}

	if (mdown && !mup && std::find(collision.begin(), collision.end(), Collision::DOWN) == collision.end()) {
		move(Directions::DOWN);
	}

	if (mright && !mleft && std::find(collision.begin(), collision.end(), Collision::RIGHT) == collision.end()) {
		move(Directions::RIGHT);
	}

	if (mleft && !mright && std::find(collision.begin(), collision.end(), Collision::LEFT) == collision.end()) {
		move(Directions::LEFT);
	}
}

void MovableActor::jump() {
	if (jumping) return;

	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), Collision::DOWN);
	if (it != collision.end())
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;

	disable_gravity();
	set_vspeed(JUMP);
	jumping = true;
}

void MovableActor::disable_collision(Collision col) {
	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), col);
	if (it != collision.end()) {
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;
	}
}

void MovableActor::set_collider(std::shared_ptr<MovableActor> actor, Collision col, float dif) {
	collider = actor ? actor : nullptr;

	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), col);
	if (it == collision.end()) {
		if (collision.size() == 4) {
			std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), Collision::NONE);
			if (it != collision.end()) {
				collision.at(std::distance(collision.begin(), it)) = col;
			}
		}
		else {
			collision.push_back(col);
		}
	}

	if (!movement) return;

	if (col == Collision::UP || col == Collision::DOWN) y += dif;
	else if (col == Collision::RIGHT || col == Collision::LEFT) x += dif;
}