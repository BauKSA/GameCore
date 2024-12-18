#include "PhysicsSystem.h"
#include "MovableActor.h"

void PhysicsSystem::update() {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<MovableActor> actor_1 = actors.at(i).lock();
		if (!actor_1) continue;

		bool stable_right = false;
		bool stable_left = false;

		float point_a = actor_1->get_x();
		float point_b = point_a + actor_1->get_width();

		for (size_t j = 0; j < actors.size(); j++) {
			if (actors.at(j).expired()) continue;
			std::shared_ptr<MovableActor> actor_2 = actors.at(j).lock();

			if (!actor_2) continue;
			if (actor_1 == actor_2) continue;
			if (std::abs(actor_1->get_y() + actor_1->get_height() - actor_2->get_y()) > 1.0f) continue;

			float actor_2_left = actor_2->get_x();
			float actor_2_right = actor_2_left + actor_2->get_width();

			if (point_a >= actor_2_left
				&& point_a <= actor_2_right) {
				stable_left = true;
			}

			if (point_b >= actor_2_left
				&& point_b <= actor_2_right) {
				stable_right = true;
			}
		}

		if (!stable_right) if (actor_1->get_name() == "player") std::cout << "Inestable right" << std::endl;
		if (!stable_left) if (actor_1->get_name() == "player") std::cout << "Inestable left" << std::endl;
	}
}