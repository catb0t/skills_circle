
normal: test.c
	cc test.c -ggdb -O0 -o test

test: test_circle.c
	cc test_circle.c -lcriterion -o test_circle
