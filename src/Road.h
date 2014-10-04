#ifndef ROAD_H
#define ROAD_H
#include "StaticObject.h"

class Road : public StaticObject {

public:
	Road();
	Road(double x,double y,double z);
	~Road();
	void draw();
};

#endif