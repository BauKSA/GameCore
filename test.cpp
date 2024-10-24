#include "Test.h"
#include "JoystickMapping.h"

ComplexAnimatedActor* initialize_test() {
	AnimationPaths _default;
	_default.name = "default";
	_default.paths = {
		"./test0.png",
		"./test1.png",
		"./test2.png",
		"./test3.png",
		"./test4.png",
	};

	AnimationPaths left;
	left.name = "left";
	left.paths = {
		"./test4.png",
		"./test.png",
	};

	AnimationPaths right;
	right.name = "right";
	right.paths = {
		"./test2.png",
		"./test.png",
	};

	ComplexAnimatedActor* actor = new ComplexAnimatedActor("test_actor", 10, 10, .125);
	actor->initialize_sprite({ _default, left, right });

	return actor;
}

static std::vector<Actions> set_actions() {
	std::vector<Actions> actions;
	Actions up = Actions{ {ALLEGRO_KEY_W, JOY_BUTTON_UP}, "up" };
	Actions down = Actions{ {ALLEGRO_KEY_S, JOY_BUTTON_DOWN}, "down" };
	Actions right = Actions{ {ALLEGRO_KEY_D, JOY_BUTTON_RIGHT}, "right" };
	Actions left = Actions{ {ALLEGRO_KEY_A, JOY_BUTTON_LEFT}, "left" };

	actions.push_back(up);
	actions.push_back(down);
	actions.push_back(right);
	actions.push_back(left);

	return actions;
}

InputSystem<ComplexAnimatedActor>* initialize_input(ComplexAnimatedActor* actor) {
	std::vector<Actions> actions = set_actions();
	InputSystem<ComplexAnimatedActor>* actor_input = new InputSystem<ComplexAnimatedActor>(actor, actions,
		[](std::string action, bool key_pressed, ComplexAnimatedActor* actor) {
		if (action == "right") {
			if (key_pressed) {
				actor->set_movement(RIGHT, key_pressed);
				actor->set_animation("right");
			} else {
				actor->set_movement(RIGHT, key_pressed);
				actor->set_animation("default");
			}
		} else if (action == "left") {
			if (key_pressed) {
				actor->set_movement(LEFT, key_pressed);
				actor->set_animation("left");
			}
			else {
				actor->set_movement(LEFT, key_pressed);
				actor->set_animation("default");
			}
		}
	});

	return actor_input;
}