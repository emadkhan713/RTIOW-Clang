#include <stdio.h>
#include "vec3.h"

int main(void) {
  Point a = {1, 2, 3};
  Point b = {2, 1, 2};
  Point result = Point_norm(Point_cross(a, b));
  Vec3_print(result);

  return 0;
}
