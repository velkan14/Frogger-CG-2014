#include "GL\glut.h"
GLUquadric * qobj;

void reshape1(int w, int h) {
	float xmin = -1., xmax = 3.,
		ymin = -2., ymax = 1.;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
}

void reshape2(int w, int h) {
	float xmin = -1., xmax = 3., ymin = -2., ymax = 1.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D(xmin - delta, xmax + delta, ymin, ymax);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D(xmin, xmax, ymin - delta, ymax + delta);
	}
}

void reshape3(int w, int h) {
	float xmin = -1., xmax = 3., ymin = -2., ymax = 1.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D(xmin - delta, xmax + delta, ymin, ymax);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D(xmin, xmax, ymin - delta, ymax + delta);
	}
}

float xmin = -1., xmax = 3., ymin = -2., ymax = 1.;
float xscale = (xmax - xmin) / 480, yscale = (ymax - ymin) / 360;
void reshape4(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float c = (xmax + xmin) * .5;
	xmax = c + xscale * w * .5;
	xmin = c - xscale * w * .5;
	c = (ymax + ymin) * .5;
	ymax = c + yscale * h * .5;
	ymin = c - yscale * h * .5;
	gluOrtho2D(xmin, xmax, ymin, ymax);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0., 0., 0.);
	glBegin(GL_POLYGON);
	glVertex2f(-0.8, -1.0);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, 0.8);
	glVertex2f(-0.8, 0.8);
	glEnd();
	glPushMatrix();
	glTranslatef(2., -1., 0.);
	gluDisk(qobj, 0., 0.75, 96, 5);
	glPopMatrix();
	glFlush();
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(480, 360);
	glutCreateWindow("Windows & Viewports l");
	glutReshapeFunc(reshape4);
	glutDisplayFunc(display);
	glClearColor(1., 1., 1., 0.);
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GL_FILL);
	glutMainLoop();
	return 0;
}