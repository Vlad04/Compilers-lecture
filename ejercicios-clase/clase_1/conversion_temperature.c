#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    float F, C;
    F=atof(argv[1]);
    printf("Farenheit: %.2f \n", F);
    C=(F-32.0)*(5.0/9.0);
    printf("Celcius: %.2f \n",C);
    
    

    return 0;
}
