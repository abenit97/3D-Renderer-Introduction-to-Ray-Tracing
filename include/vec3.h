#ifndef VEC3_H
#define VEC3_H
/**
 * @class Vec3
 * @brief Representa a un vector en tres dimensiones y a sus operaciones básicas.
 */
class Vec3 {
public:
    float x, y, z;

    /**
     * Constructor de la clase Vec3.
     * @param x Coordenada en el eje X (por defecto, 0).
     * @param y Coordenada en el eje Y (por defecto, 0).
     * @param z Coordenada en el eje Z (por defecto, 0).
     */
    Vec3(float x = 0, float y = 0, float z = 0);

    /*
     Operaciones con vectores
      
     operator[X] es la forma especial en C++ de sobrecargar el operador [X] permitiendo hacer "a [X] b" en lugar de "a.operacion(b)".
      
     "const" al final, indica que este método no modifica el objeto al que se llama.

     El parámetro v recibe un vector por referencia, evitando copiar este de forma innecesaria. "const" garantiza que 'v' no será modificado dentro del método.
     */

    /**
     * Operación vectorial SUMA.
     * 
     * Operador sobrecargado de suma +.
     * 
     * @param v Recibe un vector por referencia.
     */
    Vec3 operator+(const Vec3& v) const;

    /**
     * Operación vectorial RESTA.
     * 
     * Operador sobrecargado de resta -.
     * 
     * @param v Recibe un vector por referencia.
     */
    Vec3 operator-(const Vec3& v) const;

    /**
     * Operación vectorial PRODUCTO ESCALAR.
     * 
     * @param v Recibe un vector por referencia.
     */
    float dot(const Vec3& v) const;

    /**
     * Operación vectorial MULTIPLICACIÓN POR UN ESCALAR.
     * 
     * Operador sobrecargado de multiplicación *.
     * 
     * @param v Recibe un vector por referencia.
     */
    Vec3 operator*(float s) const;

    /**
     * Operación vectorial NORMALIZACIÓN.
     * 
     * @param v Recibe un vector por referencia.
     */
    Vec3 normalize() const;
};

#endif