#include "DrawSystem.h"
#include "MovableActor.h"

void DrawSystem::update() {
	std::sort(actors.begin(), actors.end(),
		[](const std::shared_ptr<MovableActor> a, const std::shared_ptr<MovableActor> b) {
			return a->get_depth() < b->get_depth();
		});

	draw();
}

void DrawSystem::draw() {
	for (size_t i = 0; i < actors.size(); i++) {
		actors.at(i)->draw();
	}
}