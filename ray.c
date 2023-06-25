#include "vec3.h"
#include "ray.h"

Point Ray_at(Ray r, float time) {
  return Vec3_add(
    r.origin,
    Vec3_scalarM(r.dir, time)
  );
}

