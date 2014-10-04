#include "River.h"

River::River(){
}

River::~River(){
}

void River::draw(){

	glColor3f(0.0f, 0.0f, 1.0f); //blue
	glPushMatrix();
	glTranslatef(0, 10.5, 0);
	glScalef(14, 5, 0);
	glutSolidCube(1);
	glPopMatrix();

}
