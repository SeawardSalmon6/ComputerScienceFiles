%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "main.tab.h"

  YYSTYPE yylval;
  int lines;
%}

DIGIT                   [0-9]
VAR_NAME                [A-Za-z_][A-Za-z_0-9]*
ATTRIBUTION_SYMBOL      "="
SPACE                   [\t\r" "]
MATH_OPERATORS          [+\-*/%]
NEWLINE                 \n
INSTRUCTION_SEPARATOR   ";"
ATTRIBUTION_SYMBOLS     {ATTRIBUTION_SYMBOL}|"+="|"-="|"*="|"/="|"%="
COMPARISON_SYMBOLS      "=="|"<="|">="|"<"|">"
PONTUATION_SYMBOLS      "("|")"|"{"|"}"|","|"["|"]"
OL_COMMENTS_EXPRESSION  "//"[^\n]*
ML_COMMENTS_EXPRESSION  "/*"[^\n]*"*/"

INTEGER                 "-"?{DIGIT}+
FLOAT                   "-"?{DIGIT}+("."{DIGIT}+)?
STRING                  \"[^\n]*\"
BOOL                    "true"|"false"
TYPES_VALUES            {INTEGER}|{FLOAT}|{STRING}|{BOOL}

MATH_OPERATION          ({INTEGER}|{FLOAT})({SPACE}?{MATH_OPERATORS}{SPACE}?({INTEGER}|{FLOAT}))+

INTEGER_KEYWORD         "int"
FLOAT_KEYWORD           "float"
STRING_KEYWORD          "string"
BOOL_KEYWORD            "boolean"
TYPES_KEYWORDS          {INTEGER_KEYWORD}|{FLOAT_KEYWORD}|{STRING_KEYWORD}|{BOOL_KEYWORD}
CONSTANT_KEYWORD        "const"
RESERVED_WORDS          {INTEGER_KEYWORD}|{FLOAT_KEYWORD}|{STRING_KEYWORD}|{BOOL_KEYWORD}|{CONSTANT_KEYWORD}|"if"|"else"|"else if"|"while"|"for"

%%

"+"        { return ADD; }
"-"        { return SUB; }
"*"        { return MUL; }
"/"        { return DIV; }
"%"        { return REST; }
"|"        { return ABS; }
{FLOAT}    { yylval = atoi(yytext); return NUMBER; }
{NEWLINE}  { lines++; return EOL; }
{SPACE}    { /* ignore whitespace */ }
"("        { return LEFT_PAREN; }
")"        { return RIGHT_PAREN; }
.          { printf("Mystery character %c\n", *yytext); }

%%
