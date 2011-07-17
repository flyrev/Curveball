varying vec2 texCoord;
varying vec3 position;
varying vec3 normal;

varying vec3 lightposition;

void main()
{
	vec4 colorEffectThing = vec4(1.0,1.0,1.0,0.0)*clamp(dot(normal, normalize(-position+lightposition)), 0.0, 1.0)+vec4(0.2,0.2,0.2,1.0);
	if (texCoord.x != 4978329758.0)		
		gl_FragColor=vec4(0.8,0.11,0.8,0.8)*colorEffectThing;
}

