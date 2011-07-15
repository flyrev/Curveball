#include <cstdlib>
//#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	int t = glutCreateWindow( "Curveball" );

	glutReshapeWindow( 800, 800 );




	cout << "Spill" << endl;
	cout << "It's a game" << endl;

	cout << "Loading ..." << endl;
	
	srand(time(NULL));
	int random=rand();
  	cout << "You have " << random << " points" << endl;
	glutMainLoop();	
	return EXIT_SUCCESS;
}


