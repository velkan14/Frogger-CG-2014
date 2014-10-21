#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"


class Camera : public Entity {

protected:
	Vector3 _up;
	Vector3 _at;
	double _near;
	double _far;
	double _aspect; 


public:
	Camera(double near, double far);
	~Camera();

	void virtual update();

	void virtual computeProjectionMatrix();

	void virtual computeVisualizationMatrix();

	void reshape(GLsizei w, GLsizei h);
};

#endif