#ifndef _UTILITY_HEADER_H
#define _UTILITY_HEADER_H
	#if  !defined(CHECK_GL_ERROR) && defined(_DEBUG)
		#include <stdexcept>
		#include <GL/GLU.h>
		#include <sstream>
		#define CHECK_GL_ERROR { \
							GLint error_code; \
							std::stringstream error_string; \
							while ((error_code = glGetError())  != GL_NO_ERROR)\
							{ \
								error_string <<  "GL_ERROR: "<<(const unsigned char *) gluErrorString( error_code) << " at line " << __LINE__ <<" in file " << __FILE__ << "\n";\
							}\
							if ( error_string.str().size() != 0) \
								throw std::logic_error(error_string.str().c_str());\
						}
		
	#else
		#define CHECK_GL_ERROR
	#endif
#endif