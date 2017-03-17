#include "circle.h"

/* !! MAIN !! */
int main (void) {

  circle2d_t* c = circle2d_new(-1, 0, 0);

  char* s = circle2d_see(c);

  printf("%s\n", s);

  safefree(s);

  circle2d_destruct(c);

  return 0;
}
