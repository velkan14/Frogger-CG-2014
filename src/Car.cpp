#include "Car.h"

Car::Car() {
}

Car::Car(double x,double y,double z):DynamicObject(x,y,z){
}

Car::~Car() {
}

void Car::draw() {

	glPushMatrix();
	glTranslatef(0, 0, 0.375);
	
		glColor3f(0., 0., 0.);
		//carbody
		glPushMatrix();
		glScalef(.8, .8, .6);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-.4, 0, -.15);
		//hood + front wheels
		glPushMatrix();
		glTranslatef(-.25, 0, 0);
		glScalef(.5, .6, .3);
		glutSolidCube(1);
		glPopMatrix();
		glColor3f(0.25f, 0.25f, 0.25f);
		glPushMatrix();
		glTranslatef(-.25, .4, 0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(.1, .13, 10, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-.25, -0.4, 0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(0.1, .13, 10, 20);
		glPopMatrix();

		glPopMatrix();

		glColor3f(0., 0., 0.);
		glPushMatrix();
		glTranslatef(.4, 0, -.15);
		//back + back wheels
		glPushMatrix();
		glTranslatef(.25, 0, 0);
		glScalef(.5, .6, .3);
		glutSolidCube(1);
		glPopMatrix();
		glColor3f(0.25f, 0.25f, 0.25f);
		glPushMatrix();
		glTranslatef(.25, .4, 0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(.1, .13, 10, 20);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(.25, -.4, 0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(.1, .13, 10, 20);
		glPopMatrix();

		glPopMatrix();

	glPopMatrix();

}