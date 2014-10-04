#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "GameObject.h"

class StaticObject : public GameObject {

public:
	StaticObject();
	virtual ~StaticObject() = 0;
};

#endif