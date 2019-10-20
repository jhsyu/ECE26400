WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose
TESTFLAGS = -DTEST_CREATELIST -DTEST_ELIMINATE -DDEBUG -DTEST_DELETENODE

SRCS = main.c hw12.c
OBJS = $(SRCS:%.c=%.o)

hw12: $(OBJS)
	$(GCC) $(OBJS) -o hw12

.c.o:
	$(GCC) -c $*.c

testmemory: hw12
	$(VAL) ./hw12  4 5

testall: test1 test2 test3

test1: hw12
	./hw12 4 5 > output1
	diff output1 expected/expected1

test2: hw12
	./hw12 7 3 > output2
	diff output2 expected/expected2

test3: hw12
	./hw12 8 2 > output3
	diff output3 expected/expected2

clean:
	rm -f hw12 *.o output?
