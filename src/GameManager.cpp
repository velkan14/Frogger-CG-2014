#include "GameManager.h"


GameManager::GameManager() {
	_cameras = new OrthogonalCamera(-10, 10, 0, 14, -1, 10);
	
	//_cameras = new PerspectiveCamera(65, 1, 1, 20); 

	_game_objects = * new std::vector<GameObject *>;
	t_act=0; 
	t_ant=0;
}

GameManager::~GameManager() {
}

void GameManager::display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//Por cada objecto fazer draw!!! :D
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	(*_cameras).computeVisualizationMatrix();

	for(GameObject * g : _game_objects){
		glPushMatrix();
		//std::cout << (g->getPosition()->getX()) << "  " << g->getPosition()->getY() << std::endl;
		glTranslated(g->getPosition()->getX(),g->getPosition()->getY(),g->getPosition()->getZ());
		//glTranslated(5,3,0);
		g->draw();
		glPopMatrix();

	
	}

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
	(*_cameras).reshape(w,h);
}

void GameManager::keyPressed(unsigned char key) {
	//std::cout << "in " << key << std::endl;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	(*_cameras).computeProjectionMatrix();
	if(key == 'a' || key == 'A') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, -0.006, 0));
		//frogger->setSpeed(0,-0.01,0);
	}//Down
	else if (key == 'o' || key == 'O') {
		//std::cout << "o" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.007,0,0));
		//frogger->setSpeed(-0.01,0,0);
	}//Esquerda
	else if (key == 'p' || key == 'P'){
		//std::cout << "p" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.007,0,0));
		//frogger->setSpeed(0.01,0,0);
	} //Direita
	else if (key == 'q' || key == 'Q'){
		//std::cout << "q" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0,0.006,0));
		//frogger->setSpeed(0,0.01,0);
	} //Cima
}


void GameManager::keyUp (unsigned char key) {  
	if (key == 'a' || key == 'A') {
		//std::cout << "a" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, 0.006, 0));
	}//Down
	else if (key == 'o' || key == 'O') {
		//std::cout << "o" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.007,0,0));
	}//Esquerda
	else if (key == 'p' || key == 'P'){
		//std::cout << "p" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.007,0,0));
	} //Direita
	else if (key == 'q' || key == 'Q'){
		//std::cout << "q" << std::endl;
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0,-0.006,0));
	} //Cima


}  




void GameManager::onTimer() {
	t_act = glutGet(GLUT_ELAPSED_TIME);
	//std::cout << "onTimer"<< std::endl;
	this->update(t_act - t_ant);
	t_ant = t_act;
}

void GameManager::idle() {
}

void GameManager::update(double delta_t) {
	//std::cout << "update"<< std::endl;
	/*for(GameObject * g : _game_objects){
		g->update(delta_t);
	}*/
	frogger->update(delta_t);

}

void GameManager::init() {
	frogger = new Frog(0,0.5,0.5);
	_game_objects.push_back(new Road(0,0,0));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0));
	_game_objects.push_back(new Riverside(0,0,0));
	_game_objects.push_back(new TimberLog(-2,10.5,0.5));
	_game_objects.push_back(new Car(2,3.5,0.5));
	_game_objects.push_back(frogger);
}