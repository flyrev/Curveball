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

vec3::vec3(const vec3& vector)
	: x(data[0])
	, y(data[1])
	, z(data[2])
{
	data[0] = vector.x;
	data[1] = vector.y;
	data[2] = vector.z;
}



// vec2 begins HIAR


vec2::vec2(float x, float y)
	: x(data[0])
	, y(data[1])
{
	data[0] = x;
	data[1] = y;
}

// Dereference operator
vec2::operator const float*() const
{
	return data;
}

vec2& vec2::operator=(const vec2 &vector)
{
	x=vector.x;
	y=vector.y;
	
	return *this;
}

vec2::vec2(const vec2& vector)
	: x(data[0])
	, y(data[1])
{
	data[0] = vector.x;
	data[1] = vector.y;
}
