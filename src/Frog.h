#ifndef FROG_H
#define FROG_H
#include "DynamicObject.h"


class Frog : public DynamicObject {

public:
	Frog();
	~Frog();
	void draw();
};

#endif