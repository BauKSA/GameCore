#pragma once
#include "GenericSystem.h"

#ifndef _TICKSYSTEM_
#define _TICKSYSTEM_

class TickSystem : public GenericSystem {
public:
	void update(float delta_time) override;
};

#endif // !_TICKSYSTEM_
