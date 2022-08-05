#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

color ray_color(const ray &r) {
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	//Linear blend formula:
	//(1 - t) * startValue + t * endValue
	//in this case we are going from white (1.0,1.0,1.0) to light blue (0.5, 0.7, 1.0)
	return (1.0 - t) * color(1.0,1.0,1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {
	//Image
	const auto aspect_ratio = 16.0/9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	
	//Camera
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * aspect_ratio;
	auto focal_length = 1.0;

	auto origin = point3(0,0,0);
	auto horizontal = vec3(0, viewport_width, 0);
	auto vertical = vec3(viewport_height, 0, 0);
	auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

	/* 
	 Pixels are written in rows: left -> right. Columns: top -> bottom
	 RBG conventional component values range from 0 to 1
	 Image values range from 0 to 255
	 */

	std::cout<<"P3\n" << image_width << " " << image_height << "\n255\n"<< std::endl;

	for (int h = image_height - 1; h >= 0; h--) {
		std::cerr<<"\rScanlines remaining: " << h <<' '<< std::flush;
		for (int w = 0; w < image_width; w++) {
			auto v = double(h) / (image_width - 1);
			auto u = double(w) / (image_height - 1);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}
	std::cerr<<"\nDone.\n"<<std::endl;
}
