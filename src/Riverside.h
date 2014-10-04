#ifndef RIVERSIDE_H
#define RIVERSIDE_H
#include "StaticObject.h"

class Riverside : public StaticObject {

public:
	Riverside();
	Riverside(double x,double y,double z);
	~Riverside();
	void draw();
};
#endif