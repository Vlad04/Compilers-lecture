%{ 
#undef writeToken 
#include <stdio.h> 
void writeToken(char s[]); 
FILE  *fp; 
%} 
 
%% 
f   writeToken("floatdcl "); 
i   writeToken("intdcl "); 
p   writeToken("print "); 
[a-eghj-oq-z]  writeToken("id"); 
[0-9]+   writeToken("inum"); 
[0-9]+"."[0-9]{1,5} writeToken("fnum"); 
"="   writeToken(" assign "); 
"+"   writeToken(" plus "); 
"-"   writeToken(" minus "); 
"*"   writeToken(" multiplication "); 
"/"   writeToken(" division "); 
[/][/].*\n   
^\n    
[ \t]+ 
\n   writeToken("\n"); 
%% 
 
int main(int argc, char **argv) { 
    FILE    *fd; 
    fp = fopen("tokens.out","w"); 
 
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
    { 
        printf("Usage: a.out filename\n"); 
    } 
 
    fclose(fp); 
    return (0); 
} 
 
void writeToken(char s[]) { 
    fprintf(fp,"%s", s); 
} 
