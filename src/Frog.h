#ifndef FROG_H
#define FROG_H
#include "DynamicObject.h"


class Frog : public DynamicObject {

public:
	int _car;
	int _log;
	Frog();
	Frog(double x, double y, double z);
	~Frog();
	void draw();
	double checkPositionX(double x);
	double checkPositionY(double y);

};

#endif