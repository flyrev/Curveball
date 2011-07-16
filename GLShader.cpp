#include "GLShader.h"
#include <string>
#include <fstream>
#include <cstring>
#include <stdexcept>

using namespace std;

#define CHECK_GL_ERROR 

GLShaderProgram::GLShaderProgram(const char * filename)
	: vert_handle(0)
	, frag_handle(0)
	, prog_handle(0)
	, filename_base(filename)
{
	Reload();

}

Uniform * GLShaderProgram::getUniform( const char * semantic )
{
		return new Uniform(semantic, this);
}



void GLShaderProgram::Reload()
{
	
	// Temporary vertex objects
	unsigned int t_vert_handle = 0, t_frag_handle = 0, t_prog_handle = 0;

	try {

		Array<GLchar * > vertex_shader_source;
		Array<int> vertex_shader_source_line_lengths;
		Array<int> fragment_shader_source_line_lengths;
		Array<GLchar * > fragment_shader_source;

		ifstream in( string(filename_base).append(".vert").c_str(), ios::in );

		if (!in)
			throw runtime_error( string("Could not open file: ").append(filename_base).append(".vert").c_str() );

		string buffer;
		while ( getline( in, buffer))
		{
			char * temp = new char[buffer.size()];
			memcpy( temp, buffer.c_str(), buffer.size() );
			vertex_shader_source_line_lengths.add(buffer.size());
			vertex_shader_source.add( temp );
		}
	
		t_vert_handle = glCreateShader( GL_VERTEX_SHADER );
		glShaderSource(t_vert_handle, vertex_shader_source.size(), (const GLchar**)vertex_shader_source.getData(), vertex_shader_source_line_lengths);

		glCompileShader(t_vert_handle);

		int iv = 0;
		glGetShaderiv( t_vert_handle, GL_COMPILE_STATUS, &iv );
		if (iv == GL_FALSE)
		{
			glGetShaderiv( t_vert_handle, GL_INFO_LOG_LENGTH, &iv);
			char * temp = new char [iv];
			glGetShaderInfoLog( t_vert_handle, iv, &iv, temp);
			runtime_error exc( string("Vertex shader error:\n").append(temp) );
			delete [] temp;
			throw exc;
		}


		in.close();
		in.open( string(filename_base).append(".frag").c_str(), ios::in );

		if (!in)
			throw runtime_error( string("Could not open file: ").append(filename_base).append(".frag").c_str() );

		while ( getline( in, buffer))
		{
			char * temp = new char[buffer.size()];
			memcpy( temp, buffer.c_str(), buffer.size() );
			fragment_shader_source_line_lengths.add(buffer.size());
			fragment_shader_source.add( temp );
		}
	
		t_frag_handle = glCreateShader( GL_FRAGMENT_SHADER );
		glShaderSource(t_frag_handle, fragment_shader_source.size(), (const GLchar **)fragment_shader_source.getData(), fragment_shader_source_line_lengths);

		glCompileShader(t_frag_handle);

		iv = 0;
		glGetShaderiv( t_frag_handle, GL_COMPILE_STATUS, &iv );
		if (  iv == GL_FALSE)
		{
			glGetShaderiv( t_frag_handle, GL_INFO_LOG_LENGTH, &iv);
			char * temp = new char [iv];
			glGetShaderInfoLog( t_frag_handle, iv, &iv, temp);
			runtime_error exc( string("Vertex shader error:\n").append(temp) );
			delete [] temp;
			throw exc;
		}

		in.close();
		fragment_shader_source_line_lengths.clear();
		fragment_shader_source.clear_dynamic();
		vertex_shader_source_line_lengths.clear();
		vertex_shader_source.clear_dynamic();

		t_prog_handle = glCreateProgram();

		glAttachShader(	t_prog_handle, t_vert_handle);
		glAttachShader(	t_prog_handle, t_frag_handle);

		glLinkProgram( t_prog_handle );

		glGetProgramiv( t_prog_handle, GL_LINK_STATUS, &iv);

		if (  iv == GL_FALSE )
		{
			glGetProgramiv( t_prog_handle, GL_INFO_LOG_LENGTH, &iv);
			char * temp = new char [iv];
			glGetProgramInfoLog( t_prog_handle, iv, &iv, temp);
			runtime_error exc( string("Vertex shader error:\n").append(temp) );
			delete [] temp;
			throw exc;
		}

		if (vert_handle)
			 glDeleteShader(vert_handle);
		if (frag_handle)
			 glDeleteShader(frag_handle);
		if (prog_handle)
			 glDeleteProgram(vert_handle);
		
		prog_handle = t_prog_handle;
		vert_handle = t_vert_handle;
		frag_handle = t_frag_handle;


	} catch (...)
	{
		 if (t_vert_handle)
			 glDeleteShader(t_vert_handle);
		 if (t_frag_handle)
			 glDeleteShader(t_frag_handle);
		 if (t_prog_handle)
			 glDeleteProgram(t_vert_handle);
		 
		 throw;
	}
}

GLShaderProgram::~GLShaderProgram(void)
{
		if (vert_handle)
			 glDeleteShader(vert_handle);
		if (frag_handle)
			 glDeleteShader(frag_handle);
		if (prog_handle)
			 glDeleteProgram(vert_handle);
	
}
