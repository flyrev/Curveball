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

#define PI 3.14

int frames=0;

using namespace std;

Quad *quad;
GLShaderProgram *quadShader;
GLShaderProgram *sphereShader;

GLVertexAttribute *quadposition;
GLVertexAttribute *ballposition;
GLVertexIndices *indices;
Sphere *sphere;

Uniform *rotation;

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
	glClearColor(0.0f,0.0f,0.1f,1.0f);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	//	glEnable(GL_BLEND);
	
	rotation->Matrix(mat4::Rotation(vec3(0,1,0), frames++/1999.0f));
	
	sphereShader->Use();
	ballposition->Enable();
	glDrawElements(GL_TRIANGLES, sphere->getIndexCount(), GL_UNSIGNED_SHORT, sphere->getIndexData());
	ballposition->Disable();
	
	quadShader->Use();
	quadposition->Enable();
	glDrawElements(GL_TRIANGLES, 6*1, GL_UNSIGNED_SHORT, quad->getIndexData());
	quadposition->Disable();

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
		
	quad = new Quad(vec2(0,0),0.5,0.5);
	quadShader = new GLShaderProgram("maria");
	quadposition = new GLVertexAttribute("position", 2, 0, 0, quadShader, 4, quad->getVertexData());

	sphereShader = new GLShaderProgram("sphere");
	sphere = new Sphere(0.25,100,100);
	rotation = sphereShader->getUniform("rotation");
	ballposition = new GLVertexAttribute("position", 3, 0, 0, sphereShader, sphere->getVertexCount(), sphere->getVertexData());

	glutMainLoop();	

	cout << "Life is a game" << endl;
	cout << "This was life" << endl;
	
	return EXIT_SUCCESS;
}
