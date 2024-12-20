#include <cmath>

#include "CollisionSystem.h"
#include "MovableActor.h"

bool CollisionSystem::check_vertices(sf::Vector2f vertex, sf::Vector2f top_left_limit, sf::Vector2f bottom_right_limit) {
	return (vertex.x >= top_left_limit.x && vertex.x <= bottom_right_limit.x
		&& vertex.y >= top_left_limit.y && vertex.y <= bottom_right_limit.y);
}

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

			float margin = 8.f;

			sf::Vector2f top_left = { actor_1->get_x() - (actor_1->get_width() / 2.f), actor_1->get_y() };
			sf::Vector2f top_right = { actor_1->get_x() + (actor_1->get_width() / 2.f), actor_1->get_y() };
			sf::Vector2f bottom_left = { actor_1->get_x() - (actor_1->get_width() / 2.f), actor_1->get_y() + actor_1->get_height() };
			sf::Vector2f bottom_right = { actor_1->get_x() + (actor_1->get_width() / 2.f), actor_1->get_y() + actor_1->get_height() };

			sf::Vector2f actor_2_top_left = { actor_2->get_x() - (actor_2->get_width() / 2.f), actor_2->get_y() };
			sf::Vector2f actor_2_bottom_right = { actor_2->get_x() + (actor_2->get_width() / 2.f), actor_2->get_y() + actor_2->get_height() };

			if (check_vertices(bottom_left, actor_2_top_left, actor_2_bottom_right)) {
				if (std::abs(bottom_right.y - actor_2_top_left.y) <= margin) {
					float dif = bottom_right.y - actor_2_top_left.y;
					actor_1->set_collider(actor_2, Collision::DOWN, -dif);
					cdown = true;
				}
				else {
					float dif = std::abs(bottom_left.x - actor_2_bottom_right.x);
					actor_1->set_collider(actor_2, Collision::LEFT, dif + 0.5f);
					cleft = true;
				}
			}
			else if (check_vertices(bottom_right, actor_2_top_left, actor_2_bottom_right)) {
				if (std::abs(bottom_right.y - actor_2_top_left.y) <= margin) {
					float dif = bottom_right.y - actor_2_top_left.y;
					actor_1->set_collider(actor_2, Collision::DOWN, -dif);
					cdown = true;
				}
				else {
					float dif = std::abs(bottom_right.x - actor_2_top_left.x);
					actor_1->set_collider(actor_2, Collision::RIGHT, -dif - 0.5f);
					cright = true;
				}
			}

			if (check_vertices(top_right, actor_2_top_left, actor_2_bottom_right)) {
				if (cright) break;
				float dif = std::abs(bottom_right.x - actor_2_top_left.x);
				actor_1->set_collider(actor_2, Collision::RIGHT, -dif - 0.5f);
				cright = true;
			}
			else if (check_vertices(top_left, actor_2_top_left, actor_2_bottom_right)) {
				if (cleft) break;
				float dif = std::abs(bottom_left.x - actor_2_bottom_right.x);
				actor_1->set_collider(actor_2, Collision::LEFT, dif + 0.5f);
				cleft = true;
			}
		}

		if (!cdown) actor_1->disable_collision(Collision::DOWN);
		if (!cright) actor_1->disable_collision(Collision::RIGHT);
		if (!cleft) actor_1->disable_collision(Collision::LEFT);
	}
}