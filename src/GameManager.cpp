#include "GameManager.h"

//void GameManagerTimer(int value){}

GameManager::GameManager() {
	_cameras = *new std::vector <Camera *>;
	_game_objects = * new std::vector<GameObject *>;
	_logs = * new std::vector<TimberLog *>;
	_cars = * new std::vector<Car *>;
	gameLights = new Lights();
	active_camera = 0;
	t_act=0; 
	t_ant=0;
	minspeed = 0.002;
	maxspeed = 0.003;
	t_speed = 0;
	t_aux = 0;
}

GameManager::~GameManager() {
}

void GameManager::display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//Por cada objecto fazer draw!!! :D
	
	GLdouble eqn[4] = { 1.0, 0.0, 0.0, 0.0 };
	GLdouble eqn2[4] = { -1.0, 0.0, 0.0, 0.0 };
	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glClipPlane(GL_CLIP_PLANE0, eqn); // x > -10
	glEnable(GL_CLIP_PLANE0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10, 0, 0);
	glClipPlane(GL_CLIP_PLANE1, eqn2); // x < 10
	glEnable(GL_CLIP_PLANE1);
	glPopMatrix();

	//glutTimerFunc(200, GameManagerTimer, 3);
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

	//Up
	if (key == 'q' || key == 'Q'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, 0.004, 0));
	}//Down
	else if(key == 'a' || key == 'A') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, -0.004, 0));
	}//Left
	else if (key == 'o' || key == 'O') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.005,0,0));
	}//Right
	else if (key == 'p' || key == 'P'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.005,0,0));
	}//Lighting ON/OFF
	else if (key == 'l' || key == 'L'){
		if (glIsEnabled(GL_LIGHTING)){
			glDisable(GL_LIGHTING);
			display();
		}
		else{
			glEnable(GL_LIGHTING);
			display();
		}
	}//Day/Night Mode	
	else if (key == 'n' || key == 'N'){
		if (glIsEnabled(GL_LIGHT0)){
			glDisable(GL_LIGHT0);
			display();
		}
		else{
			glEnable(GL_LIGHT0);
			gameLights->setDirectional();
			display();
		}
	}//Spotlights
	else if (key == 'c' || key == 'C'){
		if (glIsEnabled(GL_LIGHT1)){
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
			glDisable(GL_LIGHT5);
			glDisable(GL_LIGHT6);
			display();
		}
		else{
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT2);
			glEnable(GL_LIGHT3);
			glEnable(GL_LIGHT4);
			glEnable(GL_LIGHT5);
			glEnable(GL_LIGHT6);
			gameLights->setDirectional();
			gameLights->setPointLights();
			gameLights->setLighting();
			display();
		}
	}//Camera 1
	else if (key == '1'){
		active_camera = 0;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
	}//Camera 2
	else if (key == '2'){
		active_camera = 1;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
	}//Camera 3
	else if (key == '3'){
		active_camera = 2;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
	}
}


void GameManager::keyUp (unsigned char key) {

	//Up
	if (key == 'q' || key == 'Q'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, -0.004, 0));
	}//Down
	else if (key == 'a' || key == 'A') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, 0.004, 0));
	}//Left
	else if (key == 'o' || key == 'O') {
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0.005,0,0));
	}//Right
	else if (key == 'p' || key == 'P'){
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.005,0,0));
	}
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

	if (glIsEnabled(GL_LIGHT1)){
		gameLights->setDirectional();
		gameLights->setPointLights();
		gameLights->setLighting();
	}

	frogger->update(delta_t, 0, 0);

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
				frogger->setPosition(0, 0.5, 0.075);
			}
		}
	}
	display();
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
	_cameras.push_back(new PerspectiveCamera(90, 1, 1, 20, 0, 1.5, 10));
	_cameras.push_back(new PerspectiveCamera(90, 1, 1, 20, 0, 0, 3));
	frogger = new Frog(0, .5, .075);
	_game_objects.push_back(new Road(0,0,0));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0));
	_game_objects.push_back(new Riverside(0,0,0));
	//_game_objects.push_back(new border(0, 0, 0));
	_game_objects.push_back(frogger);
	

	TimberLog * log = new TimberLog(randomPosition(), 8.6, 0);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(),0,0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 9.85, 0);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 11.1, 0);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);
	log = new TimberLog(randomPosition(), 12.35, 0);
	log->setSpeed(*(log->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_logs.push_back(log);

	Car * car = new Car(randomPosition(), 1.67, .01);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 2.92, .01);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 4.17, .01);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
	car = new Car(randomPosition(), 5.42, .01);
	car->setSpeed(*(car->getSpeed()) + Vector3(randomSpeed(), 0, 0));
	_cars.push_back(car);
}