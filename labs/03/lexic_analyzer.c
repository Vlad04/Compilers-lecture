#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
       char * file_name = argv[1];
       FILE *h_file = fopen(file_name,"r");

       char c;
       bool isFloat;

       while((c = fgetc(h_file)) != EOF){
               
               isFloat = false;

               //to avoid spaces
               if(c == '\n'){
                       printf("\n");
                       continue;
               }

               if(c == ' '){
                       continue;
               }

               //for int and float numbers
               if(isdigit(c)){
                        while(c != ' ' && c != '\n'){
                               if(c == '.'){
                                       isFloat = true;
                               }
                               c = fgetc(h_file);
                        }
                       if(isFloat){
                               printf("fnum ");
                       } else {
                               printf("inum ");
                       }
                       
                       if(c == '\n'){
                               printf("\n");
                       }
                       continue;
               }

               //for the lexical analyzis
               switch(c){
                       case 'f':
                               printf("floatdcl ");
                               break;
                       case 'i':
                               printf("intdcl ");
                               break;
                       case 'p':
                               printf("print ");
                               break;
                       case '=':
                               printf("assign ");
                               break;
                       case '+':
                               printf("plus ");
                               break;
                       case '-':
                               printf("minus ");
                               break;
                       case '*':
                               printf("multiplication ");
                               break;
                       case '/':
                               if((c = fgetc(h_file)) == '/'){
                                        char n = fgetc(h_file);
                                        while(n != '\n'){
                                                n = fgetc(h_file);
                                        }
                                        break;
                                } else {
                                       ungetc(c, h_file);
                                       printf("division ");
                                       break;
                               }
                       default:
                               printf("id ");
                               break;
               }
       }

       fclose(h_file);
}
