#ifndef __WALL_H
#define __WALL_H
#include "quad.h"

class Wall {
 public:
	Wall(float x, float y)
		: quad(x, y, 0.50, 0.50),
	          shader("quad")
			  {
		       			viewProj = shader.getUniform("viewProj2");
					position = new GLVertexAttribute("position2", 2, 0, 0, &shader, quad.getVertexCount(), quad.getVertexData());
					texture = new GLVertexAttribute("texCoords2", 2, 0, true, &shader, quad.getVertexCount(), quad.getTextureCoords());
		}

	void Draw(const mat4 &viewProj){
		shader.Use();
		position->Enable();
		texture->Enable();
		this->viewProj->Matrix(viewProj);
		glDrawElements(GL_TRIANGLES, quad.getIndexCount(), GL_UNSIGNED_SHORT, quad.getIndexData());
		glFlush();
		position->Disable();
		texture->Disable();
		shader.Unbind();
	}
 private:
	Quad quad;
	GLUniform *viewProj;
	GLShaderProgram shader;
	GLVertexAttribute *texture;
	GLVertexAttribute *position;
};


#endif
