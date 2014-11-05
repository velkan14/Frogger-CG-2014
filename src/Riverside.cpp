#include "Riverside.h"

Riverside::Riverside(){
}

Riverside::Riverside(double x,double y,double z):StaticObject(x,y,z){}

Riverside::~Riverside(){
}

void Riverside::draw(){

	GLfloat mat_ambient[] = { .3, 1, .4, 1 };
	GLfloat mat_diffuse[] = { .1, .8, .1, 1 };
	GLfloat mat_specular[] = { 0, .3, 0, 1 };
	GLfloat mat_shininess[] = { 5 };

	glColor3f(0.0f, 1.0f, 0.0f); //green
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

	/*glPushMatrix();
	glTranslatef(0, 7.5, 0);
	glScalef(20, 1, 1);
	glutSolidCube(1);
	glTranslated(0, 6, 0);
	glutSolidCube(1);
	glPopMatrix();*/
}