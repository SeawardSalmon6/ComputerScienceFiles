%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "main.tab.h"

  int lines = 0;
  int lexical_errors = 0;

  void print_error(char *, const char *, int);
%}

DIGIT                   [0-9]
VAR_NAME                [A-Za-z_][A-Za-z_0-9]*
ATTRIBUTION_SYMBOL      "="
SPACE                   [\t\r" "]
NEWLINE                 \n
INSTRUCTION_SEPARATOR   ";"
OL_COMMENTS_EXPRESSION  "//"[^\n]*
ML_COMMENTS_EXPRESSION  "/""*"[^*]*"*""/"

INTEGER                 "-"?{DIGIT}+
FLOAT                   "-"?{DIGIT}+("."{DIGIT}+)?
STRING                  \"[^\n]*\"
BOOL                    "true"|"false"

INTEGER_KEYWORD         "int"
FLOAT_KEYWORD           "float"
STRING_KEYWORD          "string"
BOOL_KEYWORD            "boolean"
VOID_KEYWORD            "void"
TYPES_KEYWORDS          {INTEGER_KEYWORD}|{FLOAT_KEYWORD}|{STRING_KEYWORD}|{BOOL_KEYWORD}|{VOID_KEYWORD}
RETURN_KEYWORD          "return"

%%

 /* Ignore spaces */
{SPACE}                  {}
{OL_COMMENTS_EXPRESSION} {}
{ML_COMMENTS_EXPRESSION} {}
{NEWLINE}                { lines++; }

{RETURN_KEYWORD}         { return (RETURN_KEYWORD); }
"while"                  { return (WHILE); }
"for"                    { return (FOR); }
"if"                     { return (IF); }
"else"                   { return (ELSE); }
"else if"                { return (ELSE_IF); }
"++"                     { return (PLUS_PLUS); }
"--"                     { return (MINUS_MINUS); }

 /* ============== Compiler Compatible Data Types */
{INTEGER}                { return (NUMBER); }
{FLOAT}                  { return (NUMBER); }
{STRING}                 { return (STRING); }
{BOOL}                   { return (BOOL); }

"+"                      { return (ADD); }
"-"                      { return (SUB); }
"*"                      { return (MUL); }
"/"                      { return (DIV); }
"%"                      { return (REST); }

","                      { return (COMMA); }
"("                      { return (LEFT_PAREN); }
")"                      { return (RIGHT_PAREN); }
"{"                      { return (LEFT_BRACE); }
"}"                      { return (RIGHT_BRACE); }
{ATTRIBUTION_SYMBOL}     { return (ATRIB); }
"=="                     { return (EQUAL); }

{TYPES_KEYWORDS}         { return (TYPE_KEYWORD); }
{VAR_NAME}               { return (ID); }

"!"                      { return (NOT); }
"||"                     { return (OR); }
"&&"                     { return (AND); }
">"                      { return (GREATER_THAN); }
">="                     { return (GREATER_THAN_EQUAL); }
"<"                      { return (LESS_THAN); }
"<="                     { return (LESS_THAN_EQUAL); }

 /* ============== Newline Reader */
{INSTRUCTION_SEPARATOR}  { return (EOL); }

.                        { lexical_errors++; print_error(yytext, "Unknown token", lines + 1); }

%%

int yywrap() {
  return 1;
}

void print_error(char *declaration, const char *error_label, int error_at_line) {
  printf("\n\n!-> LEXICAL ERROR at line %d\n", error_at_line);
  printf("  - %s: %s\n", error_label, declaration);
}
