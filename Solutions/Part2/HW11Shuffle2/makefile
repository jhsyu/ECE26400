WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS)
	$(GCC) $(OBJS) -o hw11

.c.o:
	$(GCC) -c $*.c

testmemory: hw11
	$(VAL) ./hw11  4 5

testall: test1 test2 test3

test1: hw11
	./hw11 4 5 | sort | uniq > output1
	diff -w output1 expected/expected_4_5

test2: hw11
	./hw11 7 3 | sort | uniq > output2
	diff -w output2 expected/expected_7_3

test3: hw11
	./hw11 8 2 | sort | uniq > output3
	diff -w output3 expected/expected_8_2

test4: hw11
	./hw11 11 2 | sort | uniq > output4
	diff -w output4 expected/expected_11_2

clean:
	rm -f hw11 *.o output?
