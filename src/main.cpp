#include <iostream>
#include "Color.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"

double hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vector3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0 * a);
    }
}

Color ray_color(const Ray& r) {
    auto t = hit_sphere(Point3(0,0, -1), 0.5, r);
    if (t > 0.0) {
        Vector3 N = unit_vector(r.at(t) - Vector3(0,0,-1));
        return 0.5 * Color(N.x + 1, N.y + 1, N.z + 1);
    }
    Vector3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main()
{
    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = Point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = Vector3(viewport_width, 0, 0);
    auto viewport_v = Vector3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - Vector3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {
        std::clog << "\rScanlines remaining: " << (image_height - i) << ' ' << std::flush;

        for (int j = 0; j < image_width; j++) {
            auto pixel_center = pixel00_loc + (j * pixel_delta_u) + (i * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}
