#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, double eyeX, double eyeY, double eyeZ):Camera(zNear, zFar){
		_fovy = fovy;
		_aspect = aspect;
			_eyeX = eyeX;
		_eyeY = eyeY;
		_eyeZ = eyeZ;
	}

	void PerspectiveCamera::update(Vector3 frog_pos){
		_eyeX = frog_pos.getX();
		_eyeY = frog_pos.getY() - 2;		
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
		gluLookAt(_eyeX, _eyeY, _eyeZ, (0 + _eyeX), (7 + _eyeY), (1 - _eyeZ), 0, 1, 0);
		//gluLookAt(-5,5,3,0,1,0,0,0,1);
		//gluLookAt(0,0,20, 0,0,0,0,0,1);
		//glRotated(-15,1,0,0);
	}
