#include "Roadside.h"

Roadside::Roadside(){
}

Roadside::Roadside(double x,double y,double z):StaticObject(x,y,z){}

Roadside::~Roadside(){
}

void Roadside::draw(){
	glColor3f(0.25f, 0.25f, 0.25f); //dark gray
	glPushMatrix();
	glTranslated(0, .5, 0);
	glScalef(20, 1, 1);
	glutSolidCube(1);
	glTranslated(0, 6, 0);
	glutSolidCube(1);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(0, 6.5, 0);
	glScalef(20, 1, 0);
	glutSolidCube(1);
	glPopMatrix();*/
}