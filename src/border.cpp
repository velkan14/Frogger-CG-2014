#include "border.h"

border::border(){
}

border::border(double x, double y, double z) :StaticObject(x, y, z){}

border::~border(){
}

void border::draw(){
	glColor3f(1.0f,1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(13, 7.5, 0);
	glScalef(6, 15, 4);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-13, 7.5, 0);
	glScalef(6, 15, 4);
	glutSolidCube(1);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(0, 13.5, 0);
	glScalef(20, 1, 0);
	glutSolidCube(1);
	glPopMatrix();*/

}