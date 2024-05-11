#include <stdio.h>
int main() {
    //nombre del usuario
    
    char nombre [10];
    int puntaje [10];
    int intentos; 

    printf("nombre: \n");
    scanf("%[^\n]",&nombre);
    printf("HOLA:%s\n ",nombre);


    //puntaje
    printf("ingrese su puntaje: \n ");
    scanf ("%d",&puntaje);
    //top
    int posición = 10;
    int puesto = 0; 
    for (puesto  = 0; puesto < posición; puesto++)
    {
        printf("puesto: %d \n nombre:%s\n y puntaje:%d ", puesto+1, nombre[puesto],puntaje[puesto]);
    }
     

    
    
    
    return 0;
}