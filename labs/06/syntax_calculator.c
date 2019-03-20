#define _GNU_SOURCE 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
 
#define MAXNUMSTRING 255 
 
//Helper funcs 
bool match(char*); 
void next(); 
 
//My productions
bool S(); 
bool T(); 
bool F(); 
bool R(); 
bool G(); 
 

int line_count = 1; 
char line[MAXNUMSTRING];
char *save = NULL; 
char *p = NULL; 
char *graph = "";  
char *saveline; 
bool newLine; 
 
int main(int argc, char **argv){ 
    FILE *fp; 
 
    fp = fopen(argv[1], "r"); 
    
    if(fp == NULL){ 
        perror("Error while opening file\n"); 
        exit(EXIT_FAILURE);  
    } 
 
    while(fgets(line,MAXNUMSTRING,fp) != NULL){ 
        
        newLine = false; 
        asprintf(&graph,"%sdigraph N",graph); 
        asprintf(&graph,"%s%d",graph,line_count); 
        asprintf(&graph,"%s {\n\n",graph); 
        asprintf(&saveline,"%s",line); 
        graph = ""; 
        p = strtok(line," "); 
        bool result = S(); 
        
        if(result == true){ 
            asprintf(&graph,"%s\n}\n\n",graph); 
            printf("True\n%s",graph); 
    
        }
        
    } 
    return 0; 
} 
 
void next(){ 

    if(newLine){ 
        p = "\n"; 
    } 
    else { 
        save = p; 
        p = strtok(NULL," "); 
        if(p[strlen(p)-1] == '\n'){ 
            p[strlen(p)-1] = 0; 
            newLine = true; 
            line_count=line_count+1; 
        } 
    } 
    
    if(p == NULL){
    next();
    } 
} 
 
bool match(char* token){ 
    bool result = false; 
    
    if (strcmp(token, p) == 0){ 
       result = true; 
    } 
    
    next(); 

    return result; 
} 
 
bool S(){ 
    return F() && match("\n") || T() && match("\n"); 
} 
 
bool T(){ 
    bool result = false; 
 
    if(strcmp(p,"intdcl") == 0){ 
        asprintf(&graph,"%s  S -> {D,newline}\n",graph); 
        asprintf(&graph,"%s  T -> {intdcl,id}\n",graph); 
        result = match("intdcl") && match("id"); 
    } 
    else if(strcmp(p,"print") == 0){ 
        asprintf(&graph,"%s  S -> {D,newline}\n",graph); 
        asprintf(&graph,"%s  T -> {print,id}\n",graph); 
        result = match("print") && match("id"); 
    } 
    else if(strcmp(p,"floatdcl") == 0){ 
        asprintf(&graph,"%s  S -> {D,newline}\n",graph); 
        asprintf(&graph,"%s  T -> {floatdcl,id}\n",graph); 
        result = match("floatdcl") && match("id"); 
    } 
 
    return result; 
} 
 
bool F(){ 
    bool result = false; 
 
    if(strcmp(p,"id") == 0){ 
        asprintf(&graph,"%s  S -> {F,newline}\n",graph); 
        asprintf(&graph,"%s  F -> {id,assign,G,R}\n",graph); 
        result = match("id") && match("assign") && G() && R(); 
    } 
 
    return result; 
} 
 
bool G(){ 
    bool result = false; 
 
    if(strcmp(p,"id") == 0){ 
        asprintf(&graph,"%s  G -> {id}\n",graph); 
        result = match("id"); 
    } 
    else if(strcmp(p,"inum") == 0){ 
        asprintf(&graph,"%s  G -> {inum}\n",graph); 
        result = match("inum"); 
    } 
    else if(strcmp(p,"fnum") == 0){ 
        asprintf(&graph,"%s  G -> {fnum}\n",graph); 
        result = match("fnum"); 
    } 
 
    return result; 
} 

bool R(){ 
    bool result = false; 
 
    if(strcmp(p,"plus") == 0){ 
        asprintf(&graph,"%s  R -> {plus,G,R}\n",graph); 
        result = match("plus") && G() && R(); 
    } 
    else if(strcmp(p,"minus") == 0){ 
        asprintf(&graph,"%s  R -> {minus,G,R}\n",graph); 
        result = match("minus") && G() && R(); 
    } 
    else if(strcmp(p,"multiplication") == 0){ 
        asprintf(&graph,"%s  R -> {multiplication,G,R}\n",graph); 
        result = match("multiplication") && G() && R(); 
    } 
    else if(strcmp(p,"division") == 0){ 
        asprintf(&graph,"%s  R -> {division,G,R}\n",graph); 
        result = match("division") && G() && R(); 
    }else { 
        asprintf(&graph,"%s  R -> {λ}\n",graph); 
        result = true; 
    } 
    return result; 
} 
