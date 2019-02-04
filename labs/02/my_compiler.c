//This program checks syntax errors (brackets, parenthesis and braces)
//To run this code please compile gcc my_compiler.c -o my_compiler
//Finally run as ./my_compiler < hello_world.c
#include<stdio.h>

int brace,brackets,parenthesis,line;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
    int c;
    

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
    
    if( brace != 0)
    {
        printf(" Error in Braces \n");
        brace = 0;
    }   
    else if( brackets != 0)
    {
        printf(" Error in brackets\n");
        brackets = 0;
    }
    else if( parenthesis != 0)
    {
        printf(" Error in parenthesis\n");
        parenthesis = 0;
    }
    
    else {
        printf(" All your code is nice on terms of syntax :) \n");
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

    if ( c == '{')
        brace--;
    else if ( c == '}')
        brace++;
    else if( c == '(')
        parenthesis--;
    else if( c == ')')
        parenthesis++;
    else if( c == '[')
        brackets--;
    else if( c == ']')
        brackets++;
}

