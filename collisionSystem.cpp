#include <cmath>

#include "CollisionSystem.h"
#include "MovableActor.h"

void CollisionSystem::update() {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<MovableActor> actor_1 = actors.at(i).lock();
		if (!actor_1) continue;

		bool cdown = false;
		bool cright = false;
		bool cleft = false;

		for (size_t j = 0; j < actors.size(); j++) {
			if (actors.at(j).expired()) continue;
			std::shared_ptr<MovableActor> actor_2 = actors.at(j).lock();

			if (!actor_2) continue;
			if (actor_1 == actor_2) continue;

			float actor_1_ceil = actor_1->get_y();
			float actor_1_floor = actor_1->get_y() + actor_1->get_height();

			float actor_2_ceil = actor_2->get_y();
			float actor_2_floor = actor_2->get_y() + actor_2->get_height();

			float actor_1_left = actor_1->get_x();
			float actor_1_right = actor_1->get_x() + actor_1->get_width();

			float actor_2_left = actor_2->get_x();
			float actor_2_right = actor_2->get_x() + actor_2->get_width();

			float actor_x_margin = (actor_1->get_width() / 2);

			//Si coninciden en X, buscamos colisi�n abajo (y)
			if ((actor_1_right > actor_2_left && actor_1_left < actor_2_right)) {
				if ((actor_1_floor > actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MAX_STEP)
					|| (actor_1_floor < actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MIN_STEP)) {
					float dif = (actor_1->get_y() + actor_1->get_height() - actor_2->get_y() - 1.0f) * -1;
					actor_1->set_collider(actor_2, Collision::DOWN, dif);
					cdown = true;

				}
			}

			//Si hay coincidencia en Y
			if ((actor_1_floor - MAX_STEP > actor_2_ceil) && (actor_1_ceil < actor_2_floor)) {
				//Buscamos colisi�n en RIGHT
				if (actor_1_right + 1 > actor_2_left && actor_1_right < actor_2_right) {
					actor_1->set_collider(actor_2, Collision::RIGHT);
					cright = true;
				}

				//Buscamos colisi�n en LEFT
				if (actor_1_left > actor_2_left && actor_1_left - 1 < actor_2_right) {
					actor_1->set_collider(actor_2, Collision::LEFT);
					cleft = true;
				}
			}
		}

		if (!cdown) actor_1->disable_collision(Collision::DOWN);
		if (!cright) actor_1->disable_collision(Collision::RIGHT);
		if (!cleft) actor_1->disable_collision(Collision::LEFT);
	}
}