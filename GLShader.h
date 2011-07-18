#ifndef __GL_SHADER_CLASS_HEADER
#define __GL_SHADER_CLASS_HEADER

#include <GL/glew.h>
#include <string>
#include <stdexcept>
#include "Array.h"
#include "geometry.h"

class GLUniform;

class GLShaderProgram
{
private:
	unsigned int vert_handle, frag_handle, prog_handle;
	std::string filename_base;
public:
	GLShaderProgram(const char * shader_filename_base);
	void Use() { glUseProgram(prog_handle); }
	void Unbind() { glUseProgram(0); }
	void Reload();
	
	GLUniform * getUniform( const char * semantic );
	
	operator GLuint () const
	{
		return prog_handle;
	}

	~GLShaderProgram(void);
};

class GLUniform
{
	friend class GLShaderProgram;
	GLuint handle;
	GLShaderProgram * prog;
	GLUniform( const char * semantic, GLShaderProgram * prog)
		: prog(prog)
	{
		handle = glGetUniformLocation(*prog, semantic);
	}
public:
	void Matrix( const mat2 & m)
	{
		prog->Use();
		glUniformMatrix2fv(handle, 1, false, m);
	}

	void Matrix( const mat3 & m)
	{
		prog->Use();
		glUniformMatrix3fv(handle, 1, false, m);
	}
	void Matrix( const mat4 & m)
	{
		prog->Use();
		glUniformMatrix4fv(handle, 1, false, m);
	}

	void Vector( const vec2 & v)
	{
		prog->Use();
		glUniform2fv(handle,1,v);
	}
	void Vector( const vec3 & v)
	{
		prog->Use();
		glUniform3fv(handle,1,v);
	}
	void Vector( const vec4 & v)
	{
		prog->Use();
		glUniform4fv(handle,1,v);
	}

	void Float( float f )	
	{
		prog->Use();
		glUniform1f(handle,f);
	}
	void Int( int i )
	{
		prog->Use();
		glUniform1i(handle,i);
	}
	
};
		

class GLVertexAttribute
{
private:
	GLuint attrib_index ;
	GLuint buffer_handle;
	GLShaderProgram * shader;

	GLuint components, stride;
	bool normalized;
public:
	GLVertexAttribute( const char * semantic, GLuint components, GLuint stride, bool normalized, GLShaderProgram * shader, int element_count, GLfloat * data )
		: shader (shader)
		, components(components)
		, stride(stride)
		, normalized(normalized)
	{
		glGenBuffers(1, &buffer_handle);

		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glBufferData( GL_ARRAY_BUFFER, element_count*sizeof(float)*components, data, GL_STATIC_DRAW);
		glBindBuffer( GL_ARRAY_BUFFER, 0); // unbind
		
		ChangeProgram( shader, semantic);
	}

	void Enable()
	{
		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		
		glVertexAttribPointer(attrib_index, components, GL_FLOAT, normalized ? GL_TRUE : GL_FALSE, 0, 0);
		glEnableVertexAttribArray(attrib_index);
		glBindBuffer( GL_ARRAY_BUFFER, 0); // unbind
	}

	void Disable()
	{
		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glDisableVertexAttribArray(attrib_index);
		glBindBuffer( GL_ARRAY_BUFFER, 0); // unbind
	}

	void ChangeProgram( GLShaderProgram * prog, const char * semantic)
	{
		prog->Use();
		int temp=glGetAttribLocation(*prog, semantic);

		if (temp == -1)
			throw std::runtime_error(std::string("Vertex attribute: ").append(semantic).append(" was not found in the current program.") );

		attrib_index = temp;
		shader = prog;

		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glVertexAttribPointer(attrib_index, components, GL_FLOAT, normalized ? GL_TRUE : GL_FALSE, 0, 0);
		glBindBuffer( GL_ARRAY_BUFFER, 0); // unbind
		
	}
};

#endif
