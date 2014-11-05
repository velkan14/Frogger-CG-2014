#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "Lights.h"
#include "Frog.h"
#include "Car.h"
#include "River.h"
#include "Road.h"
#include "TimberLog.h"
#include "Roadside.h"
#include "Riverside.h"
#include "border.h"


class GameManager {


private:
	std::vector<GameObject *> _game_objects;
	std::vector<Camera *> _cameras;
	std::vector<Car *> _cars;
	std::vector<TimberLog *> _logs;

	Frog * frogger;
	Lights * gameLights;
	int active_camera;
	int _w, _h;
	double t_act, t_ant;
	int t_speed, t_aux;
	double minspeed, maxspeed;

public:
	GameManager();
	~GameManager();

	void display();

	void reshape(GLsizei w, GLsizei h);

	void keyPressed(unsigned char key);

	void keyUp(unsigned char key);

	void onTimer();

	void idle();

	void update(double delta_t);

	void init();

	void collisionCar(Car * car);
	void collisionTimberLog(TimberLog * log, int i);

	double randomPosition();
	double randomSpeed();
};

#endif