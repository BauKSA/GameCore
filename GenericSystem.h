#include<vector>

#ifndef _GENERICSYSTEM_
#define _GENERICSYSTEM_
class BaseActor;

class GenericSystem {
protected:
	std::vector<BaseActor*> actors;
public:
	GenericSystem() {}

	virtual void add_actor(BaseActor* actor);
	virtual void update() {}
	virtual void update(float delta_time) {}
};

#endif // !_GENERICSYSTEM_