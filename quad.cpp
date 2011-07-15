#include "quad.h"
#include <cstdlib>

Quad::Quad(vec2 coordinates, float height, float width)
	: coordinates(coordinates),
	  width(width),
	  height(height)
{
	vertexData=(float*)malloc(sizeof(vec2)*4);
	int index=0;
	vertexData[index++] = coordinates.x;
	vertexData[index++] = coordinates.y;

	vertexData[index++] = coordinates.x+width;
	vertexData[index++] = coordinates.y;

	vertexData[index++] = coordinates.x;
	vertexData[index++] = coordinates.y+height;

	vertexData[index++] = coordinates.x+height;
	vertexData[index++] = coordinates.y+width;

	indexData = (uint16_t*)malloc(sizeof(uint16_t)*6);

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

uint16_t *Quad::getIndexData()
{
	return indexData;	
}
