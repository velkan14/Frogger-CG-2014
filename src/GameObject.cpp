#include "GameObject.h"


GameObject::GameObject(){
}

GameObject::GameObject(double x, double y, double z){
	_position = new Vector3(x,y,z);
}

GameObject::~GameObject(){
}

void GameObject::draw(){
}

void GameObject::update(double delta_t){
}
