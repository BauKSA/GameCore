#include "Test.h"
#include "JoystickMapping.h"

AnimatedActor* initialize_test() {
	std::vector<std::string> paths = {
		"./test0.png",
		"./test1.png",
		"./test2.png",
		"./test3.png",
		"./test4.png",
	};

	AnimatedActor* actor = new AnimatedActor("test_actor", 10, 10, .125);
	actor->initialize_sprite(paths);

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

InputSystem* initialize_input(BaseActor* actor) {
	std::vector<Actions> actions = set_actions();
	InputSystem* actor_input = new InputSystem(actor, actions, [](std::string action, bool key_pressed, BaseActor* actor) {
		if (action == "right") {
			if (key_pressed) {
				std::cout << "Movemos a la derecha" << std::endl;
				actor->set_movement(RIGHT, key_pressed);
			} else {
				std::cout << "Dejamos de mover" << std::endl;
				actor->set_movement(RIGHT, key_pressed);
			}
		} else if (action == "left") {
			if (key_pressed) {
				std::cout << "Movemos a la izquierda" << std::endl;
				actor->set_movement(LEFT, key_pressed);
			}
			else {
				std::cout << "Dejamos de mover" << std::endl;
				actor->set_movement(LEFT, key_pressed);
			}
		}
	});

	return actor_input;
}