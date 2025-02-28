#ifndef GESTION_DE_CAJAS_H
#define GESTION_DE_CAJAS_H

#define MAX_LENGTH 50
#define MAX_DIAS 30
#define MAX_MESES 12
#define MAX_CAJAS 20
#define MAX_PRODUCTOS 100
#define MAX_SEGMENTO 25
#define MAX_CARRITO 100
#define MAXLENGTH2 50
#define MAX_SEGMENTO2 25
#define IVA 0.16

#include <stdio.h>
#include <gtk/gtk.h>

extern float tasabolivares;
extern float tasaeuros;
extern float tasapesoscolombianos;

typedef struct {
    int numero_caja;
    int numero_empleado;
    char nombre_responsable[50];
    double total_bs[MAX_DIAS][MAX_MESES];
    double total_dolares[MAX_DIAS][MAX_MESES];
    double total_pesos_colombianos[MAX_DIAS][MAX_MESES];
    double total_euros[MAX_DIAS][MAX_MESES];
    int facturados; // Número de facturas emitidas
    int ocupado; // 0 = libre, 1 = ocupado
} Caja;
extern Caja nueva_caja;

// Gestión de cajas
void menu_cajas();  // Implementada
void crear_caja(); // Implementada
void modificar_tasas(float tasa_bs,float tasa_pesos,float tasa_euros); // Implementada
void eliminar_caja(int numero_caja); // Implementada
void mostrar_cajas(GtkWidget *ventana_mostrar_cajas, GtkWidget *text_mostrar_cajas); // Implementada
void liberar_caja(int numero_caja); // Implementada

#endif // GESTION_DE_CAJAS_H
