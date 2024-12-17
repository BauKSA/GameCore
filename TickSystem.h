#pragma once
#include<vector>

#include "MovableActor.h"
#include "System.h"
#include "Component.h"

#ifndef _TICKSYSTEM_
#define _TICKSYSTEM_

class TickSystem : public System {
public:
	void update(float delta_time) override;
};

#endif // !_TICKSYSTEM_
