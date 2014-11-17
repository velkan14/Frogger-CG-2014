#ifndef LIGHTS_H
#define LIGHTS_H
#include "Frog.h"

class Lights {

private:
	double l0_x, l0_y, l0_z;

public:
	Lights();
	~Lights();

	void setDirectional();
	void setPointLights();
	void setHeadlight(Frog frogger);
};

#endif