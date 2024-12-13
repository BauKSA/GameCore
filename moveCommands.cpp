#include "MoveCommands.h"

void MoveRightCommand::execute(AnimatedActor& actor) {
	actor.set_movement(Directions::RIGHT);
	actor.set_animation("right");
}

void MoveLeftCommand::execute(AnimatedActor& actor) {
	actor.set_movement(Directions::LEFT);
	actor.set_animation("left");
}

void StandRightCommand::execute(AnimatedActor& actor) {
	actor.set_movement(Directions::RIGHT, false);
	actor.set_animation("default");
}

void StandLeftCommand::execute(AnimatedActor& actor) {
	actor.set_movement(Directions::LEFT, false);
	actor.set_animation("default");
}

void JumpCommand::execute(AnimatedActor& actor) {
	actor.jump();
	actor.set_animation("default");
}