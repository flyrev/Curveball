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

float dot( const vec2& lhs, const vec2 & rhs)
{
	return lhs.x * rhs.x + lhs.y*rhs.y;
}

vec3 cross( const vec3& lhs, const vec3 & rhs )
{
	return vec3(lhs.y*rhs.z - lhs.z*rhs.y, rhs.x*lhs.z -lhs.x*rhs.z, lhs.y*rhs.z - rhs.y*lhs.z );
}

float dot( const vec3& lhs, const vec3 & rhs)
{
	return lhs.x * rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

float dot( const vec4& lhs, const vec4 & rhs)
{
	return lhs.x * rhs.x + lhs.y*rhs.y + lhs.z*rhs.z + lhs.w*rhs.w;
}


vec2 normalize( const vec2 & v)
{
	return v*(1.0f/v.length());
}

vec3 normalize( const vec3 & v)
{
	return v*(1.0f/v.length());
}

vec4 normalize( const vec4 & v)
{
	return v*(1.0f/v.length());
}

