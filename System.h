#include<vector>
#include<memory>

#ifndef _SYSTEM_
#define _SYSTEM_
class MovableActor;

class System {
protected:
	std::vector<std::shared_ptr<MovableActor>> actors;
public:
	System() {}

	virtual void add_actor(std::shared_ptr<MovableActor> actor);
	virtual void update() {}
	virtual void update(float delta_time) {}
};

#endif // !_SYSTEM_