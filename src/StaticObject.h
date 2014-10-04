#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "GameObject.h"

class StaticObject : public GameObject {

public:
	StaticObject();
	StaticObject(double x,double y,double z);
	virtual ~StaticObject() = 0;
};

#endif