#include "Frog.h"


Frog::Frog() {
}

Frog::Frog(double x, double y, double z):DynamicObject(x,y,z){
	_x = .5;
	_y = .5;
	_car = 0;
	_log = 0;
}

Frog::~Frog() {
}

/*void DynamicObject::update(double delta_t){
	//setPosition(getPosition() + getSpeed()*delta_t);
}*/

double Frog::checkPositionX(double x) {
	if(x > 9.5) return 9.5;
	else if (x <-9.5) return -9.5;
	return x;
}

double Frog::checkPositionY(double y){
	if(y > 13.5) return 13.5;
	else if (y<0.5) return 0.5;
	return y;
}

void Frog::draw() {
	glPushMatrix();
	glTranslated(0, 0, 0.075);

		glPushMatrix();
		glTranslated(0, 0, 0.175);
		glColor3f(1., 0., 0.);
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
	
		glColor3f(0., 0.8, 0.);
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