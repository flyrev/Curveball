#ifndef __GL_SHADER_CLASS_HEADER
#define __GL_SHADER_CLASS_HEADER

#include <GL/glew.h>
#include <string>

class GLShaderProgram
{
	unsigned int vert_handle, frag_handle, prog_handle;
	std::string filename_base;
public:
	GLShaderProgram( const char * shader_filename_base);
	void Use() { glUseProgram(prog_handle);}
	void Reload();

	operator GLuint () const
	{
		return prog_handle;
	}

	~GLShaderProgram(void);
};

#endif
