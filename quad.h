#pragma once
#include "geometry.h"
#include <stdint.h>
#include "GLShader.h"

class Quad
{
 public:
	Quad(float x, float y, float z, float height, float width);
	float *getVertexData();
	uint16_t *getIndexData();
	void Draw(const mat4 &viewProj);
 private:	
	vec2 coordinates;
	float height;
	float width;
	float *vertexData;
	uint16_t *indexData;
	GLShaderProgram shader;
	GLVertexAttribute *position;
	GLUniform *projView;
};
