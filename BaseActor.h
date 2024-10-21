#include<string>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "GenericSprite.h"
#include "Utils.h"

#ifndef _BASEACTOR_
#define _BASEACTOR_

class BaseActor: public GenericSprite {
protected:
	float speed;
public:
	BaseActor(std::string name, float x, float y, std::string sprite_path, float _speed) :
		GenericSprite(name, x, y, sprite_path), speed(_speed) {};

	void move(directions dir);
};

#endif // !_BASEACTOR_