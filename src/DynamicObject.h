#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "GameObject.h"

class DynamicObject : public GameObject {

protected:
	Vector3 * _speed;


public:
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double _x;
	double _y;


	DynamicObject();
	DynamicObject(double  x, double y, double z);
	~DynamicObject();

	void update(double delta_t, double pos, double speed);
	double virtual checkPositionX(double x, double pos, double speed);
	double virtual checkPositionY(double y);
	void setSpeed(const Vector3 & speed);
	void setSpeed(double x, double y, double z);

	Vector3 * getSpeed();

};
#endif