#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"

/**
 * @class Sphere
 * @brief Representa a una esfera.
 */
class Sphere {
public:
    Vec3 centro; // Punto que representa el centro de la esfera.
    float radio; // Valor numérico que representa el radio de la esfera.

    /**
     * Constructor de la clase Sphere.
     * @param c Centro de la esfera (vector, punto en el espacio).
     * @param r Radio de la esfera (valor numérico decimal).
     * 
     * "centro" y "radio" son modificados con los valores de la llamada. Los vectores son llamados por referencia para evitar copiarlos de forma innecesaria.
     */
    Sphere(const Vec3& c, float r);

    /**
     * Comprueba si un rayo intersecta con la esfera.
     * @param rayo El rayo con origen y dirección.
     * @param t0 Punto de intersección más cercano al origen del rayo, si lo hay.
     * @return true si hay una intersección, false si no.
     */
    bool intersection(const Ray& rayo, float t0) const;
};

#endif