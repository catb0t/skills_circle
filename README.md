# circle

---

requires gcc and linux (doesn't build on Windows)

to make the application:

```sh
$ make
gcc test.c -ggdb -O0 -o test
$ ./test
circle2d #0
.x = 2
.y = 2
.radius = 5.5
circle2d #1
.x = 4
.y = 5
.radius = 10.5
circle2d #2
.x = 3
.y = 5
.radius = 2.3
c1->containsPoint(3, 3) == true
c1->contains(c2)        == false
c1->overlaps(c3)        == true
```