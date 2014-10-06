#include "GameManager.h"
GameManager * gm = 0;

void reshape(GLsizei w, GLsizei h) {
	gm->reshape(w,h); 
}

void display(){
	gm->display();
}
void input(unsigned char key, int x, int y){
	gm->keyPressed(key);
	
}
void onTimer(int i){
	gm->onTimer();
	
	glutTimerFunc(0, onTimer,10);
}

void keyUp(unsigned char key, int x, int y){
	gm->keyUp(key);
}

int main(int argc, char ** argv) {
	gm = new GameManager();
	gm->init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutCreateWindow("Frogger");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(0, onTimer,10);
	glutKeyboardFunc(input);
	glutKeyboardUpFunc(keyUp);
	glClearColor(1., 1., 1., 0.);
	glutMainLoop();
	return 0;
}