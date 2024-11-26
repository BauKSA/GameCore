#pragma once
#include "GenericComponent.h"
#include "BaseActor.h"

#ifndef _GRAVITYCOMPONENT_
#define _GRAVITYCOMPONENT_

class GravityComponent : public GenericComponent {
protected:
	const float GRAVITY;
public:
	GravityComponent(float _GRAVITY = 9.8f) :
		GRAVITY(_GRAVITY) {
	}

	void tick(float delta_time, BaseActor& acotr) override;
};

#endif // !_GRAVITYCOMPONENT_
