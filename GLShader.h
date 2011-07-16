#ifndef __GL_SHADER_CLASS_HEADER
#define __GL_SHADER_CLASS_HEADER

#include <GL/glew.h>
#include <string>
#include <stdexcept>

class GLShaderProgram
{
	unsigned int vert_handle, frag_handle, prog_handle;
	std::string filename_base;
public:
	GLShaderProgram(const char * shader_filename_base);
	void Use() { glUseProgram(prog_handle); }
	void Reload();
	void clear();
	void clear_dynamic();
	
	operator GLuint () const
	{
		return prog_handle;
	}

	~GLShaderProgram(void);
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
		
		ChangeProgram( shader, semantic);

	}

	void Enable()
	{
		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glEnableVertexAttribArray(attrib_index);
	}

	void Disable()
	{
		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glDisableVertexAttribArray(attrib_index);
	}

	void ChangeProgram( GLShaderProgram * prog, const char * semantic)
	{
		int temp= glGetAttribLocation(*prog, semantic);

		if ( temp == -1)
			throw std::runtime_error(std::string("Vertex attribute: ").append(semantic).append(" was not found in the current program.") );

		attrib_index = temp;
		shader = prog;

		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glVertexAttribPointer(attrib_index, components, GL_FLOAT, normalized, 0, 0);
	}

};

class GLVertexIndices
{
private:
	GLuint attrib_index;
	GLuint buffer_handle;
	GLShaderProgram * shader;

public:
	GLVertexIndices( const char * semantic, GLuint components, GLuint stride, bool normalized, GLShaderProgram * shader, int element_count, GLushort * data )
		: shader (shader)
	{
		glGenBuffers(1, &buffer_handle);

		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffer_handle);
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, element_count*sizeof(float)*components, data, GL_STATIC_DRAW);
		
		try{
			ChangeProgram( shader, semantic);
		}catch (...)
		{
			glDeleteBuffers( 1, &buffer_handle);
			throw;
		}
	}

	void Enable()
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffer_handle);
		glEnableVertexAttribArray(attrib_index);
	}

	void Disable()
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffer_handle);
		glDisableVertexAttribArray(attrib_index);
	}

	void ChangeProgram( GLShaderProgram * prog, const char * semantic)
	{
		int temp= glGetAttribLocation(*prog, semantic);

		if ( temp == -1)
			throw std::runtime_error(std::string("Vertex attribute: ").append(semantic).append(" was not found in the current program.") );

		attrib_index = temp;
		shader = prog;

		glBindBuffer( GL_ARRAY_BUFFER, buffer_handle);
		glVertexAttribPointer(attrib_index, 1, GL_UNSIGNED_SHORT, 0, 0, 0);
	}
};

#endif
