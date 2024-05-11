#include <stdio.h>
#define fijo 10
int main(){ 

    int numeros[10]; 
    char nombre[10];  // Nombre fijo para todos los jugadores
    int intentos ;

    printf("\nnombre: ");
    scanf("%s", nombre);
    printf("\npuntos:");
    scanf("%d",&intentos);
   //for
    printf(" ¡ TOP DE LOS MEJORES 10 JUGADORES ! \n");

    for (int i = 0; i < fijo ; i++)

    {
    printf(" %d)  NOMBRE:%s |  PUNTOS:%d\n", i+1, nombre, intentos);
    }


    return 0; 
}