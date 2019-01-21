#include <stdio.h>
int main()
{
    int w, x, y, z;
    int i = 4; int j = 5;
    printf("1 El valor de i, j es: %d , %d \n", i,j);
    printf("\n");
    {
      int j = 7;
      i = 6;
      w = i + j;

      printf("El valor de w es: %d + %d = %d \n", i, j, w);
    }
    x = i + j;
      printf("El valor de x es: %d + %d = %d \n", i, j, x);
    {
      int i = 8;
      y = i + j;

    printf("El valor de y es: %d + %d = %d \n", i, j, y);
    }
    z = i + j;
    printf("El valor de z es: %d + %d = %d \n", i, j, z);
   return 0;
}
