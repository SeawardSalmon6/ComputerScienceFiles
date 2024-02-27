%{
  #include <stdio.h>
  #include <stdlib.h>

  extern int lines;
  extern int lexical_errors;
  int parser_errors = 0;

  void yyerror(char *);
  int yylex();
%}

%token EOL 
%token ADD SUB MUL DIV REST
%token TYPE_KEYWORD RETURN_KEYWORD
%token ID NUMBER STRING BOOL
%token LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE COMMA ATRIB EQUAL NOT AND OR
%token WHILE FOR IF ELSE ELSE_IF PLUS_PLUS MINUS_MINUS
%token GREATER_THAN GREATER_THAN_EQUAL LESS_THAN LESS_THAN_EQUAL

%start program

%%

program       : /* empty */
              | commands
              | decl_functions
              ;

decl_functions : decl_function
               | decl_function decl_functions
               ;

commands      : command EOL
              | commands command EOL
              | commands built_in_functions
              ;

built_in_functions : WHILE LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
                   | FOR LEFT_PAREN assignment EOL expression EOL assignment RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
                   | if_statement
                   ;

if_statement  : IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
              | IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE ELSE_IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
              | IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE ELSE_IF LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE ELSE LEFT_BRACE commands RIGHT_BRACE
              ;

command       : assignment
              | function_call
              | decl_variable
              | RETURN_KEYWORD expression
              ;

decl_variable : TYPE_KEYWORD var_list
              ;

var_list      : ID COMMA var_list
              | ID
              ;

expression_list : expression COMMA expression_list
                | expression
                ;

assignment    : TYPE_KEYWORD ID ATRIB expression
              | ID ATRIB expression
              | ID PLUS_PLUS
              | ID MINUS_MINUS
              ;

expression    : term        
              | term ADD expression
              | term SUB expression
              | term MUL expression
              | term DIV expression
              | term REST expression
              | term EQUAL expression
              | term AND expression
              | term OR expression
              | term GREATER_THAN expression
              | term GREATER_THAN_EQUAL expression
              | term LESS_THAN expression
              | term LESS_THAN_EQUAL expression
              ;

decl_function : TYPE_KEYWORD ID LEFT_PAREN RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
              | TYPE_KEYWORD ID LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE
              | TYPE_KEYWORD ID LEFT_PAREN decl_variable RIGHT_PAREN LEFT_BRACE commands RIGHT_BRACE
              | TYPE_KEYWORD ID LEFT_PAREN decl_variable RIGHT_PAREN LEFT_BRACE RIGHT_BRACE
              ;

function_call : ID LEFT_PAREN RIGHT_PAREN
              | ID LEFT_PAREN expression_list RIGHT_PAREN
              ;

term          : NUMBER
              | STRING
              | BOOL
              | LEFT_PAREN expression RIGHT_PAREN
              | ID
              | function_call
              | NOT term
              ;

%%

int main() {
  yyparse();

  printf("\n\n------------------- END OF FILE -------------------\n");

  if (parser_errors > 0) {
    printf("\n--> O compilador encontrou %d erros sintáticos", parser_errors);
  }

  if (lexical_errors > 0) {
    printf("\n--> O compilador encontrou %d erros léxicos", lexical_errors);
  }

  if (parser_errors == 0 && lexical_errors == 0) {
    printf("\n--> O compilador não encontrou erros");
  } else {
    printf("\n--> O compilador encontrou erros. O programa inserido NÃO é válido!");
  }

  printf("\n--> O arquivo de entrada possui %d linhas\n\n", lines);

  return 0;
}

void yyerror(char *msg) {
  parser_errors++;
  printf("\n--> Erro: %s próximo à linha %d\n", msg, lines);
}