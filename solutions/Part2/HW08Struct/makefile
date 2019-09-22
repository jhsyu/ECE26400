

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_COUNTVECTOR -DTEST_READVECTOR -DTEST_COMPAREVECTOR -DTEST_WRITEVECTOR -DTEST_MAIN -DDBUG

SRCS = main.c hw08.c
OBJS = $(SRCS:%.c=%.o)
TSTS = testgen.c hwo8.c
TSTO = $(SRCS:%.c=%.o)

hw08: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw08

#testgen: $(TSTO)
#	$(GCC) $(TESTFALGS) $(TSTO) -o testgen

.c.o:
		$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw08
			$(VAL) ./hw08 inputs/test5.bin output5.bin x

testall: test1 test2 test3 test4 test5

test1: hw08
	./hw08 inputs/input1.bin output1.bin x
	diff output1.bin expected/expected1.bin
	./hw08 inputs/input1.bin output1.bin y
	diff output1.bin expected/expected1.bin
	./hw08 inputs/input1.bin output1.bin z
	diff output1.bin expected/expected1.bin

test2: hw08
	./hw08 inputs/input2.bin output2.bin x
	diff output2.bin expected/expected2.bin
	./hw08 inputs/input2.bin output2.bin y
	diff output2.bin expected/expected2.bin
	./hw08 inputs/input2.bin output2.bin z
	diff output2.bin expected/expected2.bin

test3: hw08
	./hw08 inputs/input3.bin output3.bin x
	diff output3.bin expected/expected3.bin
	./hw08 inputs/input3.bin output3.bin y
	diff output3.bin expected/expected3.bin
	./hw08 inputs/input3.bin output3.bin z
	diff output3.bin expected/expected3.bin

test4: hw08
	./hw08 inputs/input4.bin output4.bin x
	diff output4.bin expected/expected4.bin
	./hw08 inputs/input4.bin output4.bin y
	diff output4.bin expected/expected4.bin
	./hw08 inputs/input4.bin output4.bin z
	diff output4.bin expected/expected4.bin

test5: hw08
	./hw08 inputs/input5.bin output5.bin x
	diff output5.bin expected/expected5.bin
	./hw08 inputs/input5.bin output5.bin y
	diff output5.bin expected/expected5.bin
	./hw08 inputs/input5.bin output5.bin z
	diff output5.bin expected/expected5.bin


clean:
	rm -f hw08 *.o output?
