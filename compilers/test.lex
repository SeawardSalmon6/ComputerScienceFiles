%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>

  int lines = 0;
  int errors = 0;

  void print_error(char *, const char *, int);
%}

DIGIT                   [0-9]
VAR_NAME                [A-Za-z_][A-Za-z_0-9]*
ATTRIBUTION_SYMBOL      "="
SPACE                   [\t\r" "]
MATH_OPERATORS          [+\-*/%]
NEWLINE                 \n
INSTRUCTION_SEPARATOR   ";"
ATTRIBUTION_SYMBOLS     {ATTRIBUTION_SYMBOL}|"+="|"-="|"*="|"/="|"%="
COMPARISON_SYMBOLS      "=="|"<="|">="|"<"|">"|"!="
PONTUATION_SYMBOLS      "("|")"|"{"|"}"|","|"["|"]"
OL_COMMENTS_EXPRESSION  "//"[^\n]*
ML_COMMENTS_EXPRESSION  "/*"([^*/]|("**")*|("//")*)*"*/"

INTEGER                 ("-"?{DIGIT}+)
FLOAT                   ("-"?{DIGIT}+("."{DIGIT}+)?)
STRING                  (\"[^\n]*\")
BOOL                    ("true"|"false")
TYPES_VALUES            ({INTEGER}|{FLOAT}|{STRING}|{BOOL})

MATH_OPERATION          ({INTEGER}|{FLOAT})({SPACE}?{MATH_OPERATORS}{SPACE}?({INTEGER}|{FLOAT}))+

INTEGER_KEYWORD         "int"
FLOAT_KEYWORD           "float"
STRING_KEYWORD          "string"
BOOL_KEYWORD            "boolean"
TYPES_KEYWORDS          {INTEGER_KEYWORD}|{FLOAT_KEYWORD}|{STRING_KEYWORD}|{BOOL_KEYWORD}
CONSTANT_KEYWORD        "const"
RESERVED_WORDS          {INTEGER_KEYWORD}|{FLOAT_KEYWORD}|{STRING_KEYWORD}|{BOOL_KEYWORD}|{CONSTANT_KEYWORD}|"if"|"else"|"else if"|"while"|"for"

%%

{SPACE} {
  // Ignore spaces
}

{INTEGER} {
  printf("  - INTEGER: %s\n", yytext);
}

{FLOAT} {
  printf("  - FLOAT: %s\n", yytext);
}

{BOOL} {
  printf("  - BOOL: %s\n", yytext);
}

{STRING} {
  printf("  - STRING: %s\n", yytext);
}

{NEWLINE} {
  lines++;
}

. {
  print_error(yytext, "Unknown token", lines + 1);
}

%%

int main(int argc, char *argv[]) {
  FILE *fp = NULL;

  argc--; argv++;
  if (argc == 1) {
    fp = fopen(argv[0], "r");

    if (!fp) {
      printf("\n\n!--> Error: could not open the specified file. Use: ./main <filename>\n\n");
      exit(1);
    }

    yyin = fp;
  } else if (argc > 1) {
    if (!fp) {
      printf("\n\n!--> Error: too much arguments. Use: ./main <filename>\n\n");
      exit(1);
    }
  }

  yylex();

  printf("\n\n------------------- END OF FILE -------------------\n");

  if (errors > 0) {
    printf("\n--> O compilador encontrou %d erros", errors);
  }

  printf("\n--> O arquivo de entrada possui %d linhas\n\n", lines);

  return 0;
}

void print_error(char *declaration, const char *error_label, int error_at_line) {
  printf("\n\n!-> ERROR at line %d\n", error_at_line);
  printf("  - %s: %s\n", error_label, declaration);
}

int yywrap() {
  return 1;
}
