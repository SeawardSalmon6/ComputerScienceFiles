%option noyywrap

%{
  int lines = 0;
  int errors = 0;

  void print_declaration(char *, const char *);
  void print_declaration_error(char *, const char *, int);
  void print_error(char *, const char *, int);
  void print_type_error(char *, const char *, int);
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

{SPACE}

 /* ============== Compiler Compatible Data Types */
{INTEGER} {
  printf("\nInteger: %d", atoi(yytext));
}

{FLOAT} {
  printf("\nFloat: %f", atof(yytext));
}

"-"?{DIGIT}+(","{DIGIT}+)? {
  errors++;
  print_error(yytext, "Float numbers accepts (.) as decimal separator", lines + 1);
}

{STRING} {
  char *token;
  int string_size = 0;

  token = strtok(yytext, "\"");

  printf("\nString: %s", token);
}

\'[^\n]*\' {
  errors++;
  print_error(yytext, "Strings accepts (') as delimiters", lines + 1);
}

{BOOL} {
  printf("\nBoolean: %s", strcmp("true", yytext) == 0 ? "true" : "false");
}

 /* ============== Reserved Keywords */
{RESERVED_WORDS} {
  printf("\nReserved Keyword: %s", yytext);
}

 /* ============== Variables Identifier */
{VAR_NAME} {
  printf("\nVariable Identifier: %s", yytext);
}

{DIGIT}+{VAR_NAME} {
  errors++;
  print_error(yytext, "Identifier names should not have numbers as first character", lines + 1);
}

 /* ============== Math Related */
{MATH_OPERATORS} {
  printf("\nMath Operator: %s", yytext);
}

{MATH_OPERATION} {
  printf("\nMath Operation: %s", yytext);
}

 /* ============== Attribution Symbols */
{ATTRIBUTION_SYMBOLS} {
  printf("\nThis is an attribution symbol: %s", yytext);
}

 /* ============== Comparison Symbols */
{COMPARISON_SYMBOLS} {
  printf("\nThis is a comparison symbol: %s", yytext);
}

 /* ============== Pontuation Symbols */
{PONTUATION_SYMBOLS} {
  printf("\nThis is a pontuation symbol: %s", yytext);
}

 /* ============== Comments */
{OL_COMMENTS_EXPRESSION} {
  printf("\nThis is a comment: %s", yytext);
}

{ML_COMMENTS_EXPRESSION} {
  printf("\nThis is a comment: %s", yytext);
}

 /* ============== Integer Declaration */
({CONSTANT_KEYWORD}{SPACE})?{INTEGER_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{INTEGER}{INSTRUCTION_SEPARATOR} {
  print_declaration(yytext, "int");
}

({CONSTANT_KEYWORD}{SPACE})?{INTEGER_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?({FLOAT}|{STRING}|{BOOL}){INSTRUCTION_SEPARATOR} {
  errors++;
  print_type_error(yytext, "int", lines + 1);
}

 /* ============== Float Declaration */
({CONSTANT_KEYWORD}{SPACE})?{FLOAT_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{FLOAT}{INSTRUCTION_SEPARATOR} {
  print_declaration(yytext, "float");
}

({CONSTANT_KEYWORD}{SPACE})?{FLOAT_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?({INTEGER}|{STRING}|{BOOL}){INSTRUCTION_SEPARATOR} {
  errors++;
  print_type_error(yytext, "float", lines + 1);
}

 /* ============== String Declaration */
({CONSTANT_KEYWORD}{SPACE})?{STRING_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{STRING}{INSTRUCTION_SEPARATOR} {
  print_declaration(yytext, "string");
}

({CONSTANT_KEYWORD}{SPACE})?{STRING_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?({FLOAT}|{INTEGER}|{BOOL}){INSTRUCTION_SEPARATOR} {
  errors++;
  print_type_error(yytext, "string", lines + 1);
}

 /* ============== Boolean Declaration */
({CONSTANT_KEYWORD}{SPACE})?{BOOL_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{BOOL}{INSTRUCTION_SEPARATOR} {
  print_declaration(yytext, "boolean");
}

({CONSTANT_KEYWORD}{SPACE})?{BOOL_KEYWORD}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?({FLOAT}|{STRING}|{INTEGER}){INSTRUCTION_SEPARATOR}? {
  errors++;
  print_type_error(yytext, "boolean", lines + 1);
}

 /* ============== Global Declaration Rules */
{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{TYPES_VALUES}{INSTRUCTION_SEPARATOR} {
  print_declaration(yytext, "unknown");
}

{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{TYPES_VALUES} {
  errors++;
  print_declaration_error(yytext, "no_instruction_separator", lines + 1);
}

({CONSTANT_KEYWORD}{SPACE})?{TYPES_KEYWORDS}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{INSTRUCTION_SEPARATOR}? {
  errors++;
  print_declaration_error(yytext, "no_value", lines + 1);
}

({CONSTANT_KEYWORD}{SPACE})?{TYPES_KEYWORDS}{SPACE}{VAR_NAME}{SPACE}?{SPACE}?{TYPES_VALUES}?{INSTRUCTION_SEPARATOR}? {
  errors++;
  print_declaration_error(yytext, "no_attribution", lines + 1);
}

({CONSTANT_KEYWORD}{SPACE})?{TYPES_KEYWORDS}{SPACE}{VAR_NAME}{SPACE}?{ATTRIBUTION_SYMBOL}{SPACE}?{TYPES_VALUES} {
  errors++;
  print_declaration_error(yytext, "no_instruction_separator", lines + 1);
}

 /* ============== Newline Reader */
{NEWLINE} {
  lines++;
}

.* {
  errors++;
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
  } else {
    yyin = stdin;
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

void print_type_error(char *declaration, const char *type, int error_at_line) {
  printf("\n\n!-> ERROR at line %d\n", error_at_line);
  printf("  - Type error: the provided value it's not a (%s) value: %s\n", type, declaration);
}

void print_declaration_error(char *yytext, const char *error_type, int error_at_line) {
  if (error_type) {
    if (strcmp(error_type, "no_instruction_separator") == 0) {
      print_error(yytext, "Missing ';' at the end of instruction", error_at_line);
    } else if (strcmp(error_type, "no_value") == 0) {
      print_error(yytext, "Missing value for current statement", error_at_line);
    } else if (strcmp(error_type, "no_attribution") == 0) {
      print_error(yytext, "Expected a statement", error_at_line);
    }
  }
}

void print_declaration(char *declaration, const char *type) {
  char *token, *var_name, *value;
  int string_size, is_a_constant = 0;

  if (strcmp(type, "unknown") == 0) {
    var_name = strtok(declaration, "="); // Get the variable name
  } else {
    // Tokenize 'til TYPE_KEYWORD or CONST_KEYWORD
    token = strtok(declaration, " ");

    // Tokenize TYPE_KEYWORD if first keyword was a CONST
    if (strcmp(token, "const") == 0) {
      token = strtok(NULL, " ");
      is_a_constant = 1;
    }

    var_name = strtok(NULL, "="); // Get the variable name
  }

  value = strtok(NULL, ";"); // Get the variable value

  if (!var_name || !value) {
    printf("\n\nError: Invalid declaration format");
    return;
  }

  // Trim leading and trailing spaces from the variable name and value
  while (*var_name == ' ' || *var_name == '\t') {
    var_name++;
  }

  string_size = strlen(var_name);
  while (string_size > 0 && (var_name[string_size - 1] == ' ' || var_name[string_size - 1] == '\t')) {
    var_name[string_size - 1] = '\0';
    string_size--;
  }

  while (*value == ' ' || *value == '\t') {
    value++;
  }

  string_size = strlen(value);
  while (string_size > 0 && (value[string_size - 1] == ' ' || value[string_size - 1] == '\t' || value[string_size - 1] == ';' || value[string_size - 1] == '\n')) {
    value[string_size - 1] = '\0';
    string_size--;
  }

  if (strcmp(type, "unknown") == 0) {
    printf("\n\nYou're declaring a unknown type variable");
    printf("\n  -> %s = %s\n", var_name, value);
  } else if (strcmp(type, "int") == 0) {
    printf("\n\nYou're declaring an%sInteger Variable:", is_a_constant ? " Constant " : " ");
    printf("\n  -> %s = %d\n", var_name, atoi(value));
  } else if (strcmp(type, "float") == 0) {
    printf("\n\nYou're declaring a%sFloat Variable:", is_a_constant ? " Constant " : " ");
    printf("\n  -> %s = %f\n", var_name, atof(value));
  } else if (strcmp(type, "string") == 0) {
    printf("\n\nYou're declaring a%sString Variable:", is_a_constant ? " Constant " : " ");
    printf("\n  -> %s = %s\n", var_name, value);
  } else if (strcmp(type, "boolean") == 0) {
    printf("\n\nYou're declaring a%sBoolean Variable:", is_a_constant ? " Constant " : " ");
    printf("\n  -> %s = %s\n", var_name, value);
  } else {
    printf("\n\nUnknown Variable Declaration!\n");
  }
}
