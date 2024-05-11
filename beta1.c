#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t inicio, fin;
    double tiempoFIN;

    char nombre[20];

    printf("¡BIENVENIDO AL JUEGO!\n");
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    system("clear");
    printf("Un placer, %s\n", nombre);
    printf("\n");
    printf("¡REGLAS DEL JUEGO!\n");
    printf("1) Este número misterioso es de 5 cifras\n");
    printf("2) Se le indicará si alguno de sus números es correcto o ninguno lo es\n");
    printf("3) También se le indicará si los números correctos están en la posición correcta\n");
    printf("4) Tiene 10 intentos para adivinarlo\n");
    printf("¡SUERTE %s :D!\n", nombre);

    time(&inicio);

    int intentosMAX = 10;
    int intentos = 0;
    int num[5];

    // Inicializa el generador de números aleatorios con la hora actual
    srand(time(NULL));
    int aleatorio = rand() % 90000 + 10000;
    int arreglo[5];

    for (int i = 0; i < 5; i++) {
        arreglo[i] = aleatorio % 10;
        aleatorio /= 10;
    }

    for (intentos = 0; intentos < intentosMAX; intentos++) {
        printf("Intento %d de %d Ingresa tu numero :   ", intentos + 1, intentosMAX);
        for (int i = 0; i < 1; i++) {
            scanf("%d", &num[i]);
        }

        // Verifica los números ingresados y da retroalimentación al usuario
        int correctos = 0;
        int enPosicionCorrecta = 0;

        for (int i = 0; i < 5; i++) {
            if (num[i] == arreglo[i]) {
                enPosicionCorrecta++;
            } else {
                for (int j = 0; j < 5; j++) {
                    if (num[i] == arreglo[j]) {
                        correctos++;
                        break;
                    }
                }
            }
        }

        printf("Números correctos en la posición correcta: %d\n", enPosicionCorrecta);
        printf("Números correctos en la posición incorrecta: %d\n", correctos);
    }

    time(&fin);
    tiempoFIN = difftime(fin, inicio);
    printf("Tiempo: %.0f segundos\n", tiempoFIN);

    int op;
    printf("¿Deseas intentar de nuevo?\n");
    printf("1) Para jugar otra vez\n");
    printf("2) Para ver el top 10 mejores jugadores\n");
    scanf("%d", &op);
    system("clear");

    if (op == 1) {
        printf("Volver a jugar\n");
    } else {
        printf("¡BIENVENIDO AL TOP 10!\n");
    }

    return 0;
}
