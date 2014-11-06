#include "Frog.h"


Frog::Frog() {
}

Frog::Frog(double x, double y, double z):DynamicObject(x,y,z){
	_x = .45;
	_y = .45;
	_car = 0;
	_log = -1;
}

Frog::~Frog() {
}

double Frog::checkPositionX(double x, double pos, double speed) {
	if(x > 9.55) return 9.55;
	else if (x <-9.55) return -9.55;
	return x;
}

double Frog::checkPositionY(double y){
	if(y > 13.55) return 13.55;
	else if (y<0.45) return 0.45;
	return y;
}

void Frog::draw() {

	GLfloat mat_ambient1[] = { 1, .2, .2, 1 };
	GLfloat mat_diffuse1[] = { 1, .1, .1, 1 };
	GLfloat mat_specular1[] = { .7, 0, 0, 1 };
	GLfloat mat_shininess1[] = { 80 };
	GLfloat mat_ambient2[] = { .2, 1, .1, 1 };
	GLfloat mat_diffuse2[] = { .1, .7, .1, 1 };
	GLfloat mat_specular2[] = { 0, .2, 0, 1 };
	GLfloat mat_shininess2[] = { 5 };


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

	glPushMatrix();
	glScaled(.9, .9, .7);
	glPushMatrix();
	glTranslated(0, 0, 0.175);
	glColor3f(1., 0., 0.);//Red
		//Left Eye
		glPushMatrix();
		glTranslated(-0.25,0.25,0.1);
		glScalef(0.1,0.11, .1);
		glutSolidSphere(1,10,10);
		glPopMatrix();

		//Right Eye
		glPushMatrix();
		glTranslated(0.25,0.25,0.1);
		glScalef(0.1, 0.11, .1);
		glutSolidSphere(1,10,10);
		glPopMatrix();
	
		glColor3f(0., 0.8, 0.);//Green
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
		//Main Body
		glPushMatrix();
		glScalef(0.35, 0.45, .25);
		glutSolidSphere(1,10,10);
		glPopMatrix();
	glPopMatrix();
	

	glPushMatrix();
	glTranslated(-0.4,-0.2,0);
		//---------Left Back Leg------------
		//Rectangle Horizontal
		glPushMatrix();
		glTranslated(0.05,0.05,0);
		glScalef(0.3, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
		//Rectangle Vertical 
		glPushMatrix();
		glTranslated(-0.05,-0.15,0);
		glScalef(0.1, 0.3, .1);
		glutSolidCube(1);
		glPopMatrix();
		//Square
		glPushMatrix();
		glTranslated(-0.15,-0.15,0);
		glScalef(0.1, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.4,0.1,0);
		//------------Left Front Leg------------
		glPushMatrix();
		glTranslated(0.05,-0.05,0);
		glScalef(0.3, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.05,0.1,0);
		glScalef(0.1, 0.2, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-0.15,0.05,0);
		glScalef(0.1, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,0.1,0);
		//------------Right Front Leg------------
		glPushMatrix();
		glTranslated(-0.05,-0.05,0);
		glScalef(0.3, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.05,0.1,0);
		glScalef(0.1, 0.2, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.15,0.05,0);
		glScalef(0.1, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,-0.2,0);
		//---------Right Back Leg------------
		glPushMatrix();
		glTranslated(-0.05,0.05,0);
		glScalef(0.3, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.05,-0.15,0);
		glScalef(0.1, 0.3, .1);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0.15,-0.15,0);
		glScalef(0.1, 0.1, .1);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}