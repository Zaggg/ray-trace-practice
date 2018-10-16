#include "material.h"

vec3 material::reflect(const vec3 & v, const vec3 & n) const
{
	return v - 2 * dot(v, n)*n;
}

//Snell's law
//see https://zhuanlan.zhihu.com/p/31127076 for complete formula
bool material::refract(const vec3 & v, const vec3 & n, float ni_over_nt, vec3 & refracted) const
{
	vec3 uv = unit_vector(v);
	float dt = dot(uv, n);
	//it's a just inner staff of a square root
	float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
	if (discriminant > 0)
	{
		refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
		return true;
	}
	else
	{
		return false;
	}
}

// it's not Fresnel equation but Schlick's approximation
// see more in https://zhuanlan.zhihu.com/p/31534769
// the ratio of reflection, r0 means the angle with normal is zero
float material::schlick(float cosine, float ref_idx) const
{
	//which means that reflection index cannot be 0
	float r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return r0 + (1 - r0)*pow((1 - cosine), 5);
}
