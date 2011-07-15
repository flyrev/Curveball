#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

void keyboard(unsigned char key, int x, int y)
{
	switch(key) {

	case 27: // ESC
		exit(1);
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
	glutSolidSphere(0.5f, 1000, 1000);
	glutSwapBuffers();
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


