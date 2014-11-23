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

double getHexagonX(int vertex){
	return hexagonX[vertex];
}

double getHexagonY(int vertex){
	return hexagonY[vertex];
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

	//glBindTexture(GL_TEXTURE_2D,)
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glTexCoord2f(1, 0);
	glVertex3d(1, 0, 0);
	glTexCoord2f(1,1);
	glVertex3d(1, 1, 0);
	glTexCoord2f(0, 1);
	glVertex3d(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3d(0, 0, 0);
	glEnd();
}