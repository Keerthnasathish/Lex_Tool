%{
#include <stdio.h>
%}

%%
"if"      { printf("IF keyword\n"); }
"else"    { printf("ELSE keyword\n"); }
"int"     { printf("INT keyword\n"); }
"float"   { printf("FLOAT keyword\n"); }

[0-9]+    { printf("NUMBER\n"); }
[a-zA-Z]+ { printf("IDENTIFIER\n"); }

[ \t\n]   ;
.         { printf("UNKNOWN: %s\n", yytext); }
%%

int main() {
    printf("Enter input:\n");
    yylex();
    return 0;
}
