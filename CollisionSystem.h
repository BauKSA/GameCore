#pragma once
#include "GenericSystem.h"

#ifndef _COLLISIONSYSTEM_
#define _COLLISIONSYSTEM_

class CollisionSystem : public GenericSystem {
public:
	virtual void update() override;
};

#endif // !_COLLISIONSYSTEM_
