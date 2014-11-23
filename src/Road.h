#ifndef ROAD_H
#define ROAD_H
#include "StaticObject.h"

class Road : public StaticObject {
private:
	GLuint _texture;
public:
	Road();
	Road(double x,double y,double z, GLuint texture);
	~Road();
	void draw();
	void drawSquareTex();
};

#endif