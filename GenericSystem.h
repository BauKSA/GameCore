#include<vector>
#include<memory>

#ifndef _GENERICSYSTEM_
#define _GENERICSYSTEM_
class BaseActor;

class GenericSystem {
protected:
	std::vector<std::shared_ptr<BaseActor>> actors;
public:
	GenericSystem() {}

	virtual void add_actor(std::shared_ptr<BaseActor> actor);
	virtual void update() {}
	virtual void update(float delta_time) {}
};

#endif // !_GENERICSYSTEM_