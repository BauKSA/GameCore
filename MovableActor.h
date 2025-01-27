#include<string>
#include<iostream>
#include<vector>
#include<memory>

#include "AnimatedActor.h"
#include "System.h"
#include "Component.h"
#include "Utils.h"

#ifndef _MOVABLEACTOR_
#define _MOVABLEACTOR_

class MovableActor : public AnimatedActor {
protected:
	//speed
	float hspeed;
	float vspeed;
	float speed;
	float friction;
	float acceleration;

	//movement
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;

	float rotation;
	float rotation_origin;

	bool gravity;
	bool jumping;
	bool falling;
	bool physics;
	bool stable;
	bool stabilizing;

	std::vector<std::shared_ptr<Component<MovableActor>>> components;
public:
	MovableActor(std::string name, float x, float y, float _speed = 0, float depth = 1.0f) :
		AnimatedActor(name, x, y, depth), hspeed(0.0f), vspeed(0.0f), speed(_speed), acceleration(10.f), friction(12.f),
		mup(false), mdown(false), mright(false), mleft(false), rotation(0.0f), rotation_origin(0.0f),
		gravity(true), jumping(false), falling(false), physics(false), stable(true), stabilizing(false){
		components = {};
		movement = true;
	};


	//Methods
	void set_movement(Directions dir, bool key_pressed = true);
	void move(Directions dir);
	void jump();

	void add_component(std::shared_ptr<Component<MovableActor>> component);

	//Virtuals
	virtual void tick(float delta_time);
	virtual void initialize(std::vector<AnimationPaths> paths) override { return AnimatedActor::initialize(paths); }

	//Declared
	//Speed
	void reset_vspeed() { vspeed = 0; };
	void set_vspeed(float speed) { vspeed = speed; };
	void set_rotation(float r) { if (!physics) return;  rotation = r; };
	void set_rotation_origin(float origin) { if (!physics) return;  rotation_origin = origin; };
	void disable_movement() { movement = false; }

	float get_vspeed()const { return vspeed; };
	float get_hspeed()const { return hspeed; };

	bool is_jumping()const { return jumping; };
	bool is_falling()const { return falling; };

	//Gravity
	void enable_gravity() { gravity = true; jumping = true; };
	void disable_gravity() { gravity = false; };
	bool get_gravity()const { return gravity; };

	void enable_physics() { physics = true; };
	bool has_physics() const { return physics; };
	bool is_stable() const { return stable; };
	void stabilize(bool s) { stable = s; };
	bool is_stabilizing()const { return stabilizing; };

	virtual void set_collider(std::shared_ptr<Actor> actor, Collision col = Collision::NONE, float dif = 0.0f) override;
};

#endif // !_MOVABLEACTOR_