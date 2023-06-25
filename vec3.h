#ifndef VEC3_H
#define VEC3_H

#include <stdarg.h>

#define COLORSPACE 255

typedef struct {
  float x, y, z;
} Vec3;

Vec3 Vec3_add(int num, ...);
Vec3 Vec3_scalarM(float scalar, Vec3 vec);
float Vec3_len_sqd(Vec3 vec);
float Vec3_len(Vec3 vec);
void Vec3_print(Vec3 input);

typedef Vec3 Point;
typedef Vec3 Color3;

float Point_dot(Point me, Point other);
Point Point_cross(Point me, Point other);
Point Point_norm(Point vec);

void Color3_writePixel(Color3 color);
#endif
