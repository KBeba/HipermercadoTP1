// MENUS.H
#ifndef GESTION_DE_PRODUCTOS_E_INVENTARIO_H
#define GESTION_DE_PRODUCTOS_E_INVENTARIO_H

#define MAX_LENGTH 50
#define MAX_SEGMENTO 25

#include "gestion_de_clientes.h"
#include <gtk/gtk.h>

typedef struct {                       // struct para almacenar datos del producto
    char codigo[MAX_LENGTH];
    char nombre[MAX_LENGTH];
    char segmento[MAX_SEGMENTO];
    int cantidad;
    float precioUSD;
    float precioCOP;
    float precioVEF;
    float precioEUR;
} Producto;

typedef struct {
    char codigo[20];
    char nombre[50];
    int cantidadcomprada;
    float preciounitario;
} Carrito;


void generarCodigoProducto(char *codigo, char *segmento); //implementada

int cargarContadorSegmento(char *segmento); //implementada

void guardarContadorSegmento(const char *segmento, int contador); //implementada

void obtenerNombreArchivoSegmento(char *segmento, char *nombreArchivo); //implementada

void agregarProductoPorSegmento(); //implementada

void consultarSegmentoPorArchivo(GtkTextView *textview, char *segmento);//implementada

void mostrarMenuSegmentos(); //implementada

void mostrarinventario(); //implementada

#endif // GESTION_DE_PRODUCTOS_E_INVENTARIO_H
