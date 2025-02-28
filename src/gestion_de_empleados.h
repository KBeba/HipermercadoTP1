#ifndef GESTION_DE_EMPLEADOS_H
#define GESTION_DE_EMPLEADOS_H

#define MAX_LENGTH 50
#define MAX_SEGMENTO 25

#include "sistema_de_usuarios.h"
#include <gtk/gtk.h>

// Gestión de empleados
void menu_gestion_empleados(); // implementada

void registrarEmpleado(); // implementada

void mostrarEmpleados(GtkTextView *textview); // implementada

void modificarEmpleado(); // implementada

void eliminarEmpleado();    // implementada

int cantidad_de_empleados(); // implementada


#endif // GESTION_DE_EMPLEADOS_H
