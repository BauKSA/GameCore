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
public:
	Actor(std::string _name, float _x, float _y, float _depth = 1.0f) :
		x(_x), y(_y), name(_name), depth(_depth) {
		sprite = nullptr;
	}

	virtual std::shared_ptr<Sprite> initialize(std::string& path);

	void draw();

	float get_x() const { return x; }
	float get_y() const { return y; }

	float get_width() const { return sprite ? sprite->width : 0.0f; }
	float get_height() const { return sprite ? sprite->height : 0.0f; }
	float get_depth() const { return depth; }

	std::string get_name() const { return name; }

	void destroy() const { auto self = shared_from_this(); self.reset(); }
};

#endif // !_ACTOR_