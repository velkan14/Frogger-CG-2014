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
	_ratio = (_right - _left) / (_top- _bottom);
	if (_ratio < _aspect)
	{
		float delta = ((_top - _bottom) * _aspect - (_right - _left)) / 2;
		gluOrtho2D(_left - delta, _right + delta, _bottom, _top);
	}
	else
	{
		float delta = ((_right - _left) / _aspect - (_top - _bottom)) / 2;
		gluOrtho2D(_left, _right, _bottom - delta, _top + delta);
	}
}

void OrthogonalCamera::computeVisualizationMatrix() {
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
		/*_at.getX(), _at.getY(), _at.getZ(), 
		_up.getX(), _up.getY(), _up.getZ() );*/
}
