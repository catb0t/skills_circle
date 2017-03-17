#include <criterion/criterion.h>
#include "circle.h"

Test(ci, negs) {
  for (short a = -2; a < 2; a++) {
    for (short b = -2; b < 2; b++) {
      for (short c = -2; c < 2; c++) {
        circle2d_t* res = circle2d_new((ldbl_t ) a + .00123, (ldbl_t ) b + .00123, (ldbl_t ) c + .00123);
        //printf("%d, %d, %d\n", a, b, c);
        if ((a < 0) || (b < 0) || (c < 0)) {
          cr_assert( res == NULL );

        } else {
          cr_assert( res != NULL );
          circle2d_destruct(res);
        }
      }
    }
  }
}

Test(ci, cpt) {
  c2d_t
    *a = circle2d_new(0, 0, 5),
    *b = circle2d_new(0, 0, 3);

  cr_assert(circle2d_contains(a, b));

  circle2d_destruct(b);

  b = circle2d_new(1, 0, 4);

  cr_assert(circle2d_contains(a, b));
}

