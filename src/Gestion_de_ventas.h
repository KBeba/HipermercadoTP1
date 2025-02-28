#ifndef GESTION_DE_VENTAS_H
#define GESTION_DE_VENTAS_H

#include <stdio.h>
#include "Gestion_de_Procutos_e_inventario.h"

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_SEGMENTO2 25
#define MAX_LENGTH 50
#define MAX_SEGMENTO 25
#define MAX_CARRITO 100

extern float tasabolivares;
extern float tasaeuros;
extern float tasapesoscolombianos;


extern Carrito carrito[MAX_CARRITO];

extern int numproductoscarritos;

// Gestión de ventas

void menu_ventas(); // implementada

void consulta_diaria_por_caja(FILE *archivo_cajas, int numero_caja, int dia, int mes, GtkWidget *text_mostrar_ventas); // implementada

void ventas_mensuales_por_caja(FILE *archivo_cajas, int numero_caja, int mes, GtkWidget *text_mostrar_ventas); // implementada

void total_ventas_mensuales_supermercado(FILE *archivo_cajas,int mes, GtkWidget *text_view); // implementada

void cancelarcompra(); // implementada

void tasadecambio(); // implementada

void agregarproductoalcarrito(Producto producto, int cantidad); // implementada

void procesarunacompra(int numero_caja, int numero_empleado); // implementada

void mostrarcarrito(float tasabolivares, float tasaeuros, float tasapesoscolombianos, GtkTextView *textview); // implementada

void oficializarventa(int cedula_cliente, int numero_caja, int numero_empleado, GtkTextView *text_mostrar_cajas); // implementada

void imprimirFactura(); // implementada

void mostrar_ultimas_10_facturas();

void menu_ventasadm();

#endif // GESTION_DE_VENTAS_H
