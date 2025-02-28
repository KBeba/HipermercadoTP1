#include "gestion_de_empleados.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_LENGTH 50
#define MAX_SEGMENTO 25

void menu_gestion_empleados() {
    int opcion;
    do {
        printf("\n==== GESTION DE EMPLEADOS ====\n");
        printf("1. Mostrar Empleados\n"); // Opción para mostrar empleados
        printf("2. Modificar Empleado\n");
        printf("3. Eliminar Empleado\n");
        printf("4. Cantidad de Empleados\n");
        printf("0. Volver al Menu Administrador\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                 // Mostrar la lista de empleados
                break;
            case 2:
                modificarEmpleado(); // Modificar un empleado
                break;
            case 3:
                eliminarEmpleado(); // Eliminar un empleado
                break;
            case 4:
                cantidad_de_empleados(); // Mostrar la cantidad de empleados
                break;
            case 0:
                return; // Volver al menú de administrador
            default:
                printf("\nOpcion invalida!\n");
        }
    } while (1);
}

void registrarEmpleado() {
    FILE *archivo_empleados = fopen("empleados.txt", "a");
    if (archivo_empleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }

    Usuario empleado;

    printf("\n==== REGISTRO DE EMPLEADO ====\n");
    obtenerEntrada("Nombre: ", empleado.nombre, 0, 1);
    obtenerEntrada("Apellido: ", empleado.apellido, 0, 0);
    obtenerEntrada("Direccion: ", empleado.direccion, 0, 1);
    obtenerEntrada("Telefono: ", empleado.telefono, 1, 0);
    obtenerEntrada("Cedula: ", empleado.cedula, 1, 0);
    obtenerEntrada("Usuario: ", empleado.usuario, 0, 0);
    obtenerEntrada("Contrasena: ", empleado.password, 0, 0);
    obtenerEntrada("Pregunta de seguridad: ", empleado.pregunta, 0, 1);
    obtenerEntrada("Respuesta de seguridad: ", empleado.respuesta, 0, 1);

    fprintf(archivo_empleados, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
            empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta);

    fclose(archivo_empleados);
    printf("\nEmpleado registrado exitosamente!\n");
}

void mostrarEmpleados(GtkTextView *textview) {
    FILE *archivo_empleados = fopen("empleados.txt", "r");
    if (archivo_empleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }

    Usuario empleado;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
    gtk_text_buffer_set_text(buffer, "==== LISTA DE EMPLEADOS ====\n", -1); // Limpiar y establecer el título

    char texto[1024]; // Buffer para almacenar la información de cada empleado

    while (fscanf(archivo_empleados, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                  empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta) != EOF) {
        // Formatear la información del empleado
        snprintf(texto, sizeof(texto),
                 "\nNombre: %s %s\n"
                 "Usuario: %s\n"
                 "Cedula: %s\n"
                 "Pregunta de seguridad: %s\n"
                 "Respuesta de seguridad: %s\n",
                 empleado.nombre, empleado.apellido, empleado.usuario, empleado.cedula, empleado.pregunta, empleado.respuesta);

        // Insertar la información en el GtkTextView
        gtk_text_buffer_insert_at_cursor(buffer, texto, -1);
    }

    fclose(archivo_empleados);
}
void modificarEmpleado(const char *cedula, const char *nombre, const char *apellido, const char *direccion,const char *telefono, const char *usuario, const char *password,
                       const char *pregunta, const char *respuesta) {
    FILE *archivo_empleados = fopen("empleados.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (archivo_empleados == NULL || temp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Usuario empleado;
    int encontrado = 0;

    while (fscanf(archivo_empleados, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                  empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta) != EOF) {
        if (strcmp(empleado.cedula, cedula) == 0) {
            encontrado = 1;
            // Actualizar los datos del empleado con los nuevos valores
            strncpy(empleado.nombre, nombre, MAX_LENGTH);
            strncpy(empleado.apellido, apellido, MAX_LENGTH);
            strncpy(empleado.direccion, direccion, MAX_LENGTH);
            strncpy(empleado.telefono, telefono, MAX_LENGTH);
            strncpy(empleado.usuario, usuario, MAX_LENGTH);
            strncpy(empleado.password, password, MAX_LENGTH);
            strncpy(empleado.pregunta, pregunta, MAX_LENGTH);
            strncpy(empleado.respuesta, respuesta, MAX_LENGTH);
        }
        // Escribir el empleado (modificado o no) en el archivo temporal
        fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
                empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta);
    }

    fclose(archivo_empleados);
    fclose(temp);

    if (encontrado) {
        // Reemplazar el archivo original con el temporal
        remove("empleados.txt");
        rename("temp.txt", "empleados.txt");
        printf("\nEmpleado modificado exitosamente!\n");
    } else {
        printf("\nEmpleado no encontrado!\n");
        remove("temp.txt");  // Eliminar el archivo temporal si no se encontró el empleado
    }
}



void eliminarEmpleado(const char *cedula) {
    FILE *archivo_empleados = fopen("empleados.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (archivo_empleados == NULL || temp == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Usuario empleado;
    int encontrado = 0;

    while (fscanf(archivo_empleados, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                  empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta) != EOF) {
        if (strcmp(empleado.cedula, cedula) == 0) {
            encontrado = 1;
            printf("\nEmpleado eliminado exitosamente!\n");
        } else {
            fprintf(temp, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
                    empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                    empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta);
        }
    }

    fclose(archivo_empleados);
    fclose(temp);

    if (encontrado) {
        remove("empleados.txt");
        rename("temp.txt", "empleados.txt");
    } else {
        printf("\nEmpleado no encontrado!\n");
        remove("temp.txt");
    }
}

int cantidad_de_empleados() {
    FILE *archivo_empleados = fopen("empleados.txt", "r");
    if (archivo_empleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return -1; // Retorna -1 en caso de error
    }

    Usuario empleado;
    int contador = 0;

    // Leer el archivo y contar los empleados
    while (fscanf(archivo_empleados, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                  empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta) != EOF) {
        contador++;
    }

    fclose(archivo_empleados);

    return contador; // Retorna la cantidad de empleados
}
