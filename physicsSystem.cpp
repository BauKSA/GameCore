#include "PhysicsSystem.h"
#include "MovableActor.h"

void PhysicsSystem::update() {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<MovableActor> actor_1 = actors.at(i).lock();
		if (!actor_1) continue;
		if (actor_1->is_jumping()) continue;
		if (actor_1->is_stabilizing()) continue;

		float margin = actor_1->get_width() + 1;

		bool stable_right = false;
		bool stable_left = false;

		float point_ab = actor_1->get_x();
		float point_a = actor_1->get_x() - (actor_1->get_width());
		float point_b = actor_1->get_x() + (actor_1->get_width());

		for (size_t j = 0; j < actors.size(); j++) {
			if (actors.at(j).expired()) continue;
			std::shared_ptr<MovableActor> actor_2 = actors.at(j).lock();

			if (!actor_2) continue;
			if (actor_1 == actor_2) continue;
			if (std::abs(actor_1->get_y() + actor_1->get_height() - actor_2->get_y()) > .5f) continue;

			float left = actor_2->get_x() - (actor_2->get_width() / 2.f);
			float right = actor_2->get_x() + (actor_2->get_width() / 2.f);

			if (point_a + margin >= left
				&& point_a - margin <= right) {
				stable_left = true;
			}

			if (point_b + margin > left
				&& point_b - margin <= right) {
				stable_right = true;
			}
		}

		if (stable_left && stable_right) {
			actor_1->stabilize(true);
			actor_1->set_rotation(0.f);
		}
		else {
			if (!stable_right && stable_left) {
				actor_1->set_rotation(1.f);
			}
			else if (!stable_left && stable_right) {
				actor_1->set_rotation(-1.f);
			}
			actor_1->stabilize(false);
		}
	}
}