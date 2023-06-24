#include <stdio.h>

int main(void) {
  for (int i = 0; i < 256; ++i) {
    float a = (float) i/(256 - 1);
    int b = a * 255.999;
    printf("%f %d\n", a, b);
  }
}
