#include "Camera.h"

Camera::Camera(double near, double far){
	_near = near;
	_far = far;
}

Camera::~Camera() {
}

void Camera::update(Vector3 frog_pos) {
}

void Camera::computeProjectionMatrix() {
}

void Camera::computeVisualizationMatrix() {
}

void Camera::reshape(GLsizei w, GLsizei h) {
	_aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	computeProjectionMatrix();
}