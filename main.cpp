// #include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>
//#include <cstdint> // WTF
#include "geometry.h"
#include "GLShader.h"
#include "quad.h"
#include "sphere.h"
#include "Entities.h"

#define PI 3.14

int frames=0;

using namespace std;

Quad *quad;
Ball *ball;

mat4 projView;

void keyboard(unsigned char key, int x, int y)
{
	switch(key) {

	case 27: // ESC
	cout << "Life is a game" << endl;
	cout << "This was life" << endl;
	

		exit(EXIT_SUCCESS);
		break;
	}
}

void update()
{
	glutPostRedisplay();
	ball->Update(frames++/2000.0);
}

void render()
{
	glClearColor(0.0f,0.0f,0.2f,1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_FRONT);
	glEnable(GL_BLEND);

	ball->Draw(projView);
	quad->Draw(projView);

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	projView = mat4::Projection(100.0f, 10000.0f, PI/4, 1.0f);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	int t = glutCreateWindow( "Curveball" );

	glutInitWindowSize( 800, 800 );

	cout << "Spill" << endl;
	cout << "It's a game" << endl;
	cout << "Loading ..." << endl;
	glewInit();

	srand(time(NULL));
	int random=rand();
  	cout << "You have " << random << " points" << endl;
	
	glutIdleFunc(&update);
	glutDisplayFunc(&render);
	glutKeyboardFunc(&keyboard);
		
	quad = new Quad(0,0,-200,50,50);
	ball = new Ball(0,0,-200,25);

	glutMainLoop();	

	return EXIT_SUCCESS;
}
