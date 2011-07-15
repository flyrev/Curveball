#pragma once

class Quad
{
 public:
	Quad(float x, float y, float height, float width)
	float *getVertexData();
	uint16_t *getIndexData();
 private:	
	float x;
	float y;
	float height;
	float width;
	float *vertexData;
	uint_16 *indexData;
};
