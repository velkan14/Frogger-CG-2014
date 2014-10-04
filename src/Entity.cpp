#include "Entity.h"

Entity::Entity(){
}

Entity::~Entity(){
}

Vector3 * Entity::getPosition() {
	return _position;
}

void Entity::setPosition(double x, double y, double z) {
	_position = new Vector3(x,y,z);
}

//Vector3 * Entity::setPosition(const Vector3 & p)
void Entity::setPosition(Vector3 * p) {
	_position = p;
}


