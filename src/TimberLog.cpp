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
	glTranslatef(0, 0, -.2);
	glScalef(3, 1, .6);
	glutSolidCube(1);
	glPopMatrix();
}