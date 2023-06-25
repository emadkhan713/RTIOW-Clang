#include <stdio.h>

int main(void) {
  const float aspect_ratio = (float)16 / 9;
  const int height = 300;
  const int width = height * aspect_ratio;
  printf("%f %d %d\n", aspect_ratio, height, width);

  return 0;
}
