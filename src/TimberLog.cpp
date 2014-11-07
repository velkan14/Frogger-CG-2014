#include "TimberLog.h"

TimberLog::TimberLog() {
}

TimberLog::TimberLog(double x, double y, double z):DynamicObject(x,y,z){
	_x = 1.5;
	_y = .55;
	_log=0;
}

TimberLog::~TimberLog() {
}

void TimberLog::draw() {

	GLfloat mat_ambient[] = { .8, .6, .5, 1 };
	GLfloat mat_diffuse[] = { .5, .2, .1, 1 };
	GLfloat mat_specular[] = { .3, .2, .1, 1 };
	GLfloat mat_shininess[] = { 5 };

	glColor3f(0.6f, 0.29f, 0); //brown
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslated(-1, 0, -0.43);
	for (int x = 0; x < 3; x++){
		glPushMatrix();
		glScaled(.5, .55, .5);
		drawCube();
		glPopMatrix();
		glTranslated(1, 0, 0);
	}
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(0, 0, -.2);
	glScalef(3, 1, .6);
	glutSolidCube(1);
	glPopMatrix();*/
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
