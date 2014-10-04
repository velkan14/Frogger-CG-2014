#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"


class Camera : public Entity {

protected:
	Vector3 _up;
	Vector3 _at;
	double _near;
	double _far;

public:
	Camera(double near, double far);
	~Camera();

	void update();

	void computeProjectionMatrix();

	void computeVisualizationMatrix();
};

#endif