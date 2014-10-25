#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "Frog.h"
#include "Car.h"
#include "River.h"
#include "Road.h"
#include "TimberLog.h"
#include "Roadside.h"
#include "Riverside.h"


class Camera;
class GameObject;

class GameManager {


private:
	std::vector<GameObject *> _game_objects;
	std::vector<Camera *> _cameras;
	int active_camera;
	int _w, _h;
	Frog * frogger;
	Car * car;
	TimberLog * log;
	double t_act, t_ant;

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

	void collisionCar();
	void collisionTimberLog();
};

#endif