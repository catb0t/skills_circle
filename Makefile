CC := gcc
normal: test.c
	$(CC) -DCDTORDBG test.c -ggdb -O0 -o test

test: test_circle.c
	$(CC) test_circle.c -lcriterion -o test_circle
