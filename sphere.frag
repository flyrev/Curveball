varying vec2 texCoord;
varying vec3 position;
varying vec3 normal;

varying vec3 lightposition;

void main()
{
	vec4 colorEffectThing = vec4(0.8,0.8,0.8,0)*clamp(0.0,1.0, dot(normal, normalize(position-lightposition)))+vec4(0.2,0.2,0.2,1.0);
	if (texCoord.x != 10038098)
		gl_FragColor=vec4(texCoord.xy,0.8,0.8)*colorEffectThing;

}

