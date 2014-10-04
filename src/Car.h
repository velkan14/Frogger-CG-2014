#ifndef CAR_H
#define CAR_H
#include "DynamicObject.h"

class Car : public DynamicObject {

public:
	Car();
	~Car();
	void draw();
};
#endif