#include "vec3.h"

#include <cmath>

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);    
}


Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
}


float Vec3::dot(const Vec3& v) const {
    return x * v.x + y * v.y + z * v.z;
}


Vec3 Vec3::operator*(float s) const{
    return Vec3(x * s, y * s, z * s);
}


Vec3 Vec3::normalize() const{
    float magnitud = std::sqrt(x * x + y * y + z * z);
    return Vec3(x / magnitud, y / magnitud, z / magnitud);
}