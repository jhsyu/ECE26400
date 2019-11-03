WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE -DTEST_CONVERT -DDEBUG

SRCS = main.c list.c convert.c
OBJS = $(SRCS:%.c=%.o)

hw14: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw14

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw14
	$(VAL) ./hw14  ./inputs/test5

testall: test1 test2 test3 test4 test5

test1: hw14
	./hw14 ./inputs/test1 > output1
	diff output1 expected/expected1

test2: hw14
	./hw14 ./inputs/test2 > output2
	diff output2 expected/expected2

test3: hw14
	./hw14 ./inputs/test3 > output3
	diff output3 expected/expected3

test4: hw14
	./hw14 ./inputs/test4 > output4
	diff output4 expected/expected4

test5: hw14
	./hw14 ./inputs/test5 > output5
	diff output5 expected/expected5

clean:
	rm -f hw14 *.o output?
