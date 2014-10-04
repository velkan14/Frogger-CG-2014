#include "GameManager.h"


GameManager::GameManager() {
	_cameras = new OrthogonalCamera(-7.,7.,0.,14., 3., 3.);
	_game_objects = * new std::vector<GameObject *>;
}

GameManager::~GameManager() {
}

void GameManager::display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//Por cada objecto fazer draw!!! :D
	std::cout <<"cenas1";
	for(GameObject * g : _game_objects) g->draw();

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
	float xmin = -7., xmax = 7., ymin = 0., ymax = 14.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D(xmin - delta, xmax + delta, ymin, ymax);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D(xmin, xmax, ymin - delta, ymax + delta);
	}
}

void GameManager::keyPressed() {
}

void GameManager::onTimer() {
}

void GameManager::idle() {
}

void GameManager::update() {
}

void GameManager::init() {
	_game_objects.push_back(new Frog());
	_game_objects.push_back(new Road());
	_game_objects.push_back(new Roadside());
	_game_objects.push_back(new River());
	_game_objects.push_back(new Riverside());

	
	
}