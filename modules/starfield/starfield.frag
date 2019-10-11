#version 430
#include "cnovr.glsl"

layout(location = 19) uniform vec4 props;

out vec4 colorOut;

in vec3 localpos;
in vec4 extradata;
in vec3 comprgb;

//uint16_t magnitude_mag1000;
//int16_t bvcolor_mag1000;
//int16_t vicolor_mag1000;

layout(location = 8) uniform sampler2D textures[];

void main()
{
	//float mag = (14.-extradata.x)/14.;
	float mag = 5./extradata.x; //pow( extradata.x, 10. );
	if( mag < .1 ) mag = .1;

	vec3 rgb = mix( normalize( comprgb ), vec3(1.), .5 );
	colorOut = vec4( rgb, 1.0 ) * mag;
}