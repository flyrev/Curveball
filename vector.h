#pragma once

class vec3
{
 public:
	vec3(float x, float y, float z);
	operator const float*() const;
	vec3& operator=(const vec3 &vector);
	vec3(const vec3&);
	float &x;
	float &y;
	float &z;
 private:
	float data[3];
};

class vec2
{
 public:
	vec2(float x, float y);
	operator const float*() const;
	vec2& operator=(const vec2 &vector);
	vec2(const vec2&);
	float &x;
	float &y;
 private:
	float data[2];
};
