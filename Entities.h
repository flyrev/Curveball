#pragma once

#include "geometry.h"

const double PI = acos(-1);

class Ball
{
	vec3 rotation_axis;
	float rotation;
	float spin;

	vec3 position;
	vec3 velocity;
	float radius;

	vec3 magnus_effect()
	{
		const float S = 5;
		return cross( rotation_axis*spin, velocity );
	}

	

public:
	/** Interval is the time since the last update, in game-time. */
	void Update( double interval) 
	{
		velocity += magnus_effect()*interval;
		position += velocity;

		rotation += spin;
		if ( rotation < 0.0f)
			rotation += 2*PI;
		else if ( rotation >= 2*PI )
			rotation -= 2*PI;



		
		
	}


};

