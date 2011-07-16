#ifndef __QUAD_H
#define __QUAD_H

class Quad
{
 public:
	Quad(float x, float y, float width, float height)
		{
			int index=0;
			vertexData[index++] = x;
			vertexData[index++] = y;
			
			vertexData[index++] = x+width;
			vertexData[index++] = y;

			vertexData[index++] = x;
			vertexData[index++] = y+height;

			vertexData[index++] = x+width;
			vertexData[index++] = y+height;

			index=0;
			
			indexData[index++] = 0;
			indexData[index++] = 1;
			indexData[index++] = 2;
			indexData[index++] = 2;
			indexData[index++] = 1;
			indexData[index++] = 3;
		
			index=0;
			textureCoords[index++] = 0;
			textureCoords[index++] = 0;

			textureCoords[index++] = 1;
			textureCoords[index++] = 0;

			textureCoords[index++] = 0;
			textureCoords[index++] = 1;

			textureCoords[index++] = 1;
			textureCoords[index++] = 1;
		}

	GLushort *getIndexData() {
		return indexData;
	}

	GLfloat *getVertexData() {
		return vertexData;
	}

	GLfloat *getTextureCoords() {
		return textureCoords;
	}

	GLushort getIndexCount() {
		return 6;		
	}

	GLushort getVertexCount() {
		return 4;
	}
	
 private:
	GLushort indexData[6];
	GLfloat vertexData[8];
	GLfloat textureCoords[8];
};

#endif
