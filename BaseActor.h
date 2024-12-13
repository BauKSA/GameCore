#include<string>
#include<iostream>
#include<vector>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<memory>

#include "SpriteActor.h"
#include "GenericSystem.h"
#include "GenericComponent.h"
#include "Utils.h"

#ifndef _BASEACTOR_
#define _BASEACTOR_

enum class Collision {
	NONE = 0,
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 4
};

class BaseActor : public SpriteActor {
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

	std::weak_ptr<BaseActor> collider;
	std::vector<std::string> available_colliders;

	std::vector<std::shared_ptr<GenericComponent>> components;
public:
	BaseActor(std::string name, float x, float y, float speed = 0) :
		SpriteActor(name, x, y), hspeed(speed), vspeed(0),
		mup(false), mdown(false), mright(false), mleft(false),
		gravity(true), jumping(false) {
		components = {};
		collision = { Collision::NONE, Collision::NONE, Collision::NONE, Collision::NONE };
	};

	void initialize(std::string path) { SpriteActor::initialize_sprite(path); }

	//Methods
	void set_movement(Directions dir, bool key_pressed = true);
	void move(Directions dir);
	void jump();

	void add_component(std::shared_ptr<GenericComponent> component);

	void disable_collision(Collision col);

	//Virtuals
	virtual void tick(float delta_time);

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

	void set_collider(std::shared_ptr<BaseActor> actor, Collision col = Collision::NONE, float dif = 0.0f);
};

#endif // !_BASEACTOR_