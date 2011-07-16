#include "geometry.h"

// Vec2
vec2 vec2::operator+( const vec2 & rhs) const
{
	return vec2( x + rhs.x, y+ rhs.y);
}
vec2 vec2::operator-( const vec2 & rhs) const
{
	return vec2( x - rhs.x, y- rhs.y);
}
vec2 vec2::operator*( const vec2 & rhs) const
{
	return vec2( x * rhs.x, y* rhs.y);
}
	
vec2 & vec2::operator=(const vec2 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}
vec2 & vec2::operator*=(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::operator*( float v) const
{
	return vec2( x*v, y*v);
}
vec2 & vec2::operator*=( float v)
{
	x *= v;
	y *= v;
	return *this;
}

//Vec3
vec3 vec3::operator+( const vec3 & rhs) const
{
	return vec3( x + rhs.x, y+ rhs.y, z+ rhs.z);
}
vec3 vec3::operator-( const vec3 & rhs) const
{
	return vec3( x - rhs.x, y- rhs.y, z- rhs.z);
}
vec3 vec3::operator*( const vec3 & rhs) const
{
	return vec3( x * rhs.x, y* rhs.y, z* rhs.z);
}
	
vec3 & vec3::operator=(const vec3 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}
vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
vec3 & vec3::operator*=(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}
	
vec3 vec3::operator*( float v) const
{
	return vec3( x*v, y*v, z*v);
}
vec3 & vec3::operator*=( float v)
{
	x *= v;
	y *= v;
	z *= v;
	return *this;
}

// Vec 4
vec4 vec4::operator+( const vec4 & rhs) const
{
	return vec4( x + rhs.x, y+ rhs.y, z+ rhs.z, w+ rhs.w);
}
vec4 vec4::operator-( const vec4 & rhs) const
{
	return vec4( x - rhs.x, y- rhs.y, z- rhs.z, w- rhs.w);
}
vec4 vec4::operator*( const vec4 & rhs) const
{
	return vec4( x * rhs.x, y* rhs.y, z* rhs.z, w* rhs.w);
}
	
vec4 & vec4::operator=(const vec4 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}
vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}
vec4 & vec4::operator*=(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}
	
vec4 vec4::operator*( float v) const
{
	return vec4( x*v, y*v, z*v, w*v);
}
vec4 & vec4::operator*=( float v)
{
	x *= v;
	y *= v;
	z *= v;
	w *= v;
	return *this;
}