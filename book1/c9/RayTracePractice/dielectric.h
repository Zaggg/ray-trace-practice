#pragma once
#include "material.h"
class dielectric :
	public material
{
public:
	dielectric()=default;
	dielectric(float ri) :ref_idx(ri) {};
	~dielectric()=default;

	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

	float ref_idx;
};

