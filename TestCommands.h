#pragma once
#include "Command.h"
#include "MovableActor.h"

#ifndef _TESTCOMMANDS_
#define _TESTCOMMANDS_

class MoveRight : public Command<MovableActor> {
public:
	virtual void execute(MovableActor& actor) override {
		std::cout << "Move Right" << std::endl;
		actor.set_movement(Directions::RIGHT);

		if (actor.get_animation() == "right") return;
		actor.set_animation("right");
	}
};

class StandRight : public Command<MovableActor> {
public:
	virtual void execute(MovableActor& actor) override {
		std::cout << "Stand Right" << std::endl;
		actor.set_movement(Directions::RIGHT, false);

		if (actor.get_animation() == "default") return;
		actor.set_animation("default");
	}
};

class MoveLeft : public Command<MovableActor> {
public:
	virtual void execute(MovableActor& actor) override {
		std::cout << "Move Left" << std::endl;
		actor.set_movement(Directions::LEFT);

		if (actor.get_animation() == "left") return;
		actor.set_animation("left");
	}
};

class StandLeft : public Command<MovableActor> {
public:
	virtual void execute(MovableActor& actor) override {
		std::cout << "Stand Left" << std::endl;
		actor.set_movement(Directions::LEFT, false);

		if (actor.get_animation() == "default") return;
		actor.set_animation("default");
	}
};

#endif // !_TESTCOMMANDS_
