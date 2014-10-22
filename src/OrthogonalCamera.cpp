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

	//glOrtho(_left, _right, _bottom, _top, _near, _far);
	_ratio = (_right - _left) / (_top- _bottom);
	if (_ratio < _aspect)
	{
		float delta = ((_top - _bottom) * _aspect - (_right - _left)) / 2;
		glOrtho(_left - delta, _right + delta, _bottom, _top, _near, _far);
	}
	else
	{
		float delta = ((_right - _left) / _aspect - (_top - _bottom)) / 2;
		glOrtho(_left, _right, _bottom - delta, _top + delta, _near, _far);
	}
}

void OrthogonalCamera::computeVisualizationMatrix() {
	gluLookAt(0, 0, 5, 0, 0, -1, 0, 1, -1);
		/*_at.getX(), _at.getY(), _at.getZ(), 
		_up.getX(), _up.getY(), _up.getZ() );*/
}
