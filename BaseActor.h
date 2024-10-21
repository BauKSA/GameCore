
#include<string>
#include<vector>
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#ifndef _BASEACTOR_
#define _BASEACTOR_

#define ANIMATION_SPEED 0.15

class BaseActor {
protected:
	float x;
	float y;
	float frame_time;
	std::vector<ALLEGRO_BITMAP*> sprites;
	int actual_frame;
public:
	BaseActor(float _x, float _y, std::vector<std::string> paths) :
		x(_x), y(_y) {
		for (int i = 0; i < paths.size(); i++) {
			ALLEGRO_BITMAP* frame = al_load_bitmap(paths.at(i).c_str());
			sprites.push_back(frame);
		}

		actual_frame = 0;
		frame_time = 0.0;
	}

	void draw(int flags = 0) {
		if (!sprites.at(actual_frame)) return;
		al_draw_bitmap(sprites.at(actual_frame), x, y, flags);
	}

	void update(float delta_time) {
		frame_time += delta_time;
		if (frame_time >= ANIMATION_SPEED) {
			actual_frame = (actual_frame + 1) % sprites.size();
			frame_time = 0.0;
		}
	}

	float get_x() const { return x; }
	float get_y() const { return y; }
	void reset_frames() { actual_frame = 0; }

	~BaseActor() {
		for (int i = 0; i < sprites.size(); i++) {
			al_destroy_bitmap(sprites.at(i));
		}
	}
};

#endif // !_BASEACTOR_