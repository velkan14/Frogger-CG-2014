#include "GameManager.h"

//void GameManagerTimer(int value){}

GameManager::GameManager() {
	_cameras = *new std::vector <Camera *>;
	_game_objects = * new std::vector<GameObject *>;
	_logs = * new std::vector<TimberLog *>;
	_cars = * new std::vector<Car *>;
	_lives = * new std::vector<Frog *>;
	gameLights = new Lights();
	active_camera = 0;
	t_act=0; 
	t_ant=0;
	minspeed = 0.002;
	maxspeed = 0.003;
	t_speed = 0;
	t_aux = 0;
	pausa = true;
	_textureRoad = loadBMP_custom("C:\\Users\\Daniel\\Desktop\\CG\\Work\\textureRoad.bmp");
	_textureRiver = loadBMP_custom("C:\\Users\\Daniel\\Desktop\\CG\\Work\\textureRiver.bmp");
	t_passed = 0;

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

	if (!pausa){
		escreve("p");
	}
	if (vidas == 0){
		escreve("r");
	}

	desenha_vidas();

	glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
	_w = w;
	_h = h;
	(*_cameras[active_camera]).reshape(w, h);
}

void GameManager::keyPressed(unsigned char key) {
	if (key == 's' || key == 'S'){
		if(pausa){
			pausa = false;
		}
		else{
			pausa=true;
		}
	}
	if (key == 'r' || key == 'R'){
		
		t_act = 0;
		t_ant = 0;
		minspeed = 0.002;
		maxspeed = 0.003;
		t_speed = 0;
		t_aux = 0;
		pausa = true;
		vidas = 5;	
		_cameras = *new std::vector <Camera *>;
		_game_objects = *new std::vector<GameObject *>;
		_logs = *new std::vector<TimberLog *>;
		_cars = *new std::vector<Car *>;
		t_passed = glutGet(GLUT_ELAPSED_TIME);
		init();
		(*_cameras[0]).reshape(_w, _h);
		(*_cameras[0]).computeVisualizationMatrix();
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
		gameLights->setPointLights();
	}



	//Up
	if (key == 'q' || key == 'Q'){
		frogger->setRot(0);
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, 0.004, 0));
	}//Down
	else if(key == 'a' || key == 'A') {
		frogger->setRot(180);
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(0, -0.004, 0));
	}//Left
	else if (key == 'o' || key == 'O') {
		frogger->setRot(90);
		frogger->setSpeed(*(frogger->getSpeed()) + Vector3(-0.005,0,0));
	}//Right
	else if (key == 'p' || key == 'P'){
		frogger->setRot(-90);
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
			gameLights->setPointLights();
			display();
		}
	}//Camera 1
	else if (key == '1'){
		active_camera = 0;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
		gameLights->setPointLights();
	}//Camera 2
	else if (key == '2'){
		active_camera = 1;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
		gameLights->setPointLights();
	}//Camera 3
	else if (key == '3'){
		active_camera = 2;
		(*_cameras[active_camera]).reshape(_w, _h);
		(*_cameras[active_camera]).computeVisualizationMatrix();
		gameLights->setDirectional();
		gameLights->setPointLights();
	}
	else if (key == 'h' || key == 'H'){
		if(glIsEnabled(GL_LIGHT7)){
			glDisable(GL_LIGHT7);
		}
		else{
		glEnable(GL_LIGHT7);
		gameLights->setHeadlight(*frogger);
		}
		display();

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
	t_act = glutGet(GLUT_ELAPSED_TIME) - t_passed;
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
		if (glIsEnabled(GL_LIGHT1))
			gameLights->setPointLights();
	}

	if(pausa && (vidas != 0 )){

		frogger->update(delta_t, 0, 0);
		if (glIsEnabled(GL_LIGHT7))
			gameLights->setHeadlight(*frogger);

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
					vidas--;
					frogger->setPosition(0, 0.45, 0.075);
				}
			}
		}
	}
	display();
}

void GameManager::collisionCar(Car * car){
		if((frogger->xmax > car->xmin) && (frogger->xmin < car->xmax) && (frogger->ymax > car->ymin) && (frogger->ymin < car->ymax)){
			vidas--;
			frogger->setPosition(0,0.45,0.075);
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
	vidas = 5;
	double x = 9.5;
	for (int i = 0; i < 5; i++){
		_lives.push_back(new Frog(-x, .3, 0));
		x = x - 0.5;
	}
	_cameras.push_back(new OrthogonalCamera(-10, 10, 0, 14, -1, 10));
	_cameras.push_back(new PerspectiveCamera(90, 1, 1, 20, 0, 1.5, 10));
	_cameras.push_back(new PerspectiveCamera(90, 1, 1, 20, 0, 0, 3));
	frogger = new Frog(0, .45, .075);
	_game_objects.push_back(new Road(0,0,0, _textureRoad));
	_game_objects.push_back(new Roadside(0,0,0));
	_game_objects.push_back(new River(0,0,0,_textureRiver));
	_game_objects.push_back(new Riverside(0,0,0));
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

GLuint GameManager::loadBMP_custom(const char * imagepath){
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	// Open the file
	FILE * file = fopen(imagepath, "rb");
	if (!file){
		printf("Image could not be opened\n");
		return 0;
	}
	if (fread(header, 1, 54, file) != 54){ // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}
	if (header[0] != 'B' || header[1] != 'M'){
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way
	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);
	
	for (int i = 0; i < (int)(width * height); ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D,NULL);
	return textureID;
}


void GameManager::escreve(char *s){
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, _w, 0, _h);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glRasterPos2f(0, 400);

	int len, i;
	char * string;
	string = "";

	if (s == "p"){
		string = "                                                    Jogo em pausa, para continuar pressione 'S'";
	}
	else if (s == "r"){
		string = "                                                     Jogo perdido, para recomecar pressione 'R'";
	}

	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glutSwapBuffers();

}

void GameManager::desenha_vidas(){

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	(*_cameras[0]).computeProjectionMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	(*_cameras[0]).computeVisualizationMatrix();

	glPushMatrix();
	int i = 0;
	for (i; i != vidas; i++){
		glPushMatrix();
		glTranslatef(_lives[i]->getPosition()->getX(), _lives[i]->getPosition()->getY(), _lives[i]->getPosition()->getZ());
		glScalef(.4, .4, .4);
		_lives[i]->draw();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glutSwapBuffers();
}