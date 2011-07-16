#ifndef __GEOMETRY_VECTORS_AND_STUFF_H 
#define __GEOMETRY_VECTORS_AND_STUFF_H

#include <cmath>
#include <GL/gl.h>
class vec2 
{
	float data[2];
public:
	float & x;
	float & y;

	vec2() : x(data[0]), y(data[1]) {}
	vec2( float x, float y) : x(data[0]), y(data[1]) { this->x = x; this->y = y; }
	vec2( const vec2 & copy): x(data[0]), y(data[1]) { *this = copy; }

	float length() const { return sqrt(x*x + y*y);}

	vec2 operator+( const vec2 &) const;
	vec2 operator-( const vec2 &) const;
	vec2 operator*( const vec2 &) const;
	vec2 operator*( float v) const;

	vec2 & operator*=( float v);
	vec2 & operator=(const vec2 & rhs);
	vec2 & operator-=(const vec2 & rhs);
	vec2 & operator+=(const vec2 & rhs);
	vec2 & operator*=(const vec2 & rhs);

	operator GLfloat*() 
	{
		return data;
	}
	
	operator const GLfloat*() const
	{
		return data;
	}

};

extern float dot( const vec2& lhs, const vec2 & rhs);

class vec3
{
	float data[3];
public:
	float & x;
	float & y;
	float & z;

	vec3(): x(data[0]), y(data[1]), z(data[2]){}
	vec3( float x, float y, float z) : x(data[0]), y(data[1]), z(data[2]) { this->x = x; this->y = y; this->z = z; }
	vec3( const vec3 & copy): x(data[0]), y(data[1]), z(data[2])  { *this = copy; }
	vec3( const vec2 & xy, float z) : x(data[0]), y(data[1]), z(data[2]) { this->x = xy.x; this->y = xy.y; this->z = z;}
	vec3( float z, const vec2 & yz) : x(data[0]), y(data[1]), z(data[2]) { this->x = x; this->y = yz.x; this->z = yz.y; }

	float length() const { return sqrt(x*x + y*y + z*z);}

	vec3 operator+( const vec3 &) const;
	vec3 operator-( const vec3 &) const;
	vec3 operator*( const vec3 &) const;
	vec3 operator*( float v) const;

	vec3 & operator*=( float v);
	vec3 & operator=(const vec3 & rhs);
	vec3 & operator-=(const vec3 & rhs);
	vec3 & operator+=(const vec3 & rhs);
	vec3 & operator*=(const vec3 & rhs);

	operator GLfloat*() 
	{
		return data;
	}
	
	operator const GLfloat*() const
	{
		return data;
	}

	
};

extern vec3 cross( const vec3& lhs, const vec3 & rhs );
extern float dot( const vec3& lhs, const vec3 & rhs);

class vec4 
{
	float data[4];
public:
	float & x;
	float & y;
	float & z;
	float & w;

	vec4() : x(data[0]), y(data[1]), z(data[2]), w(data[3]) {}
	vec4( float x, float y, float z, float w) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) { this->x = x; this->y = y; this->z = z; this->w = w; }
	vec4( const vec4 & copy): x(data[0]), y(data[1]), z(data[2]), w(data[3])  { *this = copy; }
	vec4( const vec3 & xyz, float w) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) { this->x = xyz.x; this->y = xyz.y; this->z = xyz.z; this->w = w;}
	vec4( float x, const vec3 & yzw) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) { this->x = x; this->y = yzw.x; this->z = yzw.y; this->w = yzw.z; }
	vec4( const vec2 & xy, const vec2 & zw) : x(data[0]), y(data[1]), z(data[2]), w(data[3]) { x = xy.x; y = xy.y; z = zw.x; w = zw.y; }

	float length() const { return sqrt(x*x + y*y + z*z + w*w);}
	
	vec4 operator+( const vec4 &) const;
	vec4 operator-( const vec4 &) const;
	vec4 operator*( const vec4 &) const;
	vec4 operator*( float v) const;

	vec4 & operator*=( float v);
	vec4 & operator=(const vec4 & rhs);
	vec4 & operator-=(const vec4 & rhs);
	vec4 & operator+=(const vec4 & rhs);
	vec4 & operator*=(const vec4 & rhs);
	
	
	operator GLfloat* () 
	{
		return data;
	}
	
	operator const GLfloat*() const
	{
		return data;
	}

};

extern float dot( const vec4& lhs, const vec4 & rhs);


extern vec2 normalize( const vec2 & v);

extern vec3 normalize( const vec3 & v);

extern vec4 normalize( const vec4 & v);




//////////////////////////////////////////////////////////
/////////////      Matrices 
//////////////////////////////////////////////////////////

class mat2
{
	float data[4];
	static inline int index(int row, int column) { return row + column*2; }

public:
	mat2(){}
	mat2( vec2 row1, vec2 row2 ) 
	{ 
		Get(0,0) = row1.x;
		Get(0,1) = row1.y;
		Get(1,0) = row2.x;
		Get(1,1) = row2.y;
	}

	mat2( float r0c0, float r0c1, float r1c0, float r1c1) 
	{ 
		Get(0,0) = r0c0;
		Get(0,1) = r0c1;
		Get(1,0) = r1c0;
		Get(1,1) = r1c1;
	}

	float & Get(int row, int column) { return data[index(row, column)]; }
	float Get(int row, int column) const { return data[index(row, column)]; }

	operator GLfloat*() 
	{
		return data;
	}
	operator const GLfloat*() const
	{
		return data;
	}

	mat2 operator * ( const mat2 & rhs) const
	{
		return mat2( Get(0,0)*rhs.Get(0,0) + Get(0,1)*rhs.Get(1,0)
					,Get(0,0)*rhs.Get(0,1) + Get(0,1)*rhs.Get(1,1)
					,Get(1,0)*rhs.Get(0,0) + Get(1,1)*rhs.Get(1,0)
					,Get(1,0)*rhs.Get(0,1) + Get(1,1)*rhs.Get(1,1) );
	}

	mat2 & operator *= ( const mat2 & rhs)
	{
				return	*this = (*this) * rhs;
	}

	vec2 operator*(const vec2 & rhs) const
	{
		return vec2( Get(0,0)*rhs.x + Get(0,1)*rhs.y
					,Get(1,0)*rhs.x + Get(1,1)*rhs.y );
	}

	mat2 operator*( float v ) const
	{
		mat2 temp(*this);
		for (int i = 0; i < 4; i++)
			temp.data[i] *= v;
		return temp;
	}

	mat2 & operator*= ( float v)
	{
		for (int i = 0; i < 4; i++)
			this->data[i] *= v;
		return *this;
	}

	mat2 operator+ ( const mat2 & rhs) const
	{
		return mat2( Get(0,0) + rhs.Get(0,0), Get(0,1) + rhs.Get(0,1), Get(1,0) + rhs.Get(1,0), Get(1,1) + rhs.Get(1,1));
	}

	mat2 & operator+= ( const mat2 & rhs)
	{
		Get(0,0) += rhs.Get(0,0);
		Get(0,1) += rhs.Get(0,1); 
		Get(1,0) += rhs.Get(1,0); 
		Get(1,1) += rhs.Get(1,1);
		return *this;
	}

	static mat2 Identity() { return mat2( 1,0,0,1 );}

	static mat2 Rotation( float rad_angle )
	{
		return mat2( cos(rad_angle), -sin(rad_angle), sin(rad_angle), cos(rad_angle));
	}

};

class mat3
{
	static const int n = 9;
	float data[n];
	
	static inline int index(int row, int column) { return row + column*3; }

public:
	mat3(){}
	mat3( vec3 row1, vec3 row2, vec3 row3 ) 
	{ 
		Get(0,0) = row1.x;
		Get(0,1) = row1.y;
		Get(0,2) = row1.z;
		
		Get(1,0) = row2.x;
		Get(1,1) = row2.y;
		Get(1,2) = row2.z;

		Get(2,0) = row3.x;
		Get(2,1) = row3.y;
		Get(2,2) = row3.z;
	}

	mat3( float r0c0, float r0c1, float r0c2
		, float r1c0, float r1c1, float r1c2
		, float r2c0, float r2c1, float r2c2) 
	{ 
		Get(0,0) = r0c0;
		Get(0,1) = r0c1;
		Get(0,2) = r0c2;

		Get(1,0) = r1c0;
		Get(1,1) = r1c1;
		Get(1,2) = r1c2;

		Get(2,0) = r2c0;
		Get(2,1) = r2c1;
		Get(2,2) = r2c2;
	}

	float & Get(int row, int column) { return data[index(row, column)]; }
	float Get(int row, int column) const { return data[index(row, column)]; }

	operator GLfloat*() 
	{
		return data;
	}
	operator const GLfloat*() const
	{
		return data;
	}

	mat3 operator * ( const mat3 & rhs) const
	{
		return mat3( Get(0,0)*rhs.Get(0,0) + Get(0,1)*rhs.Get(1,0) + Get(0,2)*rhs.Get(2,0)
					,Get(0,0)*rhs.Get(0,1) + Get(0,1)*rhs.Get(1,1) + Get(0,2)*rhs.Get(2,1)
					,Get(0,0)*rhs.Get(0,2) + Get(0,1)*rhs.Get(1,2) + Get(0,2)*rhs.Get(2,2)
					
					,Get(1,0)*rhs.Get(0,0) + Get(1,1)*rhs.Get(1,0) + Get(1,2)*rhs.Get(2,0)
					,Get(1,0)*rhs.Get(0,1) + Get(1,1)*rhs.Get(1,1) + Get(1,2)*rhs.Get(2,1)
					,Get(1,0)*rhs.Get(0,2) + Get(1,1)*rhs.Get(1,2) + Get(1,2)*rhs.Get(2,2)

					,Get(2,0)*rhs.Get(0,0) + Get(2,1)*rhs.Get(1,0) + Get(2,2)*rhs.Get(2,0)
					,Get(2,0)*rhs.Get(0,1) + Get(2,1)*rhs.Get(1,1) + Get(2,2)*rhs.Get(2,1)
					,Get(2,0)*rhs.Get(0,2) + Get(2,1)*rhs.Get(1,2) + Get(2,2)*rhs.Get(2,2)
					);
	}

	mat3 & operator *= ( const mat3 & rhs)
	{
				return	*this = (*this) * rhs;
	}

	vec3 operator*(const vec3 & rhs) const
	{
		return vec3( Get(0,0)*rhs.x+ Get(0,1)*rhs.y + Get(0,2)*rhs.z
					,Get(1,0)*rhs.x+ Get(1,1)*rhs.y + Get(1,2)*rhs.z
					,Get(2,0)*rhs.x+ Get(2,1)*rhs.y + Get(2,2)*rhs.z
					);
	}

	mat3 operator*( float v ) const
	{
		mat3 temp(*this);
		for (int i = 0; i < n; i++)
			temp.data[i] *= v;
		return temp;
	}

	mat3 & operator*= ( float v)
	{
		for (int i = 0; i < n; i++)
			this->data[i] *= v;
		return *this;
	}

	mat3 operator+ ( const mat3 & rhs) const
	{
		mat3 temp(*this);
		for ( int i = 0; i < n; i++)
			temp.data[i] *= rhs.data[i];
		return temp;
	}

	mat3 & operator+= ( const mat3 & rhs)
	{
		for ( int i = 0; i < n; i++)
			this->data[i] *= rhs.data[i];
		return *this;
		
	}

	static mat3 Identity() { return mat3( 1,0,0,0,1,0,0,0,1 );}
	static mat3 Rotation( const vec3 & axis, float rad_angle)
	{
		vec3 u = normalize( axis );
		float Sin = sin(rad_angle);
		float Cos = cos(rad_angle);
		float OneMinusCos = 1.0f-Cos;

		return mat3( Cos + u.x*u.x*(OneMinusCos) , u.x*u.y*(OneMinusCos) - u.z*Sin, u.x*u.z*(OneMinusCos) + u.y*Sin,
					u.y*u.x*(OneMinusCos) + u.z*Sin, Cos + u.y*u.y*(OneMinusCos), u.y*u.z*(OneMinusCos) - u.x*Sin,
					u.z*u.x*(OneMinusCos) - u.y*Sin, u.z*u.y*(OneMinusCos) + u.x*Sin, Cos + u.z*u.z*(OneMinusCos));
	}
};

class mat4
{
	static const int n = 16;
	float data[n];
	
	static inline int index(int row, int column) { return row + column*4; }

public:
	mat4(){}

	mat4( const vec4 & row1, const vec4 &row2, const vec4 & row3, const vec4 & row4 ) 
	{ 
		Get(0,0) = row1.x;
		Get(0,1) = row1.y;
		Get(0,2) = row1.z;
		Get(0,3) = row1.w;
		
		Get(1,0) = row2.x;
		Get(1,1) = row2.y;
		Get(1,2) = row2.z;
		Get(1,3) = row2.w;
		
		Get(2,0) = row3.x;
		Get(2,1) = row3.y;
		Get(2,2) = row3.z;
		Get(2,3) = row3.w;
		
		Get(3,0) = row4.x;
		Get(3,1) = row4.y;
		Get(3,2) = row4.z;
		Get(3,3) = row4.w;
	}

	mat4( float r0c0, float r0c1, float r0c2, float r0c3
		, float r1c0, float r1c1, float r1c2, float r1c3
		, float r2c0, float r2c1, float r2c2, float r2c3
		, float r3c0, float r3c1, float r3c2, float r3c3) 
	{ 
		Get(0,0) = r0c0;
		Get(0,1) = r0c1;
		Get(0,2) = r0c2;
		Get(0,3) = r0c3;
		
		Get(1,0) = r1c0;
		Get(1,1) = r1c1;
		Get(1,2) = r1c2;
		Get(1,3) = r1c3;
		
		Get(2,0) = r2c0;
		Get(2,1) = r2c1;
		Get(2,2) = r2c2;
		Get(2,3) = r2c3;
		
		Get(3,0) = r3c0;
		Get(3,1) = r3c1;
		Get(3,2) = r3c2;
		Get(3,3) = r3c3;
	}

	float & Get(int row, int column) { return data[index(row, column)]; }
	float Get(int row, int column) const { return data[index(row, column)]; }

	operator GLfloat*() 
	{
		return data;
	}
	operator const GLfloat*() const
	{
		return data;
	}

	mat4 operator * ( const mat4 & rhs) const
	{
		return mat4( Get(0,0)*rhs.Get(0,0) + Get(0,1)*rhs.Get(1,0) + Get(0,2)*rhs.Get(2,0) + Get(0,3)*rhs.Get(3,0) 
					,Get(0,0)*rhs.Get(0,1) + Get(0,1)*rhs.Get(1,1) + Get(0,2)*rhs.Get(2,1) + Get(0,3)*rhs.Get(3,1)
					,Get(0,0)*rhs.Get(0,2) + Get(0,1)*rhs.Get(1,2) + Get(0,2)*rhs.Get(2,2) + Get(0,3)*rhs.Get(3,2)
					,Get(0,0)*rhs.Get(0,3) + Get(0,1)*rhs.Get(1,3) + Get(0,2)*rhs.Get(2,3) + Get(0,3)*rhs.Get(3,3)
					
					,Get(1,0)*rhs.Get(0,0) + Get(1,1)*rhs.Get(1,0) + Get(1,2)*rhs.Get(2,0) + Get(1,3)*rhs.Get(3,0) 
					,Get(1,0)*rhs.Get(0,1) + Get(1,1)*rhs.Get(1,1) + Get(1,2)*rhs.Get(2,1) + Get(1,3)*rhs.Get(3,1)
					,Get(1,0)*rhs.Get(0,2) + Get(1,1)*rhs.Get(1,2) + Get(1,2)*rhs.Get(2,2) + Get(1,3)*rhs.Get(3,2)
					,Get(1,0)*rhs.Get(0,3) + Get(1,1)*rhs.Get(1,3) + Get(1,2)*rhs.Get(2,3) + Get(1,3)*rhs.Get(3,3)
					
					,Get(2,0)*rhs.Get(0,0) + Get(2,1)*rhs.Get(1,0) + Get(2,2)*rhs.Get(2,0) + Get(2,3)*rhs.Get(3,0) 
					,Get(2,0)*rhs.Get(0,1) + Get(2,1)*rhs.Get(1,1) + Get(2,2)*rhs.Get(2,1) + Get(2,3)*rhs.Get(3,1)
					,Get(2,0)*rhs.Get(0,2) + Get(2,1)*rhs.Get(1,2) + Get(2,2)*rhs.Get(2,2) + Get(2,3)*rhs.Get(3,2)
					,Get(2,0)*rhs.Get(0,3) + Get(2,1)*rhs.Get(1,3) + Get(2,2)*rhs.Get(2,3) + Get(2,3)*rhs.Get(3,3)
					
					,Get(3,0)*rhs.Get(0,0) + Get(3,1)*rhs.Get(1,0) + Get(3,2)*rhs.Get(2,0) + Get(3,3)*rhs.Get(3,0) 
					,Get(3,0)*rhs.Get(0,1) + Get(3,1)*rhs.Get(1,1) + Get(3,2)*rhs.Get(2,1) + Get(3,3)*rhs.Get(3,1)
					,Get(3,0)*rhs.Get(0,2) + Get(3,1)*rhs.Get(1,2) + Get(3,2)*rhs.Get(2,2) + Get(3,3)*rhs.Get(3,2)
					,Get(3,0)*rhs.Get(0,3) + Get(3,1)*rhs.Get(1,3) + Get(3,2)*rhs.Get(2,3) + Get(3,3)*rhs.Get(3,3)
					);
	}

	mat4 & operator *= ( const mat4 & rhs)
	{
				return	*this = (*this) * rhs;
	}

	vec4 operator*(const vec4 & rhs) const
	{
		return vec4( Get(0,0)*rhs.x + Get(0,1)*rhs.y + Get(0,2)*rhs.z + Get(0,3)*rhs.w 
					,Get(1,0)*rhs.x + Get(1,1)*rhs.y + Get(1,2)*rhs.z + Get(1,3)*rhs.w 
					,Get(2,0)*rhs.x + Get(2,1)*rhs.y + Get(2,2)*rhs.z + Get(2,3)*rhs.w 
					,Get(3,0)*rhs.x + Get(3,1)*rhs.y + Get(3,2)*rhs.z + Get(3,3)*rhs.w 
					);
	}

	mat4 operator*( float v ) const
	{
		mat4 temp(*this);
		for (int i = 0; i < n; i++)
			temp.data[i] *= v;
		return temp;
	}

	mat4 & operator*= ( float v)
	{
		for (int i = 0; i < n; i++)
			this->data[i] *= v;
		return *this;
	}

	mat4 operator+ ( const mat4 & rhs) const
	{
		mat4 temp(*this);
		for ( int i = 0; i < n; i++)
			temp.data[i] *= rhs.data[i];
		return temp;
	}

	mat4 & operator+= ( const mat4 & rhs)
	{
		for ( int i = 0; i < n; i++)
			this->data[i] *= rhs.data[i];
		return *this;	
	}

	static mat4 Identity() { return mat4( 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);}

	static mat4 Translation( const vec3 & trans_vec)
	{
		return mat4( vec4(1,0,0,0), vec4(0,1,0,0), vec4(0,0,1,0), vec4( trans_vec ,1));
	}

	static mat4 Rotation(const vec3 & axis, float rad_angle)
	{
		vec3 u = normalize( axis );
		float Sin = sin(rad_angle);
		float Cos = cos(rad_angle);
		float OneMinusCos = 1.0f-Cos;

		return mat4( Cos + u.x*u.x*(OneMinusCos) , u.x*u.y*(OneMinusCos) - u.z*Sin, u.x*u.z*(OneMinusCos) + u.y*Sin, 0,
					u.y*u.x*(OneMinusCos) + u.z*Sin, Cos + u.y*u.y*(OneMinusCos), u.y*u.z*(OneMinusCos) - u.x*Sin, 0, 
					u.z*u.x*(OneMinusCos) - u.y*Sin, u.z*u.y*(OneMinusCos) + u.x*Sin, Cos + u.z*u.z*(OneMinusCos), 0,
					0,0,0,1);
	}

	static mat4 Projection( float near, float far, float h_fov_in_rad, float aspect )
	{
		float r = near * tan(h_fov_in_rad/2);
		float t = r*aspect;
		

		return mat4(	near/r, 0, 0, 0,
						0, near/t, 0, 0,
						0,0, -(far+near)/(far-near), -2*far*near/(far-near),
						0,0,-1,0);
	}
};

extern mat4 operator * (float v, const mat4 & m);
extern mat3 operator * (float v, const mat3 & m);
extern mat2 operator * (float v, const mat2 & m);



#endif
