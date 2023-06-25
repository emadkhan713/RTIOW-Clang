#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "vec3.h"

Vec3 Vec3_add(int num, ...) {
  va_list ap;
  va_start(ap, num);

  Vec3 first = va_arg(ap, Vec3);
  float x = first.x;
  float y = first.y;
  float z = first.z;

  for (int i = 1; i < num; i++) {
    Vec3 other = va_arg(ap, Vec3);
    x += other.x;
    y += other.y;
    z += other.z;
  }
  va_end(ap);
  Vec3 result = {x, y, z};
  return result;
}

Vec3 Vec3_scalarM(Vec3 vec, float scalar) {
  Vec3 result = {
    vec.x * scalar,
    vec.y * scalar,
    vec.z * scalar 
  };
  return result;
}

float Vec3_len_sqd(Vec3 vec) {
  return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
}

float Vec3_len(Vec3 vec) {
  return sqrt(Vec3_len_sqd(vec));
}

void Vec3_print(Vec3 input) {
  printf("Vec3: {%f %f %f}", input.x, input.y, input.z);
}

float Point_dot(Point me, Point other) {
  return me.x*other.x + me.y*other.y + me.z*other.z;
}

Point Point_cross(Point me, Point other) {
  Point result = {
    me.y*other.z - other.y*me.z,
  -(me.x*other.z - other.x*me.z),
    me.x*other.y - other.x*me.y
  };
  return result;
}

Point Point_norm(Point vec) {
  Point result = Vec3_scalarM(vec, (float)1/Vec3_len(vec));
  return result;
}

void Color3_writePixel(Color3 color) {
  int r = color.x * 255.999;
  int g = color.y * 255.999;
  int b = color.z * 255.999;
  printf("%d %d %d\n", r, g, b);
}
