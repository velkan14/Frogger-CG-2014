#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Entity.h"

class GameObject : public Entity {

public:
	GameObject();
	~GameObject();
	void virtual draw();
	void update(double delta_t);
};

#endif