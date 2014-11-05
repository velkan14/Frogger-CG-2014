#include "Car.h"

Car::Car() {
}

Car::Car(double x,double y,double z):DynamicObject(x,y,z){
	_x = .9;
	_y = .4;
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
	glutSolidTorus(.1, .13, 5, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-.25, -0.4, 0);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(0.1, .13, 5, 5);
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
	glutSolidTorus(.1, .13, 5, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.25, -.4, 0);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(.1, .13, 5, 5);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

//void Car::draw()
//{
//	glPushMatrix();
//	glTranslatef(0, 0, 1);
//	glScalef(3, 3, 3);
//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	
//	//Sides
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glBegin(GL_QUADS);			
//	glNormal3f(0.0, -1, 0.0);	
//	glVertex3f(.3, -.15, 0);
//	glVertex3f(-.2, -.15, 0);
//	glVertex3f(-.2, -.15, -.1);
//	glVertex3f(.3, -.15, -.1);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, 1.0, 0.0);
//	glVertex3f(.3, .15, 0);
//	glVertex3f(-.2, .15, 0);
//	glVertex3f(-.2, .15, -.1);
//	glVertex3f(.3, .15, -.1);
//	glEnd();
//
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, 1.0, 0.0);
//	glVertex3f(.1, .15, 0.05);
//	glVertex3f(-.2, .15, 0.05);
//	glVertex3f(-.2, .15, 0.0);
//	glVertex3f(.1, .15, 0.0);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, -.15, 0.05);
//	glVertex3f(-.2, -.15, 0.05);
//	glVertex3f(-.2, -.15, 0.0);
//	glVertex3f(.1, -.15,0.0);
//	glEnd();
//	
//	
//	//Capo
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.3, -.05, 0.0);
//	glVertex3f(.3, .05, 0.0);
//	glVertex3f(.1, .15, 0.05);
//	glVertex3f(.1, -.15, 0.05);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.3, 0.15, 0.0);
//	glVertex3f(.3, -0.15, 0.0);
//	glVertex3f(.3, -.15, -0.1);
//	glVertex3f(.3, .15, -0.1);
//	glEnd();
//	glColor3f(1.0f, 0.8f, 0.8f);
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, -0.15, 0.05);
//	glVertex3f(.1, -0.15, 0.0);
//	glVertex3f(.3, -.05, 0.0);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, 0.15, 0.05);
//	glVertex3f(.1, 0.15, 0.0);
//	glVertex3f(.3, .05, 0.0);
//	glEnd();
//	glColor3f(0.3f, 0.8f, 0.8f);
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, -0.15, 0.0);
//	glVertex3f(.3, -0.15, 0.0);
//	glVertex3f(.3, -.05, 0.0);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, 0.15, 0.0);
//	glVertex3f(.3, 0.15, 0.0);
//	glVertex3f(.3, .05, 0.0);
//	glEnd();
//	
//	//Vidro Front
//	glColor3f(0.0f, 0.0f, .5f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, .1, 0.15);
//	glVertex3f(.1, -.1, 0.15);
//	glVertex3f(.1, -.15, 0.05);
//	glVertex3f(.1, .15, 0.05);
//	glEnd();
//
//	//Copa Front
//	glColor3f(0.0f, 0.0f, .5f);
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(.1, -.1, 0.15);
//	glVertex3f(.1, 0.1, 0.15);
//	glVertex3f(.0, 0, 0.2);
//	glEnd();
//
//	//Copa Back
//	glColor3f(-1.0f, 0.0f, 0.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);
//	glVertex3f(-.2, .15, -0.1);
//	glVertex3f(-.2, .15, 0.05);
//	glVertex3f(-.2, -.15, 0.05);
//	glVertex3f(-.2, -.15, -0.1);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);//Normal não feita
//	glVertex3f(-.2, .15, 0.05);
//	glVertex3f(-.2, .1, 0.1);
//	glVertex3f(-.2, -.1, 0.1);
//	glVertex3f(-.2, -.15, 0.05);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glNormal3f(0.0, -1.0, 0.0);//Normal não feita
//	glVertex3f(-.2, .1, 0.1);
//	glVertex3f(-.1, 0, 0.2);
//	glVertex3f(-.2, -.1, 0.1);
//
//	glEnd();
//	//Copa
//	glColor3f(1.0f, 0.0f, 1.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);//Normal não feita
//	glVertex3f(.1, -.1, 0.15);
//	glVertex3f(-.2, -.1, 0.1);
//	glVertex3f(-.2, -.15, 0.05);
//	glVertex3f(.1, -.15, 0.05);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0); //Normal não feita
//	glVertex3f(.1, .1, 0.15);
//	glVertex3f(-.2, .1, 0.1);
//	glVertex3f(-.2, .15, 0.05);
//	glVertex3f(.1, .15, 0.05);
//	glEnd();
//
//	glColor3f(1.0f, 0.5f, 1.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);//Normal não feita
//	glVertex3f(0, 0, 0.2);
//	glVertex3f(-0.1, 0, 0.2);
//	glVertex3f(-.2, -.1, 0.1);
//	glVertex3f(.1, -.1, 0.15);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0, -1.0, 0.0);//Normal não feita
//	glVertex3f(0, 0, 0.2);
//	glVertex3f(-0.1, 0, 0.2);
//	glVertex3f(-.2, .1, 0.1);
//	glVertex3f(.1, .1, 0.15);
//	glEnd();
//
//
//	glutSwapBuffers();
//	glPopMatrix();
//}