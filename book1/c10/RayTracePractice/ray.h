#pragma once
#include "vec3.h"
#include "random_gen.h"
#define _USE_MATH_DEFINES
#include <math.h>

static random_gen rg;

class ray
{
public:
	ray()=default;
	~ray()=default;

	ray(const vec3& a, const vec3& b)
	{
		A = a;
		B = b;
	}
	vec3 origin() const
	{
		return A;
	}
	vec3 direction() const
	{
		return B;
	}
	vec3 point_at_parameter(float t) const
	{
		return A + t*B;
	}

	vec3 A;
	vec3 B;
};

static vec3 random_in_unit_sphere()
{
	vec3 p;
	do {
		p = 2.0*vec3(rg.dice(), rg.dice(), rg.dice()) - vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}