#pragma once
#include "Component.h"
#include "MovableActor.h"

#ifndef _JUMPCOMPONENT_
#define _JUMPCOMPONENT_

class JumpComponent : public Component {
protected:
	const float GRAVITY;
public:
	JumpComponent(float _GRAVITY = 9.8f) :
		GRAVITY(_GRAVITY) {
	}

	void tick(float delta_time, MovableActor& actor) override;
};

#endif // !_JUMPCOMPONENT_