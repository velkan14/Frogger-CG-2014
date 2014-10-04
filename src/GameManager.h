#include <GL\glut.h>
#include "OrthogonalCamera.h"
class Camera;
class GameObject;

class GameManager {

private:
	GameObject * _game_objects;
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