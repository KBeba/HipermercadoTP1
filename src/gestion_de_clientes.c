#include "gestion_de_clientes.h"
#include "sistema_de_usuarios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> // obtener la fecha y hora actuales, se utiliza en facturas y ventas

void menu_clientes() {
    FILE *archivo_clientes = fopen("datos_cliente.txt", "a+");
    if (archivo_clientes == NULL) {
        printf("ERROR, NO SE PUDO ABRIR EL ARCHIVO.\n\n");
        return;
    }

    int opc;
    do {
        printf("\n\n====== MENU CLIENTES ======\n\n");
        printf("1. MOSTRAR TODOS LOS CLIENTES\n");
        printf("2. MODIFICAR DATOS DE UN CLIENTE\n");
        printf("3. ELIMINAR CLIENTE\n");
        printf("4. NUMERO DE CLIENTES ACTUALES\n");
        printf("5. BUSCAR CLIENTE POR CEDULA\n");
        printf("0. SALIR\n\n");
        printf("======================================\n\n");
        scanf("%d", &opc);
        limpiarBuffer();

        switch (opc) {
            case 1:
                leer_y_mostrar_clientes(archivo_clientes);
                break;
            case 2: {
                int cedula;
                printf("INGRESE LA CEDULA DEL CLIENTE QUE DESEA MODIFICAR: \n\n");
                scanf("%d", &cedula);
                limpiarBuffer();
                modificar_cliente(archivo_clientes, cedula);
                break;
            }
            case 3: {
                int cedula;
                printf("INGRESE LA CEDULA DEL CLIENTE QUE DESEA ELIMINAR:\n\n");
                scanf("%d", &cedula);
                eliminar_cliente(archivo_clientes, cedula);
                break;
            }
            case 4: {
                cantidad_de_clientes(archivo_clientes);
                break;
            }
            case 5: { // Agregar esta sección
                int cedula;
                printf("INGRESE LA CEDULA DEL CLIENTE QUE DESEA BUSCAR: \n\n");
                scanf("%d", &cedula);
                limpiarBuffer();
                buscar_cliente_por_cedula(archivo_clientes, cedula);
                break;
            }
            case 0:
                printf("\n\n");
                break;
            default:
                printf("OPCION INVALIDA. INTENTE DE NUEVO\n\n");
        }
    } while (opc != 0);

    fclose(archivo_clientes);
}

void datos_cliente(Cliente *c) {
    obtenerEntrada("Nombres: ", c->nombres_cliente, 0, 1);
    obtenerEntrada("Apellido: ", c->apellido_cliente, 0, 0);
    obtenerEntrada("Telefono: ", c->telefono_cliente, 1, 0);
    obtenerEntrada("Direccion: ", c->direccion_cliente, 0, 1);
    obtenerEntrada("Cedula: ", c->cedulastr, 1, 0);
    c->cedula_cliente = atoi(c->cedulastr); // Convierte la cadena a número
}

void guardar_cliente(Cliente *c, FILE *f) {
    if (fprintf(f, "%s,%s,%s,%s,%d\n", c->nombres_cliente, c->apellido_cliente, c->telefono_cliente, c->direccion_cliente, c->cedula_cliente) < 0) {
        printf("ERROR AL GUARDAR LOS DATOS EN EL ARCHIVO.\n");
        return;
    }
}

void leer_y_mostrar_clientes(FILE *f) {
    rewind(f);

    Cliente c;
    printf("\n\n====== LISTA DE CLIENTES ======\n\n");

    while (fscanf(f, " %[^,],%[^,],%[^,],%[^,],%d\n",
        c.nombres_cliente, c.apellido_cliente, c.telefono_cliente, c.direccion_cliente, &c.cedula_cliente) != EOF) {
        printf("     Nombres: %s\n", c.nombres_cliente);
        printf("     Apellido: %s\n", c.apellido_cliente);
        printf("     Telefono: %s\n", c.telefono_cliente);
        printf("     Direccion: %s\n", c.direccion_cliente);
        printf("     Cedula: %d\n\n", c.cedula_cliente);
        printf("=======================================\n\n");
    }
}

void modificar_cliente(FILE *archivo_clientes, int cedula) {
    FILE *temp_archivo = fopen("temp_clientes.txt", "w");
    if (temp_archivo == NULL) {
        printf("ERROR, NO SE PUDO ABRIR EL ARCHIVO.\n\n");
        return;
    }

    rewind(archivo_clientes);

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n",
                  cliente.nombres_cliente,
                  cliente.apellido_cliente,
                  cliente.telefono_cliente,
                  cliente.direccion_cliente,
                  &cliente.cedula_cliente) != EOF) {
        if (cliente.cedula_cliente == cedula) {
            printf("POR FAVOR, INGRESE LOS NUEVOS DATOS: \n\n");
            datos_cliente(&cliente);
            encontrado = 1;
        }

        fprintf(temp_archivo, "%s,%s,%s,%s,%d\n",
                cliente.nombres_cliente,
                cliente.apellido_cliente,
                cliente.telefono_cliente,
                cliente.direccion_cliente,
                cliente.cedula_cliente);
    }

    fclose(temp_archivo);
    fclose(archivo_clientes);

    if (encontrado) {
        remove("datos_cliente.txt");
        rename("temp_clientes.txt", "datos_cliente.txt");
        printf("CLIENTE MODIFICADO CON EXITO.\n");
    } else {
        printf("NO SE ENCONTRO EL CLIENTE CON CEDULA: %d\n", cedula);
        remove("temp_clientes.txt");
    }
}

void eliminar_cliente(FILE *archivo_clientes, int cedula) {
    FILE *temp_archivo = fopen("temp_clientes.txt", "w");
    if (temp_archivo == NULL) {
        printf("ERROR, NO SE PUDO ABRIR EL ARCHIVO.\n\n");
        return;
    }

    rewind(archivo_clientes);

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n",
                  cliente.nombres_cliente,
                  cliente.apellido_cliente,
                  cliente.telefono_cliente,
                  cliente.direccion_cliente,
                  &cliente.cedula_cliente) != EOF) {
        if (cliente.cedula_cliente == cedula) {
            encontrado = 1;
            printf("CLIENTE CON CEDULA %d ELIMINADO\n\n", cedula);
        } else {
            fprintf(temp_archivo, "%s,%s,%s,%s,%d\n",
                    cliente.nombres_cliente,
                    cliente.apellido_cliente,
                    cliente.telefono_cliente,
                    cliente.direccion_cliente,
                    cliente.cedula_cliente);
        }
    }

    fclose(temp_archivo);
    fclose(archivo_clientes);

    if (encontrado) {
        remove("datos_cliente.txt");
        rename("temp_clientes.txt", "datos_cliente.txt");
    } else {
        printf("NO SE ENCONTRO EL CLIENTE CON CEDULA: %d\n", cedula);
        remove("temp_clientes.txt");
    }
}

void cantidad_de_clientes(FILE *archivo_clientes) {
    rewind(archivo_clientes);
    int cont = 0;
    Cliente cliente;

    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n",
                  cliente.nombres_cliente,
                  cliente.apellido_cliente,
                  cliente.telefono_cliente,
                  cliente.direccion_cliente,
                  &cliente.cedula_cliente) != EOF) {
        cont++;
    }

    printf("\nLA CANTIDAD DE CLIENTES QUE HAN COMPRADO SON: %d\n\n", cont);
}

int verificar_clientes_existente(FILE *archivo_clientes, int cedula_cliente) {
    rewind(archivo_clientes);
    Cliente cliente;
    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n",
                  cliente.nombres_cliente,
                  cliente.apellido_cliente,
                  cliente.telefono_cliente,
                  cliente.direccion_cliente,
                  &cliente.cedula_cliente) != EOF) {
        if (cliente.cedula_cliente == cedula_cliente) {
            return 1; // Cliente ya existe
        }
    }

    return 0; // No encontrado
}

void buscar_cliente_por_cedula(FILE *archivo_clientes, int cedula) {
    rewind(archivo_clientes);
    Cliente cliente;
    int encontrado = 0;

    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n",
                  cliente.nombres_cliente,
                  cliente.apellido_cliente,
                  cliente.telefono_cliente,
                  cliente.direccion_cliente,
                  &cliente.cedula_cliente) != EOF) {
        if (cliente.cedula_cliente == cedula) {
            printf("\nCLIENTE ENCONTRADO:\n");
            printf("     Nombres: %s\n", cliente.nombres_cliente);
            printf("     Apellido: %s\n", cliente.apellido_cliente);
            printf("     Telefono: %s\n", cliente.telefono_cliente);
            printf("     Direccion: %s\n", cliente.direccion_cliente);
            printf("     Cedula: %d\n", cliente.cedula_cliente);
            printf("=======================================\n\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("NO SE ENCONTRO UN CLIENTE CON LA CEDULA: %d\n", cedula);
    }
}
