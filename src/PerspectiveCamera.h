#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include "Camera.h"

class PerspectiveCamera : public Camera {

private:
	double _fovy;

public:

	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
	~PerspectiveCamera();

	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	
};
#endif