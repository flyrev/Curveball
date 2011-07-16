attribute vec3 position;
varying vec3 normal;
 
void main()
{
	gl_Position = vec4(position,1.0);
	gl_Position.xy*=2;
	normal = position;
}