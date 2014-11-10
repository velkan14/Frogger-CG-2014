#include "Lights.h"

Lights::Lights(){
	l0_x = -1;
	l0_y = -1;
	l0_z = 1;

	GLfloat model_amb[] = { .2, .2, .2, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_amb);

	this->setDirectional();
	this->setPointLights();
}

void Lights::setDirectional(){

	GLfloat l0_ambient[] = { .1, .1, .1, 1 };
	GLfloat l0_diffuse[] = { .8, .8, .8, 1 };
	GLfloat l0_specular[] = { 1, 1, 1, 1 };
	GLfloat l0_direction[] = { l0_x, l0_y, l0_z, 0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, l0_direction);
}

void Lights::setPointLights(){

	GLfloat l1_ambient[] = { .2, .2, .1, 1 };
	GLfloat l1_diffuse[] = { 1, 1, 1, 1 };
	GLfloat l1_specular[] = { 1, 1, 1, 1 };
	GLfloat a = 1, b = 0.1, c = 0.01;
	GLfloat spot_cutoff = 25, spot_exponent = 50;

	GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };
	GLfloat l1_position[] = { -5.5, .5, 8, 1 };
	GLfloat l2_position[] = { 5.5, .5, 8, 1 };
	GLfloat l3_position[] = { -4, 7, 8, 1 };
	GLfloat l4_position[] = { 4, 7, 8, 1 };
	GLfloat l5_position[] = { -5.5, 13.5, 8, 1 };
	GLfloat l6_position[] = { 5.5, 13.5, 8, 1 };

	//Spotlight 1
	glLightfv(GL_LIGHT1, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT1, GL_POSITION, l1_position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	//Spotlight 2
	glLightfv(GL_LIGHT2, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT2, GL_POSITION, l2_position);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
	//Spotlight 3
	glLightfv(GL_LIGHT3, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT3, GL_POSITION, l3_position);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
	//Spotlight 4
	glLightfv(GL_LIGHT4, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT4, GL_POSITION, l4_position);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction);
	//Spotlight 5
	glLightfv(GL_LIGHT5, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT5, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT5, GL_POSITION, l5_position);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spot_direction);
	//Spotlight 6
	glLightfv(GL_LIGHT6, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT6, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT6, GL_POSITION, l6_position);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spot_direction);
}

void Lights::setHeadlight(){

	GLfloat l7_position[] = { -5.5, .5, 8, 1 };
	GLfloat l1_ambient[] = { .2, .2, .1, 1 };
	GLfloat l1_diffuse[] = { 1, 1, 1, 1 };
	GLfloat l1_specular[] = { 1, 1, 1, 1 };
	GLfloat a = 1, b = 0.1, c = 0.01;
	GLfloat spot_cutoff = 25, spot_exponent = 2;
	GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };


	glLightfv(GL_LIGHT7, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT7, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, b);
	glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, c);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(GL_LIGHT7, GL_POSITION, l7_position);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spot_direction);



}