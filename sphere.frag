varying vec3 normal;

const vec3 lightposition=vec3(100,10,0);

void main()
{
	vec4 colorEffectThing = vec4(0.8,0.8,0.8,0)*dot(normal,clamp(0.0,1.0,(gl_FragCoord-lightposition)))+vec4(0.2,0.2,0.2,1.0);
	gl_FragColor=vec4(0.0,1.0,0.8,0.8)*colorEffectThing;
}