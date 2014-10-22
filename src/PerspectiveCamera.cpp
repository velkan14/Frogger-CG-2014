#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar):Camera(zNear, zFar){
		_fovy = fovy;
		_aspect = aspect;
	}

	void PerspectiveCamera::update(){
		
	}
	void PerspectiveCamera::computeProjectionMatrix(){
		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();*/
		gluPerspective(_fovy, _aspect, _near, _far);
		//gluPerspective(60, _aspect, 1.5, 20);
	}
	void PerspectiveCamera::computeVisualizationMatrix(){
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		gluLookAt(0, 0, 10, 0, 7, -5, 0, 1, 0);
		glRotatef(-10, 1, 0, 0);
		//gluLookAt(-5,5,3,0,1,0,0,0,1);
		//gluLookAt(0,0,20, 0,0,0,0,0,1);
		//glRotated(-15,1,0,0);
	}
