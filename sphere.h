#pragma once

#include <stdint.h>
#include <GL/gl.h>

class Sphere
{
private:
	GLfloat *vertices;
	GLfloat *normals;
	GLfloat *texcoords;
	GLushort *indices;
	const unsigned int rings;
	const unsigned int sectors;
public:
	Sphere(float radius, unsigned int rings, unsigned int sectors);
	float *getVertexData() const { return vertices; }
	uint16_t *getIndexData() const { return indices; }
	uint16_t getVertexCount() const { return rings*sectors; } 
	uint16_t getIndexCount() const { return rings*sectors*6; }
	
};
