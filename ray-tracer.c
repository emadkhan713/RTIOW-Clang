#include <stdio.h>
#include <math.h>
#include "vec3.h"
#include "ray.h"

typedef enum {false, true} bool;

bool hittable(Ray r, Point centre, float radius) {
  Vec3 CA = Vec3_add(2,
    r.origin,
    Vec3_scalarM(-1, centre)
  );
  //float b_CA = Point_dot(r.dir, CA);
  //fprintf(stderr, "CA %f %f %f\n", r.dir.x, r.dir.y, r.dir.z);

  float a = Point_dot(r.dir, r.dir);
  float b = 2.0f * Point_dot(r.dir, CA);
  float c = Point_dot(CA, CA) - (float)radius*radius;
  float discriminant = b*b - 4.0f*a*c;
  //fprintf(stderr, "a %f b %f c %f dis %f\n", a, b, c, discriminant);

  if (discriminant < 0) {
    //fprintf(stderr, "nohit\n");
    return false;
  }
  return true;

  float t1, t2;
  t1 = (-b + sqrt(discriminant)) / (2.0f*a) ;
  t2 = (-b - sqrt(discriminant)) / (2.0f*a) ;
  //fprintf(stderr, "t1 %f t2 %f\n", t1, t2);
  if (t1 < t2) {
    return true;
  } else if (t1 > t2) {
    return true;
  } else {
    return false;
  }
}

Color3 Ray_color(Ray r) {
  //fprintf(stderr, "x %f y %f z %f\n", r.dir.x, r.dir.y, r.dir.z);
  Point circle_centre = {0, 0, -1.0f};
  float radius = 0.5f;
  if ( hittable(r, circle_centre, radius) ) {
    Color3 red = {1.0f, 0, 0};
    return red;
  }
  Point dir_norm = Point_norm(r.dir);
  float t = 0.5f * (dir_norm.y + 1.0f);
  Color3 top = {1.0f, 1.0f, 1.0f};
  Color3 bottom = {0.5f, 0.7f, 1.0f};
  return Vec3_add(2,
    Vec3_scalarM(1.0f - t, top),
    Vec3_scalarM(t, bottom)
  );
}

int main(int argc, char *argv[]) {

  // Image
  const float aspect_ratio = 16.0f / 9;
  const int width = 400;
  const int height = width / aspect_ratio;

  // Camera
  const int v_height = 2;
  const int v_width = v_height * aspect_ratio;
  const float focal_len = 1.0f;

  Point origin = {0, 0, 0};
  Vec3  horizontal = {v_width, 0, 0};
  Vec3  vertical   = {0, v_height, 0};
  Vec3  focal_vec  = {0, 0, focal_len};
  Point l_l_corner = Vec3_add(4,
    origin,
    Vec3_scalarM(-0.5f, horizontal),
    Vec3_scalarM(-0.5f, vertical),
    Vec3_scalarM(-1.0f, focal_vec)
  );

  // Render
  printf("P3\n%d %d\n%d\n", width, height, COLORSPACE);

  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      float u = (float)i / (width-1);
      float v = (float)j / (height-1);
      Ray r = {
        origin,
        Vec3_add(4,
          l_l_corner,
          Vec3_scalarM(u, horizontal),
          Vec3_scalarM(v, vertical),
          Vec3_scalarM(-1, origin)
        )
      };
      Color3 pixel = Ray_color(r);
      Color3_writePixel(pixel);
    }
    fprintf(stderr, "Completed scanline %d of %d.\n", height - j, height);
  }
  return 0;
}
