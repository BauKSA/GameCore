#include<iostream>

#include "GameWindow.h"
#include "Actor.h"

void Actor::draw() {
	sprite->frame.setPosition(x, y);
	GameWindow::window().draw(sprite->frame);
}

std::shared_ptr<Sprite> Actor::initialize(std::string& path) {
	sprite = std::make_shared<Sprite>();

	if (!sprite->texture.loadFromFile(path)) {
		const std::string error = "Can't initialize sprite in " + name;
		std::cerr << "Error initializing sprite: " << error << std::endl;
		return nullptr;
	}

	sprite->frame.setTexture(sprite->texture);

	sprite->width = sprite->texture.getSize().x;
	sprite->height = sprite->texture.getSize().y;

	x += sprite->width / 2.f;

	sprite->frame.setOrigin(sprite->width / 2.f, 0);
	sprite->frame.setPosition(x, y);


	return sprite;
}

void Actor::set_collider(std::shared_ptr<Actor> actor, Collision col, float dif) {
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
void Actor::disable_collision(Collision col) {
	std::vector<Collision>::iterator it = std::find(collision.begin(), collision.end(), col);
	if (it != collision.end()) {
		collision.at(std::distance(collision.begin(), it)) = Collision::NONE;
	}
}
