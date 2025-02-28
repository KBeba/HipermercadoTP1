#include "gestion_cajas.h"
#include "sistema_de_usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> // obtener la fecha y hora actuales, se utiliza en facturas y ventas
#include <gtk/gtk.h>

void menu_cajas() {
    FILE *archivo_cajas = fopen("cajas.dat", "rb+");
    if (archivo_cajas == NULL) {
        archivo_cajas = fopen("cajas.dat", "wb+");
        if (archivo_cajas == NULL) {
            printf("ERROR, NO SE PUDO ABRIR O CREAR EL ARCHIVO DE CAJAS\n\n");
            return;
        }
    }

    int opcion;
    do {
        printf("\n\n====== MENU CAJAS ======\n\n");
        printf("1. CREAR UNA NUEVA CAJA\n");
        printf("2. ELIMINAR UNA CAJA\n");  // Eliminamos la opción de modificar tasas
        printf("3. MOSTRAR TODAS LAS CAJAS\n");
        printf("0. VOLVER AL MENU PRINCIPAL\n\n");
        printf("======================================\n\n");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                void crear_caja();
                break;
            case 2:

                break;
            case 3:

                break;
            case 0:
                printf("\n\n");
                break;
            default:
                printf("OPCION INVALIDA. INTENTE DE NUEVO\n\n");
        }
    } while (opcion != 0);

    fclose(archivo_cajas);
}

// Función para guardar la caja en el archivo
void crear_caja(GtkWidget *widget, gpointer data) {
    FILE *archivo_cajas = fopen("cajas.dat", "ab+");
    if (!archivo_cajas) {
        printf("ERROR, NO SE PUDO ABRIR O CREAR EL ARCHIVO DE CAJAS\n\n");
        return;
    }


    for (int i = 0; i < MAX_DIAS; i++) {
        for (int j = 0; j < MAX_MESES; j++) {
            nueva_caja.total_bs[i][j] = 0;
            nueva_caja.total_dolares[i][j] = 0;
            nueva_caja.total_pesos_colombianos[i][j] = 0;
            nueva_caja.total_euros[i][j] = 0;
        }
    }

    nueva_caja.facturados = 0;
    nueva_caja.ocupado = 0;

    fwrite(&nueva_caja, sizeof(Caja), 1, archivo_cajas);
    fclose(archivo_cajas);
    printf("NUEVA CAJA CREADA\n\n");
}


void eliminar_caja(int numero_caja) {
    FILE *archivo_cajas = fopen("cajas.dat", "rb");
    FILE *archivo_temporal = fopen("temp.dat", "wb");
    if (!archivo_cajas || !archivo_temporal) {
        printf("ERROR AL ABRIR EL ARCHIVO\n\n");
        return;
    }

    Caja caja;
    int encontrado = 0;

    while (fread(&caja, sizeof(Caja), 1, archivo_cajas)) {
        if (caja.numero_caja == numero_caja) {
            encontrado = 1;
        } else {
            fwrite(&caja, sizeof(Caja), 1, archivo_temporal);
        }
    }

    fclose(archivo_cajas);
    fclose(archivo_temporal);

    if (encontrado) {
        remove("cajas.dat");
        rename("temp.dat", "cajas.dat");
        printf("CAJA ELIMINADA\n\n");
    } else {
        printf("CAJA NO ENCONTRADA\n\n");
        remove("temp.dat");
    }
}


void mostrar_cajas(GtkWidget *ventana_mostrar_cajas, GtkWidget *text_mostrar_cajas) {
    FILE *archivo_cajas = fopen("cajas.dat", "rb");
    if (!archivo_cajas) {
        printf("ERROR AL ABRIR EL ARCHIVO\n\n");
        return;
    }

    Caja caja;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_cajas));
    gtk_text_buffer_set_text(buffer, "", -1); // Limpiar el contenido previo

    char texto[1024] = "======= LISTA DE CAJAS ========\n\n";
    while (fread(&caja, sizeof(Caja), 1, archivo_cajas)) {
        char temp[256];
        sprintf(temp, "CAJA %d:\n EMPLEADO: %d\n RESPONSABLE: %s\n FACTURAS EMITIDAS: %d\n ESTADO: %s\n\n",
                caja.numero_caja, caja.numero_empleado, caja.nombre_responsable, caja.facturados,
                caja.ocupado ? "Ocupada" : "Libre");
        strcat(texto, temp);
    }

    // Establecer el texto en el GtkTextView
    gtk_text_buffer_set_text(buffer, texto, -1);
    fclose(archivo_cajas);

    // Mostrar la ventana
    gtk_widget_show_all(ventana_mostrar_cajas);
}



void modificar_tasas(float tasa_bs,float tasa_pesos,float tasa_euros) {
    // Obtener los valores de las tasas de los GtkEntry
    tasabolivares = tasa_bs; // Obtener tasa Bolívares
    tasaeuros = tasa_euros;   // Obtener tasa Euros
    tasapesoscolombianos = tasa_pesos; // Obtener tasa Pesos Colombianos

    // Imprimir las nuevas tasas para confirmación (puedes eliminar esto si no lo necesitas)
    printf("NUEVAS TASAS APLICADAS:\n");
    printf("  Tasa Bolívares: %.2f\n", tasabolivares);
    printf("  Tasa Euros: %.2f\n", tasaeuros);
    printf("  Tasa Pesos Colombianos: %.2f\n", tasapesoscolombianos);
}

void liberar_caja(int numero_caja) {
    FILE *archivo_cajas = fopen("cajas.dat", "rb+");
    if (archivo_cajas == NULL) {
        printf("Error al abrir el archivo de cajas.\n");
        return;
    }

    Caja caja;
    rewind(archivo_cajas);

    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        if (caja.numero_caja == numero_caja) {
            caja.ocupado = 0;
            fseek(archivo_cajas, -((long)sizeof(Caja)), SEEK_CUR);
            fwrite(&caja, sizeof(Caja), 1, archivo_cajas);
            fflush(archivo_cajas);
            break;
        }
    }

    fclose(archivo_cajas);
}
