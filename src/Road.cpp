#include "Road.h"

Road::Road(){
}

Road::~Road(){
}

void Road::draw(){
	glColor3f(0.5f, 0.5f, 0.5f); //gray
	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glScalef(14, 5, 0);
	glutSolidCube(1);
	glPopMatrix();
}