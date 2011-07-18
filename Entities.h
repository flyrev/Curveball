#pragma once

#include "geometry.h"
#include "sphere.h"
#include "GLShader.h"

#ifdef _WIN32
	static const double M_PI = acos(-1.0);
#endif

class Ball
{
	vec3 rotation_axis;
	float rotation;
	float spin;

	vec3 position;
	vec3 velocity;
	float radius;

	GLShaderProgram shader;
	GLVertexAttribute *positionAttrib;
	GLVertexAttribute *texCoordAttrib;
	GLUniform *worldMatrix;
	GLUniform *projView;

	Sphere sphere;

	vec3 magnus_effect()
	{
		const float S = 0.2;
		return cross( rotation_axis*spin, velocity )*(1.0f)*S;
	}
	

 public:
 Ball(float x, float y, float z, float radius)
	 : shader("sphere"),
		position(x,y,z),
		rotation(0),
		spin(0.01),
		sphere(radius, 20, 20),
		velocity(0.0000000,0,-1)	
	{	
		positionAttrib = new GLVertexAttribute("Position", 3, 0, 0, &shader, sphere.getVertexCount(), sphere.getVertexData());
		texCoordAttrib = new GLVertexAttribute("texCoords", 2, 0, true, &shader, sphere.getVertexCount(), sphere.getTexCoordData());
		rotation_axis=vec3(0,1,0);
		worldMatrix = shader.getUniform("world");
		projView = shader.getUniform("projView");
	}

	void Draw(const mat4 &projViewArg)
	{
		shader.Use();
		positionAttrib->Enable();
		texCoordAttrib->Enable();
		worldMatrix->Matrix(mat4::Translation(position)*mat4::Rotation(rotation_axis, rotation));
		projView->Matrix(projViewArg);
		
		glDrawElements(GL_TRIANGLES, sphere.getIndexCount(), GL_UNSIGNED_SHORT, sphere.getIndexData());
		glFlush();
		positionAttrib->Disable();
		texCoordAttrib->Disable();
		shader.Unbind(); // rofl
	}

	const vec3& getPosition() const {
		return position;
	}

	float getRadius() const {
		return radius;
	}

	/** Interval is the time since the last update, in game-time. */
	void Update(double interval) 
	{
		velocity += magnus_effect()*interval;
		position += velocity;

		rotation += spin;
		if ( rotation < 0.0f)
			rotation += 2*M_PI;
		else if ( rotation >= 2*M_PI )
			rotation -= 2*M_PI;
	}
};

