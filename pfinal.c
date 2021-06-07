//Inclusión de librerías ----------------------------------------------------------.
int menu(void);
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Verifica el sistema operativo para incluir la libreria
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//Definición de valores ------------------------------------------------------------.
int menu(void);
#define PI 3.1417
#define TAM 100

//Prototipos de funciones ------------------------------------------------------------.
int menu(void);
int enteroPositivo(void);
void borrarConsola(void);

float calculadoraBasica(float, float, int);
float calculadoraAreas(float, float, int);
int calculadoraMatrices(int[2][10][10]);

void convertirTemp(float);
void convertirMasa(float);
void convertirDistancia(float);

void ingresoDatosLis(char[][TAM], int[], int[], int[], int);
void impresionDatosLis(char[][TAM], int[], int[], int[], int);

void temporizador(int, int, int);

void genContra(int, char[21]);

//Función principal -----------------------------------------------------------------.
int main(void)
{

    //Inicializacion de variables ------------------------------
    int opm, opLis, cantTarea, status = 0; // opm = opción de menú
    int op1 = 0, opM = 0, numInt[] = {0, 0, 0, 0, 0}, cantMatriz = 0;
    float numFloat[] = {0, 0, 0}, answ = 1;
    char nom[TAM][TAM], asig[TAM][TAM];
    int dia[TAM], mes[TAM], year[TAM], matriz[3][10][10];

    //Loop principal
    do
    {
        opm = menu(); //Muestra el menú y recibe la opción seleccionada.
        borrarConsola();
        switch (opm)
        {
        case 1: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("---SECCIÓN DE CALCULADORAS---\n------------------------------\n");
            do
            {
                printf("\nOPCIONES:\n1. OPERACIONES BÁSICAS\n2. ÁREAS\n3. MATRICES\n4. Regresar\n\n");
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
                            borrarConsola();
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
                            borrarConsola();
                            printf("--------------------\n");
                            printf("La respuesta es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 6);
                    break;

                case 2: //Calculadora de Areas

                    borrarConsola();
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
                        borrarConsola();

                        if (opM != 5)
                        {
                            //Envía 2 números y la opción elegida
                            answ = calculadoraAreas(numFloat[0], numFloat[1], opM);
                            borrarConsola();
                            printf("--------------------\n");
                            printf("El área es %.2f \n", answ);
                            printf("--------------------\n");
                        }

                    } while (opM != 5);
                    break;

                case 3: //Calculadora de matrices
                    borrarConsola();
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
                            borrarConsola();
                            status = calculadoraMatrices(matriz);
                            printf("\n");
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 4:
                    borrarConsola();
                    break;

                default:
                    borrarConsola();
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 2: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("SECCIÓN DE CONVERTIDORES\n------------------------------\n\n");
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
                    borrarConsola();
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
                            borrarConsola();
                            //Invoca a la función que imprime las conversiones
                            convertirTemp(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 2:
                    borrarConsola();
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
                            borrarConsola();
                            //Invoca a la función que imprime las conversiones
                            convertirMasa(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 3:
                    borrarConsola();
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
                            borrarConsola();
                            //Invoca a la función que imprime las conversiones
                            convertirDistancia(numFloat[0]);
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;
                case 4:
                    borrarConsola();
                    break;
                default:
                    borrarConsola();
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 3: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("SECCIÓN DE TAREAS\n------------------------------\n\n");
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
                    borrarConsola();
                    printf("Ingrese la cantidad de tareas que desea enlistar: ");
                    scanf("%d", &cantTarea);
                    ingresoDatosLis(asig, dia, mes, year, cantTarea);
                    break;

                case 2:
                    borrarConsola();
                    impresionDatosLis(asig, dia, mes, year, cantTarea);
                    break;

                case 3:
                    borrarConsola();
                    break;

                default:
                    borrarConsola();
                    break;
                }
            } while (opLis <= 0 || opLis > 4);
            break;

        case 4: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("SECCIÓN DE HERRAMIENTAS\n------------------------------\n");
            do
            {
                printf("OPCIONES:\n1. TEMPORIZADOR\n2. ---\n3. ---\n4. Regresar\n\n");
                op1 = enteroPositivo();
                if (opM > 4 || opM < 1) //En caso de una opción inválida
                {
                    printf("\nOpción inválida, intente nuevamente\n");
                }
                switch (op1)
                {
                case 1: //Inicia un temporizador
                    borrarConsola();
                    do
                    {
                        //se registran horas, minutos, segundos
                        numInt[0] = 0, numInt[1] = 0, numInt[2] = 0;
                        printf("1. Iniciar un temporizador \n2. Regresar\n");
                        do
                        {
                            opM = enteroPositivo(); //Recibe una opción
                            if (opM > 2 || opM < 1) //En caso de una opción inválida
                            {
                                printf("\nOpción inválida, intente nuevamente\n");
                            }
                        } while (opM > 2 || opM < 1);

                        // Solicita al usuario horas, minutos y segundos dentro de un rango permitido
                        if (opM != 2)
                        {
                            printf("A continuación ingrese\n\n");
                            do //Ingreso de horas
                            {
                                printf("Horas (0 - 24): ");
                                scanf("%d", &numInt[0]);
                            } while (numInt[0] < 0 || numInt[0] > 24);

                            do //Ingreso de minutos
                            {
                                printf("Minutos (0 - 60): ");
                                scanf("%d", &numInt[1]);
                            } while (numInt[1] < 0 || numInt[1] > 60);

                            do //Ingreso de segundos
                            {
                                printf("Segundos (0 - 60): ");
                                scanf("%d", &numInt[2]);
                            } while (numInt[2] < 0 || numInt[2] > 60);
                            borrarConsola();

                            //Invoca a la función que inicia el temporizador y envía valores de tiempo
                            printf("Iniciado un temporizador %d/%d/%d\n", numInt[0], numInt[1], numInt[2]);
                            temporizador(numInt[0], numInt[1], numInt[2]);
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 2:
                    borrarConsola();
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
                            printf("Ingrese el valor de ");
                            scanf("%f", &numFloat[0]);
                            borrarConsola();
                            //TODO
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 3:
                    borrarConsola();
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
                            printf("Ingrese el valor ");
                            scanf("%f", &numFloat[0]);
                            borrarConsola();
                            //Invoca a la función que
                            //TODO
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;
                case 4:
                    borrarConsola();
                    break;
                default:
                    borrarConsola();
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 5: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("ADMINISTRADOR DE CONTRASEÑAS\n------------------------------\n");
            do
            {
                printf("OPCIONES:\n1. GENERAR CONTRASEÑA\n2. GUARDAR\n3. MOSTRAR\n4. Regresar\n\n");
                op1 = enteroPositivo();
                if (opM > 4 || opM < 1) //En caso de una opción inválida
                {
                    printf("\nOpción inválida, intente nuevamente\n");
                }
                switch (op1)
                {
                case 1: //Generador de contraseñas
                    borrarConsola();
                    do
                    {
                        char contra[15];
                        printf("1. Generar una nueva contraseña \n2. Regresar\n");
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
                            borrarConsola();
                            //Invoca a la función que genera una contraseña
                            do
                            {
                                printf("Ingrese la langitud para la contraseña\n");
                                numInt[0] = enteroPositivo();

                                if (numInt[0] > 20)
                                {
                                    borrarConsola();
                                    printf("El límite es 20\n\n");
                                }
                            } while (numInt[0] > 20);

                            //Se invoca a la función enviando el arreglo de la contraseña y la longitud
                            genContra(numInt[0], contra);
                            borrarConsola();
                            //Imprime la contraseña generada por la función
                            printf("Contraseña generada:\n");
                            printf("\n%s\n\n", contra);
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 2:
                    borrarConsola();
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
                            printf("Ingrese el valor de ");
                            scanf("%f", &numFloat[0]);
                            borrarConsola();
                            //TODO
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;

                case 3:
                    borrarConsola();
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
                            printf("Ingrese el valor ");
                            scanf("%f", &numFloat[0]);
                            borrarConsola();
                            //Invoca a la función que
                            //TODO
                        }
                        if (opM == 2)
                        {
                            borrarConsola();
                        }
                    } while (opM != 2);
                    break;
                case 4:
                    borrarConsola();
                    break;
                default:
                    borrarConsola();
                    printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
                    break;
                }
            } while (op1 != 4);
            break;

        case 6: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("------------------------------\n");
            printf("SECCIÓN DE AYUDA E INFORMACIÓN\n------------------------------\n");
            break;

        case 7:              //------------------------------------------------------------------------------------------.
            borrarConsola(); //Borra la consola
            break;

        case 8: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("Terminando el programa...\n");
            return 0;
            break;

        default: //------------------------------------------------------------------------------------------.
            borrarConsola();
            printf("***ERROR***\nLa opción ingresada no se encuentra en el menú\n");
            break;
        }
    } while (opm != 8);
}

//Funciones secundarias -----------------------------------------------------------------.
int menu(void)
{
    float nop;
    printf("------------- STUDENT TOOLS -------------\n");
    printf("-----------------------------------------\n");
    printf("---DEL SIGUIENTE MENÚ ELIJA UNA OPCIÓN---\n\n");
    printf("1. CALCULADORAS\n2. CONVERTIDORES\n3. LISTA DE TAREAS\n4. HERRAMIENTAS\n5. CONTRASEÑAS\n");
    printf("6. AYUDA / ACERCA DE\n7. BORRAR LA CONSOLA\n8. SALIR / TERMINAR\n");
    printf("\n");
    printf("|---Opción(1-8)---> ");
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
        borrarConsola();
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
    borrarConsola();

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
            borrarConsola();
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
            borrarConsola();
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
            borrarConsola();
            int valor = 0;
            if (cantColumnas[0] == cantFilas[1])
            {
                cantFilas[2] = cantFilas[0];
                cantColumnas[2] = cantColumnas[1];
                printf("Matriz resultante de %d x %d\n", cantFilas[2], cantColumnas[2]);

                for (int i = 0; i < cantFilas[2]; i++)
                {
                    for (int j = 0; j < cantColumnas[2]; j++)
                    {
                        matriz[2][i][j] = 0;
                        for (int k = 0; k < cantColumnas[2]; k++)
                        {
                            matriz[2][i][j] += matriz[0][i][k] * matriz[1][k][j];
                        }
                        printf("%d ", matriz[2][i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("El número de columnas de la primera matriz debe coincidir con el número de filas de la segunda matriz.");
            }

            break;

        case 4: //Insertar C en A
            borrarConsola();
            for (int i = 0; i < cantFilas[2]; i++) //Filas
            {
                for (int j = 0; j < cantColumnas[2]; j++) //Columnas
                {
                    matriz[0][i][j] = matriz[2][i][j];
                    cantFilas[0] = cantFilas[2];
                    cantColumnas[0] = cantColumnas[2];
                }
            }
            printf("\n");
            break;

        case 5: //Insertar C en B
            borrarConsola();
            for (int i = 0; i < cantFilas[2]; i++) //Filas
            {
                for (int j = 0; j < cantColumnas[2]; j++) //Columnas
                {
                    matriz[1][i][j] = matriz[2][i][j];
                    cantFilas[1] = cantFilas[2];
                    cantColumnas[1] = cantColumnas[2];
                }
            }
            printf("\n");
            break;

        case 6: //Regresar
            borrarConsola();
            return 0;
            break;

        default:
            borrarConsola();
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
    borrarConsola();
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
void temporizador(int horas, int minutos, int segundos)
{

    while (horas > 0 || minutos > 0 || segundos > 0)
    {

        if (segundos > 0)
        {
            segundos--;
        }
        if (segundos == 0 && minutos > 0)
        {
            minutos--;
            segundos = 59;
        }
        if (minutos == 0 && horas > 0)
        {
            horas--;
            minutos = 59;
        }
        printf("TIEMPO RESTANTE\n--------------\n");
        printf("  %d:%d:%d  \n", horas, minutos, segundos);
        printf("--------------\n");
#ifdef _WIN32
        Sleep(1000); //En caso de usar Windows
#else
        usleep(1000000); //En caso de usar otro sistema operativo
#endif
        borrarConsola();
    }
    printf("\n======Temporizador finalizado======\n");
}

//OPCIÓN 5 -
void genContra(int longitud, char contra[21])
{
    int rnd = 0;
    srand((unsigned int)(time(NULL)));
    //Se definen simbolos
    char numeros[] = "1234567890";
    char letras[] = "abcdefghijklmnoqprstuvwyzx";
    char LETRAS[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbolos[] = "!@#$%^&*(){}[]:<>?,./";

    rnd = rand() % 4;
    for (int i = 0; i < longitud; i++)
    {
        if (rnd == 1)
        {
            contra[i] = numeros[rand() % 10];
            rnd = rand() % 4;
        }
        else if (rnd == 2)
        {
            contra[i] = symbolos[rand() % 26];
            rnd = rand() % 4;
        }
        else if (rnd == 3)
        {
            contra[i] = LETRAS[rand() % 26];
            rnd = rand() % 4;
        }
        else
        {
            contra[i] = letras[rand() % 21];
            rnd = rand() % 4;
        }
    }
}
//OPCIÓN 6 -

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

void borrarConsola(void)
{
#ifdef _WIN32
    system("cls"); //En caso de usar Windows
#else
    system("clear");     //En caso de usar otro sistema operativo
#endif
}