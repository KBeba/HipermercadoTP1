#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>// obtener la fecha y hora actuales, se utiliza en facturas y ventas
#include <gtk/gtk.h>

#include "Gestion_de_Procutos_e_inventario.h"
#include "Menus_Principales.h"
#include "sistema_de_usuarios.h"

#define MAX_LENGTH 50
#define MAX_SEGMENTO 25
#define MAXLENGTH2 50



void generarCodigoProducto(char *codigo, char *segmento) {
    int contador = cargarContadorSegmento(segmento);
    int randomPart = rand() % 10000;  // Parte aleatoria

    // Asignar prefijo según el segmento
    char prefijo[4];
    if (strcmp(segmento, "Licores") == 0) {
        strcpy(prefijo, "001");
    } else if (strcmp(segmento, "Hortalizas") == 0) {
        strcpy(prefijo, "002");
    } else if (strcmp(segmento, "Charcuteria") == 0) {
        strcpy(prefijo, "003");
    } else if (strcmp(segmento, "Varios") == 0) {
        strcpy(prefijo, "005");
    } else {
        strcpy(prefijo, "000");  // Prefijo por defecto
    }

    // Formato del codigo: <Prefijo>-<Contador>-<RandomPart>
    sprintf(codigo, "%s-%04d-%04d", prefijo, contador++, randomPart);

    // Guardar el contador actualizado
    guardarContadorSegmento(segmento, contador);
}

int cargarContadorSegmento( char *segmento) {
    char nombreArchivo[MAX_LENGTH];
    sprintf(nombreArchivo, "contador_%s.txt", segmento);
    int contador = 1;  // Si no existe el archivo, comenzamos en 1
    FILE *file = fopen(nombreArchivo, "r");
    if (file != NULL) {
        fscanf(file, "%d", &contador);
        fclose(file);
    }
    return contador;
}

void guardarContadorSegmento(const char *segmento, int contador) {
    char nombreArchivo[MAX_LENGTH];
    sprintf(nombreArchivo, "contador_%s.txt", segmento);
    FILE *file = fopen(nombreArchivo, "w");
    if (file == NULL) {
        printf("Error al guardar el contador para el segmento %s.\n", segmento);
        return;
    }
    fprintf(file, "%d", contador);
    fclose(file);
}

void obtenerNombreArchivoSegmento(char *segmento, char *nombreArchivo) {
    for (int i = 0; segmento[i] != '\0'; i++) {
        if (segmento[i] == ' ') {
            segmento[i] = '_';
        }
    }
    sprintf(nombreArchivo, "inventario_%s.txt", segmento);
}

void agregarProductoPorSegmento(const char *segmento, int cantidad, Producto producto) {
    char nombreArchivo[MAXLENGTH2];

    // Copiar el segmento seleccionado al producto
    strcpy(producto.segmento, segmento);

    // Asignar la cantidad
    producto.cantidad = cantidad;

    // Generar el código del producto
    generarCodigoProducto(producto.codigo, producto.segmento);

    // Obtener el nombre del archivo
    obtenerNombreArchivoSegmento(producto.segmento, nombreArchivo);

    // Guardar el producto en el archivo
    FILE *file = fopen(nombreArchivo, "a");
    if (file == NULL) {
        g_print("Error al abrir el archivo de inventario.\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%d,%.2f\n", producto.codigo, producto.nombre, producto.segmento, producto.cantidad, producto.precioUSD);
    fclose(file);
    g_print("Producto agregado correctamente al inventario.\n");
}

void consultarSegmentoPorArchivo(GtkTextView *textview, char *segmento) {
    char nombreArchivo[MAXLENGTH2];
    obtenerNombreArchivoSegmento(segmento, nombreArchivo);

    FILE *file = fopen(nombreArchivo, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de inventario.\n");
        return;
    }

    Producto producto;
    int productoCount = 1;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
    gtk_text_buffer_set_text(buffer, "", -1); // Limpiar el TextView

    char texto[1024] = "";
    snprintf(texto, sizeof(texto), "\n--- Inventario del segmento: %s ---\n", segmento);
    gtk_text_buffer_insert_at_cursor(buffer, texto, -1);

    while (fscanf(file, "%49[^,],%49[^,],%24[^,],%d,%f\n", producto.codigo, producto.nombre, producto.segmento, &producto.cantidad, &producto.precioUSD) != EOF) {
        snprintf(texto, sizeof(texto), "Producto %d:\n  Codigo: %s\n  Nombre: %s\n  Cantidad: %d\n  Precio USD:%.2f\n. \n", productoCount++, producto.codigo, producto.nombre, producto.cantidad, producto.precioUSD);
        gtk_text_buffer_insert_at_cursor(buffer, texto, -1);
    }
    fclose(file);
}




