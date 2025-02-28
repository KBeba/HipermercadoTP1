#include "Menus_Principales.h"
#include "sistema_de_usuarios.h"
#include "validaciones.h"
#include "gestion_de_empleados.h"
#include "Gestion_de_Procutos_e_inventario.h"
#include "Gestion_de_ventas.h"
#include "gestion_de_clientes.h"
#include "gestion_cajas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// ================= MENÚS PRINCIPALES =================


void mostrAdmins() {
    FILE *archivo = fopen("admins.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de admins.\n");
        return;
    }

    char linea[200];
    printf("\n==== ADMINISTRADORES REGISTRADOS ====\n");
    while (fgets(linea, 200, archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
}

