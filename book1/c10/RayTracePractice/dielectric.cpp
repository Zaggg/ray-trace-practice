#include "dielectric.h"

bool dielectric::scatter(const ray & r_in, const hit_record & rec, vec3 & attenuation, ray & scattered) const
{
	vec3 outward_normal;
	vec3 reflected = reflect(r_in.direction(), rec.normal);
	float ni_over_nt;
	// here in book was written wrong as (1.0,1.0,0.0);
	attenuation = vec3(1.0, 1.0, 1.0);
	vec3 refracted;
	float reflect_prob;
	float cosine;
	// normal start from center of sphere which set in hit function of sphere
	if (dot(r_in.direction(), rec.normal) > 0)
	{
		outward_normal = -rec.normal;
		// the refractive index of air near to 1;
		// the ref_idx looks like material/air
		// so when they are in different direction, let index be divided by 1
		ni_over_nt = ref_idx;
		cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
	}
	else
	{
		outward_normal = rec.normal;
		ni_over_nt = 1.0 / ref_idx;
		cosine = - dot(r_in.direction(), rec.normal) / r_in.direction().length();
	}

	// it will cause no reflection ray be counted;
	if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
	{
		reflect_prob = schlick(cosine, ref_idx);
	}
	else
	{
		//scattered = ray(rec.p, reflected);
		reflect_prob = 1.0;
	}


	if (rg.dice() < reflect_prob)
	{
		scattered = ray(rec.p, reflected);
	}
	else
	{
		scattered = ray(rec.p, refracted);
	}
	return true;
}
