#include "GameManager.h"
GameManager * gm = 0;

void reshape(GLsizei w, GLsizei h) {
	gm->reshape(w,h); 
}

void display(){
	gm->display();
}
void keyPressed(unsigned char key, int x, int y){
	gm->keyPressed(key);
	
}
void onTimer(int i){
	if (i == 20){
		std::cout << "DEU!!!" << std::endl;
	}
	gm->onTimer();
	
	glutTimerFunc(20, onTimer,10);
}

void keyUp(unsigned char key, int x, int y){
	gm->keyUp(key);
}

int main(int argc, char ** argv) {
	gm = new GameManager();
	gm->init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Frogger");
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(20, onTimer,10);
	glutTimerFunc(50, onTimer, 20);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glClearColor(1., 1., 1., 0.);
	glutMainLoop();
	return 0;
}