#ifndef __WALL_H
#define __WALL_H
#include "quad.h"
#include "Entities.h"



class Wall {
 public:
 Wall(float x, float y, float near, float aspect, float h_fov_in_rad)
		: quad(x, y, 500, 500),
	          shader("quad")
			  {
				  world = shader.getUniform("world");
				  
				  r = near * tan(h_fov_in_rad/2);
				  t = r*aspect;

				  transform[0] = mat4::Translation(vec3(r,0,0))*mat4::Rotation(vec3(0,1,0),-M_PI/2); // 
				  transform[1] = mat4::Translation(vec3(-r,0,0))*mat4::Rotation(vec3(0,1,0),M_PI/2);
				  transform[2] = mat4::Translation(vec3(0,t,0))*mat4::Rotation(vec3(1,0,0),M_PI/2);
				  transform[3] = mat4::Translation(vec3(0,-t,0))*mat4::Rotation(vec3(1,0,0),-M_PI/2);
				  
     	       			viewProj = shader.getUniform("viewProj2");
					position = new GLVertexAttribute("position2", 2, 0, 0, &shader, quad.getVertexCount(), quad.getVertexData());
					texture = new GLVertexAttribute("texCoords2", 2, 0, true, &shader, quad.getVertexCount(), quad.getTextureCoords());
		}

	vec3* collides(Ball *ball) 
	{  
		if (ball->getPosition().x + ball->getRadius() > r)
			return new vec3(-1,0,0);

		if (ball->getPosition().y + ball->getRadius() > r)
			return new vec3(0,-1,0);

		if (ball->getPosition().z + ball->getRadius() > r)
			return new vec3(0,0,-1);
	
		if (ball->getPosition().x - ball->getRadius() < -r)
			return new vec3(1,0,0);

		if (ball->getPosition().y - ball->getRadius() < -r)
			return new vec3(0,1,0);

		if (ball->getPosition().z - ball->getRadius() < -r)
			return new vec3(0,0,1);

		return 0;
	}

	void Draw(const mat4 &viewProj){
		shader.Use();
		position->Enable();
		texture->Enable();
		
		this->viewProj->Matrix(viewProj);
		for (int i=0; i<4; i++) {
			world->Matrix(transform[i]);
			glDrawElements(GL_TRIANGLES, quad.getIndexCount(), GL_UNSIGNED_SHORT, quad.getIndexData());
		}
		position->Disable();
		texture->Disable();
		shader.Unbind();
	}
 private:
	Quad quad;
	GLUniform *viewProj;
	GLUniform *world;
	GLShaderProgram shader;
	GLVertexAttribute *texture;
	GLVertexAttribute *position;
	mat4 transform[4];
	float t,r;
};


#endif
