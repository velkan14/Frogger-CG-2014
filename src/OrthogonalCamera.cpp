#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far):Camera(near,far){
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
}
	
OrthogonalCamera::~OrthogonalCamera() {

}

void OrthogonalCamera::update() {

}

void OrthogonalCamera::computeProjectionMatrix() {
	gluOrtho2D(_left, _right, _bottom, _top);
}

void OrthogonalCamera::computeVisualizationMatrix() {
	gluLookAt(0,0, 5, 0,0,-1, 0,1,0);
		/*_at.getX(), _at.getY(), _at.getZ(), 
		_up.getX(), _up.getY(), _up.getZ() );*/
}
