#include<string>
#include<iostream>
#include<vector>
#include<memory>

#include "Actor.h"
#include "System.h"
#include "Component.h"
#include "Utils.h"

#ifndef _MOVABLEACTOR_
#define _MOVABLEACTOR_

class MovableActor : public Actor {
protected:
	//speed
	float hspeed;
	float vspeed;

	//movement
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;

	bool gravity;
	bool jumping;

	std::vector<Collision> collision;

	std::weak_ptr<MovableActor> collider;
	std::vector<std::string> available_colliders;

	std::vector<std::shared_ptr<Component>> components;
public:
	MovableActor(std::string name, float x, float y, float speed = 0, float depth = 1.0f) :
		Actor(name, x, y, depth), hspeed(speed), vspeed(0),
		mup(false), mdown(false), mright(false), mleft(false),
		gravity(true), jumping(false) {
		components = {};
		collision = { Collision::NONE, Collision::NONE, Collision::NONE, Collision::NONE };
	};


	//Methods
	void set_movement(Directions dir, bool key_pressed = true);
	void move(Directions dir);
	void jump();

	void add_component(std::shared_ptr<Component> component);

	void disable_collision(Collision col);

	//Virtuals
	virtual void tick(float delta_time);
	virtual std::shared_ptr<Sprite> initialize(std::string& path) override { return Actor::initialize(path); }

	//Declared
	//Speed
	void reset_vspeed() { vspeed = 0; };
	void set_vspeed(float speed) { vspeed = speed; };

	float get_vspeed()const { return vspeed; };
	float get_hspeed()const { return hspeed; };

	//Gravity
	void enable_gravity() { gravity = true; jumping = true; };
	void disable_gravity() { gravity = false; };
	bool get_gravity()const { return gravity; };

	void set_collider(std::shared_ptr<MovableActor> actor, Collision col = Collision::NONE, float dif = 0.0f);
};

#endif // !_MOVABLEACTOR_