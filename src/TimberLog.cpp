#include "TimberLog.h"

TimberLog::TimberLog() {
}

TimberLog::TimberLog(double x, double y, double z):DynamicObject(x,y,z){
	_x = 1.5;
	_y = .5;
	_log=0;
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

double TimberLog::checkPositionX(double x, double pos, double speed) {
	if (x > 16) {
		this->setSpeed(Vector3(speed, 0, 0));
		return pos;
	}
	return x;
}

double TimberLog::checkPositionY(double y){
	return y;
}
