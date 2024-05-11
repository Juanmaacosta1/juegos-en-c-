#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct almacen
{
    char nombre[20]; 
    int numero;
};

int main () {

    int jugadores; 

    printf("ingrese la cantidad de jugadores: ");
    scanf("%d", &jugadores); 

    struct almacen CantJugadores[jugadores]; 

    for (int i = 0; i < jugadores; i++)
    {
       printf("\ningrese su nombre:\n", i + 1); 
       scanf("%s", CantJugadores[i].nombre);
   
    }
    
    srand(time(NULL));
       int numerosec = rand() % 100000 + 1;
       printf("numero:%d \n",&numerosec );
   


    return 0;
}