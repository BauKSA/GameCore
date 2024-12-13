#include<iostream>
#include<cmath>

#include "BaseActor.h"

void BaseActor::add_component(std::shared_ptr<GenericComponent> component) {
	components.push_back(component);
}

void BaseActor::move(Directions dir) {
	const float speed = vspeed > MAX_STEP ? MAX_STEP : vspeed;
	switch (dir) {
	case Directions::UP:
		y -= std::abs(speed);
		break;
	case Directions::DOWN:
		y += std::abs(speed);
		break;
	case Directions::RIGHT:
		x += std::abs(hspeed);
		break;
	case Directions::LEFT:
		x -= std::abs(hspeed);
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::set_movement(Directions dir, bool key_pressed) {
	switch (dir) {
	case Directions::RIGHT:
		mright = key_pressed;
		break;
	case Directions::LEFT:
		mleft = key_pressed;
		break;
	default:
		std::cerr << "Error moving actor " << name;
		return;
	}
}

void BaseActor::tick(float delta_time) {
	for (size_t i = 0; i < components.size(); i++) {
		components.at(i)->tick(delta_time, *this);
	}

	if (std::find(collision.begin(), collision.end(), Collision::DOWN) != collision.end() && jumping) {
		jumping = false;
		disable_gravity();
	}
	else if (std::find(collision.begin(), collision.end(), Collision::DOWN) == collision.end() && !jumping) {
		jumping = true;
		enable_gravity();
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

void BaseActor::jump() {
	if (jumping) return;

	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), Collision::DOWN);
	if (it != collision.end())
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;

	disable_gravity();
	set_vspeed(JUMP);
	jumping = true;
}

void BaseActor::disable_collision(Collision col) {
	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), col);
	if (it != collision.end()) {
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;
	}
}

void BaseActor::set_collider(std::shared_ptr<BaseActor> actor, Collision col, float dif) {
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

	if (col == Collision::UP || col == Collision::DOWN) y += dif;
	else if (col == Collision::RIGHT || col == Collision::LEFT) x += dif;
}