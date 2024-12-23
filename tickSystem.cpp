#include "TickSystem.h"

void TickSystem::update(float delta_time) {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<Actor> actor = actors.at(i).lock();
		if (!actor) continue;

		actor->tick(delta_time);
	}
}