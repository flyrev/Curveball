attribute vec3 position;
varying vec3 normal;
uniform mat4 rotation;
 
void main()
{
	gl_Position = rotation*vec4(position,1.0);
	gl_Position.xy*=2;
	normal = position;
}