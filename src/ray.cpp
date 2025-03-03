#include "ray.h"

Ray::Ray(const Vec3& o, const Vec3& d) : origen(o), direccion(d.normalize()) {}

    
Vec3 Ray::pointAt(float t) const {
    return origen + direccion *t;
}