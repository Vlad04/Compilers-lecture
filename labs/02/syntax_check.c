//This program checks syntax errors (brackets, parenthesis and braces)
//To run this code please compile gcc my_compiler.c -o my_compiler
//Finally run as ./my_compiler < hello_world.c
#include<stdio.h>

int brace,brack,parenthesis,line;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
    int c;
    
    extern int brace,brack,paren;

    while((c=getchar())!=EOF){
        if( c == '/')
            if((c=getchar())== '*')
                incomment();
            else 
                search(c);
        else if( c == '\'' || c == '"')
            inquote(c);
        else
            search(c);
    }
    
    if( brace < 0 || brace > 0)
    {
        printf("Error in Braces\n");
        brace = 0;
    }   
    else if( brack < 0 || brack > 0)
    {
        printf("Error in brackets\n");
        brack = 0;
    }
    else if( parenthesis < 0 || parenthesis > 0)
    {
        printf("Error in parenthesis\n");
        parenthesis = 0;
    }
    
    if(brace == 0 && brack == 0 && parenthesis == 0)
    {
        printf("All your code is nice on terms of syntax :) \n");
    }
    
    
    return 0;
}

void incomment()
{
    int c,d;
    
    c = getchar();
    d = getchar();

    while(c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

void inquote(int c)
{
    int d;

    putchar(c);

    while((d=getchar())!=c)
        if( d == '\\')
            getchar();
}

void search(int c)
{
    extern int brace,brack,paren;

    if ( c == '{')
        brace--;
    else if ( c == '}')
        brace++;
    else if( c == '(')
        brack--;
    else if( c == ')')
        brack++;
    else if( c == '[')
        parenthesis--;
    else if( c == ']')
        parenthesis++;
}

