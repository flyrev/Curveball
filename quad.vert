attribute vec2 position2;
attribute vec2 texCoords2;

varying vec2 texCoord;

uniform mat4 viewProj2;
uniform mat4 world;
 
void main()
{
	gl_Position = viewProj2*world*vec4(position2, 0.0, 1.0);	
	texCoord=texCoords2;
}