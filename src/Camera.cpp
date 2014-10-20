#include "Camera.h"

Camera::Camera(double near, double far){
	_at = * new Vector3(0,0,10);
	_up = * new Vector3(0,0,0);
}

Camera::~Camera() {
}

void Camera::update() {
}

void Camera::computeProjectionMatrix() {
}

void Camera::computeVisualizationMatrix() {
}