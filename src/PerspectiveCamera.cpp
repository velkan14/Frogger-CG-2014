#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar):Camera(zNear, zFar){
		_fovy = fovy;
		_aspect = aspect;
	}

	void PerspectiveCamera::update(){
		
	}
	void PerspectiveCamera::computeProjectionMatrix(){
		gluPerspective(_fovy, _aspect, _near, _far);
	}
	void PerspectiveCamera::computeVisualizationMatrix(){
		gluLookAt(0.0, 0, 5, 0, 0, 0, 0.0, 1.0, 0.0);
		//gluLookAt(-5,5,3,0,1,0,0,0,1);
		//gluLookAt(0,0,20, 0,0,0,0,0,1);
		//glRotated(-15,1,0,0);
	}
