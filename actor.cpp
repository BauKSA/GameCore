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