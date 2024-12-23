#include "PhysicsSystem.h"
#include "MovableActor.h"

bool PhysicsSystem::check_vertices(sf::Vector2f vertex, sf::Vector2f top_left_limit, sf::Vector2f bottom_right_limit) {
	return (vertex.x >= top_left_limit.x && vertex.x <= bottom_right_limit.x
		&& vertex.y >= top_left_limit.y && vertex.y <= bottom_right_limit.y);
}

void PhysicsSystem::update() {
	for (size_t i = 0; i < actors.size(); i++) {
		if (actors.at(i).expired()) continue;
		std::shared_ptr<Actor> actor_1 = actors.at(i).lock();
		if (!actor_1) continue;

		bool cdown = false;
		bool cright = false;
		bool cleft = false;

		for (size_t j = 0; j < actors.size(); j++) {
			if (actors.at(j).expired()) continue;
			std::shared_ptr<Actor> actor_2 = actors.at(j).lock();

			if (!actor_2) continue;
			if (actor_1 == actor_2) continue;

			float margin = 8.f;

			sf::Vector2f top_left = { actor_1->get_x() - (actor_1->get_width() / 2.f), actor_1->get_y() };
			sf::Vector2f top_right = { actor_1->get_x() + (actor_1->get_width() / 2.f), actor_1->get_y() };
			sf::Vector2f bottom_left = { actor_1->get_x() - (actor_1->get_width() / 2.f), actor_1->get_y() + actor_1->get_height() };
			sf::Vector2f bottom_right = { actor_1->get_x() + (actor_1->get_width() / 2.f), actor_1->get_y() + actor_1->get_height() };

			sf::Vector2f actor_2_top_left = { actor_2->get_x() - (actor_2->get_width() / 2.f), actor_2->get_y() };
			sf::Vector2f actor_2_bottom_right = { actor_2->get_x() + (actor_2->get_width() / 2.f), actor_2->get_y() + actor_2->get_height() };

			if (check_vertices(bottom_left, actor_2_top_left, actor_2_bottom_right)) {
				if (std::abs(bottom_right.y - actor_2_top_left.y) <= margin) {
					//if (actor_1->get_name() == "player") std::cout << "[DEBUG] Stable in LEFT" << std::endl;
				}
			}
			
			if (check_vertices(bottom_right, actor_2_top_left, actor_2_bottom_right)) {
				if (std::abs(bottom_right.y - actor_2_top_left.y) <= margin) {
					//if (actor_1->get_name() == "player") std::cout << "[DEBUG] Stable in RIGHT" << std::endl;
				}
			}
		}
	}
}