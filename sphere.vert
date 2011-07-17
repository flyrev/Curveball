attribute vec3 Position;
attribute vec2 texCoords;

uniform mat4 world;
uniform mat4 projView;

varying vec3 position;
varying vec2 texCoord;
varying vec3 normal;

varying vec3 lightposition;

void main()
{
	position=(world*vec4(Position, 1.0)).xyz;
	gl_Position = projView*vec4(position, 1.0);

	normal = normalize(Position.xyz);

	texCoord=texCoords;

	lightposition=(vec4(-100,-100,-100, 1.0)).xyz;
}
