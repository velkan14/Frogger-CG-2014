#ifndef BORDER_H
#define BORDER_H
#include "StaticObject.h"

class border : public StaticObject {

public:
	border();
	border(double x, double y, double z);
	~border();
	void draw();
};
#endif