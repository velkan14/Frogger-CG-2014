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
		//gluLookAt();
	}
