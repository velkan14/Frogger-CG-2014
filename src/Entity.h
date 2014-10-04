#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include "Vector3.h"
#include <GL\glut.h>

class Entity {

protected:
	Vector3 * _position;

public:
	Entity();
	~Entity();
	Vector3 * getPosition();
	void setPosition(double x, double y, double z);
	void setPosition(Vector3 * p);
};
#endif
