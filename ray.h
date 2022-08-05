#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
	public:
		point3 orig;
		vec3 dir;
	public:
		ray() {}
		ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

		point3 origin() const {
			return orig;
		}
		vec3 direction() const {
			return dir;
		}

		//Ray formula: R(t) = a + tb 
		//This returns the point at a specific coordinate
		point3 at(double t) const {
			return orig + t*dir;
		}
};

#endif
