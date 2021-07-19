//Segunda versión del programa
//Inclusión de librerías ----------------------------------------------------------.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
//Verifica el sistema operativo para incluir la libreria adecuada
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
int enteroPositivo(void);
int main(void)
{
    int op;
    op = enteroPositivo();
    printf("Opcion = %i\n", op);
    return 0;
}

int enteroPositivo(void)
{
    char n;
    int num = 0;
    do
    {
        //Se recibe imput como caracter para validar
        printf("-->");
        scanf("%c", &n);

    } while (num < 0 || isdigit(n) == 0);
    num = n - '0'; //Convierte caracter en int
    return num;
}