#include "Car.h"

Car::Car() {
}

Car::Car(double x,double y,double z):DynamicObject(x,y,z){
	_x = 1.1;
	_y = 0.5;
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

	//Metallic Red
	GLfloat mat_ambient1[] = { .9, .2, .2, 1 };
	GLfloat mat_diffuse1[] = { 1, .1, .1, 1 };
	GLfloat mat_specular1[] = { .9, 0, 0, 1 };
	GLfloat mat_shininess1[] = { 120 };
	//Rubber Black
	GLfloat mat_ambient2[] = { .3, .3, .3, 1 };
	GLfloat mat_diffuse2[] = { .2, .2, .2, .5 };
	GLfloat mat_specular2[] = { .1, .1, .1, 1 };
	GLfloat mat_shininess2[] = { 5 };
	//Metallic Silver
	GLfloat mat_ambient3[] = { .7, .7, .7, 1 };
	GLfloat mat_diffuse3[] = { .3, .3, .3, 1 };
	GLfloat mat_specular3[] = { .7, .7, .7, 1 };
	GLfloat mat_shininess3[] = { 120 };
	//White Lights
	GLfloat mat_ambient4[] = { .9, .9, .5, 1 };
	GLfloat mat_diffuse4[] = { 1, .1, .1, 1 };
	GLfloat mat_specular4[] = { .4, .4, 0, 1 };
	GLfloat mat_shininess4[] = { 20 };
	GLfloat mat_emission4[] = { .5, .4, .1, 0 };

	computeHexagonVertices();
	glPushMatrix();
	glScaled(.25, .2, .25);

	glColor3f(1, 0, 0);//Red
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

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

	glColor3f(.1, .1, .1);//Black
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

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
	//Spare Wheel
	glPushMatrix();
	glTranslated(-4, 0, 1.9);
	glRotated(90, 1, 0, 0);
	glRotated(-90, 0, 1, 0);
	glScaled(.8, .8, .5);
	drawHexagonPrism();
	glPopMatrix();

	glColor3f(.7, .7, .7);//Silver
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess3);

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

	glColor3f(1, 1, 0);//Yellow
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse4);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular4);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess4);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission4);

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

	GLfloat default_emission[] = { 0, 0, 0, 1 };
	glMaterialfv(GL_FRONT, GL_EMISSION, default_emission);

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