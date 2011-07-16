#pragma once
#include "geometry.h"
#include <stdint.h>

class Quad
{
 public:
	Quad(vec2 pos, float height, float width);
	float *getVertexData();
	uint16_t *getIndexData();
 private:	
	vec2 coordinates;
	float height;
	float width;
	float *vertexData;
	uint16_t *indexData;
};
