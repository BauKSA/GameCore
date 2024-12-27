#pragma once
#include "Component.h"
#include "MovableActor.h"

#ifndef _GRAVITYCOMPONENT_
#define _GRAVITYCOMPONENT_

class GravityComponent : public Component {
protected:
	const float GRAVITY;
public:
	GravityComponent(float _GRAVITY = 15.f) :
		GRAVITY(_GRAVITY) {
	}

	void tick(float delta_time, MovableActor& acotr) override;
};

#endif // !_GRAVITYCOMPONENT_
