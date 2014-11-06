#include "Roadside.h"

Roadside::Roadside(){
}

Roadside::Roadside(double x,double y,double z):StaticObject(x,y,z){}

Roadside::~Roadside(){
}

void Roadside::draw(){

	GLfloat mat_ambient[] = { .6, .6, .6, 1 };
	GLfloat mat_diffuse[] = { .2, .2, .2, .5 };
	GLfloat mat_specular[] = { .25, .25, .25, 1 };
	GLfloat mat_shininess[] = { 80 };

	glColor3f(0.25f, 0.25f, 0.25f); //dark gray
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslated(-10, 0, 0);
	for (int x = 0; x < 20; x++){
		drawSquare();
		glTranslated(0, 6, 0);
		drawSquare();
		glTranslated(1, -6, 0);
	}
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(0, .5, 0);
	glScalef(20, 1, 1);
	glutSolidCube(1);
	glTranslated(0, 6, 0);
	glutSolidCube(1);
	glPopMatrix();*/
}