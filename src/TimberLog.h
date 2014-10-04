#ifndef TIMBERLOG_H
#define TIMBERLOG_H
#include "DynamicObject.h"

class TimberLog : public  DynamicObject {

public:
	TimberLog();
	~TimberLog();
	void draw();
};
#endif