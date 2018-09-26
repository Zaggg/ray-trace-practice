#pragma once
#include "ray.h"

class camera
{
public:
	camera();
	~camera()=default;

	ray get_ray(float u, float v);

	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;
};

