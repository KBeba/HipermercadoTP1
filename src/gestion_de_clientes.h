#ifndef GESTION_DE_CLIENTES_H
#define GESTION_DE_CLIENTES_H

#include <stdio.h>
#include "Gestion_de_Procutos_e_inventario.h" // Corregir el include

#define MAX_LENGTH 50

typedef struct {
    char nombres_cliente[MAX_LENGTH];
    char apellido_cliente[MAX_LENGTH];
    char telefono_cliente[MAX_LENGTH];
    char direccion_cliente[MAX_LENGTH];
    int cedula_cliente;
    char cedulastr[MAX_LENGTH]; 

} Cliente;

void menu_clientes(); //implementado

void datos_cliente(Cliente *c); //implementado

void guardar_cliente(Cliente *c, FILE *f); //implementado

void leer_y_mostrar_clientes(FILE *f); //implementado

void modificar_cliente(FILE *f, int cedula); //implementado

void eliminar_cliente(FILE *f, int cedula); //implementado

void cantidad_de_clientes(FILE *f); //implementado

int verificar_clientes_existente(FILE *archivo_clientes, int cedula_cliente); //implementado

void buscar_cliente_por_cedula(FILE *archivo_clientes, int cedula); //implementado

#endif // GESTION_DE_CLIENTES_H