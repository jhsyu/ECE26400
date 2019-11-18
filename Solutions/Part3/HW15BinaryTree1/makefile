ARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_BUILDTREE #-DDEBUG

SRCS = main.c tree.c
OBJS = $(SRCS:%.c=%.o)

hw15: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw15

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw15
	$(VAL) ./hw15 ./inputs/test5in ./inputs/test5post ./outputs/output5
	
testall: test1 test2 test3 test4 test5 test6

test1: hw15
	./hw15 ./inputs/test1in ./inputs/test1post ./outputs/output1
	diff ./outputs/output1 ./expected/expected1

test2: hw15
	./hw15 ./inputs/test2in ./inputs/test2post ./outputs/output2
	diff ./outputs/output2 ./expected/expected2

test3: hw15
	./hw15 ./inputs/test3in ./inputs/test3post ./outputs/output3
	diff ./outputs/output3 ./expected/expected3

test4: hw15
	./hw15 ./inputs/test4in ./inputs/test4post ./outputs/output4
	diff ./outputs/output4 ./expected/expected4

test5: hw15
	./hw15 ./inputs/test5in ./inputs/test5post ./outputs/output5
	diff ./outputs/output5 ./expected/expected5

test6: hw15
	./hw15 ./inputs/test6in ./inputs/test6post ./outputs/output6
	diff ./outputs/output6 ./expected/expected6

clean:
	rm -f hw15 *.o outputs/output*
