#include "MoveCommands.h"

void MoveRightCommand::execute(ComplexAnimatedActor& actor) {
	actor.set_movement(RIGHT);
	actor.set_animation("right");
}

void MoveLeftCommand::execute(ComplexAnimatedActor& actor) {
	actor.set_movement(LEFT);
	actor.set_animation("left");
}

void StandRightCommand::execute(ComplexAnimatedActor& actor) {
	actor.set_movement(RIGHT, false);
	actor.set_animation("default");
}

void StandLeftCommand::execute(ComplexAnimatedActor& actor) {
	actor.set_movement(LEFT, false);
	actor.set_animation("default");
}

void JumpCommand::execute(ComplexAnimatedActor& actor) {
	actor.jump();
	actor.set_animation("default");
}