%{
  #include <stdio.h>
  #include <stdlib.h>

  #define YYSTYPE int
  extern YYSTYPE yylval;

  int yylex();
  int yyerror(char *);

  extern int lines;
%}

%token NUMBER
%token ADD SUB MUL DIV ABS REST
%token EOL
%token LEFT_PAREN RIGHT_PAREN

%start calclist

%%

calclist: /* empty */      {}
        | calclist exp EOL { printf("= %d\n", $2); }
        ;

exp     : term                        { $$ = $1; }
        | term ADD exp                { $$ = $1 + $3; }
        | term SUB exp                { $$ = $1 - $3; }
        | term MUL exp                { $$ = $1 * $3; }
        | term DIV exp                { $$ = $1 / $3; }
        | term REST exp               { $$ = ((int)$1) % ((int)$3); }
        ;

term    : NUMBER                      { $$ = $1; }
        | ABS term                    { $$ = $2 >= 0 ? $2 : - $2; }
        | LEFT_PAREN exp RIGHT_PAREN  { $$ = $2; }
        ;

%%

int main(int argc, char **argv) {
  yyparse();
  printf("\n--> Total lines: %d\n", lines);
  return 0;
}

int yyerror(char *s) {
  printf("error: %s\n", s);
  return 0;
}