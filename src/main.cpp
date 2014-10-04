#include "GameManager.h"
GameManager * gm = 0;
void reshape(GLsizei w, GLsizei h) {
	if (gm) gm->reshape(w,h); 
}
void display(){
	if (gm) gm->display();
}

int main(int argc, char ** argv) {
	gm = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutCreateWindow("Windows & Viewports l");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glClearColor(1., 1., 1., 0.);
	glutMainLoop();
	return 0;
}