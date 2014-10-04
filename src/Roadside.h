#ifndef ROADSIDE_H
#define ROADSIDE_H
#include "StaticObject.h"

class Roadside : public StaticObject {

public:
	Roadside();
	Roadside(double x,double y,double z);
	~Roadside();
	void draw();
};
#endif