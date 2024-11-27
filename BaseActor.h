#include<string>
#include<iostream>
#include<vector>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "GenericSprite.h"
#include "GenericSystem.h"
#include "GenericComponent.h"
#include "Utils.h"

#ifndef _BASEACTOR_
#define _BASEACTOR_

class BaseActor : public GenericSprite {
protected:
	//speed
	float ispeed;
	float hspeed;
	float vspeed;

	//movement
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;

	//collision
	bool cdown;
	bool cright;
	bool cleft;

	std::vector<GenericSystem*> systems;
	std::vector<GenericComponent*> components;
	bool gravity;
	bool jumping;
public:
	BaseActor(std::string name, float x, float y, float speed = 0) :
		GenericSprite(name, x, y), hspeed(speed), vspeed(0), ispeed(speed) {
		mup = false;
		mdown = false;
		mright = false;
		mleft = false;

		cdown = false;
		cright = false;
		cleft = false;

		gravity = true;
		jumping = false;
		systems = {};
		components = {};
	};

	void initialize_sprite(std::string path) override { GenericSprite::initialize_sprite(path); }

	//Methods
	void move(directions dir);
	void set_movement(directions dir, bool key_pressed = true);
	void add_system(GenericSystem* system);
	void add_component(GenericComponent* component);
	void jump();
	void set_collision(int dir, float pos = 0);
	void disable_collision(int dir);

	//Virtuals
	virtual void tick(float delta_time);

	//Declared
	void reset_hspeed() { hspeed = ispeed; };
	void reset_vspeed() { vspeed = 0; };
	float get_vspeed()const { return vspeed; };
	float get_ispeed()const { return ispeed; };
	float get_hspeed()const { return hspeed; };
	void enable_gravity() { gravity = true; jumping = true; };
	void disable_gravity() { gravity = false; };
	bool get_gravity()const { return gravity; };
	void set_vspeed(float speed) { vspeed = speed; };
	bool get_cdown()const { return cdown; }
};

#endif // !_BASEACTOR_