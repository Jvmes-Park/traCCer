#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

//3 point vector class
class vec3 {
	public:
		double e[3];
	public:
		//e -> edges
        	vec3() : e{0,0,0} {}
        	vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
	
        	double x() const { return e[0]; }
        	double y() const { return e[1]; }
        	double z() const { return e[2]; }

		//negation operator
        	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        	double operator[](int i) const { return e[i]; }
        	double& operator[](int i) { return e[i]; }

		//adding another vector
        	vec3& operator+=(const vec3 &v) {
        	    e[0] += v.e[0];
            	    e[1] += v.e[1];
		    e[2] += v.e[2];
            	    return *this;
      	 	}

		//scale multiplication
	        vec3& operator*=(const double t) {
	            e[0] *= t;
	            e[1] *= t;
	            e[2] *= t;
	            return *this;
	        }
	
		//scale division
	        vec3& operator/=(const double t) {
	            return *this *= 1/t;
	        }
	
        	double length() const {
        	    return std::sqrt(length_squared());
        	}
	
	        double length_squared() const {
	            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	        }
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

//VECTOR UTILITIES: operations for vectors that are not part of the original vector in class

//Outputing the vector's 3 points
inline std::ostream& operator<<(std::ostream &out, vec3 &v) {
	return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

//adding 2 vectors
inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

//subtracting 2 vectors
inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}
//multiplying 2 vectors
inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}
//scale mutliplication
inline vec3 operator*(double t, const vec3 &v) {
	return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}
//single multiplication
inline vec3 operator*(const vec3 &v, double t) {
	return t * v;
}
//scale division
inline vec3 operator/(vec3 v, double t) {
	return (1/t) * v;
}
//dot product
inline double dot(const vec3 &v1, const vec3 &v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}
//cross product
inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1], 
		    v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
		    v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

//a unit vector. which is a vector that is all 0's except for 1's diagonal across it
inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

#endif
