#include<chrono>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include "AllegroInitializer.h"
#include "Utils.h"
#include "BaseActor.h"
#include "Timer.h"
#include "TickSystem.h"

#include "Test.h"

int main(int argc, char** argv) {
    AllegroInitializer* initializer = new AllegroInitializer;
    initializer->init();

    if (initializer->failed()) {
        delete initializer;
        return -1;
    }

    float last_frame_time = al_get_time();
    bool running = true;

    //------------
    //TESTING INIT
    //------------
    ComplexAnimatedActor* test_player = initialize_test();
    InputSystem<ComplexAnimatedActor>* test_input = initialize_input(test_player);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    test_player->draw();
    al_flip_display();

    test_input->start_listening();
    test_player->move(RIGHT);
    //------------
    //TESTING  END
    //------------

    TickSystem* tick_system = new TickSystem();
    tick_system->add_actor(test_player);

    while (running) {
        float current_time = al_get_time();
        float delta_time = current_time - last_frame_time;
        last_frame_time = current_time;

        test_input->listen();
        tick_system->update(delta_time);
    }

    return 0;
}