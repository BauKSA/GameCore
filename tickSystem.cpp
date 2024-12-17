#include "TickSystem.h"

void TickSystem::update(float delta_time) {
	for (std::shared_ptr<MovableActor> actor : actors) {
		if (!actor) continue;
		actor->tick(delta_time);
	}
}