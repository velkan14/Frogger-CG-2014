#include "Lights.h"

Lights::Lights(){
	l0_x = -1;
	l0_y = -1;
	l0_z = 1;

	this->setLighting();
	this->setDirectional();
	//this->setPointLights();
	glEnable(GL_LIGHT0);
}

void Lights::setDirectional(){
	GLfloat l0_direction[] = { l0_x, l0_y, l0_z, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, l0_direction);
}

void Lights::setPointLights(){
	GLfloat l1_position[] = { -8, .5, 6, 1 };
	glLightfv(GL_LIGHT1, GL_POSITION, l1_position);

	GLfloat l2_position[] = { 8, .5, 6, 1 };
	glLightfv(GL_LIGHT2, GL_POSITION, l2_position);

	GLfloat l3_position[] = { -8, 7, 6, 1 };
	glLightfv(GL_LIGHT3, GL_POSITION, l3_position);

	GLfloat l4_position[] = { 8, 7, 6, 1 };
	glLightfv(GL_LIGHT4, GL_POSITION, l4_position);

	GLfloat l5_position[] = { -8, 13.5, 6, 1 };
	glLightfv(GL_LIGHT5, GL_POSITION, l5_position);

	GLfloat l6_position[] = { 8, 13.5, 6, 1 };
	glLightfv(GL_LIGHT6, GL_POSITION, l6_position);
}

void Lights::setLighting(){
	GLfloat model_amb[] = { .2, .2, .2, 1 };
	GLfloat l0_ambient[] = { .1, .1, .1, 1 };
	GLfloat l0_diffuse[] = { .2, .2, .2, 1 };
	GLfloat l0_specular[] = { .1, .1, .1, 1 };
	GLfloat l1_ambient[] = { .2, .2, .2, 1 };
	GLfloat l1_diffuse[] = { .5, .5, .5, 1 };
	GLfloat l1_specular[] = { .75, .75, .75, 1 };
	GLfloat a = 1, b = 0.3;

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_amb);

	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_specular);

	/*glLightfv(GL_LIGHT1, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, b);

	glLightfv(GL_LIGHT2, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, b);

	glLightfv(GL_LIGHT3, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, b);

	glLightfv(GL_LIGHT4, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, b);
	
	glLightfv(GL_LIGHT5, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT5, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, b);
	
	glLightfv(GL_LIGHT6, GL_AMBIENT, l1_ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, l1_diffuse);
	glLightfv(GL_LIGHT6, GL_SPECULAR, l1_specular);
	glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, a);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, b);*/
}