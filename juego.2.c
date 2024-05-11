#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void pantalla_final()
{
    int result = pantalla_final;
    return result;
}

int main()
{
    int puntaje = 0; 
    char opcion;
    do{
    //Inicialización de variables
    time_t inicio_reloj, fin_reloj;
    double tiempoFIN, minuto = 0;
    char nombre [20];
    srand(time(NULL));
    int numero, d = 1, 
    intentos = 10, 
    numAleatorio[5],
    numIngresado[5]; //tamaño de los arreglos que contendran los numeros tanto ingresados como el aleatorio

    numAleatorio[0] = (rand() % 9) + 1; // esto para que el primer numero sea distinto a 0 y se respete el numero de 5 digitos
    for (int i = 1; i < 5; i++)
    {
        numAleatorio[i] = rand() % 10; //genera un numero aleatorio entre 0 y 9 y lo almacena en las posiciones restantes del arreglo //
    }
//Inicio
system("clear");
puts("\t\t\t\033[1;32m  ## El número oculto ##\033[0m\n");
        printf("Ingrese su nombre: ");
        scanf("%[^\n]", nombre);
        system("clear");
    printf("¡Bienvenido a \033[1;32m\"El número oculto\"\033[0m, %s!", nombre);
    printf("\n\n");
    printf("¡ REGLAS DEL JUEGO ! \n\n");
    printf("*Este número misterioso es de 5 dígitos.\n");
    printf("*Se le indicará si alguno de sus números es correcto o ninguno lo es.\n");
    printf("*También se le indicará si los números correctos están en la posición correcta.\n");
    printf("*Tiene 10 intentos para adivinarlo.\n\n");
    printf("¡ SUERTE %s :D !", nombre); 
    printf("\n\n");

    getchar();
    
    printf("\t\t\t## Presione Enter para empezar el juego ##\n");
    
    getchar();
    
    system("clear");
    
    //inicio de reloj
     time(&inicio_reloj);

    //Comparacion//
    while (intentos > 0)
    {
        printf("\033[90m(Intento %d/10)\033[0m\n", d);
        printf("Ingrese un número de 5 dígitos: ");
        scanf("%d", &numero);
        d++;

    // Validar que el número tiene 5 dígitos
    if (numero < 10000 || numero > 99999) 
    {
        printf("El número ingresado no tiene 5 dígitos.\n");
        printf("\033[90mSaliendo del programa. . .\033[0m");
        return 1; // Salir del programa con un código de error
    } else
    {
        // Extrae los dígitos y los almacena en el array
        numIngresado[0] = numero / 10000; // Dígito de la decena de mil
        numero %= 10000; // Quita las decenas de mil
        numIngresado[1] = numero / 1000; // Dígito de la unidad de mil
        numero %= 1000; //Quita las unidades de mil
        numIngresado[2] = numero / 100; // Dígito de las centenas
        numero %= 100; // Quita las centenas
        numIngresado[3] = numero / 10;  // Dígito de las decenas
        numIngresado[4] = numero % 10;  // Dígito de las unidades
    }
    
    
    // Comparación de los numeros //
    for (int i = 0; i < 5; i++) {
        if (numIngresado[i] == numAleatorio[i]) {
            printf("\033[1;32mNúmero %d es correcto y está en la posicion correcta.\033[1;0m\n", numIngresado[i]);
        } else {
            int posicion = 0;
            for (int j = 0; j < 5; j++) {
                if (numIngresado[i] == numAleatorio[j]) {
                    printf("\033[1;33mNúmero %d es correcto pero está en la posición incorrecta.\033[1;0m\n", numIngresado[i]);
                    posicion = 1;
                    break;
                }
            }
            if (!posicion) {
                printf("\033[1;31mNúmero %d no coincide.\033[1;0m\n", numIngresado[i]);
            }
        }
    }

    int numCorrecto = 1; 
    for (int i = 0; i < 5; i++)
    {
        if (numIngresado[i] != numAleatorio[i])
        {
            numCorrecto = 0; 
            break;
        }
    }
int a;
    if (numCorrecto)
    {
        printf("\n¡Felicidades! Has encontrado el número. \n");
        pantalla_final();
        
    }
    
 
    intentos--;
    }

    //Finaliza el cronometro
    time(&fin_reloj);

    //Calcula el tiempo transcurrido del cronometro (minutero y segundero)
    tiempoFIN = difftime(fin_reloj, inicio_reloj);
    double un_minuto;
    un_minuto = 60;
    double almacenar_tiempo_transcurrido = tiempoFIN;

    //Minutero
    while(almacenar_tiempo_transcurrido > un_minuto){
        minuto = minuto + 1;
        almacenar_tiempo_transcurrido = almacenar_tiempo_transcurrido - un_minuto;
    }

    //Segundero
    do{
        if(tiempoFIN > un_minuto){
            tiempoFIN = tiempoFIN - un_minuto;
        }
    }while(tiempoFIN > un_minuto);

    printf("\n");
    system("clear");

    //Pantalla final
    system("clear");
    printf("\t\t\t    ¡Fin del juego!\n");
        puts("");
    printf("\t\t       Tiempo transcurrido: %02.0f:%02.0f\n", minuto, tiempoFIN);
    printf("\t\t        Cantidad de intentos: %d\n\n", d-1);

    //¿Volver a jugar?
    printf("\t\t      ## ¿Desea volver a jugar? ##\n"); 
    printf("\t   ## Pulsa 's' para aceptar / Pulsa 'n' para cancelar ##\n");
    scanf(" %c", &opcion);
        switch (opcion)
        {
        case 's':
        case 'S':
            break;
        case 'n':
        case 'N':
            break;
        
        default:
        printf  ("¡Esa opción no existe!");
            return 1;
        }
    }while(opcion != 'n' && opcion != 'N');


    return 0;
    
}