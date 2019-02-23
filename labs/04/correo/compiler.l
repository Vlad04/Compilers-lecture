%{
#include <stdio.h>
%}

%%
p                           printf("print");
f                           printf("floatDcl");
i                           printf("intDcl");
[0123456789]+               printf("inum");
[0123456789]+"."[0-9]       printf("fnum");
[a-eg-hj-oq-z]+             printf("id");
"="                         printf("assign");
"+"                         printf("sum");
"*"                         printf("multiplication");
"/"                         printf("division");
"-"                         printf("minus");
[/][/].*\n                  printf("comment\n");

%%

int main(int argc, char **argv) {
    FILE    *fd;

    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        yylex();
        fclose(fd);
    }
    else
        printf("Usage: a.out filename\n");
    return (0);
}
