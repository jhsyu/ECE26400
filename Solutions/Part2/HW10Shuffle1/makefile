
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw10

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw10
	$(VAL) ./hw10  4 > output1

testall: test1 test2 test3

test1: hw10
	./hw10 4 > output1
	diff -w output1 expected/expected4

test2: hw10
	./hw10 8 > output1
	diff -w output2 expected/expected8

test3: hw10
	./hw10 10 > output1
	diff -w output3 expected/expected11

clean:
	rm -f hw10 *.o output?
