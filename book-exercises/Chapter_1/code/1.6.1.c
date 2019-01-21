#include <stdio.h>
int main()
{

    printf("\n");
    printf("Revisemos el codigo: \n");
    printf("\n");
    printf("int w, x, y, z;");
    printf("int i = 4; int j = 5;\n");
    printf("{\n");
    printf("  int j = 7;\n");
    printf("  i = 6;\n");
    printf("  w = i + j;\n");
    printf("}\n");
    printf("x = i + j;\n");
    printf("{\n");
    printf("  int i = 8;\n");
    printf("  y = i + j;\n");
    printf("}\n");
    printf("z = i + j;\n");
    printf("\n");
    
    int w, x, y, z;
    int i = 4; int j = 5;
    printf("El valor inicial de i, j es: %d , %d \n", i,j);
    printf("\n");
    {
      int j = 7;
      i = 6;
      w = i + j;

      printf("El valor de w es: i %d + j %d = %d \n", i, j, w);
    }
    x = i + j;
      printf("El valor de x es: i %d + j %d = %d \n", i, j, x);
    {
      int i = 8;
      y = i + j;

    printf("El valor de y es: i %d + j %d = %d \n", i, j, y);
    }
    z = i + j;
    printf("El valor de z es: i %d + j %d = %d \n", i, j, z);
   return 0;
}
