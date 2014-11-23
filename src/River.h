#ifndef RIVER_H
#define RIVEr_H
#include "StaticObject.h"

class River : public StaticObject {
private:
	GLuint _texture;
public:
	River();
	River(double x,double y,double z, GLuint texture);
	~River();
	void draw();
	void drawSquareTex();
};
#endif