#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include "OrthogonalCamera.h"
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
	Camera * _cameras;

public:
	GameManager();
	~GameManager();

	void display();

	void reshape(GLsizei w, GLsizei h);

	void keyPressed();

	void onTimer();

	void idle();

	void update();

	void init();
};

#endif