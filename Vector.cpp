#include "vector.h"

vec3::vec3(float x, float y, float z)
{
	data[x] = x;
	data[y] = y;
	data[z] = z;
}

// Dereference operator
vec3::operator const float*() const
{
	return data;
}
