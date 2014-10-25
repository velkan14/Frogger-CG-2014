#include "GameManager.h"


GameManager::GameManager() {
	//_cameras = new OrthogonalCamera(-10, 10, 0, 14, -1, 10);
	
	//_cameras = new PerspectiveCamera(65, 1, 1, 20); 
	
	_game_objects = * new std::vector<GameObject *>;
	_cameras = *new std::vector <Camera *>;
	active_camera = 0;
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
	if (active_camera == 2){
		(*_cameras[active_camera]).update(*frogger->getPosition());
	}
	(*_cameras[active_camera]).computeVisualizationMatrix();

	for(GameObject * g : _game_objects){
		glPushMatrix();
		//std::cout << (g->getPosition()->getX()) << "  " << g->getPosition()->getY() << std::endl;
		glTranslated(g->getPosition()->getX(),g->getPosition()->getY(),g->getPosition()->getZ());
		g->draw();
		glPopMatrix();

	
	}

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
	_w = w;
	_h = h;
	(*_cameras[active_camera]).reshape(w, h);
}

void GameManager::keyPressed(unsigned char key) {

	if (key == '1'){
		active_camera = 0;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		(*_cameras[active_camera]).reshape(_w,_h);
	}
	else if (key == '2'){
		active_camera = 1;
			glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		(*_cameras[active_camera]).reshape(_w, _h);
	}
	else if (key == '3'){
		active_camera = 2;
			glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		(*_cameras[active_camera]).reshape(_w, _h);
	}
	else if(key == 'a' || key == 'A') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, -0.006, 0));
	}//Down
	else if (key == 'o' || key == 'O') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.007,0,0));
	}//Esquerda
	else if (key == 'p' || key == 'P'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.007,0,0));
	} //Direita
	else if (key == 'q' || key == 'Q'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0,0.006,0));
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
	_cameras.push_back(new OrthogonalCamera(-10, 10, 0, 14, -1, 10));
	_cameras.push_back(new PerspectiveCamera(66, 1, 1, 20, 0, 1.5, 10));
	_cameras.push_back(new PerspectiveCamera(60, 1, 1, 20, 0, 0, 3));
	frogger = new Frog(0,0.5,0.5);
	_game_objects.push_back(new Road(0,0,0));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0));
	_game_objects.push_back(new Riverside(0,0,0));
	_game_objects.push_back(new TimberLog(-2,10.5,0.5));
	_game_objects.push_back(new Car(2,3.5,0.5));
	_game_objects.push_back(frogger);
}