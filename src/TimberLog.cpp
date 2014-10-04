#include "TimberLog.h"

TimberLog::TimberLog() {
}

TimberLog::~TimberLog() {
}

void TimberLog::draw() {
	glColor3f(0.4f, 0.2f, 0.5f); //brown
	glPushMatrix();
	glScalef(3, 3, 1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(.1, .13, 30, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.75, 0, 0);
	glScalef(3, 3, 1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(.1, .13, 30, 100);
	glPopMatrix();
}