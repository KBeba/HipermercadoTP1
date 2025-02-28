#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h> // obtener la fecha y hora actuales, se utiliza en facturas y ventas

#include"validaciones.h"

#define MAX_LENGTH 50

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int esNumero(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

void obtenerEntrada(char *mensaje, char *dato, int esNum, int espacios) {
    int valido;
    do {
        valido = 1;
        printf("%s", mensaje);
        fgets(dato, MAX_LENGTH, stdin);
        dato[strcspn(dato, "\n")] = '\0';

        if (dato[0] == '\0') {
            printf("Campo obligatorio!\n");
            valido = 0;
            continue;
        }

        if (!espacios) {
            for (size_t i = 0; i < strlen(dato); i++) {
                if (isspace(dato[i])) {
                    printf("No se permiten espacios!\n");
                    valido = 0;
                    break;
                }
            }
        }

        if (esNum && !esNumero(dato)) {
            printf("Solo numeros permitidos!\n");
            valido = 0;
        }
    } while (!valido);
}
void obtenerEntradaEntero(char *mensaje, int *dato) {
    char buffer[100];
    obtenerEntrada(mensaje, buffer, 1, 0);
    *dato = atoi(buffer);
}
