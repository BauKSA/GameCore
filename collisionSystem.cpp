#include <cmath>

#include "CollisionSystem.h"
#include "BaseActor.h"

void CollisionSystem::update() {

	for (size_t i = 0; i < actors.size(); i++) {
		bool cdown = false;
		bool cright = false;
		bool cleft = false;

		for (size_t j = 0; j < actors.size(); j++) {
			if (actors.at(i) != actors.at(j)) {
				BaseActor* actor_1 = actors.at(i);
				BaseActor* actor_2 = actors.at(j);

				float actor_1_ceil = actor_1->get_y();
				float actor_1_floor = actor_1->get_y() + actor_1->get_height();

				float actor_2_ceil = actor_2->get_y();
				float actor_2_floor = actor_2->get_y() + actor_2->get_height();

				float actor_1_left = actor_1->get_x();
				float actor_1_right = actor_1->get_x() + actor_1->get_width();

				float actor_2_left = actor_2->get_x();
				float actor_2_right = actor_2->get_x() + actor_2->get_width();

				float actor_x_margin = (actor_1->get_width() / 2);

				//Si coninciden en X, buscamos colisión abajo (y)
				if ((actor_1_right > actor_2_left && actor_1_left < actor_2_right)) {
					if ((actor_1_floor > actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MAX_STEP)
						|| (actor_1_floor < actor_2_ceil && std::abs(actor_1_floor - actor_2_ceil) < MIN_STEP)) {
						actor_1->set_collision(DOWN, actor_2->get_y() - (actor_2->get_height() / 2) + 0.01);
						actor_1->set_collider(actor_2);
						cdown = true;
					}
				}

				//Si hay coincidencia en Y
				if ((actor_1_floor - MAX_STEP > actor_2_ceil) && (actor_1_ceil < actor_2_floor)) {
					//Buscamos colisión en RIGHT
					if (actor_1_right + 1 > actor_2_left && actor_1_right < actor_2_right) {
						actor_1->set_collision(RIGHT);
						actor_1->set_collider(actor_2);
						cright = true;
					}

					//Buscamos colisión en LEFT
					if (actor_1_left > actor_2_left && actor_1_left - 1 < actor_2_right) {
						actor_1->set_collision(LEFT);
						actor_1->set_collider(actor_2);
						cleft = true;
					}
				}


			}
		}

		if (!cright) actors.at(i)->disable_collision(RIGHT);
		if (!cleft) actors.at(i)->disable_collision(LEFT);
		if (!cdown) actors.at(i)->disable_collision(DOWN);
	}
}