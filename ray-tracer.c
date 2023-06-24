#include <stdio.h>
#include <math.h>

#define COLORSPACE 255

int main(int argc, char *argv[]) {

  //const float aspect_ratio = (float) 16/9;
  const int height = 256;
  const int width  = 256;
  //const int width = (int) height * aspect_ratio;

  printf("P3\n%d %d\n%d\n", width, height, COLORSPACE);

  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      
      float r_raw = (float) i/(width-1);
      float g_raw = (float) j/(height-1);
      float b_raw = (float) 0.25;

      int r_render = r_raw * 255.999;
      int g_render = g_raw * 255.999;
      int b_render = b_raw * 255.999;

      printf("%d %d %d\n", r_render, g_render, b_render);

    }
  }

  return 0;

}
