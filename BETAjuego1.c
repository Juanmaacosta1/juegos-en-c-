#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    int num [5];
        printf("ingrese 5 cifras \n");
    for ( int i = 0; i < 5; i++)
    {
     scanf("%d",&num[i]);
    }
    
   //arreglo 
    srand(time(NULL));
    int aleatorio [5];

    for (int i = 0; i < 5; i++)
    {
        aleatorio[i]=rand() % 10 ;
        printf("%i", aleatorio[i]);
    }

for (int i = 0; i < 5; i++) {

        if (num[i] == aleatorio[i])

         {
            printf(" \n Elemento %d: esta en la  posicion correcta ", i);
        } 
        else {
            printf("\n Elemento %d: Diferente", i);
        
        }
    }
    

    return 0;
}