#include "sphere.h"
#include <cmath>
#ifdef _WIN32
	const double M_PI = cos(-1.0);
#endif

Sphere::Sphere(float radius, unsigned int rings, unsigned int sectors)
	: rings(rings),
	  sectors(sectors)
{
	float const R = 1./(float)(rings-1);
	float const S = 1./(float)(sectors-1);
	int r, s;
	
	vertices = new GLfloat[rings * sectors * 3];
	normals = new GLfloat[rings * sectors * 3];
	texcoords = new GLfloat[rings * sectors * 2];
	
	GLfloat *v = vertices;
	GLfloat *n = normals;
	GLfloat *t = texcoords;
	
	for(r = 0; r < rings; r++) 
		for(s = 0; s < sectors; s++) {
			float const y = sin( -0.5*M_PI + M_PI * r * R );
			float const x = cos(2*M_PI * s * S) * sin( M_PI * r * R );
			float const z = sin(2*M_PI * s * S) * sin( M_PI * r * R );
			
			*t++ = s*S;
			*t++ = r*R;
			
			*v++ = x * radius;
			*v++ = y * radius;
			*v++ = z * radius;
			
			*n++ = x;
			*n++ = y;
			*n++ = z;
		}
	
	indices = new uint16_t[rings * sectors * 6];

	uint16_t *i = indices;
	
	for(r = 0; r < rings; r++) 
		for(s = 0; s < sectors; s++) {
			*i++ = r * sectors + s;
			*i++ = (r) * sectors + (s+1);
			*i++ = (r+1) * sectors + (s);

			*i++ = (r+1) * sectors + (s);
			*i++ = (r) * sectors + (s+1);
			*i++ = (r+1) * sectors + (s+1);
		}
}
