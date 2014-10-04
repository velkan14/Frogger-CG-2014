#include "Camera.h"

class OrthogonalCamera : Camera {

private:
	double _left;
	double _right;
	double _bottom;
	double _top;

public:
	OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
	~OrthogonalCamera();

	void update();

	void computeProjectionMatrix();

	void computeVisualizationMatrix();
};