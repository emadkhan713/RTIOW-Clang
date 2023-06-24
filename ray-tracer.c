#include <stdio.h>
#include <math.h>
#include "vec3.h"

#define COLORSPACE 255

int main(int argc, char *argv[]) {

  //const float aspect_ratio = (float) 16/9;
  const int height = 256;
  const int width  = 256;
  //const int width = (int) height * aspect_ratio;

  printf("P3\n%d %d\n%d\n", width, height, COLORSPACE);

  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      Color3 pixel = {
        (float)i / (width-1),
        (float)j / (height-1),
        0.25f
      };
      Color3_writePixel(pixel);
    }
    fprintf(stderr, "Completed scanline %d of %d.\n", height - j, height);
  }
  return 0;
}
