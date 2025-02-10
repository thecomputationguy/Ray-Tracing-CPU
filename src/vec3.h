#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            
            return *this;
        }

        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            
            return *this;
        }

        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        std::ostream& operator<<(const vec3& v) {
            return std::cout<< v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
        }
        
        vec3 operator+(const vec3 &v) const {
            return vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
        }
        
        vec3 operator-(const vec3 &v) const {
            return vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
        }
        
        vec3 operator*(const vec3 &v) const {
            return vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
        }
        
        vec3 operator*(const double t) {
            return vec3(e[0] * t, e[1] * t, e[2] * t);
        }
        
        vec3 operator/(const double t) {
            return vec3(e[0] * (1/t), e[1] * (1/t), e[2] * (1/t));
        }
        
        double dot(const vec3& v) {
            return e[0] * v.e[0]
                 + e[1] * v.e[1]
                 + e[2] * v.e[2];
        }
        
        vec3 cross(const vec3& v) {
            return vec3(e[1] * v.e[2] - e[2] * v.e[1],
                        e[2] * v.e[0] - e[0] * v.e[2],
                        e[0] * v.e[1] - e[1] * v.e[0]);
        }
        
        vec3 unit_vector(const vec3& v) {
            return vec3(v) / v.length();
        }
};

// define a point as a vec3
using point3 = vec3;

#endif /* VEC3_H */
