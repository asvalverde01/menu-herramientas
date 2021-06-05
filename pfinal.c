/******************************************************************************
Segundo avance del proyecto final
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1417
#define TAM 100

//Prototipos de funciones ------------------------------------------------------------.
int menu(void);
int enteroPositivo(void);
float calculadoraBasica(float, float, int);
float calculadoraAreas(float, float, int);
int calculadoraMatrices(int[2][10][10]);

void convertirTemp(float);
void convertirMasa(float);
void convertirDistancia(float);
int convertirVelocidad(int);

void ingresoDatosLis(char[][TAM], int[], int[], int[], int);
void impresionDatosLis(char[][TAM], int[], int[], int[], int);

//Función principal -----------------------------------------------------------------.
int main(void)
{
    // opm = opción de menú
    int opm, opLis, cantTarea, status = 0;
    int op1 = 0, opM = 0, numInt[] = {0, 0, 0, 0, 0}, cantMatriz = 0;
    float numFloat[] = {0, 0, 0}, answ = 1;
    char nom[TAM][TAM], asig[TAM][TAM];
    int dia[TAM], mes[TAM], year[TAM];
    int matriz[3][10][10];

    do
    {
        opm = menu(); //Muestra el menú y recibe la opción seleccionada.
        system("cls");
        switch (opm)
        {
        case 1: //------------------------------------------------------------------------------------------.
            do
            {
                printf("------------------------------\n");
                printf("SECCIÓN DE CALCULADORAS\n------------------------------\n");
                printf("OPCIONES:\n1. OPERACIONES BÁSICAS\n2. ÁREAS\n3. MATRICES\n4. Regresar\n\n");
                op1 = enteroPositivo();

                switch (op1)
                {
                case 1: //Calculadora básica
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
                            system("cls");
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
                            system("cls");
                            printf("--------------------\n");
                            printf("La respuesta es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 6);
                    break;

                case 2: //Calculadora de Areas

                    system("cls");
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
                        system("cls");

                        if (opM != 5)
                        {
                            //Envía 2 números y la opción elegida
                            answ = calculadoraAreas(numFloat[0], numFloat[1], opM);
                            system("cls");
                            printf("--------------------\n");
                            printf("El área es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 5);
                    break;

                case 3: //Calculadora de matrices
                    system("cls");
                    do
                    {
                        numFloat[0] = 0;
                        printf("1. Ingresar matrices (A) y (B)\n2. Regresar\n");
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
                            system("cls");
                            status = calculadoraMatrices(matriz);
                            printf("\n");
                        }
                        if (opM == 2)
                        {
                            system("cls");
                        }
                    } while (opM != 2);
                    break;

                case 4:
                    system("cls");
                    break;

                default:
                    system("cls");
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 2: //------------------------------------------------------------------------------------------.
            system("cls");
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
                    system("cls");
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
                            system("cls");
                            //Invoca a la función que imprime las conversiones
                            convertirTemp(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("cls");
                        }
                    } while (opM != 2);
                    break;

                case 2:
                    system("cls");
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
                            system("cls");
                            //Invoca a la función que imprime las conversiones
                            convertirMasa(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("cls");
                        }
                    } while (opM != 2);
                    break;

                case 3:
                    system("cls");
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
                            system("cls");
                            //Invoca a la función que imprime las conversiones
                            convertirDistancia(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            system("cls");
                        }
                    } while (opM != 2);
                    break;
                case 4:
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 3: //------------------------------------------------------------------------------------------.
            system("cls");
            do
            {
                printf("----------------\n");
                printf("LISTA DE TAREAS\n");
                printf("----------------\n");
                printf("1.Asignar una tarea\n2.Revisar las tareas pendientes\n3.Marcar tarea como finalizada\n4.Regresar\n");
                printf("Escoja una opción:");
                scanf("%d", &opLis);
                switch (opLis)
                {
                case 1:
                    system("cls");
                    printf("Ingrese la cantidad de tareas que desea enlistar: ");
                    scanf("%d", &cantTarea);
                    ingresoDatosLis(asig, dia, mes, year, cantTarea);
                    break;

                case 2:
                    system("cls");
                    impresionDatosLis(asig, dia, mes, year, cantTarea);
                    break;

                case 3:
                    system("cls");
                    break;

                default:
                    system("cls");
                    break;
                }
            } while (opLis <= 0 || opLis > 4);
            break;

        case 4: //------------------------------------------------------------------------------------------.
            system("cls");
            printf(" ");
            break;

        case 5: //------------------------------------------------------------------------------------------.
            system("cls");
            break;

        case 6: //------------------------------------------------------------------------------------------.
            system("cls");
            printf("Terminando el programa...\n");
            return 0;
            break;

        default: //------------------------------------------------------------------------------------------.
            system("cls");
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
    printf("Del siguiente menú elija una opción:\n");
    printf("1. Calculadoras\n2. Convertidores\n3. Lista de Tareas\n4. -----\n5. Borrar la consola\n6. Salir\n");
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

int calculadoraMatrices(int matriz[3][10][10])
{
    int cantFilas[3], cantColumnas[3], opMa = 0;
    printf("Se ingresan 2 matrices a continuación 1(A) y 2(B): \n");
    for (int c = 0; c < 2; c++) //Cantidad de matrices
    {
        printf("\nIngresando la matriz %d\n", c + 1);
        printf("Ingrese la cantidad de filas: ");
        cantFilas[c] = enteroPositivo();
        printf("Ingrese la cantidad de columnas:  ");
        cantColumnas[c] = enteroPositivo();
        system("cls");
        //Ingreso de datos de las 2 matrices
        for (int i = 0; i < cantFilas[c]; i++) //Filas
        {
            for (int j = 0; j < cantColumnas[c]; j++)
            {
                printf("Matriz %d - fila %d, columna %d --> ", c + 1, i + 1, j + 1);
                scanf("%d", &matriz[c][i][j]);
                matriz[2][i][j] = 0; //Crea una matriz C
            }
        }
    }
    system("cls");

    //Muestra todas las opciones para calcular las matrices registradas
    do
    {
        //Imprime las 2 matrices
        for (int cm = 0; cm < 2; cm++)
        {
            printf("---------------\n");
            printf("Matríz %d\n", cm + 1);
            for (int i = 0; i < cantFilas[cm]; i++) //Filas
            {
                for (int j = 0; j < cantColumnas[cm]; j++)
                {
                    printf("%d ", matriz[cm][i][j]); //Imprime la matriz A y B
                }
                printf("\n");
            }
        }

        do
        {
            printf("-----------------------------\n");
            printf("\n1. Sumar A + B\n2. Restar A - B\n3. Multiplicar A * B\n-. Insertar\n4. C en A\n5. C en B\n6. Regresar\n");
            opMa = enteroPositivo();
        } while (opMa > 6);

        switch (opMa)
        {
        case 1: //Suma las matrices
            system("cls");
            printf("Matriz 'C' resultado de la suma de las matrices(A+B)\n\n");
            if (cantFilas[0] == cantFilas[1] && cantColumnas[0] == cantColumnas[1])
            {
                cantFilas[2] = cantFilas[0];
                cantColumnas[2] = cantColumnas[0];

                for (int i = 0; i < cantFilas[0]; i++) //Filas
                {
                    for (int j = 0; j < cantColumnas[0]; j++) //Columnas
                    {
                        matriz[2][i][j] = matriz[0][i][j] + matriz[1][i][j];
                        printf("%d ", matriz[2][i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                printf("Las matrices deben tener el mismo tamaño, la misma cantidad de columnas y de filas.");
            }
            break;

        case 2: //Resta las matrices
            system("cls");
            printf("Matriz 'C' resultado de la resta de las matrices(A-B)\n\n");
            if (cantFilas[0] == cantFilas[1] && cantColumnas[0] == cantColumnas[1])
            {
                cantFilas[2] = cantFilas[0];
                cantColumnas[2] = cantColumnas[0];

                for (int i = 0; i < cantFilas[0]; i++) //Filas
                {
                    for (int j = 0; j < cantColumnas[0]; j++) //Columnas
                    {
                        matriz[2][i][j] = matriz[0][i][j] - matriz[1][i][j];
                        printf("%d ", matriz[2][i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                printf("Las matrices deben tener el mismo tamaño, la misma cantidad de columnas y de filas.");
            }
            break;

        case 3: //Multiplica A * B
            system("cls");

            break;

        case 4: //Insertar C en A
            system("cls");
            for (int i = 0; i < cantFilas[2]; i++) //Filas
            {
                for (int j = 0; j < cantColumnas[2]; j++) //Columnas
                {
                    matriz[0][i][j] = matriz[2][i][j];
                }
            }
            printf("\n");
            break;

        case 5: //Insertar C en B
            system("cls");
            for (int i = 0; i < cantFilas[2]; i++) //Filas
            {
                for (int j = 0; j < cantColumnas[2]; j++) //Columnas
                {
                    matriz[1][i][j] = matriz[2][i][j];
                }
            }
            printf("\n");
            break;

        case 6: //Regresar
            system("cls");
            return 0;
            break;

        default:
            system("cls");
            printf("Error, intente nuevamente\n");
            break;
        }
    } while (opMa != 6);
    return 0;
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
*/

//OPCIÓN 3 -
void ingresoDatosLis(char asig[][TAM], int dia[], int mes[], int year[], int cantTarea)
{
    int cont;
    for (cont = 0; cont < cantTarea; cont++)
    {
        printf("Ingrese la asignación N°%d que desea enlistar: ", cont + 1);
        getchar();
        fgets(asig[cont], TAM, stdin);
        printf("Ingrese la fecha límite para la tarea asignada: \n");
        do
        {
            printf("Dia: ");
            scanf("%d", &dia[cont]);
        } while (dia[cont] > 31 || dia[cont] < 1);
        do
        {
            printf("Mes: ");
            scanf("%d", &mes[cont]);
        } while (mes[cont] >= 13 || mes[cont] < 1);
        do
        {
            printf("Año: ");
            scanf("%d", &year[cont]);
        } while (year[cont] < 2021);
    }
    system("cls");
}

void impresionDatosLis(char asig[][TAM], int dia[], int mes[], int year[], int cantTarea)
{
    printf("A continuacón tus tareas pendientes:\n ");
    for (int cont = 0; cont < cantTarea; cont++)
    {
        printf("---------------------------\n");
        printf(" Tarea N° %d\n", cont + 1);
        printf("\t\t%s\n", asig[cont]);
        printf(" La cual vence el %d/%d/%d\n ", dia[cont], mes[cont], year[cont]);
        printf("---------------------------\n");
    }
}

//OPCIÓN 4 -

//OPCIÓN 4 -

//OPCIÓN 5 -

//Esta función regresa un número positivo
int enteroPositivo(void)
{
    //variables locales
    float num; //flotante para evitar problemas en el programa
    int n = 0;
    do
    {
        printf("--> ");
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
