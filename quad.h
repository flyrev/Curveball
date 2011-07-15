#pragma once
#include <stdint.h>

class Quad
{
 public:
	Quad(float x, float y, float height, float width);
	float *getVertexData();
	uint16_t *getIndexData();
 private:	
	vec2 coordinates;
	float height;
	float width;
	float *vertexData;
	uint_16 *indexData;
};
