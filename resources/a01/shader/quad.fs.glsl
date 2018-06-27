#version 330
  
layout(location = 0)  out vec4 out0; // color 

in vec2 tc;

uniform sampler2D diffuse;
uniform sampler2D normal;
uniform sampler2D position;
uniform sampler2D depth;

uniform vec3 lightDir;
uniform mat4 viewMatrix;
uniform int debug;

const float shinyness = 32.0;
const vec3 specColor = vec3(0.4, 0.4, 0.4);

void main() 
{ 

	vec3 col = vec3(0,0,0);
	vec2 TC = tc;

	if (debug == 1) {
		gl_FragDepth = -0.5;

		if (TC.y > 0.5) {
			TC.y -= 0.5;
			if (TC.x < 0.5) col = texture2D(diffuse, TC*vec2(2,2)).rgb;
			else			col = texture2D(normal, (TC-vec2(0.5,0))*vec2(2,2)).rgb;
		}
		else {
			if (TC.x < 0.5) col = vec3(texture2D(depth, TC*vec2(2,2)).r);
			else			col = texture2D(position, (TC-vec2(0.5,0))*vec2(2,2)).rgb;
		}
	}
	else {
		// TODO A1 (a)
	}

	out0 = vec4(col, 1.0);
}
