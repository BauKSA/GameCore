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
	float ispeed;
	float hspeed;
	float vspeed;
	bool mup;
	bool mdown;
	bool mright;
	bool mleft;
	std::vector<GenericSystem*> systems;
	std::vector<GenericComponent*> components;
	bool gravity;
	bool jumping;
public:
	BaseActor(std::string name, float x, float y, float speed) :
		GenericSprite(name, x, y), hspeed(speed), vspeed(0), ispeed(speed) {
		mup = false;
		mdown = false;
		mright = false;
		mleft = false;
		gravity = false;
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

	//Virtuals
	virtual void tick(float delta_time);

	//Declared
	void reset_hspeed() { hspeed = ispeed; };
	void reset_vspeed() { vspeed = 0; };
	void set_vspeed(float speed) { vspeed = speed; };
	float get_vspeed()const { return vspeed; };
	float get_ispeed()const { return ispeed; };
	void enable_gravity() { gravity = true; };
	void disable_gravity() { gravity = false; };
	bool get_gravity()const { return gravity; };

	//TEST COLISIÓN HARDCODEADO
	void check_collision() {
		if (y >= SCREEN_HEIGHT - 100 && jumping) {
			y = SCREEN_HEIGHT - 100;
			jumping = false;
			vspeed = 0;
			disable_gravity();
		}
	}
};

#endif // !_BASEACTOR_