#include "Road.h"

Road::Road(){
}

Road::Road(double x,double y,double z):StaticObject(x,y,z){}

Road::~Road(){
}

void Road::draw(){
	GLfloat mat_ambient[] = { .2, .2, .2, 1 };
	GLfloat mat_diffuse[] = { 0, 0, 0, 0 };
	GLfloat mat_specular[] = { .5, .5, .5, 1 };
	GLfloat mat_shininess[] = { 40 };

	glColor3f(0.5f, 0.5f, 0.5f); //gray
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

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

	/*glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glScalef(20, 5, 1);
	glutSolidCube(1);
	glPopMatrix();*/
}