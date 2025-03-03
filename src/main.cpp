#include "vec3.h"
#include "ray.h"
#include "sphere.h"

#include <array>
#include <iostream>
#include <fstream>
#include <cmath>

const int WIDTH = 1920;
const int HEIGHT = 1080;
const float ASPECT_RATIO = float(WIDTH) / HEIGHT;

int main() {
    std::ofstream image("output.ppm");
    image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    Vec3 camera_origin(0, 0, 0); // Posición de la cámara
    Sphere sphere(Vec3(0, 0, -2), 1.0f); // Esfera centrada en (x, y, z) con radio X.Xf.
    Vec3 light_pos(0, 5, 1); // Posición de la fuente de luz.
    std::array<int, 3> light_color = {255, 200, 150};

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            float x = (2.0f * (i + 0.5f) / WIDTH - 1) * ASPECT_RATIO;
            float y = (1 - 2.0f * (j + 0.5f) / HEIGHT);
            Vec3 pixel_dir(x, y, -1);
            pixel_dir = pixel_dir.normalize();
    
            Ray ray(camera_origin, pixel_dir);
            float t;
            Vec3 normal;
            if (sphere.intersection(ray, t)) {
                // Se calcula el punto de impacto.
                Vec3 impact_point = ray.origen + ray.direccion * t;

                // Normal en la superficie de la esfera.
                Vec3 normal = (impact_point - sphere.centro).normalize();

                if (normal.dot(ray.direccion) > 0) {
                    normal = normal * -1; // Invertir la normal si apunta hacia adentro
                }

                // Dirección hacia la luz
                Vec3 light_dir = (light_pos - impact_point).normalize();
                
                // Producto escalar para la iluminación difusa (Lambert)
                float intensity = std::max(0.0f, normal.dot(light_dir));

                // Color base de la esfera (rojo) multiplicado por la intensidad
                int r = static_cast<int>(255 * intensity);
                int g = static_cast<int>(255 * intensity);
                int b = static_cast<int>(255 * intensity);
    
                image << r << " " << g << " " << b << " ";
            } else {
                image << "0 0 0 ";
            }
        }
        image << "\n";
    }

    image.close();
    std::cout << "Imagen generada: output.ppm\n";
    return 0;
}