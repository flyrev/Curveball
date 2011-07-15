#include "vector.h"

vec3::vec3(float x, float y, float z)
	: x(data[0])
	, y(data[1])
	, z(data[2])
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

// Dereference operator
vec3::operator const float*() const
{
	return data;
}

vec3& vec3::operator=(const vec3 &vector)
{
	x=vector.x;
	y=vector.y;
	z=vector.z;
	
	return *this;
}
