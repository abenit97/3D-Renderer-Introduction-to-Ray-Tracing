#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @class Ray
 * @brief Representa a un rayo de luz proyectado desde el receptor, en sentido inverso.
 */
class Ray {
public:
    Vec3 origen, direccion;

    /**
     * Constructor de la clase Ray.
     * @param o Origen del rayo (vector, punto en el espacio).
     * @param d Dirección del rayo (vector, hacia dónde va).
     * 
     * Se normaliza la dirección para asegurar una longitud de 1 y facilitar posteriores cálculos.
     * 
     * "origen" y "direccion" son modificados con los valores de la llamada. Los vectores son llamados por referencia para evitar copiarlos de forma innecesaria.
     */
    Ray(const Vec3& o, const Vec3& d);

    /**
     * Calcula un punto en el rayo  partir de un parámetro 't'.
     * @param t Parámetro escalar que indica la distancia desde el origen.
     * @return El punto en la trayectoria del rayo correspondeinte a 't'.
     * 
     * La ecuación del rayo es:
     *      P(t) = origen + direccion * t
     * Donde:
     *  - P(t) es el punto en el rayo a una distancia t.
     *  - origen es el punto de inicio del rayo.
     *  - direccion es la direccion ya normalizada del rayo.
     *  - t es un escalar que define cuánto se avanza sobre el recorrido del rayo.
     */
    Vec3 pointAt(float t) const;
};

#endif