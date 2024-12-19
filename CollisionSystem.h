#pragma once
#include<SFML/Graphics.hpp>
#include "System.h"

#ifndef _COLLISIONSYSTEM_
#define _COLLISIONSYSTEM_

class CollisionSystem : public System {
public:
	virtual void update() override;
	bool check_vertices(sf::Vector2f vertex, sf::Vector2f top_left_limit, sf::Vector2f bottom_right_limit);
};

#endif // !_COLLISIONSYSTEM_
