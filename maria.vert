attribute vec3 position;

uniform mat4 projView;
 
void main()
{
	gl_Position = projView*vec4(position,1);
}