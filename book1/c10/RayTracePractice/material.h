#pragma once
#include "ray.h"
#include "hitable.h"

class material
{
public:
	material()=default;
	~material()=default;

	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
	vec3 reflect(const vec3& v, const vec3& n) const;
	bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted) const;
	float schlick(float cosine, float ref_idx) const;
};

