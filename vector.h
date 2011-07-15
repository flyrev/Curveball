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
