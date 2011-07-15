#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>
//#include <cstdint> // WTF
#include "vector.h"

using namespace std;

#define PI 3.14

void keyboard(unsigned char key, int x, int y)
{
	switch(key) {

	case 27: // ESC
		exit(EXIT_SUCCESS);
		break;
	}
}

void update()
{
	glutPostRedisplay();
}

void render()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);



	glutSwapBuffers();
}

vec3 *vertexDataForSphere(int H, int V)
{
	vec3 *vertexData = (vec3*)malloc(sizeof(vec3)*H*V);
	int index=0;
	for (int h=0; h<H; h++)
		for (int v=0; v<V; v++) {
			vertexData[index++] = 
                         vec3(
			  sin(PI * h/H) * cos(2*PI * v/V), 
                          sin(PI * h/H) * sin(2*PI * v/V), 
                          cos(PI * h/H)
                         ); 
		}

	return vertexData;
}

uint16_t *indexDataForSphere(int H, int V)
{
	uint16_t *indexData = (uint16_t*)malloc(sizeof(uint16_t)*3*H*V);
	int index=0;

	for (int h=0; h<H; h++)
		for (int v=0; v<V; v++) {
			indexData[index++] = h;
			indexData[index++] = h+V;
			indexData[index++] = h+1;

			indexData[index++] = h+1;
			indexData[index++] = h-1+V;
			indexData[index++] = h+V;
		}

	return indexData;
}

int main(int argc, char **argv)
{
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
	glutMainLoop();	

	cout << "Life is a game" << endl;
	cout << "This was life" << endl;
	
	return EXIT_SUCCESS;
}
