#include "DrawSystem.h"
#include "MovableActor.h"

void DrawSystem::update() {
	std::sort(actors.begin(), actors.end(),
		[](const std::weak_ptr<MovableActor> a, const std::weak_ptr<MovableActor> b) {
			if (a.expired()) return false;
			if (b.expired()) return true;

			std::shared_ptr<MovableActor> actor_1 = a.lock();
			std::shared_ptr<MovableActor> actor_2 = b.lock();
			if (!actor_1) return false;
			if (!actor_2) return true;

			return actor_1->get_depth() < actor_2->get_depth();
		});

	draw();
}

void DrawSystem::draw() {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<MovableActor> actor = actors.at(i).lock();
		if (!actor) continue;

		actor->draw();
	}
}