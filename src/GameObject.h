#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Entity.h"
#include "Draw.h"

class GameObject : public Entity {

public:
	GameObject();
	GameObject(double x, double y, double z);
	~GameObject();
	void virtual draw();
	void update(double delta_t);
};

#endif