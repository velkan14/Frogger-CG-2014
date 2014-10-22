#include "Road.h"

Road::Road(){
}

Road::Road(double x,double y,double z):StaticObject(x,y,z){}

Road::~Road(){
}

void Road::draw(){
	glColor3f(0.5f, 0.5f, 0.5f); //gray
	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glScalef(20, 5, 1);
	glutSolidCube(1);
	glPopMatrix();
}