#include "Riverside.h"

Riverside::Riverside(){
}

Riverside::Riverside(double x,double y,double z):StaticObject(x,y,z){}

Riverside::~Riverside(){
}

void Riverside::draw(){

	//Light Green
	GLfloat mat_ambient[] = { .3, 1, .4, 1 };
	GLfloat mat_diffuse[] = { .1, .8, .1, 1 };
	GLfloat mat_specular[] = { 0, .3, 0, 1 };
	GLfloat mat_shininess[] = { 5 };
	//Dark Green
	GLfloat mat_ambient2[] = { .1, .6, .1, 1 };
	GLfloat mat_diffuse2[] = { .1, .5, .1, .5 };
	GLfloat mat_specular2[] = { 0, 0, 0, 1 };
	GLfloat mat_shininess2[] = { 5 };

	glColor3f(0.0f, 1.0f, 0.0f); //Green
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslated(-10, 7, 0);
	for (int x = 0; x < 20; x++){
		drawSquare();
		glTranslated(0, 6, 0);
		drawSquare();
		glTranslated(1, -6, 0);
	}
	glPopMatrix();

	glColor3f(0, .6, 0); //Dark Green
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

	glPushMatrix();
	glTranslated(-10, 7.9, .01);
	for (int x = 0; x < 20; x++){
		for (int y = 0; y < 2; y++){
			glPushMatrix();
			glScaled(1, .1, 0);
			drawSquare();
			glPopMatrix();
			glTranslated(0, 5.05, 0);
		}
		glTranslated(1, -10.1, 0);
	}
	glPopMatrix();
}