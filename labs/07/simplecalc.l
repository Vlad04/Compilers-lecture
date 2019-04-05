%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[0-9]+				{ yylval = atoi(yytext); return NUMBER; }
[0-9]+[.][0-9]+	    { yylval = atoi(yytext); return NUMBERF; }
f                   { yylval = (yytext); return FLOATDCL; }
p                   { yylval = (yytext); return PRINTDCL; }
i                   { yylval = (yytext); return INTDCL; }
[/][/].*\n          /*ignora comentarios*/
[ \t]               /*ignora espacios en blanco*/
[a-z]               { return ID; }
^\n                 /**/
\n                  { return NEWLINE; }
<<EOF>>             return eof; 
.                   return yytext[0];

%%
