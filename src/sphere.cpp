#include "sphere.h"

#include <cmath>

Sphere::Sphere(const Vec3& c, float r) : centro(c), radio(r) {}


bool Sphere::intersection(const Ray& rayo, float& t0) const {
    Vec3 oc = rayo.origen - centro; // Vector desde el origen del rayo al centro de la esfera.
    float a = rayo.direccion.dot(rayo.direccion);
    float b = 2.0f * oc.dot(rayo.direccion);
    float c = oc.dot(oc) - radio * radio;
    float discriminante = b * b - 4 * a * c;

    if (discriminante < 0) return false; // No hay intersección.
    float sqrtD = std::sqrt(discriminante);
    float t1 = (-b - sqrtD) / (2.0f * a);
    float t2 = (-b + sqrtD) / (2.0f * a);

    // Se selecciona el menor t positivo, ya que este es el primer impacto con la esfera.
    if (t1 > 0.001f) {
        t0 = t1;
        return true;
    }
    if (t2 > 0.001f) {
        t0 = t2;
        return true;
    }

    return false; // ambos t son negativos, la esfera está detrás de la cámara.
}