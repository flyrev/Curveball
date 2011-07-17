#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>
//#include <cstdint> // WTF
#include "geometry.h"
#include "GLShader.h"
#include "wall.h"
#include "sphere.h"
#include "Entities.h"

#define PI 3.14

const float window_width=1366.0f;
const float window_height=768.0f;

int frames=0;

using namespace std;

Wall *wall;
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
	wall->Draw(projView);

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	float aspect = window_height/window_width;
	float FOV = PI/4;
	float nearplane = 100.0f;
	projView = mat4::Projection(nearplane, 10000.0f, FOV, aspect);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	int t = glutCreateWindow( "Curveball" );
	
	glutInitWindowSize( window_width, window_height );

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
		
	ball = new Ball(0.0,0.0,-200.0,25.0);
	wall = new Wall(0.0,0.0,nearplane,aspect,FOV);

	glutMainLoop();	

	return EXIT_SUCCESS;
}
