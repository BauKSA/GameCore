#include<vector>
#include<memory>

#ifndef _SYSTEM_
#define _SYSTEM_
class Actor;

class System {
protected:
	std::vector<std::weak_ptr<Actor>> actors;
public:
	System() {}

	virtual void add_actor(std::shared_ptr<Actor> actor);
	virtual void update() {}
	virtual void update(float delta_time) {}
};

#endif // !_SYSTEM_