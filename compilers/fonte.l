%{
    /* Aluno: Thales Candido Rosa */
    int linhas = 1, erros = 0;
%}

NUM         [0-9]
ID          [A-Za-z0-9_]
ESP         [\t\r" "]

%%


{ESP} /* Espaços em braco (espaço ou tab) */

"inicio"|"fim"|"se"|"senao"|"fimse"|"enquanto"|"fimenquanto"|"para"|"fimpara" {
    /* Controle de fluxo */
    printf("Controle de fluxo: %s\n", yytext);
}

"," {
    /* Virgula para passagem de parametros */
    printf("Virgula: %s\n", yytext);
}

"escreva"|"leia" {
    /* Comandos basicos da linguagem */
    printf("Comando: %s\n", yytext);
}

"inteiro"|"decimal"|"texto"|"bool" {
    /* Tipos de variaveis */
    printf("Tipo de variável: %s\n", yytext);
}

"e"|"ou"|"nao" {
    /* Operadores logicos */
    printf("Operador logico: %s\n", yytext);
}

"verdadeiro"|"falso" {
    /* Valores logicos */
    printf("Valor logico: %s\n", yytext);
}

[A-Za-z]{ID}* {
    /* Identificadores */
    printf("Identificador: %s\n", yytext);
}

{NUM}+ {
    /* Inteiros */
    printf("Inteiro: %s\n", yytext);
}

{NUM}+"."{NUM}+ {
    /* Decimais */
    printf("Decimal: %s\n", yytext);
}

["]([^"\\\n]|\\(.|\n))*["] {
    /* Texto em aspas duplas */
    printf("Texto: %s\n", yytext);
}

[']([^'\\\n]|\\(.|\n))*['] {
    /* Texto em aspas simples */
    printf("Texto: %s\n", yytext);
}

"+"|"-"|"/"|"*"|"^"|"%" {
    /* Operadores aritmeticos */
    printf("Operador aritmetico: %s\n", yytext);
}

"("|")" {
    /* Parentesis */
    printf("Parentesis: %s\n", yytext);
}

">"|"<"|">="|"<="|"=="|"!=" {
    /* Operadores de comparacao */
    printf("Operador de comparacao: %s\n", yytext); 
}

"<-" {
    /* Operador de atribuicao (recebe) */
    printf("Atribuicao: %s\n", yytext);
}

"//"[^\n]* {
    /* Comentario de uma linha */
    printf("Comentario: %s\n", yytext);
}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {
    /* Comentarios de varias linhas */
    printf("Comentario: %s\n", yytext);
}

\n {
    /* Fim da linha */
    printf("Fim da linha\n");
    linhas++;
}

{NUM}+{ID}+ {
    printf("Identificador invalido na linha %d: %s\n", linhas, yytext);
    erros++;
}

. {
    /* Demais tokens configuram erro */
    printf("Token invalido na linha %d: %s\n", linhas, yytext);
    erros++;
}

%%

int yywrap();

int main() {
    yylex();
    printf("Total de erros encontrados: %d\n", erros);
    if (erros == 0) {
        printf("O codigo analisado esta lexicamente correto!\n");
    }
    return 0;
}
    
int yywrap() {
    return 1;
}
