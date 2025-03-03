#include "vec3.h"
#include "ray.h"
#include "sphere.h"

#include <iostream>
#include <fstream>
#include <cmath>

const int WIDTH = 1920;
const int HEIGHT = 1080;
const float ASPECT_RATIO = float(WIDTH) / HEIGHT;

int main() {
    std::ofstream image("output.ppm");
    image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    Vec3 camera_origin(0, 0, 0);
    Sphere sphere(Vec3(0, 0, -3), 1.0f); // Esfera centrada en (0, 0, -3) con radio 1.
    Vec3 light_pos(5, 5, -5); // Fuente de luz en (5, 5, -5).

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            float x = (2.0f * (i + 0.5f) / WIDTH - 1) * ASPECT_RATIO;
            float y = (1 - 2.0f * (j + 0.5f) / HEIGHT);
            Vec3 pixel_dir(x, y, -1);
            pixel_dir = pixel_dir.normalize();

            Ray ray(camera_origin, pixel_dir);
            float t;
            if (sphere.intersection(ray, t)) {
                // Rojo si impacta.
                image << "255 0 0 ";
            } else {
                // Negro si no impacta.
                image << "0 0 0 ";
            }
        }
        image << "\n";
    }

    image.close();
    std::cout << "Imagen generada: output.ppm\n";
    return 0;
}