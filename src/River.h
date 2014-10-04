#ifndef RIVER_H
#define RIVEr_H
#include "StaticObject.h"

class River : public StaticObject {

public:
	River();
	River(double x,double y,double z);
	~River();
	void draw();
};
#endif