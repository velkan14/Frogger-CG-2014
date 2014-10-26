#include "GameManager.h"


GameManager::GameManager() {
	_cameras = *new std::vector <Camera *>;
	_game_objects = * new std::vector<GameObject *>;
	_logs = * new std::vector<TimberLog *>;
	_cars = * new std::vector<Car *>;
	active_camera = 0;
	t_act=0; 
	t_ant=0;
	minspeed = 0.001;
	maxspeed = 0.0015;
	t_speed = 0;
	t_aux = 0;
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
		glTranslated(g->getPosition()->getX(),g->getPosition()->getY(),g->getPosition()->getZ());
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
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, 0.006, 0));
	}//Down
	else if (key == 'o' || key == 'O') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.007,0,0));
	}//Esquerda
	else if (key == 'p' || key == 'P'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.007,0,0));
	} //Direita
	else if (key == 'q' || key == 'Q'){
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

double GameManager::randomPosition(){
	return ((-10) - (-17)) * ((double)rand() / (double)RAND_MAX) + (-17);
}

double GameManager::randomSpeed(){
	t_speed = (int) t_act*0.0001;
	if (t_speed > t_aux +2){
		minspeed += 0.0005;
		maxspeed += 0.0005;
		t_aux = t_speed;
	}
	double random = ((minspeed)-(maxspeed)) * ((double)rand() / (double)RAND_MAX) + (maxspeed);
	return random;
}

void GameManager::update(double delta_t) {
	if (active_camera == 2){
		(*_cameras[active_camera]).update(*frogger->getPosition());
	}

	frogger->update(delta_t, randomPosition(), randomSpeed());

	for(int i = 0; i < (int)_cars.size(); i++){
		_cars[i]->update(delta_t, randomPosition(), randomSpeed());
	}

	for (int i = 0; i < (int)_logs.size(); i++){
		_logs[i]->update(delta_t, randomPosition(), randomSpeed());
	}


	if (frogger->ymax < 7){
		for (int i = 0; i < (int)_cars.size(); i++){
			collisionCar(_cars[i]);
		}
	}

	else if ((frogger->ymax > 7)){
		for (int i = 0; i < (int)_logs.size(); i++){
			collisionTimberLog(_logs[i], i);
			}
		if ((_logs[0]->_log == 0) && (_logs[1]->_log == 0) && (_logs[2]->_log == 0) && (_logs[3]->_log == 0)){
			if (frogger->_log != -1){
				frogger->setSpeed(*(frogger->getSpeed()) - Vector3(_logs[frogger->_log]->getSpeed()->getX(), 0, 0));
			}
			frogger->_log = -1;
			if ((frogger->ymin > 7.7) && (frogger->ymax < 13.5)){
				frogger->setPosition(0, 0.5, 0.5);
			}
		}
	}
}

void GameManager::collisionCar(Car * car){
		if((frogger->xmax > car->xmin) && (frogger->xmin < car->xmax) && (frogger->ymax > car->ymin) && (frogger->ymin < car->ymax)){
			frogger->setPosition(0,0.5,0.5);
		}
}


void GameManager::collisionTimberLog(TimberLog * _log, int i){
	if ((frogger->xmax > _log->xmin) && (frogger->xmin < _log->xmax) && (frogger->ymax > _log->ymin) && (frogger->ymin < _log->ymax)){
		_log->_log = 1;
		if (frogger->_log != i){
			if (frogger->_log != -1){
				frogger->setSpeed(*(frogger->getSpeed()) - Vector3(_logs[frogger->_log]->getSpeed()->getX(), 0, 0));
			}
			frogger->_log = i;
			frogger->setSpeed(*(frogger->getSpeed()) + Vector3(_logs[i]->getSpeed()->getX(), 0, 0));
		}
	}
	else{
		_log->_log = 0;
	}
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
	_game_objects.push_back(frogger);
	

	TimberLog * log = new TimberLog(randomPosition(), 8.6, 0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(),0,0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 9.85, 0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 11.1, 0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 12.35, 0.5);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);

	Car * car = new Car(randomPosition(),1.55,0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 2.8, 0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 4.05, 0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 5.3, 0.5);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
}