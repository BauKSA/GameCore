#pragma once
#include "System.h"

#ifndef _COLLISIONSYSTEM_
#define _COLLISIONSYSTEM_

class CollisionSystem : public System {
public:
	virtual void update() override;
};

#endif // !_COLLISIONSYSTEM_
