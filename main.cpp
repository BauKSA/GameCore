#include "Dependencies.h"
#include "Test.h"

int main(int argc, char** argv) {
	bool running = true;

	sf::Clock clock;
	sf::Clock frame_clock;

	float last_frame_time = 0.0f;

	sf::RenderWindow& window = GameWindow::window();
	std::shared_ptr<MovableActor> actor = initialize_test();
	std::vector<std::shared_ptr<Actor>> bricks = initialize_bricks();
	std::shared_ptr<InputComponent<MovableActor>> input = initialize_input();

	std::shared_ptr<GravityComponent> gravity = std::make_shared<GravityComponent>();

	std::unique_ptr<TickSystem> tick = std::make_unique<TickSystem>();
	std::unique_ptr<CollisionSystem> collision = std::make_unique<CollisionSystem>();
	std::unique_ptr<DrawSystem> draw = std::make_unique<DrawSystem>();
	std::unique_ptr<PhysicsSystem> physics = std::make_unique<PhysicsSystem>();

	actor->add_component(gravity);
	actor->add_component(input);

	tick->add_actor(actor);
	collision->add_actor(actor);
	physics->add_actor(actor);
	draw->add_actor(actor);

	for (std::shared_ptr<Actor> brick : bricks) {
		collision->add_actor(brick);
		tick->add_actor(brick);
		draw->add_actor(brick);
		physics->add_actor(brick);
	}

	std::vector<float> deltas{};

	float FRAMES = 60.f;

	while (window.isOpen() && running) {
		window.clear();

		float current_time = clock.getElapsedTime().asSeconds();
		float delta_time = current_time - last_frame_time;
		delta_time = std::min(delta_time, 1.0f / FRAMES);
		last_frame_time = current_time;

		float sleep_time = (1.0f / FRAMES) - frame_clock.getElapsedTime().asSeconds();
		if (sleep_time > 0) {
			sf::sleep(sf::seconds(sleep_time));
		}

		deltas.push_back(delta_time);

		if (delta_time > 0.1f) {
			std::cerr << "[WARNING] delta_time alto detectado: " << delta_time << " segundos. Posible lag." << std::endl;
		}
		else if (delta_time < 0.0001f) {
			std::cerr << "[WARNING] delta_time extremadamente bajo: " << delta_time << " segundos. Posible error de cálculo." << std::endl;
		}

		tick->update(delta_time);
		collision->update();
		physics->update();
		draw->update();

		window.display();

		frame_clock.restart();
	}

	float max = -1 , min = 1;
	for (size_t i = 0; i < deltas.size(); i++) {
		if (deltas.at(i) < min) min = deltas.at(i);
		if (deltas.at(i) > max) max = deltas.at(i);
	}

	std::cout << "\n\n\n\n";
	std::cout << "[WARNING] delta_time max: " << max << ", min: " << min << std::endl;


	return 0;
}
/*
	float last_frame_time = al_get_time();
	bool running = true;

	while (running) {
		al_set_target_bitmap(screen);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, NULL);
		for (size_t i = 0; i < bricks.size(); i++) {
			bricks.at(i)->draw();
		}

		float current_time = al_get_time();
		float delta_time = current_time - last_frame_time;

		// Debug: detectar fluctuaciones altas o bajas en delta_time
		if (delta_time > 0.1f) {
			std::cerr << "[WARNING] delta_time alto detectado: " << delta_time << " segundos. Posible lag." << std::endl;
		}
		else if (delta_time < 0.0001f) {
			std::cerr << "[WARNING] delta_time extremadamente bajo: " << delta_time << " segundos. Posible error de cálculo." << std::endl;
		}

		delta_time = std::min(delta_time, 0.066f);
		last_frame_time = current_time;

		command = test_input->listen();
		if (command) handler->check(command);

		tick_system->update(delta_time);
		collision_system->update();

		// Asegurar que el frame rate no exceda un máximo (ejemplo: 60 FPS)
		float frame_time = al_get_time() - current_time;
		if (frame_time < (1.0f / 60.0f)) {
			al_rest((1.0f / 60.0f) - frame_time);  // Pausa para limitar a 60 FPS
		}
	}

	test_input->stop_listening();
	*/