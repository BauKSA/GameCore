#include "MoveCommands.h"

void MoveRightCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::RIGHT);
	if (actor.get_animation() == "right") return;
	actor.set_animation("right");
}

void MoveLeftCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::LEFT);
	if (actor.get_animation() == "left") return;
	actor.set_animation("left");
}

void StandRightCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::RIGHT, false);
	if (actor.get_animation() == "default") return;
	actor.set_animation("default");
}

void StandLeftCommand::execute(MovableActor& actor) {
	actor.set_movement(Directions::LEFT, false);
	if (actor.get_animation() == "default") return;
	actor.set_animation("default");
}

void JumpCommand::execute(MovableActor& actor) {
	if (actor.is_jumping()) return;
	actor.jump();
}

void StopJumpCommand::execute(MovableActor& actor) {
	if (actor.get_vspeed() < 0) return;
	actor.set_vspeed(1.f);
}