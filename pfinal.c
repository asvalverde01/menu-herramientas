/******************************************************************************
Segundo avance del proyecto final

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1417

//Prototipos de funciones ------------------------------------------------------------.
int menu(void);
int enteroPositivo(void);
float calculadoraBasica(float, float, int);
float calculadoraAreas(float, float, int);

void convertirTemp(float);
void convertirMasa(float);
void convertirDistancia(float);
int convertirVelocidad(int);

//Función principal -----------------------------------------------------------------.
int main(void)
{
    // opm = opción de menú
    int opm;
    int op1 = 0, opM = 0, numInt[] = {0, 0, 0, 0, 0};
    float numFloat[] = {0, 0, 0}, answ = 1;
    do
    {
        opm = menu(); //Muestra el menú y recibe la opción seleccionada.
        system("clear");
        switch (opm)
        {
        case 1: //------------------------------------------------------------------------------------------.
            do
            {
                printf("------------------------------\n");
                printf("SECCIÓN DE CALCULADORAS\n------------------------------\n");
                printf("OPCIONES:\n1. OPERACIONES BÁSICAS\n2. ÁREAS\n3. Regresar\n\n");
                op1 = enteroPositivo();

                switch (op1)
                {
                case 1:
                    //Solicita 2 números e imprime una operación básica
                    do
                    {

                        numFloat[0] = 0;
                        numFloat[1] = 0;

                        do
                        {
                            printf("\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n");
                            printf("5. Insertar respuesta en número 1\n6. Regresar\n\n");
                            opM = enteroPositivo();
                            system("clear");
                        } while (opM > 6 || opM < 1);

                        if (opM == 5)
                        {
                            numFloat[0] = answ;
                            printf("\nSe ha copiado la respuesta en número 1 -> %.2f\n", numFloat[0]);
                            printf("\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n\n");

                            opM = enteroPositivo();
                        }
                        if (opM != 6)
                        {
                            printf("\nA continuación ingrese \n");
                            if (numFloat[0] != answ)
                            {
                                printf("Número 1 --> ");
                                scanf("%f", &numFloat[0]);
                            }
                            printf("Número 2 --> ");
                            scanf("%f", &numFloat[1]);
                            //Envía los 2 números y el operador a la función y recibe la respuesta
                            answ = calculadoraBasica(numFloat[0], numFloat[1], opM);
                            system("clear");
                            printf("--------------------\n");
                            printf("La respuesta es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 6);
                    break;

                case 2:

                    system("clear");
                    do
                    {
                        numFloat[0] = 0;
                        numFloat[1] = 0;

                        printf("\n1. Círculo\n2. Cuadrado\n3. Rectángulo\n4. Triángulo\n");
                        printf("5. Regresar\n\n");
                        opM = enteroPositivo();
                        if (opM > 5 || opM < 1) //En caso de una opción inválida
                        {
                            printf("\nOpción inválida, intente nuevamente\n");
                        }
                        system("clear");

                        if (opM != 5)
                        {
                            //Envía 2 números y la opción elegida
                            answ = calculadoraAreas(numFloat[0], numFloat[1], opM);
                            system("clear");
                            printf("--------------------\n");
                            printf("El área es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 5);
                    break;

                case 3:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 3);
            break;

        case 2: //------------------------------------------------------------------------------------------.
            system("clear");
            printf("------------------------------\n");
            printf("SECCIÓN DE CONVERTIDORES\n------------------------------\n");
            do
            {
                printf("OPCIONES:\n1. TEMPERATURA\n2. MASA\n3. DISTANCIA\n4. Regresar\n\n");
                op1 = enteroPositivo();
                if (opM > 4 || opM < 1) //En caso de una opción inválida
                {
                    printf("\nOpción inválida, intente nuevamente\n");
                }
                switch (op1)
                {
                case 1:
                    system("clear");
                    do
                    {
                        numFloat[0] = 0;
                        printf("1. Ingresar un valor de temperatura\n2. Regresar\n");
                        do
                        {
                            opM = enteroPositivo(); //Recibe una opción
                            if (opM > 2 || opM < 1) //En caso de una opción inválida
                            {
                                printf("\nOpción inválida, intente nuevamente\n");
                            }
                        } while (opM > 2 || opM < 1);

                        if (opM != 2)
                        {
                            printf("Ingrese la temperatura a convertir: ");
                            scanf("%f", &numFloat[0]);
                            system("clear");
                            //Invoca a la función que imprime las conversiones
                            convertirTemp(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("clear");
                        }
                    } while (opM != 2);
                    break;

                case 2:
                    system("clear");
                    do
                    {
                        numFloat[0] = 0;
                        printf("1. Ingresar un valor\n2. Regresar\n");
                        do
                        {
                            opM = enteroPositivo(); //Recibe una opción
                            if (opM > 2 || opM < 1) //En caso de una opción inválida
                            {
                                printf("\nOpción inválida, intente nuevamente\n");
                            }
                        } while (opM > 2 || opM < 1);

                        if (opM != 2)
                        {
                            printf("Ingrese el valor de la masa: ");
                            scanf("%f", &numFloat[0]);
                            system("clear");
                            //Invoca a la función que imprime las conversiones
                            convertirMasa(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("clear");
                        }
                    } while (opM != 2);
                    break;

                case 3:
                    system("clear");
                    do
                    {
                        numFloat[0] = 0;
                        printf("1. Ingresar un valor\n2. Regresar\n");
                        do
                        {
                            opM = enteroPositivo(); //Recibe una opción
                            if (opM > 2 || opM < 1) //En caso de una opción inválida
                            {
                                printf("\nOpción inválida, intente nuevamente\n");
                            }
                        } while (opM > 2 || opM < 1);

                        if (opM != 2)
                        {
                            printf("Ingrese el valor de distancia: ");
                            scanf("%f", &numFloat[0]);
                            system("clear");
                            //Invoca a la función que imprime las conversiones
                            convertirDistancia(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("clear");
                        }
                    } while (opM != 2);
                    break;
                case 4:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 3: //------------------------------------------------------------------------------------------.
            system("clear");
            printf(" ");
            break;

        case 4: //------------------------------------------------------------------------------------------.
            system("clear");
            printf(" ");
            break;

        case 5: //------------------------------------------------------------------------------------------.
            system("clear");
            break;

        case 6: //------------------------------------------------------------------------------------------.
            system("clear");
            printf("Terminando el programa...\n");
            return 0;
            break;

        default: //------------------------------------------------------------------------------------------.
            system("clear");
            printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
            break;
        }
    } while (opm != 6);
}

//Funciones secundarias -----------------------------------------------------------------.
int menu(void)
{
    float nop;
    printf("------------------------------------------------------\n");
    printf("Del siguiente menú elija una opción\n");
    printf("1. Calculadoras\n2. Convertidores\n3. \n4.\n5. Borrar la consola\n6. Salir\n");
    printf("------------------------------------------------------\n");
    printf("Opción(1-6)---> ");
    scanf("%f", &nop);
    //Previene un error en caso de ingresar un valor decimal
    int op = nop;
    ///Regresa el valor entero de la selección
    return op;
}

//OPCIÓN 1 -
float calculadoraBasica(float num1, float num2, int operador)
{
    if (operador == 1)
    {
        return num1 + num2;
    }
    if (operador == 2)
    {
        return num1 - num2;
    }
    if (operador == 3)
    {
        return num1 * num2;
    }
    if (operador == 4)
    {
        return num1 / num2;
    }
    return 5;
}

float calculadoraAreas(float num1, float num2, int opcion)
{
    float answ = 0;

    if (opcion == 1) //Área del círculo
    {
        printf("Ingrese el valor del rádio: ");
        scanf("%f", &num1);
        num1 = pow(num1, 2);
        answ = PI * num1;
    }
    if (opcion == 2) //Área del Cuadrado
    {
        printf("Ingrese el valor de un lado: ");
        scanf("%f", &num1);
        answ = num1 * num1;
    }
    if (opcion == 3) //Área del Rectángulo
    {
        printf("Ingrese la base: ");
        scanf("%f", &num1);
        printf("Ingrese la altura: ");
        scanf("%f", &num2);
        answ = num1 * num2;
    }
    if (opcion == 4) //Área del Triángulo
    {
        printf("Ingrese la base: ");
        scanf("%f", &num1);
        printf("Ingrese la altura: ");
        scanf("%f", &num2);
        answ = (num1 * num2) / 2;
    }
    return answ; //Devuelve el valor del área
}

//OPCIÓN 2 -
void convertirTemp(float temp)
{
    //Usando fórmulas de conversión se realiza los cáclulos
    float tempConvertida = 0;
    tempConvertida = (temp * 1.8) + 32;
    printf("%.1f celsius a fahrenheit ---> %.2f\n", temp, tempConvertida);
    tempConvertida = (temp - 32) * 0.55;
    printf("%.1f fahrenheit a celsius ---> %.2f\n", temp, tempConvertida);
    tempConvertida = temp + 273.15;
    printf("%.1f celsius a Kelvin ---> %.2f\n", temp, tempConvertida);
}

void convertirMasa(float masa)
{
    //Usando fórmulas de conversión se realiza los cáclulos
    float masaConvertida = 0;
    printf("\n");
    masaConvertida = masa / 16;
    printf("%.1f Onza a libra ---> %.3f \t\t", masa, masaConvertida);
    masaConvertida = masa * 16;
    printf("%.1f Libra a Onza ---> %.3f\n", masa, masaConvertida);
    masaConvertida = masa * 454;
    printf("%.1f Libra a Gramo ---> %.3f \t", masa, masaConvertida);
    masaConvertida = masa / 454;
    printf("%.1f Gramo a Libra ---> %.3f\n", masa, masaConvertida);
    masaConvertida = masa / 1000;
    printf("%.1f Gramo a Kilogramo ---> %.3f \t", masa, masaConvertida);
    masaConvertida = masa * 1000;
    printf("%.1f Kilogramo a Gramo ---> %.3f\n", masa, masaConvertida);
    masaConvertida = masa / 1000;
    printf("%.1f Kilogramo a Tonelada ---> %.3f \n\n", masa, masaConvertida);
}

void convertirDistancia(float distancia)
{
    //Usando fórmulas de conversión se realiza los cáclulos
    float distanciaConvertida = 0;
    printf("\n");
    distanciaConvertida = distancia / 12;
    printf("%.1f pulgada a pie ---> %.3f \t\t", distancia, distanciaConvertida);
    distanciaConvertida = distancia * 12;
    printf("%.1f pie a pulgada ---> %.3f\n", distancia, distanciaConvertida);
    distanciaConvertida = distancia * 100;
    printf("%.1f metro a centímetro ---> %.3f \t", distancia, distanciaConvertida);
    distanciaConvertida = distancia / 100;
    printf("%.1f centímetro a metro ---> %.3f\n", distancia, distanciaConvertida);
    distanciaConvertida = distancia * 1609;
    printf("%.1f milla a kilómetro ---> %.3f \t", distancia, distanciaConvertida);
    distanciaConvertida = distancia / 1609;
    printf("%.1f kilómetro a milla ---> %.3f\n\n", distancia, distanciaConvertida);
}
/*
int convertirVelocidad(int)
{
    return 0;
}

//OPCIÓN 3 -


//OPCIÓN 4 -


//OPCIÓN 4 -


//OPCIÓN 5 -


*/
//Esta función regresa un número positivo
int enteroPositivo(void)
{
    //variables locales
    float num; //flotante para evitar problemas en el programa
    int n = 0;
    do
    {
        printf("Número: ");
        scanf("%f", &num); //Recibe un número para evaluar

        if (num < 1) //En caso de ingresar un número menor que 1
        {
            printf("No se permiten números negativos o 0 \n");
        }
    } while (num < 1); //Repite mientras el número sea menor que 1

    num = round(num); //Redondea el número a su entero más cercano
    n = num;          //Convierte el número flotante en entero
    return n;
}
