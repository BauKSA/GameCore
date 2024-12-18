#pragma once
#include "System.h"

#ifndef _PHYSICSSYSTEM_
#define _PHYSICSSYSTEM_

class PhysicsSystem : public System {
public:
	virtual void update() override;
};

#endif // !_PHYSICSSYSTEM_
