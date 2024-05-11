#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definiciones de colores
#define ROJO 1
#define NEGRO 2
#define VERDE 3

// Estructura para representar una apuesta
typedef struct {
    int tipo;  // Tipo de apuesta (1: número, 2: par/impar, 3: color)
    int valor;  // Valor de la apuesta
    int monto;  // Monto apostado
} Apuesta;

// Función para girar la ruleta
int girarRuleta() {
    return rand() % 37;  // Números del 0 al 36 en la ruleta
}

// Función para realizar una apuesta
Apuesta realizarApuesta() {
    Apuesta apuesta;
    printf("\nElige el tipo de apuesta:\n");
    printf("1. Número específico\n");
    printf("2. Par/Impar\n");
    printf("3. Color (Rojo/Negro)\n");
    printf("Selecciona el número correspondiente al tipo de apuesta: ");
    scanf("%d", &apuesta.tipo);

    switch (apuesta.tipo) {
        case 1:
            printf("Ingresa el número en el que deseas apostar (entre 0 y 36): ");
            scanf("%d", &apuesta.valor);
            break;
        case 2:
            printf("Selecciona 1 para par o 2 para impar: ");
            scanf("%d", &apuesta.valor);
            break;
        case 3:
            printf("Selecciona 1 para rojo, 2 para negro: ");
            scanf("%d", &apuesta.valor);
            break;
        default:
            printf("Tipo de apuesta no válido. Se realizará una apuesta a número 0.\n");
            apuesta.tipo = 1;
            apuesta.valor = 0;
            break;
    }

    printf("Ingresa el monto de la apuesta: ");
    scanf("%d", &apuesta.monto);

    return apuesta;
}

// Función para determinar si se ha ganado la apuesta
int verificarGanador(Apuesta apuesta, int numeroGanador) {
    switch (apuesta.tipo) {
        case 1:  // Apuesta a número específico
            return (apuesta.valor == numeroGanador);
        case 2:  // Apuesta a par/impar
            return ((apuesta.valor == 1) && (numeroGanador % 2 == 0)) || ((apuesta.valor == 2) && (numeroGanador % 2 != 0));
        case 3:  // Apuesta a color
            if (apuesta.valor == ROJO) {
                return (numeroGanador % 2 == 0);
            } else if (apuesta.valor == NEGRO) {
                return (numeroGanador % 2 != 0);
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

// Función para imprimir el diseño de la ruleta
void imprimirRuleta() {
    printf(" ****   *  *   *      ****   *****   *****    \n");
    printf(" *   *  *  *   *      *        *     *   *    \n");
    printf(" ***    *  *   *      ***      *      ***     \n");
    printf(" *  *   *  *   *      *        *     *   *    \n");
    printf(" *   *   **    ****   ****     *     *   *    \n");
    printf("\n");
    printf("     |7 |28|12|35|3 |26|  0  |32|15|19|4 |21|2 |\n");
    printf("    |29|                                     |25|\n");
    printf("   |18|                                       |17|\n");
    printf("  |22|                LA RULETA                |34|\n");
    printf("   |9 |                                       |6 |\n");
    printf("    |31|                                     |27|\n");
    printf("     |14|20|1 |33|16|24|5 |10|23|8 |30|11|36|13|\n");
    printf("\n");
}

// Función para imprimir el historial de apuestas y resultados
void imprimirHistorial(Apuesta historial[], int resultados[], int numJuegos) {
    printf("\n--- Historial de Juegos ---\n");
    for (int i = 0; i < numJuegos; i++) {
        printf("Juego %d: Tipo %d, Valor %d, Monto %d, Resultado %s\n", i + 1,
               historial[i].tipo, historial[i].valor, historial[i].monto,
               (resultados[i]) ? "Ganado" : "Perdido");
    }
}

int main() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    srand(time(NULL));

    int saldo = 100;  // Saldo inicial del jugador
    int numJuegos = 0;  // Número de juegos jugados
    Apuesta historial[100];  // Historial de apuestas
    int resultados[100];  // Resultados de los juegos

    printf("Bienvenido a la ruleta. Tu saldo inicial es de %d.\n", saldo);

    while (saldo > 0) {
        // Imprimir el diseño de la ruleta
        imprimirRuleta();

        // Realizar una apuesta
        Apuesta apuesta = realizarApuesta();
        historial[numJuegos] = apuesta;  // Agregar la apuesta al historial

        // Obtener el resultado de la ruleta
        int numeroGanador = girarRuleta();

        // Imprimir el resultado
        printf("Número ganador: %d\n", numeroGanador);

        // Verificar si se ha ganado la apuesta
        resultados[numJuegos] = verificarGanador(apuesta, numeroGanador);

        // Ajustar el saldo
        if (resultados[numJuegos]) {
            saldo += historial[numJuegos].monto * 36;  // Paga 35 a 1 en una apuesta ganadora
            printf("¡Felicidades! Ganaste. Tu nuevo saldo es de %d.\n", saldo);
        } else {
            saldo -= historial[numJuegos].monto;  // Pierde el monto apostado en una apuesta perdida
            printf("Lo siento, perdiste. Tu nuevo saldo es de %d.\n", saldo);
        }

        // Incrementar el número de juegos
        numJuegos++;

        // Preguntar si el jugador quiere continuar
        char continuar;
        printf("¿Quieres seguir jugando? (s/n): ");
        scanf(" %c", &continuar);

        if (continuar != 's' && continuar != 'S') {
            break;  // Salir del bucle si el jugador no quiere continuar
        }
    }

    // Imprimir el historial de apuestas y resultados al final del juego
    imprimirHistorial(historial, resultados, numJuegos);

    printf("Gracias por jugar. Tu saldo final es de %d.\n", saldo);

    return 0;
}
