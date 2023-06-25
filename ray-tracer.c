#include <stdio.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"

Color3 Ray_color(Ray r) {
  Point dir_norm = Point_norm(r.dir);
  float t = 0.5f * (dir_norm.y + 1.0f);
  Color3 top = {1.0f, 1.0f, 1.0f};
  Color3 bottom = {0.5f, 0.7f, 1.0f};
  return Vec3_add(
    Vec3_scalarM(top, 1.0f - t),
    Vec3_scalarM(bottom, t)
  );
}

int main(int argc, char *argv[]) {

  // Image
  const float aspect_ratio = (float)16 / 9;
  const int height = 400;
  const int width = height * aspect_ratio;

  // Camera
  const int v_height = 2;
  const int v_width = v_height * aspect_ratio;
  const float focal_len = 1.0f;

  Point origin = {0, 0, 0};
  Vec3  horizontal = {v_width, 0, 0};
  Vec3  vertical   = {0, v_height, 0};
  Vec3  focal_vec  = {0, 0, focal_len};
  Point l_l_corner = Vec3_add(
    Vec3_scalarM(Vec3_add(Vec3_scalarM(Vec3_add(horizontal, vertical), 0.5f), focal_vec), -1),
    origin
  );

  // Render
  printf("P3\n%d %d\n%d\n", width, height, COLORSPACE);

  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      float u = (float)i / (width-1);
      float v = (float)j / (height-1);
      Ray r = {
        origin,
        Vec3_add(
          Vec3_add(
            Vec3_add(
              Vec3_scalarM(horizontal, u),
              Vec3_scalarM(vertical, v)
            ),
            l_l_corner
          ), 
          Vec3_scalarM(origin, -1)
        )
      };
      Color3 pixel = Ray_color(r);
      Color3_writePixel(pixel);
    }
    fprintf(stderr, "Completed scanline %d of %d.\n", height - j, height);
  }
  return 0;
}
