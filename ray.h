#ifndef RAY_H
#define RAY_H
#include "vec3.h"

typedef struct {
  Point origin;
  Vec3 dir;
} Ray;

Point Ray_at(Ray r, float time);

#endif
