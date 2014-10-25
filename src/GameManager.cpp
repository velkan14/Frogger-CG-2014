#include "GameManager.h"


GameManager::GameManager() {
	//_cameras = new OrthogonalCamera(-10, 10, 0, 14, -1, 10);
	
	//_cameras = new PerspectiveCamera(65, 1, 1, 20); 
	_cameras = *new std::vector <Camera *>;
	_game_objects = * new std::vector<GameObject *>;
	_logs = * new std::vector<TimberLog *>;
	_cars = * new std::vector<Car *>;
	active_camera = 0;
	t_act=0; 
	t_ant=0;
	saponolog = 0;
}

GameManager::~GameManager() {
}

void GameManager::display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//Por cada objecto fazer draw!!! :D
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	(*_cameras[active_camera]).computeVisualizationMatrix();

	for(GameObject * g : _game_objects){
		glPushMatrix();
		//std::cout << (g->getPosition()->getX()) << "  " << g->getPosition()->getY() << std::endl;
		glTranslated(g->getPosition()->getX(),g->getPosition()->getY(),g->getPosition()->getZ());
		//glTranslated(5,3,0);
		g->draw();
		glPopMatrix();
	}
	for(Car * car : _cars){
		glPushMatrix();
		glTranslated(car->getPosition()->getX(),car->getPosition()->getY(),car->getPosition()->getZ());
		car->draw();
		glPopMatrix();
	}
	for(TimberLog * log : _logs){
		glPushMatrix();
		glTranslated(log->getPosition()->getX(),log->getPosition()->getY(),log->getPosition()->getZ());
		log->draw();
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
	//std::cout << "in " << key << std::endl;

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
	this->update(t_act - t_ant);
	t_ant = t_act;
}

void GameManager::idle() {
}

void GameManager::update(double delta_t) {
	if (active_camera == 2){
		(*_cameras[active_camera]).update(*frogger->getPosition());
	}
	frogger->update(delta_t);
	for(int i = 0; i < (int)_cars.size(); i++){
		_cars[i]->update(delta_t);
		collisionCar(_cars[i]);
	}
	/*frogger->_log = 0;*/
	for(int i = 0; i < (int)_logs.size(); i++){
		_logs[i]->update(delta_t);
		collisionTimberLog(_logs[i]);
	}
	
	//if(frogger->_log == 1){
	//	frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.0007,0,0));
	//	
	//} else 
	//	
	if((frogger->ymin > 7.7) && (frogger->ymax < 13.5) && (_logs[0]->_log == 0) && (_logs[1]->_log == 0) && (_logs[2]->_log == 0) && (_logs[3]->_log == 0)){
			frogger->setPosition(0,0.5,0.5);
	}
}

void GameManager::collisionCar(Car * car){
	if(frogger->ymax < 7){
		if((frogger->xmax > car->xmin) && (frogger->xmin < car->xmax) && (frogger->ymax > car->ymin) && (frogger->ymin < car->ymax)){
			//frogger->_car = 1;
			frogger->setPosition(0,0.5,0.5);
		}
		else {
			//frogger->_car = 0;
		}
	}
}

//void GameManager::collisionTimberLog(TimberLog * log){
//	if((frogger->xmax > log->xmin) && (frogger->xmin < log->xmax) && (frogger->ymax > log->ymin) && (frogger->ymin < log->ymax)){
//		frogger->_log = 1;
//	}
//}

void GameManager::collisionTimberLog(TimberLog * log){
	if(frogger->ymax > 7){
		if((log->_log == 0)){
			if((frogger->xmax > log->xmin) && (frogger->xmin < log->xmax) && (frogger->ymax > log->ymin) && (frogger->ymin < log->ymax)){
			
				log->_log = 1;
				if(frogger->_log != 1){
					frogger->setSpeed(*(frogger->getSpeed()) + Vector3(log->getSpeed()->getX(),0,0));
					frogger->_log = 1;
				}
				
			}
		}
		else if (log->_log == 1){
			if(!((frogger->xmax > log->xmin) && (frogger->xmin < log->xmax) && (frogger->ymax > log->ymin) && (frogger->ymin < log->ymax))){
				log->_log = 0;
				if(frogger->_log == 1){
					frogger->setSpeed(*(frogger->getSpeed()) - Vector3(log->getSpeed()->getX(),0,0));
					frogger->_log=0;
				}			
			}
		}
	}
}





	//if(frogger->_log !=1){
	//	if((frogger->xmax > log->xmin) && (frogger->xmin < log->xmax) && (frogger->ymax > log->ymin) && (frogger->ymin < log->ymax)){
	//		frogger->_log = 1;
	//		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(log->getSpeed()->getX(),0,0));
	//	}
	//}

	//else if(frogger->getSpeed()->getX()>0.007){
	//	frogger->setSpeed(*(frogger->getSpeed()) - Vector3(log->getSpeed()->getX(),0,0));
	//	frogger->_log = 0;
	//}



void GameManager::init() {
	_cameras.push_back(new OrthogonalCamera(-10, 10, 0, 14, -1, 10));
	_cameras.push_back(new PerspectiveCamera(66, 1, 1, 20, 0, 1.5, 10));
	_cameras.push_back(new PerspectiveCamera(60, 1, 1, 20, 0, 0, 3));
	frogger = new Frog(0,0.5,0.5);
	_game_objects.push_back(new Road(0,0,0));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0));
	_game_objects.push_back(new Riverside(0,0,0));
	_game_objects.push_back(frogger);
	

	TimberLog * log = new TimberLog(-13,8.6,0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(0.002,0,0));
	_logs.push_back(log);
	log = new TimberLog(-13,9.85,0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(0.002,0,0));
	_logs.push_back(log);
	log = new TimberLog(-13, 11.1,0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(0.002,0,0));
	_logs.push_back(log);
	log = new TimberLog(-13,12.35,0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(0.002,0,0));
	_logs.push_back(log);

	Car * car = new Car(-13,1.55,0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(0.003,0,0));
	_cars.push_back(car);
	car = new Car(-13,2.8,0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(0.002,0,0));
	_cars.push_back(car);
	car = new Car(-13,4.05,0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(0.001,0,0));
	_cars.push_back(car);
	car = new Car(-13,5.3,0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(0.001,0,0));
	_cars.push_back(car);
}