#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>
//#include <cstdint> // WTF

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
	//	glutWireTeapot(0.5);
	//      glutSolidSphere(0.5f, 1000, 1000);
	glutSwapBuffers();
}

float *vertexDataForSphere(int H, int V)
{
	float *vertexData = (float*)malloc(sizeof(float)*3*H*V);
	int index=0;
	for (int h=0; h<H; h++)
		for (int v=0; v<V; v++) {
			vertexData[index++] = sin(PI * h/H) * cos(2*PI * v/V); // X
	                vertexData[index++] = sin(PI * h/H) * sin(2*PI * v/V);			// Y
	                vertexData[index++] = cos(PI * h/H); // Z
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


	
	return EXIT_SUCCESS;
}


