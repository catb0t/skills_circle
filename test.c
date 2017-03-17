#include "circle.h"

#define NUM_C 3

/* !! MAIN !! */
int main (void) {

  c2d_t
    *c1 = circle2d_new(2, 2, 5.5),
    *c2 = circle2d_new(4, 5, 10.5),
    *c3 = circle2d_new(3, 5, 2.3);

  c2d_t* cs [NUM_C] = {c1, c2, c3};

  for (size_t i = 0; i < NUM_C; i++) {
    char* s = circle2d_see(cs[i]);
    printf("%s\n", s);
    safefree(s);
  }

  printf("c1->containsPoint(3, 3) == %s\n", circle2d_contains_point(c1, 3, 3) ? "true" : "false");
  printf("c1->contains(c2)        == %s\n", circle2d_contains(c1, c2) ? "true" : "false");
  printf("c1->overlaps(c3)        == %s\n", circle2d_overlaps(c1, c3) ? "true" : "false");

  for (size_t i = 0; i < NUM_C; i++) {
    circle2d_destruct( (cs[i]) );
  }

  return 0;
}
