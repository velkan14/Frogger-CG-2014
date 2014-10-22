#include "Riverside.h"

Riverside::Riverside(){
}

Riverside::Riverside(double x,double y,double z):StaticObject(x,y,z){}

Riverside::~Riverside(){
}

void Riverside::draw(){
	glColor3f(0.0f, 1.0f, 0.0f); //green
	glPushMatrix();
	glTranslatef(0, 7.5, 0);
	glScalef(20, 1, 1);
	glutSolidCube(1);
	glTranslated(0, 6, 0);
	glutSolidCube(1);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(0, 13.5, 0);
	glScalef(20, 1, 0);
	glutSolidCube(1);
	glPopMatrix();*/

}