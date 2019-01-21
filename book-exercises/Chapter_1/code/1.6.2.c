#include <stdio.h>
int main()
{

    printf("\n");
    printf("Revisemos el codigo: \n");
    printf("\n");
    printf("int w, x, y, z;\n");
    printf("int i = 3; int j = 4;\n");
    printf("{\n");
    printf("int i = 5;\n");
    printf("w = i + j;\n");
    printf("}\n");
    printf("x = i + j;\n");
    printf("{\n");
    printf("int j = 6;\n");
    printf("i = 7;\n");
    printf("y = i + j;\n");
    printf("}\n");
    printf("z = i + j;\n");
    printf("\n");
    
    int w, x, y, z;
    int i = 3; int j = 4;
    printf("El valor de i, j es: %d , %d \n", i,j);
    printf("\n");
    {
      int i = 5;
      w = i + j;

      printf("El valor de w es: %d + %d = %d \n", i, j, w);
    }
    x = i + j;
      printf("El valor de x es: %d + %d = %d \n", i, j, x);
    {
      int j = 6;
      i=7;
      y = i + j;

    printf("El valor de y es: %d + %d = %d \n", i, j, y);
    }
    z = i + j;
    printf("El valor de z es: %d + %d = %d \n", i, j, z);
   return 0;
}
