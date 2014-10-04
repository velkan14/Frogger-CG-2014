#include "TimberLog.h"

TimberLog::TimberLog() {
}

TimberLog::TimberLog(double x, double y, double z):DynamicObject(x,y,z){
}

TimberLog::~TimberLog() {
}

void TimberLog::draw() {
	glColor3f(0.6f, 0.29f, 0); //brown
	glPushMatrix();
	glScalef(3, 3, 1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(.16, .3, 30, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.75, 0, 0);
	glScalef(3, 3, 1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(.16, .3, 30, 100);
	glPopMatrix();
}