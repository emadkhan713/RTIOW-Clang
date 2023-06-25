#include <stdio.h>

int main(void) {
  const float aspect_ratio = 16.0f / 9.0f;
  const int width = 400;
  const int height = width / aspect_ratio;
  printf("%f %d %d\n", aspect_ratio, height, width);

  return 0;
}
