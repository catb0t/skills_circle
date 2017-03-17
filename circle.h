#include <stdio.h>
#include <stdarg.h>
#include "common.h"

#define define_circle2d_getter(member_name) \
  ldbl_t circle2d_get ## member_name (const circle2d_t * const c); \
  ldbl_t circle2d_get ## member_name (const circle2d_t * const c) { \
    return c -> member_name ; } int SYNTAX_HAXG ## member_name

#define define_circle2d_setter(member_name) \
  ldbl_t circle2d_set ## member_name (circle2d_t * const c, const ldbl_t newval); \
  ldbl_t circle2d_set ## member_name (circle2d_t * const c, const ldbl_t newval) { \
    ldbl_t old = c -> member_name; \
    c -> member_name = newval; \
    return old; \
  } int SYNTAX_HAXS ## member_name

// prototype for struct
typedef struct st_circle2d_t circle2d_t;

// floats are too small for real applications -- long double is better
typedef long double ldbl_t;

// ldbl_func_t is the type of a pointer to a function taking one argument
// that returns one ldbl_t value
// return_type ( * typename ) ( cv qualified argument_types... )
typedef ldbl_t ( * circle_get_t ) (const ldbl_t);

// struct type for circle2d objects
typedef struct st_circle2d_t {
  ldbl_t _x, _y, _radius;

  size_t uid;

} circle2d_t;

/* getters for x y radius */
define_circle2d_getter(_x);
define_circle2d_getter(_y);
define_circle2d_getter(_radius);

/* setters for x y radius */
define_circle2d_setter(_x);
define_circle2d_setter(_y);
define_circle2d_setter(_radius);

// utils
bool any_negative (const size_t args, ...);

// constructor for circle2d_t objects
circle2d_t* circle2d_new (const ldbl_t x, const ldbl_t y, const ldbl_t radius);
// destructor
void   circle2d_destruct (circle2d_t * const c);
// err cond
void        err_negative (const char* const fun);
// seer
char*       circle2d_see (const circle2d_t * const c);

bool any_negative (const size_t args, ...) {
  va_list va;
  va_start(va, args);

  for (size_t i = 0; i < args; i++) {
    if (va_arg(va, ldbl_t) < 0) {
      va_end(va);
      return true;
    }
  }

  va_end(va);
  return false;
}

// fails on negative values
void err_negative (const char* const fun) {
  printf("circle2d: %s: argument to %s was negative ", fun, fun);
}

// make a new circle2d_t object from params
// params must be zero
circle2d_t* circle2d_new (const ldbl_t x, const ldbl_t y, const ldbl_t radius) {

  // NOTE: exit point!!
  if ( any_negative (3, x, y, radius) ) {
    err_negative(__func__);
    return NULL;
  }

  // stack allocated struct for nice initialiser syntax
  circle2d_t scfld = {
    ._x = x,
    ._y = y,
    ._radius = radius
  };

  // heap alloced destination
  circle2d_t* circle2d = safemalloc( sizeof (circle2d_t) );

  // copy from stack to heap
  memcpy(circle2d, &scfld, sizeof (circle2d_t));

  // report this
  report_ctor(circle2d);

  // return heap ptr
  return circle2d;
}

// destruct a circle obj; references / handles to this value are invalidated
void circle2d_destruct (circle2d_t * const circle2d) {
  report_dtor(circle2d);
  safefree(circle2d);
}


char* circle2d_see (const circle2d_t * const c) {

  char* str1 = safemalloc(100 * sizeof (char));

  // format
  snprintf(
    str1,
    99,
    "circle2d #%zu \n.x = %LG \n.y = %LG \n.radius = %LG",
    c->uid, circle2d_get_x(c), circle2d_get_y(c), circle2d_get_radius(c)
  );

  // save memory
  str1 = saferealloc(str1, sizeof (char) * (safestrnlen(str1) + 1) );

  return str1;
}

bool circle_overlaps (const circle2d_t const * a, const circle2d_t const * b) {
  ldbl_t
    ax = a->_x, ay = a->_y, ar = a->_radius;
    bx = b->_x, by = b-> _y, br = b->_radius;

  return false;
}
