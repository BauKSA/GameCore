#pragma once
#include<vector>
#include "BaseActor.h"

#ifndef _GENERICCOMPONENT_
#define _GENERICCOMPONENT_

class GenericComponent {
protected:
	std::vector<BaseActor*> actors;
public:
	GenericComponent() {};
	virtual void tick(float delta_time) {};
	void add_actor(BaseActor* actor);
};

#endif // !_GENERICCOMPONENT_