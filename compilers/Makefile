FLEX_CC=flex
CC=gcc
CFLAGS=-lm -fdiagnostics-color=always

MAIN_SOURCE=lex.yy.c
FLEX_MAIN_SOURCE=main.lex
FLEX_TEST_SOURCE=test.lex

MAIN_INPUT_FILE=input.txt
TEST_FILE=test.txt

lexic_main:
	$(FLEX_CC) $(FLEX_MAIN_SOURCE)

lexic_test:
	$(FLEX_CC) $(FLEX_TEST_SOURCE)

run_main: lexic_main
	$(CC) -o main $(MAIN_SOURCE) $(CFLAGS)

main_test: lexic_test
	$(CC) -o main $(MAIN_SOURCE) $(CFLAGS)

main: run_main
	clear
	./main < $(MAIN_INPUT_FILE)

test: main_test
	clear
	./main < $(TEST_FILE)