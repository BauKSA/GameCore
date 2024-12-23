#include "MoveCommands.h"

void MoveRightCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::RIGHT);
	actor.set_animation("right");
}

void MoveLeftCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::LEFT);
	actor.set_animation("left");
}

void StandRightCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::RIGHT, false);
	actor.set_animation("default");
}

void StandLeftCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::LEFT, false);
	actor.set_animation("default");
}

void JumpCommand::execute(MovableActor& actor) {
	actor.jump();
	actor.set_animation("default");
}

void StopJumpCommand::execute(MovableActor& actor) {
	if (actor.get_vspeed() < 0) return;
	actor.set_vspeed(1.f);
}