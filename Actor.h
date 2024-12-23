#include<string>
#include<memory>

#include "Utils.h"

#ifndef _ACTOR_
#define _ACTOR_

class Actor : std::enable_shared_from_this<Actor> {
protected:
	std::string name;
	std::shared_ptr<Sprite> sprite;
	float x;
	float y;
	float depth;

	bool movement;

	std::shared_ptr<Actor> collider;
	std::vector<Collision> collision;
	std::vector<std::string> available_colliders;
public:
	Actor(std::string _name, float _x, float _y, float _depth = 1.0f) :
		x(_x), y(_y), name(_name), depth(_depth), movement(false) {
		sprite = nullptr;
		collider = nullptr;
		collision = { Collision::NONE, Collision::NONE, Collision::NONE, Collision::NONE };
	}

	virtual std::shared_ptr<Sprite> initialize(std::string& path);

	void draw();

	float get_x() const { return x; }
	float get_y() const { return y; }

	float get_width() const { return sprite ? sprite->width : 0.0f; }
	float get_height() const { return sprite ? sprite->height : 0.0f; }
	float get_depth() const { return depth; }

	std::string get_name() const { return name; }

	virtual void set_collider(std::shared_ptr<Actor> actor, Collision col = Collision::NONE, float dif = 0.0f);
	void disable_collision(Collision col);

	//Virtuals
	virtual void tick(float delta_time) {};
	virtual void move(Directions dir) {};

	void destroy() const { auto self = shared_from_this(); self.reset(); }
};

#endif // !_ACTOR_