#include "Road.h"

Road::Road(){
}

Road::Road(double x,double y,double z):StaticObject(x,y,z){}

Road::~Road(){
}

void Road::draw(){
	GLfloat mat_ambient1[] = { .3, .3, .3, 1 };
	GLfloat mat_diffuse1[] = { .05, .05, .05, 0 };
	GLfloat mat_specular1[] = { .05, .05, .05, 1 };
	GLfloat mat_shininess1[] = { 5 };
	GLfloat mat_ambient2[] = { 1, 1, 1, 1 };
	GLfloat mat_diffuse2[] = { .9, .9, .9, 1 };
	GLfloat mat_specular2[] = { .8, .8, .8, 1 };
	GLfloat mat_shininess2[] = { 20 };

	glColor3f(0.5f, 0.5f, 0.5f); //gray
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

	//Main block
	glPushMatrix();
	glTranslated(-10, 1, 0);
	for (int x = 0; x < 20; x++){
		for (int y = 0; y < 5; y++){
			drawSquare();
			glTranslated(0, 1, 0);
		}
		glTranslated(1, -5, 0);
	}
	glPopMatrix();

	glColor3f(1, 1, 1); //white
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

	//Center stripes
	glPushMatrix();
	glTranslated(-9.5, 2.25, .005);
	for (int x = 0; x < 10; x++){
		for (int y = 0; y < 3; y++){
			glPushMatrix();
			glScaled(1, .1, 0);
			drawSquare();
			glPopMatrix();
			glTranslated(0, 1.25, 0);
		}
		glTranslated(2, -3.75, 0);
	}
	glPopMatrix();

	//Roadside Stripes
	glPushMatrix();
	glTranslated(-10, 1, .005);
	for (int x = 0; x < 20; x++){
		for (int y = 0; y < 2; y++){
			glPushMatrix();
			glScaled(1, .1, 0);
			drawSquare();
			glPopMatrix();
			glTranslated(0, 5, 0);
		}
		glTranslated(1, -10, 0);
	}
	glPopMatrix();
}