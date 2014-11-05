#include <iostream>
#include "Draw.h"
#include <math.h>

#define PI 3.14159265

double hexagonX[6];
double hexagonY[6];

void computeHexagonVertices(){

	for (int i = 0; i < 6; i++){
		hexagonX[i] = cos((60 * i) * PI / 180.0);
		hexagonY[i] = sin((60 * i) * PI / 180.0);
		//std::cout << "<" << hexagonX[i] << "," << hexagonY[i] << ">" << std::endl;
	}
}

void drawHexagonPrism(){

	//Front
	glNormal3d(0, 0, -1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 0);
	}
	glEnd();

	//Back
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 1);
	}
	glEnd();

	//Sides
	for (int i = 0; i < 6; i++){
		glBegin(GL_QUADS);
		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 0);

		glNormal3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);
		glVertex3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);

		glNormal3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);
		glVertex3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 1);

		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 1);
		glEnd();
	}
}

void drawTrapezoidalPrism(){

	//Top
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(1, -1, 1);
	glEnd();

	//Bottom
	glBegin(GL_QUADS);
	glNormal3d(0, 0, -1);
	glVertex3d(2, 1, 0);
	glVertex3d(-2, 1, 0);
	glVertex3d(-2, -1, 0);
	glVertex3d(2, -1, 0);
	glEnd();

	//Front
	glBegin(GL_QUADS);
	glNormal3d(0, -1, 0);
	glVertex3d(1, -1, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-2, -1, 0);
	glVertex3d(2, -1, 0);
	glEnd();

	//Back
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-2, 1, 0);
	glVertex3d(2, 1, 0);
	glEnd();

	//Left
	glBegin(GL_QUADS);
	glNormal3d(-1, 0, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-2, 1, 0);
	glVertex3d(-2, -1, 0);
	glEnd();

	//Right
	glBegin(GL_QUADS);
	glNormal3d(1, 0, 1);
	glVertex3d(1, -1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(2, 1, 0);
	glVertex3d(2, -1, 0);
	glEnd();
}


void drawCube(){

	//Top
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(1, -1, 1);
	glEnd();

	//Bottom
	glBegin(GL_QUADS);
	glNormal3d(0, 0, -1);
	glVertex3d(1, 1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, -1, -1);
	glVertex3d(1, -1, -1);
	glEnd();

	//Front
	glBegin(GL_QUADS);
	glNormal3d(0, -1, 0);
	glVertex3d(1, -1, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, -1, -1);
	glVertex3d(1, -1, -1);
	glEnd();

	//Back
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);
	glVertex3d(1, 1, -1);
	glEnd();

	//Left
	glBegin(GL_QUADS);
	glNormal3d(-1, 0, 0);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);
	glEnd();

	//Right
	glBegin(GL_QUADS);
	glNormal3d(1, 0, 0);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 1, -1);
	glVertex3d(1, -1, -1);
	glVertex3d(1, -1, 1);
	glEnd();
}

void drawSquare(){

	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(0, 1, 0);
	glVertex3d(0, 0, 0);
	glEnd();
}


//void drawCar(){
//
//	//Central Piece
//	glPushMatrix();
//	glTranslated(0, 0, 1.5);
//	glScaled(4, 2, .5);
//	drawCube();
//	glPopMatrix();
//	//Roof
//	glPushMatrix();
//	glTranslated(-1.5, 0, 2);
//	glScaled(2.5, 1, 1.4);
//	glRotated(90, 0, 0, 1);
//	drawTrapezoidalPrism(1, 1);
//	glPopMatrix();
//	//Hood
//	glPushMatrix();
//	glTranslated(2.5, 0, 2);
//	glScaled(1.5, 1, .5);
//	glRotated(90, 0, 0, 1);
//	drawTrapezoidalPrism(1, 1);
//	glPopMatrix();
//	//Under Piece
//	glPushMatrix();
//	glTranslated(0, 0, 1);
//	glScaled(4, 1, -0.2);
//	glRotated(90, 0, 0, 1);
//	drawTrapezoidalPrism(1, 1);
//	glPopMatrix();
//	//Right Rear Wheel
//	glPushMatrix();
//	glTranslated(-2.7, -2, hexagonY[1] + 0.05);
//	glRotated(90, 1, 0, 0);
//	glScaled(1, 1, .6);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Left Rear Wheel
//	glPushMatrix();
//	glTranslated(-2.7, 2, hexagonY[1] + 0.05);
//	glRotated(-90, 1, 0, 0);
//	glScaled(1, 1, .6);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Right Front Wheel
//	glPushMatrix();
//	glTranslated(2.7, -2, hexagonY[1] + 0.05);
//	glRotated(90, 1, 0, 0);
//	glScaled(1, 1, .5);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Left Front Wheel
//	glPushMatrix();
//	glTranslated(2.7, 2, hexagonY[1] + 0.05);
//	glRotated(-90, 1, 0, 0);
//	glScaled(1, 1, .5);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Front Up Grille
//	glPushMatrix();
//	glTranslated(4, 0, 1.95);
//	glScaled(.05, 2, .05);
//	drawCube();
//	glPopMatrix();
//	//Front Down Grille
//	glPushMatrix();
//	glTranslated(4, 0, 1.1);
//	glScaled(.05, 2, .05);
//	drawCube();
//	glPopMatrix();
//	//Right Front Light
//	glPushMatrix();
//	glTranslated(4, -1.2, 1.55);
//	glRotated(90, 0, 1, 0);
//	glScaled(.4, .4, .1);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Left Front Light
//	glPushMatrix();
//	glTranslated(4, 1.2, 1.55);
//	glRotated(90, 0, 1, 0);
//	glScaled(.4, .4, .1);
//	drawHexagonPrism();
//	glPopMatrix();
//	//Spare Wheel
//	glPushMatrix();
//	glTranslated(-4, 0, 1.9);
//	glRotated(90, 1, 0, 0);
//	glRotated(-90, 0, 1, 0);
//	glScaled(.8, .8, .5);
//	drawHexagonPrism();
//	glPopMatrix();
//}