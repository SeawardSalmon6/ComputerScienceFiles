FLEX_CC=flex
CC=gcc
CFLAGS=-lm -fdiagnostics-color=always

MAIN_SOURCE=lex.yy.c
FLEX_MAIN_SOURCE=main.lex
FLEX_TEST_SOURCE=test.lex

MAIN_INPUT_FILE=input.txt
TEST_FILE=test.txt

make_main:
	$(FLEX_CC) $(FLEX_MAIN_SOURCE)
	$(CC) -o main $(MAIN_SOURCE) $(CFLAGS)

make_test:
	$(FLEX_CC) $(FLEX_TEST_SOURCE)
	$(CC) -o main $(MAIN_SOURCE) $(CFLAGS)

main: make_main
	clear
	./main < $(MAIN_INPUT_FILE)

test: make_test
	clear
	./main < $(TEST_FILE)