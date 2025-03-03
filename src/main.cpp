#include "vec3.h"
#include "ray.h"
#include "sphere.h"

#include <vector>
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
    std::vector<Sphere> esferas = {
        Sphere(Vec3(0, 3, -5), 1.0f),   // Esfera central
        Sphere(Vec3(-1.5, 0, -5), 1.0f), // Esfera izquierda
        Sphere(Vec3(1.5, 0, -5), 1.0f)  // Esfera derecha
    };

    Vec3 light_pos(0, 1.5, -3); // Fuente de luz

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            float x = (2.0f * (i + 0.5f) / WIDTH - 1) * ASPECT_RATIO;
            float y = (1 - 2.0f * (j + 0.5f) / HEIGHT);
            Vec3 pixel_dir(x, y, -1);
            pixel_dir = pixel_dir.normalize();

            Ray ray(camera_origin, pixel_dir);
            float t_min = INFINITY;
            Sphere* closest_sphere = nullptr;

            // Buscar la esfera más cercana
            for (auto& sphere : esferas) {
                float t;
                if (sphere.intersection(ray, t) && t < t_min) {
                    t_min = t;
                    closest_sphere = &sphere;
                }
            }

            if (closest_sphere) {
                // Punto de impacto y normal
                Vec3 impact_point = ray.origen + ray.direccion * t_min;
                Vec3 normal = (impact_point - closest_sphere->centro).normalize();

                if (normal.dot(ray.direccion) > 0) {
                    normal = normal * -1; // Corregir normal si es necesario
                }

                // Dirección hacia la luz
                Vec3 light_dir = (light_pos - impact_point).normalize();

                // Verificar si hay sombra
                Vec3 shadow_origin = impact_point + normal * 0.001f;
                Ray shadow_ray(shadow_origin, light_dir);
                bool in_shadow = false;

                for (auto& sphere : esferas) {
                    float t;
                    if (&sphere != closest_sphere && sphere.intersection(shadow_ray, t)) {
                        in_shadow = true;
                        break;
                    }
                }

                // Iluminación difusa (Lambert)
                float intensity = in_shadow ? 0.0f : std::max(0.0f, normal.dot(light_dir));

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