#include "River.h"

River::River(){
}

River::River(double x,double y,double z):StaticObject(x,y,z){}

River::~River(){
}

void River::draw(){

	GLfloat mat_ambient[] = { .1, .3, .5, 1 };
	GLfloat mat_diffuse[] = { .4, .5, 1, 1 };
	GLfloat mat_specular[] = { .1, .2, .4, 1 };
	GLfloat mat_shininess[] = { 100 };

	glColor3f(0.0f, 0.0f, 1.0f); //blue
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	
	glTranslated(-10, 8, 0);
	
	for (int x = 0; x < 40; x++){
		for (int y = 0; y < 10; y++){
			glPushMatrix();
			glScalef(.5,.5,1);
			drawSquare();
			glPopMatrix();
			glTranslated(0, 0.5, 0);
		}
		glTranslated(0.5, -5, 0);
	}
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(0, 10.5, 0);
	glScalef(20, 5, 1);
	glutSolidCube(1);
	glPopMatrix();*/
}
