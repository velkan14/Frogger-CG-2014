#ifndef TIMBERLOG_H
#define TIMBERLOG_H
#include "DynamicObject.h"

class TimberLog : public  DynamicObject {

public:
	int _log;
	TimberLog();
	TimberLog(double x,double y,double z);
	~TimberLog();
	void draw();
	double checkPositionX(double x, double pos, double speed);
	double checkPositionY(double y);
};
#endif