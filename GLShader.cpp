#include "GLShader.h"
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

#define CHECK_GL_ERROR 

template <class T>
class Array
{
	T* data;
	size_t m_size, m_capacity;
public:
	Array()
		: data(0)
		, m_size(0)
	{}
	Array( const & Array<T> other)
	{
		reserve( other.capacity);
		for (int  i = 0; i < other.m_size; i++)
			data[i] = other.data[i];
		
		size = other->size;
	}

	Array( size_t size )
	{
		reserve(size);
		size = 0;
	}

	void reserve( size_t capacity )
	{
		m_capacity = capacity;
		m_size = min( m_size, m_capacity );

		T* temp = data;
		data = new T[capacity];

		if ( temp )
		{
			for (int i = 0; i < m_size; i++)
				data[i] = temp[i];
			delete temp;
		}
	}

	operator const T*() const
	{
		return data;
	}

	const T & operator[](size_t pos) const 
	{
		return data[pos];
	}

	T & operator[] ( size_t pos )
	{
		return data[pos];
	}

	void add( const T & obj)
	{
		if (m_size == m_capacity)
			reserve(m_size + msize/2 + 1);
		
		data[m_size++] = obj;
	}

	size_t size() const { return m_size; }

	void clear( bool dynamically_allocated = false)
	{
		if ( dynamically_allocated )
			for ( int i = 0; i < m_size; i++)
				if ( data[i] )
					delete data[i];
		reserve(0);
};

		


GLShaderProgram::GLShaderProgram(const char * filename)
	: vert_handle(0)
	, frag_handle(0)
	, prog_handle(0)
	, filename_base(filename)
{
	Reload();

}



	



void GLShaderProgram::Reload()
{
	
	// Temporary vertex objects
	unsigned int t_vert_handle = 0, t_frag_handle = 0, t_prog_handle = 0;

	try {

		Array<char * > vertex_shader_source;
		Array<int> vertex_shader_source_line_lengths;
		Array<int> fragment_shader_source_line_lengths;
		Array<char * > fragment_shader_source;

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
		glShaderSource(t_vert_handle, vertex_shader_source.size(), vertex_shader_source, vertex_shader_source_line_lengths);

		glCompileShader(t_vert_handle);

		int iv = 0;
		glGetShaderiv( t_vert_handle, GL_COMPILE_STATUS, &iv )
		if (  iv == GL_FALSE)
		{
			getShaderiv( t_vert_handle, GL_INFO_LOG_LENGTH, &iv)
			char * temp = new char [iv];
			getShaderInfoLog( t_vert_handle, iv, &iv, temp);
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
	
		t_frag_handle = glCreateShader( GL_VERTEX_SHADER );
		glShaderSource(t_frag_handle, fragment_shader_source.size(), fragment_shader_source, fragment_shader_source_line_lengths);

		glCompileShader(t_frag_handle);

		iv = 0;
		glGetShaderiv( t_frag_handle, GL_COMPILE_STATUS, &iv );
		if (  iv == GL_FALSE)
		{
			getShaderiv( t_frag_handle, GL_INFO_LOG_LENGTH, &iv);
			char * temp = new char [iv];
			getShaderInfoLog( t_frag_handle, iv, &iv, temp);
			runtime_error exc( string("Vertex shader error:\n").append(temp) );
			delete [] temp;
			throw exc;
		}

		in.close();
		fragment_shader_source_line_lengths.clear();
		fragment_shader_source.clear(true);
		vertex_shader_source_line_lengths.clear();
		vertex_shader_source.clear(true);

		t_prog_handle = glCreateProgram();

		glAttachShader(	t_prog_handle, t_vert_handle);
		glAttachShader(	t_prog_handle, t_frag_handle);

		glLinkProgram( t_prog_handle );

		glGetProgramiv( t_prog_handle, GL_LINK_STATUS, iv);

		if (  iv == GL_FALSE )
		{
			getProgramiv( t_prog_handle, GL_INFO_LOG_LENGTH, &iv);
			char * temp = new char [iv];
			getProgramInfoLog( t_prog_handle, iv, &iv, temp);
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
