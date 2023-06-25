#include "vec3.h"
#include "ray.h"

Point Ray_at(Ray r, float time) {
  return Vec3_add(2,
    r.origin,
    Vec3_scalarM(time, r.dir)
  );
}
