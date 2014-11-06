#include "Car.h"

Car::Car() {
}

Car::Car(double x,double y,double z):DynamicObject(x,y,z){
	_x = 1.1;
	_y = 0.54;
}

Car::~Car() {
}


double Car::checkPositionX(double x, double pos, double speed) {
	if (x > 16){
		this->setSpeed(Vector3(speed, 0, 0));
		return pos;
	}
	return x;
}

double Car::checkPositionY(double y){
	return y;
}


void Car::draw() {

	computeHexagonVertices();
	glPushMatrix();
	glScaled(.25, .2, .25);

	//Central Piece
	glPushMatrix();
	glTranslated(0, 0, 1.5);
	glScaled(4, 2, .5);
	drawCube();
	glPopMatrix();
	//Roof
	glPushMatrix();
	glTranslated(-1.5, 0, 2);
	glScaled(2.5, 1, 1.4);
	glRotated(90, 0, 0, 1);
	drawTrapezoidalPrism();
	glPopMatrix();
	//Hood
	glPushMatrix();
	glTranslated(2.5, 0, 2);
	glScaled(1.5, 1, .5);
	glRotated(90, 0, 0, 1);
	drawTrapezoidalPrism();
	glPopMatrix();
	//Under Piece
	glPushMatrix();
	glTranslated(0, 0, 1);
	glScaled(4, 1, -0.2);
	glRotated(90, 0, 0, 1);
	drawTrapezoidalPrism();
	glPopMatrix();
	//Right Rear Wheel
	glPushMatrix();
	glTranslated(-2.7, -2, getHexagonY(1) + 0.05);
	glRotated(90, 1, 0, 0);
	glScaled(1, 1, .6);
	drawHexagonPrism();
	glPopMatrix();
	//Left Rear Wheel
	glPushMatrix();
	glTranslated(-2.7, 2, getHexagonY(1) + 0.05);
	glRotated(-90, 1, 0, 0);
	glScaled(1, 1, .6);
	drawHexagonPrism();
	glPopMatrix();
	//Right Front Wheel
	glPushMatrix();
	glTranslated(2.7, -2, getHexagonY(1) + 0.05);
	glRotated(90, 1, 0, 0);
	glScaled(1, 1, .5);
	drawHexagonPrism();
	glPopMatrix();
	//Left Front Wheel
	glPushMatrix();
	glTranslated(2.7, 2, getHexagonY(1) + 0.05);
	glRotated(-90, 1, 0, 0);
	glScaled(1, 1, .5);
	drawHexagonPrism();
	glPopMatrix();
	//Front Up Grille
	glPushMatrix();
	glTranslated(4, 0, 1.95);
	glScaled(.05, 2, .05);
	drawCube();
	glPopMatrix();
	//Front Down Grille
	glPushMatrix();
	glTranslated(4, 0, 1.1);
	glScaled(.05, 2, .05);
	drawCube();
	glPopMatrix();
	//Right Front Light
	glPushMatrix();
	glTranslated(4, -1.2, 1.55);
	glRotated(90, 0, 1, 0);
	glScaled(.4, .4, .1);
	drawHexagonPrism();
	glPopMatrix();
	//Left Front Light
	glPushMatrix();
	glTranslated(4, 1.2, 1.55);
	glRotated(90, 0, 1, 0);
	glScaled(.4, .4, .1);
	drawHexagonPrism();
	glPopMatrix();
	//Spare Wheel
	glPushMatrix();
	glTranslated(-4, 0, 1.9);
	glRotated(90, 1, 0, 0);
	glRotated(-90, 0, 1, 0);
	glScaled(.8, .8, .5);
	drawHexagonPrism();
	glPopMatrix();

	glPopMatrix();
}

	//glPushMatrix();
	//glTranslatef(0, 0, 0.375);
	//
	//glColor3f(0., 0., 0.);
	////carbody
	//glPushMatrix();
	//glScalef(.8, .8, .6);
	//glutSolidCube(1);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.4, 0, -.15);
	////hood + front wheels
	//glPushMatrix();
	//glTranslatef(-.25, 0, 0);
	//glScalef(.5, .6, .3);
	//glutSolidCube(1);
	//glPopMatrix();
	//glColor3f(0.25f, 0.25f, 0.25f);
	//glPushMatrix();
	//glTranslatef(-.25, .4, 0);
	//glRotatef(-45.0, 0.0, 1.0, 0.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0);
	//glutSolidTorus(.1, .13, 5, 5);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(-.25, -0.4, 0);
	//glRotatef(-45.0, 0.0, 1.0, 0.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0);
	//glutSolidTorus(0.1, .13, 5, 5);
	//glPopMatrix();

	//glPopMatrix();

	//glColor3f(0., 0., 0.);
	//glPushMatrix();
	//glTranslatef(.4, 0, -.15);
	////back + back wheels
	//glPushMatrix();
	//glTranslatef(.25, 0, 0);
	//glScalef(.5, .6, .3);
	//glutSolidCube(1);
	//glPopMatrix();
	//glColor3f(0.25f, 0.25f, 0.25f);
	//glPushMatrix();
	//glTranslatef(.25, .4, 0);
	//glRotatef(-45.0, 0.0, 1.0, 0.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0);
	//glutSolidTorus(.1, .13, 5, 5);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(.25, -.4, 0);
	//glRotatef(-45.0, 0.0, 1.0, 0.0);
	//glRotatef(-90.0, 1.0, 0.0, 0.0);
	//glutSolidTorus(.1, .13, 5, 5);
	//glPopMatrix();
	//glPopMatrix();
	//glPopMatrix();