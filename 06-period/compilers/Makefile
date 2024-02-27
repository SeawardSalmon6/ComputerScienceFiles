FLEX_CC=flex
BISON_CC=bison -d -t
CC=gcc
CFLAGS=-lm -fdiagnostics-color=always -ll

FLEX_OUT_SOURCE=lex.yy.c
BISON_MAIN_OUT_SOURCE=main.tab.c
BISON_TEST_OUT_SOURCE=test.tab.c
FLEX_MAIN_SOURCE=main.lex
BISON_MAIN_SOURCE=main.y
FLEX_TEST_SOURCE=test.lex
BISON_TEST_SOURCE=test.y

MAIN_INPUT_FILE=input.txt
TEST_FILE=test.txt

make_main:
	$(BISON_CC) $(BISON_MAIN_SOURCE)
	$(FLEX_CC) $(FLEX_MAIN_SOURCE)
	$(CC) -o main $(FLEX_OUT_SOURCE) $(BISON_MAIN_OUT_SOURCE) $(CFLAGS)

make_test:
	$(BISON_CC) $(BISON_TEST_SOURCE)
	$(FLEX_CC) $(FLEX_TEST_SOURCE)
	$(CC) -o main $(FLEX_OUT_SOURCE) $(BISON_TEST_OUT_SOURCE) $(CFLAGS)

main: make_main
	clear
	./main < $(MAIN_INPUT_FILE)

test: make_test
	clear
	./main < $(TEST_FILE)