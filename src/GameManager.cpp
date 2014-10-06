#include "GameManager.h"


GameManager::GameManager() {
	_cameras = new OrthogonalCamera(-7.,7.,0.,14., 3., 3.);
	_game_objects = * new std::vector<GameObject *>;
	t_act=0; 
	t_ant=0;
}

GameManager::~GameManager() {
}

void GameManager::display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//Por cada objecto fazer draw!!! :D
	//std::cout <<"cenas1";
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

void GameManager::keyPressed(unsigned char key) {
	std::cout << "in " << key << std::endl;

	if(key ==97) {
		std::cout << "a" << std::endl;
		frogger->setSpeed(0,-0.01,0);
	}//Down
	else if(key == 111) {
		std::cout << "o" << std::endl;
		frogger->setSpeed(-0.01,0,0);
	}//Esquerda
	else if (key == 112){
		std::cout << "p" << std::endl;
		frogger->setSpeed(0.01,0,0);
	} //Direita
	else if (key == 113){
		std::cout << "q" << std::endl;
		frogger->setSpeed(0,0.01,0);
	} //Cima
}


void GameManager::keyUp (unsigned char key) {  
	if(key ==97) {
		std::cout << "a" << std::endl;
		frogger->setSpeed(0,0,0);
	}//Down
	else if(key == 111) {
		std::cout << "o" << std::endl;
		frogger->setSpeed(0,0,0);
	}//Esquerda
	else if (key == 112){
		std::cout << "p" << std::endl;
		frogger->setSpeed(0,0,0);
	} //Direita
	else if (key == 113){
		std::cout << "q" << std::endl;
		frogger->setSpeed(0,0,0);
	} //Cima


}  




void GameManager::onTimer() {
	t_act = glutGet(GLUT_ELAPSED_TIME);
	std::cout << "onTimer"<< std::endl;
	this->update(t_act - t_ant);
	t_ant = t_act;
}

void GameManager::idle() {
}

void GameManager::update(double delta_t) {
	std::cout << "update"<< std::endl;
	/*for(GameObject * g : _game_objects){
		g->update(delta_t);
	}*/
	frogger->update(delta_t);

}

void GameManager::init() {
	frogger = new Frog(0,0.5,0);
	_game_objects.push_back(new Road(0,0,0));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0));
	_game_objects.push_back(new Riverside(0,0,0));
	_game_objects.push_back(new TimberLog(-2,10.5,0));
	_game_objects.push_back(new Car(2,3.5,0));
	_game_objects.push_back(frogger);
}