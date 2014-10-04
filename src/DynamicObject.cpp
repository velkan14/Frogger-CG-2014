#include "DynamicObject.h"

DynamicObject::DynamicObject() {
}
DynamicObject::DynamicObject(double  x, double y, double z):GameObject(x,y,z){
}
DynamicObject::~DynamicObject() {
}

void DynamicObject::update(double delta_t) {
}
	
void DynamicObject::setSpeed(const Vector3 & speed) {
	//_speed = speed;

}
	
void DynamicObject::setSpeed(double x, double y, double z) {
	_speed = new Vector3(x,y,z);
}

Vector3 DynamicObject::getSpeed() {
	return *_speed;
}