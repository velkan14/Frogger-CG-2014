#include "Camera.h"

Camera::Camera(double near, double far){
}

Camera::~Camera() {
}

void Camera::update() {
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