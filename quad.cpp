#include "quad.h"
#include <cstdlib>


Quad::Quad(float x, float y, float z, float height, float width)
	: coordinates(coordinates),
	  width(width),
	  height(height),
	  shader("maria")
	  
{
	vertexData=new float[12];
	int index=0;
	vertexData[index++] = x;	
	vertexData[index++] = y;
	vertexData[index++] = z;

	vertexData[index++] = x+width;
	vertexData[index++] = y;
	vertexData[index++] = z;

	vertexData[index++] = x;
	vertexData[index++] = y+height;
	vertexData[index++] = z;

	vertexData[index++] = x+height;
	vertexData[index++] = y+width;
	vertexData[index++] = z;

	indexData = new GLushort[6];

	index=0;

	indexData[index++] = 0;
	indexData[index++] = 1;
	indexData[index++] = 2;

	indexData[index++] = 2;
	indexData[index++] = 1;
	indexData[index++] = 3;

	position = new GLVertexAttribute("position", 3, 0, 0, &shader, 4, vertexData);
	projView = shader.getUniform("projView");
}

float *Quad::getVertexData()
{
	return vertexData;
}

uint16_t *Quad::getIndexData()
{
	return indexData;	
}

void Quad::Draw(const mat4 &projViewArg)
{
	shader.Use();
        position->Enable();
	projView->Matrix(projViewArg);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indexData);
        position->Disable();
}

