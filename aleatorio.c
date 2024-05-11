#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Necesario para obtener la hora actual
int main() {
    //tiempo 
    time_t inicio,fin;
    double tiempoFIN;
    char nombre [20];
    //saludo al usuario 
    printf(" ¡ BIEVENIDO AL JUEGO ! \n");
        printf("ingrese su nombre : ");
        scanf("%[^\n]", nombre);
        system("clear");
    printf("Un placer, %s", nombre);
    printf("\n");
    printf("¡ REGLAS DEL JUEGO ! \n");
    printf("1) Este número misterioso es de 5 cifras\n");
    printf("2) Se le indicará si alguno de sus números es correcto o ninguno lo es\n");
    printf("3) También se le indicará si los números correctos están en la posición correcta\n");
    printf("4) Tiene 10 intentos para adivinarlo\n ");
    printf("¡ SUERTE %s :D !", nombre); 
    printf("\n"); 
// Inicializa el generador de números aleatorios con la hora actual
    srand(time(NULL));
    int aleatorio[5];
    for (int i = 0; i < 5; i++)
    {
        aleatorio[i]=rand() % 10 ;
    }
//inicio de reloj
time(&inicio);
    //mecanismo de intentos 
    int intentosMAX=10;
    int intentos=0;
    int num [5];
    for (intentos= 0; intentos < intentosMAX; intentos++)
    {
       printf("Intento %d de %d Ingresa tu numero :   ", intentos+1, intentosMAX);
        scanf("%d", &num[5]);
    }
    //termina el reloj 
 time(&fin);
tiempoFIN=difftime(fin,inicio);
printf("tiempo: %.0f segundos \n", tiempoFIN);
printf("\n");
//imprime el numero aleaorio
    for (int i = 0; i < 5; i++)
    {
        printf("%i", aleatorio[i]);
    }
//volver a jugar y top 10
    int op;
    printf("\n¿Deseas intentar de nuevo?\n");
    printf("1) Para jugar otra vez\n");
    printf("2) Para ver el top 10 mejores jugadores\n");
    scanf("%d",&op);
    system("clear");
        switch (op)
        {
        case 1:
         printf(" ! volver a jugar \n!");
          break;
        case 2:
        printf("TOP 10 \n");
         break;

        default:
        printf  ("no existe esa opcion\n");
            break;
        }
     return 0;
}