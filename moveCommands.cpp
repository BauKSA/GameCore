#include "MoveCommands.h"

void MoveRightCommand::execute(AnimatedActor& actor) {
	actor.set_movement(RIGHT);
	actor.set_animation("right");
}

void MoveLeftCommand::execute(AnimatedActor& actor) {
	actor.set_movement(LEFT);
	actor.set_animation("left");
}

void StandRightCommand::execute(AnimatedActor& actor) {
	actor.set_movement(RIGHT, false);
	actor.set_animation("default");
}

void StandLeftCommand::execute(AnimatedActor& actor) {
	actor.set_movement(LEFT, false);
	actor.set_animation("default");
}

void JumpCommand::execute(AnimatedActor& actor) {
	actor.jump();
	actor.set_animation("default");
}