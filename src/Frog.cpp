#include "Frog.h"


Frog::Frog() {
}

Frog::~Frog() {
}

void Frog::draw() {
	std::cout <<"cenas2";
	
	glColor3f(1., 0., 0.);
	//Left Eye
	glPushMatrix();
	glTranslated(-0.25,0.25,0);
	glScalef(0.1,0.11,1);
	glutSolidSphere(1,50,50);
	glPopMatrix();

	//Right Eye
	glPushMatrix();
	glTranslated(0.25,0.25,0);
	glScalef(0.1,0.11,1);
	glutSolidSphere(1,50,50);
	glPopMatrix();
	
	glColor3f(0., 0.8, 0.);
		//Main Body
	glPushMatrix();
	glScalef(0.35,0.45,1);
	glutSolidSphere(1,50,50);
	glPopMatrix();

	
	glPushMatrix();
	glTranslated(-0.4,-0.2,0);
		//---------Left Back Leg------------
		//Rectangle Horizontal
		glPushMatrix();
		glTranslated(0.05,0.05,1);
		glScalef(0.3,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
		//Rectangle Vertical 
		glPushMatrix();
		glTranslated(-0.05,-0.15,0);
		glScalef(0.1,0.3,1);
		glutSolidCube(1);
		glPopMatrix();
		//Square
		glPushMatrix();
		glTranslated(-0.15,-0.15,0);
		glScalef(0.1,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.4,0.1,0);
		//------------Left Front Leg------------
		glPushMatrix();
		glTranslated(0.05,-0.05,0);
		glScalef(0.3,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.05,0.1,0);
		glScalef(0.1,0.2,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.15,0.05,0);
		glScalef(0.1,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,0.1,0);
		//------------Right Front Leg------------
		glPushMatrix();
		glTranslated(-0.05,-0.05,0);
		glScalef(0.3,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.05,0.1,0);
		glScalef(0.1,0.2,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.15,0.05,0);
		glScalef(0.1,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,-0.2,0);
		//---------Right Back Leg------------
		glPushMatrix();
		glTranslated(-0.05,0.05,0);
		glScalef(0.3,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.05,-0.15,0);
		glScalef(0.1,0.3,1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.15,-0.15,0);
		glScalef(0.1,0.1,1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}