Sphere::Sphere(float radius, unsigned int rings, unsigned int sectors)
{
	float const R = 1./(float)(rings-1);
	float const S = 1./(float)(sectors-1);
	int r, s;
	
	sphere_vertices = new GLfloat[rings * sectors * 3];
	sphere_normals = new GLfloat[rings * sectors * 3];
	sphere_texcoords = new GLfloat[rings * sectors * 2];
	
	GLfloat *v = sphere_vertices;
	GLfloat *n = sphere_normals;
	GLFloat *t = sphere_texcoords;
	
	for(r = 0; r < rings; r++) 
		for(s = 0; s < sectors; s++) {
			float const y = sin( -M_PI_2 + M_PI * r * R );
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
	
	sphere_indices = new GLfloat[rings * sectors * 4];
	GLushort *i = sphere_indices;
	
	for(r = 0; r < rings; r++) 
		for(s = 0; s < sectors; s++) {
			*i++ = r * sectors + s;
			*i++ = r * sectors + (s+1);
			*i++ = (r+1) * sectors + (s+1);
			*i++ = (r+1) * sectors + s;
		}
}
