#include "DynamicObject.h"

DynamicObject::DynamicObject() {
}
DynamicObject::DynamicObject(double  x, double y, double z):GameObject(x,y,z){
	_speed = new Vector3(0,0,0);
}
DynamicObject::~DynamicObject() {
}

void DynamicObject::update(double delta_t, double pos, double speed) {
	double x = checkPositionX(getPosition()->getX() + getSpeed()->getX() * delta_t, pos, speed);
	double y = checkPositionY(getPosition()->getY() + getSpeed()->getY() * delta_t);
	double z = getPosition()->getZ();
	xmax = x + _x;
	xmin = x - _x;
	ymax = y + _y;
	ymin = y - _y;
	setPosition(x,y,z);
}

	
void DynamicObject::setSpeed(const Vector3 & speed) {
	_speed->set(speed.getX(), speed.getY(), speed.getZ());
}
	
void DynamicObject::setSpeed(double x, double y, double z) {
	_speed = new Vector3(x,y,z);
}

Vector3 * DynamicObject::getSpeed() {
	return _speed;
}

double DynamicObject::checkPositionX(double x, double pos, double speed){
	return x;
}

double DynamicObject::checkPositionY(double y){
	return y;
}