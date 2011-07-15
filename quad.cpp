#include "quad.h"

Quad::Quad(vec3 coords, vec3 up, float width, float height)
{
	this->x=x;
	this->y=y;
	this->height=height;
	this->width=width;

	vertexData=malloc(sizeof(float)*12);
	int index=0;
	vertexData[index++] = x;
	vertexData[index++] = y;

	vertexData[index++] = x;
	vertexData[index++] = y+height;

	vertexData[index++] = x+width;
	vertexData[index++] = y+height;


	vertexData[index++] = x;
	vertexData[index++] = y;

	vertexData[index++] = x+height;
	vertexData[index++] = y+width;

	vertexData[index++] = x+height;
	vertexData[index++] = y+width;
}

float *Quad::getVertexData()
{
	return vertexData;
}

uint16_t getIndexData()
{
	uint16_t *indexData=malloc(sizeof(uint_t)*6);
	
}
