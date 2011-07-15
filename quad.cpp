#include "quad.h"

Quad::Quad(vec2 coordinates, float height, float width)
	: coordinates(coordinates),
	  normal(normal),
	  width(width),
	  height(height)
{
	vertexData=malloc(sizeof(vec2)*4);
	int index=0;
	vertexData[index++] = x;
	vertexData[index++] = y;

	vertexData[index++] = x+width;
	vertexData[index++] = y;

	vertexData[index++] = x;
	vertexData[index++] = y+height;

	vertexData[index++] = x+height;
	vertexData[index++] = y+width;

	indexData = malloc(sizeof(float)*6);

	index=0;

	indexData[index++] = 0;
	indexData[index++] = 1;
	indexData[index++] = 2;

	indexData[index++] = 2;
	indexData[index++] = 1;
	indexData[index++] = 3;
}

float *Quad::getVertexData()
{
	return vertexData;
}

uint16_t getIndexData()
{
	return indexData;	
}
