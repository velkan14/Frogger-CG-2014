#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include "Camera.h"

class PerspectiveCamera : public Camera {

private:
	double _fovy, _eyeX, _eyeY, _eyeZ;

public:

	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, double eyeX, double eyeY, double eyeZ);
	~PerspectiveCamera();

	void update(Vector3 frog_pos);
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	
};

#endif