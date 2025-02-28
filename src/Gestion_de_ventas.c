#include "Gestion_de_ventas.h"
#include "Gestion_de_Procutos_e_inventario.h"
#include "Menus_Principales.h"
#include "sistema_de_usuarios.h"
#include "gestion_de_clientes.h"
#include "gestion_cajas.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <time.h>

#define MAX_SEGMENTO2 25
#define MAX_LENGTH 50
#define MAX_SEGMENTO 25
#define MAX_CARRITO 100
#define IVA 0.16

float tasabolivares=0.0;
float tasaeuros=0.0;
float tasapesoscolombianos=0.0;

Carrito carrito[MAX_CARRITO];

int numproductoscarritos = 0;

extern float tasabolivares; // extern para variables globales
extern float tasaeuros;
extern float tasapesoscolombianos;

void agregarproductoalcarrito(Producto producto, int cantidad) {
    // Verificar si el producto ya está en el carrito
    for (int i = 0; i < numproductoscarritos; i++) {
        if (strcmp(carrito[i].codigo, producto.codigo) == 0) {
            // Producto encontrado, actualizar la cantidad
            carrito[i].cantidadcomprada += cantidad;
            return;
        }
    }

    // Si no se encuentra el producto, agregarlo al carrito
    if (numproductoscarritos < MAX_CARRITO) {
        strcpy(carrito[numproductoscarritos].codigo, producto.codigo);
        strcpy(carrito[numproductoscarritos].nombre, producto.nombre);
        carrito[numproductoscarritos].cantidadcomprada = cantidad;
        carrito[numproductoscarritos].preciounitario = producto.precioUSD;
        numproductoscarritos++;
    } else {
        printf("El carrito está lleno. No se pueden agregar más productos.\n");
    }
}

void mostrarcarrito(float tasabolivares, float tasaeuros, float tasapesoscolombianos, GtkTextView *textview) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
    gtk_text_buffer_set_text(buffer, "", -1); // Limpiar el contenido previo

    if (numproductoscarritos == 0) {
        gtk_text_buffer_insert_at_cursor(buffer, "\n======= CARRITO VACIO =====\n", -1);
        return;
    }

    char texto[1024]; // Buffer para almacenar el texto temporalmente
    float subtotalUSD = 0.0;

    // Encabezado del carrito
    gtk_text_buffer_insert_at_cursor(buffer, "\n====== RESUMEN CARRITO ======\n", -1);

    // Mostrar cada producto en el carrito
    for (int i = 0; i < numproductoscarritos; i++) {
        float subtotalproducto = carrito[i].cantidadcomprada * carrito[i].preciounitario;
        subtotalUSD += subtotalproducto;

        snprintf(texto, sizeof(texto),
                 "\n  Producto %d:\n"
                 "    Código: %s\n"
                 "    Nombre: %s\n"
                 "    Cantidad: %d\n"
                 "    Precio unitario: %.2f USD\n",
                 i + 1, carrito[i].codigo, carrito[i].nombre, carrito[i].cantidadcomprada, carrito[i].preciounitario);

        gtk_text_buffer_insert_at_cursor(buffer, texto, -1);
    }

    // Calcular subtotales y totales con IVA
    float subtotalBolivares = subtotalUSD * tasabolivares;
    float subtotalEuros = subtotalUSD * tasaeuros;
    float subtotalPesosColombianos = subtotalUSD * tasapesoscolombianos;

    float totalconivaUSD = subtotalUSD * (1 + IVA);
    float totalconivaBolivares = subtotalBolivares * (1 + IVA);
    float totalconivaEuros = subtotalEuros * (1 + IVA);
    float totalconivaPesos = subtotalPesosColombianos * (1 + IVA);

    // Mostrar subtotales
    snprintf(texto, sizeof(texto),
             "\n  Subtotal (USD): %.2f USD\n"
             "  Subtotal (Bolívares): %.2f BS\n"
             "  Subtotal (Euros): %.2f EUR\n"
             "  Subtotal (Pesos Colombianos): %.2f COP\n",
             subtotalUSD, subtotalBolivares, subtotalEuros, subtotalPesosColombianos);

    gtk_text_buffer_insert_at_cursor(buffer, texto, -1);

    // Mostrar IVA
    snprintf(texto, sizeof(texto),
             "\n------- IVA (%.2f%%) -------\n"
             "  USD: %.2f USD\n"
             "  Bolívares: %.2f BS\n"
             "  Euros: %.2f EUR\n"
             "  Pesos Colombianos: %.2f COP\n",
             IVA * 100, subtotalUSD * IVA, subtotalBolivares * IVA, subtotalEuros * IVA, subtotalPesosColombianos * IVA);

    gtk_text_buffer_insert_at_cursor(buffer, texto, -1);

    // Mostrar totales con IVA
    snprintf(texto, sizeof(texto),
             "\nTotal con IVA (USD): %.2f USD\n"
             "Total con IVA (Bolívares): %.2f BS\n"
             "Total con IVA (Euros): %.2f EUR\n"
             "Total con IVA (Pesos Colombianos): %.2f COP\n",
             totalconivaUSD, totalconivaBolivares, totalconivaEuros, totalconivaPesos);

    gtk_text_buffer_insert_at_cursor(buffer, texto, -1);
}

void cancelarcompra() {
    for (int i = 0; i < numproductoscarritos; i++) {
        char nombreArchivo[MAX_LENGTH];
        Producto producto;

        // Obtener el nombre del archivo del segmento
        obtenerNombreArchivoSegmento(carrito[i].codigo, nombreArchivo);

        FILE *archivo = fopen(nombreArchivo, "r+");
        if (archivo == NULL) {
            printf("Error al abrir el archivo de inventario: %s\n", nombreArchivo);
            continue;
        }

        int encontrado = 0;
        long pos;

        while (fscanf(archivo, "%49[^,],%49[^,],%24[^,],%d,%f\n", producto.codigo, producto.nombre, producto.segmento, &producto.cantidad, &producto.precioUSD) != EOF) {
            if (strcmp(producto.codigo, carrito[i].codigo) == 0) {
                encontrado = 1;
                break;
            }
            pos = ftell(archivo);
        }

        if (encontrado) {
            // Revertir la cantidad del producto en el inventario
            producto.cantidad += carrito[i].cantidadcomprada;

            // Mover el cursor al inicio de la línea del producto para actualizar la cantidad
            fseek(archivo, pos, SEEK_SET);
            fprintf(archivo, "%s,%s,%s,%d,%.2f\n", producto.codigo, producto.nombre, producto.segmento, producto.cantidad, producto.precioUSD);
        } else {
            printf("Producto no encontrado en el inventario: %s\n", carrito[i].codigo);
        }

        fclose(archivo);
    }

    // Limpiar el carrito
    numproductoscarritos = 0;
    printf("Compra cancelada. El carrito ha sido vaciado y los productos han sido devueltos al inventario.\n");
}

void procesarunacompra(int numero_caja, int numero_empleado) {
    FILE *archivo_clientes = fopen("datos_cliente.txt", "r"); //retomamos el archivo clientes ya definido
    Producto producto;
    int cedula_cliente = 0;
    char nombreArchivo[MAX_LENGTH];
    char codigoproducto[20];
    int opcionsegmento, cantidadcompra;
    float subtotal = 0.0, totalconivaUSD, subtbolivares, subtpesos, subteuros, totalIVABS, totalIVAEUR, totalIVAPESOS;
    // Elimina las declaraciones locales de tasas de cambio
    int opcion = 0;

    if (archivo_clientes == NULL) {
        perror("Problema de apertura de archivo");
        return;
    }

    fclose(archivo_clientes);

    limpiarBuffer();

                // Mostrar los productos disponibles del segmento seleccionado
                void consultarSegmentoPorArchivo(GtkTextView *textview, char *segmento);

                // Abrir el archivo y buscar el producto
                obtenerNombreArchivoSegmento(producto.segmento, nombreArchivo);
                FILE *file = fopen(nombreArchivo, "r+");
                if (file == NULL) {
                    printf("Error al abrir el archivo de inventario.\n");

                }

                int encontrado = 0;
                long pos;
                while (fscanf(file, "%49[^,],%49[^,],%24[^,],%d,%f\n", producto.codigo, producto.nombre, producto.segmento, &producto.cantidad, &producto.precioUSD) != EOF) {
                    if (strcmp(producto.codigo, codigoproducto) == 0) {
                        encontrado = 1;

                    }
                    pos = ftell(file); // Guarda la posición en el archivo
                }

                if (!encontrado) {
                    printf("Producto no encontrado. \n");
                    fclose(file);

                }

                if (cantidadcompra > producto.cantidad) {
                    printf("Cantidad insuficiente en el inventario.\n");
                    fclose(file);

                }

                // Calcular los subtotales
                subtotal += producto.precioUSD * cantidadcompra;
                subtbolivares = subtotal * tasabolivares;
                subteuros = subtotal * tasaeuros;
                subtpesos = subtotal * tasapesoscolombianos;

                producto.cantidad -= cantidadcompra;

                // Mover el cursor al inicio de la línea del producto para actualizar la cantidad
                fseek(file, pos, SEEK_SET);
                fprintf(file, "%s,%s,%s,%d,%.2f\n", producto.codigo, producto.nombre, producto.segmento, producto.cantidad, producto.precioUSD);

                fclose(file);
                printf("Producto agregado al carrito\n");

                // Agregar el producto al carrito
                agregarproductoalcarrito(producto, cantidadcompra);

    totalconivaUSD = subtotal * (1 + IVA); //1+ IVA : Al sumar 1 a la tasa del IVA, estamos incluyendo tanto el monto original (1) como el IVA (0.16) en el cálculo.
    totalIVABS = subtbolivares * (1 + IVA);
    totalIVAEUR = subteuros * (1 + IVA);
    totalIVAPESOS = subtpesos * (1 + IVA);

    // Mostrar el resumen de la compra final
    printf("\n===== RESUMEN DE LA COMPRA FINAL =====\n");
    printf("Subtotal: %.2f USD\n", subtotal);
    printf("Subtotal: %.2f EUROS\n", subteuros);
    printf("Subtotal: %.2f BOLIVARES\n", subtbolivares);
    printf("Subtotal: %.2f PESOS COLOMBIANOS\n", subtpesos);
    printf("\n");
    printf("IVA (%.2f%%): %.2f USD\n", IVA * 100, subtotal * IVA);
    printf("IVA (%.2f%%): %.2f EUR\n", IVA * 100, subteuros * IVA);
    printf("IVA (%.2f%%): %.2f BS\n", IVA * 100, subtbolivares * IVA);
    printf("IVA (%.2f%%): %.2f PESOS\n", IVA * 100, subtpesos * IVA);
    printf("\n");
    printf("\nTotal USD con IVA: %.2f USD\n", totalconivaUSD);
    printf("\nTotal BOLIVARES con IVA: %.2f BS\n", totalIVABS);
    printf("\nTotal EUROS con IVA: %.2f EUR\n", totalIVAEUR);
    printf("\nTotal PESOS COLOMBIANOS con IVA: %.2f PESOS\n", totalIVAPESOS);
}

void imprimirFactura(GtkTextView *textview) {
    FILE *archivo_factura = fopen("factura.txt", "r");
    if (archivo_factura == NULL) {
        printf("Error al abrir el archivo de factura.\n");
        return;
    }

    // Obtener el buffer del textview
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

    // Limpiar el contenido previo en el textview
    gtk_text_buffer_set_text(buffer, "", -1);

    // Leer el archivo línea por línea y agregar al GtkTextView
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo_factura)) {
        gtk_text_buffer_insert_at_cursor(buffer, linea, -1);  // Insertar cada línea en el buffer del textview
    }

    fclose(archivo_factura);
}

void oficializarventa(int cedula_cliente, int numero_caja, int numero_empleado, GtkTextView *text_mostrar_cajas) {
    // Limpiar el contenido previo de los archivos
    if (numproductoscarritos == 0) {
        return; // Si el carrito está vacío, no se hace nada.
    }

    // Obtener la fecha y hora actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Se lee el número de factura desde un archivo
    int numero_factura = 1001; // Valor por defecto
    FILE *archivo_numero_factura = fopen("numero_factura.txt", "r");
    if (archivo_numero_factura != NULL) {
        fscanf(archivo_numero_factura, "%d", &numero_factura);
        fclose(archivo_numero_factura);
    }

    // Crear una cadena para la factura
    char factura[1024 * 10] = "";  // Esto contendrá toda la factura (ajusta el tamaño según sea necesario)

    // Encabezado de la factura con la fecha y hora actual
    snprintf(factura, sizeof(factura),
             "=================== FACTURA ===================\n"
             "Hipermercado Cachamay\n"
             "Factura No: %d\n"
             "Fecha: %d-%02d-%02d %02d:%02d:%02d\n"
             "Empleado No: %d\n",
             numero_factura, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, numero_empleado);

    // Buscar los datos del cliente en el archivo de clientes
    FILE *archivo_clientes = fopen("datos_cliente.txt", "r");
    if (archivo_clientes == NULL) {
        return; // Error al abrir el archivo de clientes.
    }

    Cliente cliente;
    int encontrado = 0;
    while (fscanf(archivo_clientes, "%[^,],%[^,],%[^,],%[^,],%d\n", cliente.nombres_cliente, cliente.apellido_cliente, cliente.telefono_cliente, cliente.direccion_cliente, &cliente.cedula_cliente) != EOF) {
        if (cliente.cedula_cliente == cedula_cliente) {
            encontrado = 1;
            break;
        }
    }

    fclose(archivo_clientes);

    if (!encontrado) {
        return; // Cliente no encontrado.
    }

    // Escribir los datos del cliente en la factura
    char texto[1024];
    snprintf(texto, sizeof(texto),
             "Cliente: %s %s\n"
             "Cedula: %d\n\n",
             cliente.nombres_cliente, cliente.apellido_cliente, cliente.cedula_cliente);
    strcat(factura, texto);

    // Escribir los productos del carrito en la factura
    float subtotalUSD = 0.0;
    for (int i = 0; i < numproductoscarritos; i++) {
        float subtotalproducto = carrito[i].cantidadcomprada * carrito[i].preciounitario;
        snprintf(texto, sizeof(texto),
                 "Producto %d:\n"
                 "  Código: %s\n"
                 "  Nombre: %s\n"
                 "  Cantidad: %d\n"
                 "  Precio unitario: %.2f USD\n"
                 "  Subtotal: %.2f USD\n\n",
                 i + 1, carrito[i].codigo, carrito[i].nombre, carrito[i].cantidadcomprada, carrito[i].preciounitario, subtotalproducto);
        strcat(factura, texto);
        subtotalUSD += subtotalproducto;
    }

    // Calcular subtotales en diferentes monedas
    float subtotalBolivares = subtotalUSD * tasabolivares;
    float subtotalEuros = subtotalUSD * tasaeuros;
    float subtotalPesosColombianos = subtotalUSD * tasapesoscolombianos;

    // Calcular total con IVA en cada moneda
    float totalconivaUSD = subtotalUSD * (1 + IVA);
    float totalconivaBolivares = subtotalBolivares * (1 + IVA);
    float totalconivaEuros = subtotalEuros * (1 + IVA);
    float totalconivaPesos = subtotalPesosColombianos * (1 + IVA);

    // Escribir los subtotales y totales con IVA en la factura
    snprintf(texto, sizeof(texto),
             "Subtotal (USD): %.2f USD\n"
             "Subtotal (Bolívares): %.2f BS\n"
             "Subtotal (Euros): %.2f EUR\n"
             "Subtotal (Pesos Colombianos): %.2f COP\n\n"
             "IVA (%.2f%%): %.2f USD\n"
             "IVA (%.2f%%): %.2f BS\n"
             "IVA (%.2f%%): %.2f EUR\n"
             "IVA (%.2f%%): %.2f COP\n\n"
             "Total con IVA (USD): %.2f USD\n"
             "Total con IVA (Bolívares): %.2f BS\n"
             "Total con IVA (Euros): %.2f EUR\n"
             "Total con IVA (Pesos Colombianos): %.2f COP\n"
             "===============================================\n\n",
             subtotalUSD, subtotalBolivares, subtotalEuros, subtotalPesosColombianos,
             IVA * 100, subtotalUSD * IVA, IVA * 100, subtotalBolivares * IVA, IVA * 100, subtotalEuros * IVA, IVA * 100, subtotalPesosColombianos * IVA,
             totalconivaUSD, totalconivaBolivares, totalconivaEuros, totalconivaPesos);
    strcat(factura, texto);

    // Incrementar el número de factura y guardarlo en el archivo
    numero_factura++;
    archivo_numero_factura = fopen("numero_factura.txt", "w");
    if (archivo_numero_factura != NULL) {
        fprintf(archivo_numero_factura, "%d", numero_factura);
        fclose(archivo_numero_factura);
    }

    // Registrar la venta en la caja correspondiente
    FILE *archivo_cajas = fopen("cajas.dat", "r+");
    if (archivo_cajas == NULL) {
        return; // Error al abrir el archivo de cajas.
    }

    Caja caja;
    int caja_encontrada = 0;
    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        if (caja.numero_caja == numero_caja) {
            caja_encontrada = 1;
            caja.total_bs[tm.tm_mday - 1][tm.tm_mon] += totalconivaUSD * tasabolivares;
            caja.total_dolares[tm.tm_mday - 1][tm.tm_mon] += totalconivaUSD;
            caja.total_pesos_colombianos[tm.tm_mday - 1][tm.tm_mon] += totalconivaUSD * tasapesoscolombianos;
            caja.total_euros[tm.tm_mday - 1][tm.tm_mon] += totalconivaUSD * tasaeuros;
            fseek(archivo_cajas, -(long)sizeof(Caja), SEEK_CUR);
            fwrite(&caja, sizeof(Caja), 1, archivo_cajas);
            break;
        }
    }

    fclose(archivo_cajas);

    if (!caja_encontrada) {
        return; // Caja no encontrada.
    }

    // Limpiar el carrito
    numproductoscarritos = 0;

    // Mostrar la factura en el GtkTextView
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_cajas));
    gtk_text_buffer_set_text(buffer, factura, -1);

    // Aquí podrías cerrar el archivo si lo necesitas
}




void tasadecambio() {
    printf("Ingrese la nueva tasa para los Bolivares: \n");
    scanf("%f", &tasabolivares);

    printf("Ingrese la nueva tasa para los Euros: \n");
    scanf("%f", &tasaeuros);

    printf("Ingrese la nueva tasa para los Pesos Colombianos: \n");
    scanf("%f", &tasapesoscolombianos);

    printf("Nuevas tasas aplicadas:\n");
    printf("  Tasa Bolivares: %.2f\n", tasabolivares);
    printf("  Tasa Euros: %.2f\n", tasaeuros);
    printf("  Tasa Pesos Colombianos: %.2f\n", tasapesoscolombianos);
}



void consulta_diaria_por_caja(FILE *archivo_cajas, int numero_caja, int dia, int mes, GtkWidget *text_mostrar_ventas) {
    Caja caja;
    int encontrado = 0;
    rewind(archivo_cajas);

    // Preparar el buffer para el GtkTextView
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_ventas));

    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        if (caja.numero_caja == numero_caja) {
            encontrado = 1;

            // Escribir en el GtkTextView
            char texto[1024];
            snprintf(texto, sizeof(texto),
                "VENTAS DE LA CAJA %d EN EL DIA %d DEL MES %d:\n\n"
                "    TOTAL EN BS: %.2lf\n"
                "    TOTAL EN DOLARES: %.2lf\n"
                "    TOTAL EN PESOS COLOMBIANOS: %.2lf\n"
                "    TOTAL EN EUROS: %.2lf\n\n",
                numero_caja, dia, mes,
                caja.total_bs[dia - 1][mes - 1],
                caja.total_dolares[dia - 1][mes - 1],
                caja.total_pesos_colombianos[dia - 1][mes - 1],
                caja.total_euros[dia - 1][mes - 1]);

            gtk_text_buffer_insert_at_cursor(buffer, texto, -1);
            break;
        }
    }

    if (!encontrado) {
        gtk_text_buffer_insert_at_cursor(buffer, "CAJA NO ENCONTRADA\n\n", -1);
    }

    fclose(archivo_cajas);
}
void ventas_mensuales_por_caja(FILE *archivo_cajas, int numero_caja, int mes, GtkWidget *text_mostrar_ventas) {
    Caja caja;
    int encontrado = 0;
    rewind(archivo_cajas);

    // Preparar el buffer para el GtkTextView
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_ventas));

    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        if (caja.numero_caja == numero_caja) {
            encontrado = 1;
            double total_bs = 0, total_dolares = 0, total_pesos = 0, total_euros = 0;

            for (int i = 0; i < MAX_DIAS; i++) {
                total_bs += caja.total_bs[i][mes - 1];
                total_dolares += caja.total_dolares[i][mes - 1];
                total_pesos += caja.total_pesos_colombianos[i][mes - 1];
                total_euros += caja.total_euros[i][mes - 1];
            }

            // Formateamos la información que se mostrará en el GtkTextView
            char texto_mensual[1024];
            snprintf(texto_mensual, sizeof(texto_mensual),
                "VENTAS MENSUALES DE LA CAJA %d EN EL MES %d:\n\n"
                "    TOTAL EN BS: %.2lf\n"
                "    TOTAL EN DOLARES: %.2lf\n"
                "    TOTAL EN PESOS COLOMBIANOS: %.2lf\n"
                "    TOTAL EN EUROS: %.2lf\n",
                numero_caja, mes, total_bs, total_dolares, total_pesos, total_euros);

            // Insertar la información en el GtkTextView
            gtk_text_buffer_set_text(buffer, texto_mensual, -1);
            break;
        }
    }

    if (!encontrado) {
        // Si no se encuentra la caja, mostramos un mensaje de error en el GtkTextView
        gtk_text_buffer_set_text(buffer, "CAJA NO ENCONTRADA\n\n", -1);
    }
}

void total_ventas_mensuales_supermercado(FILE *archivo_cajas, int mes, GtkWidget *text_mostrar_ventas) {
    // Obtener el buffer del GtkTextView
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_ventas));

    // Verificar que el mes sea válido
    if (mes < 1 || mes > MAX_MESES) {
        gtk_text_buffer_set_text(buffer, "MES NO VALIDO\n\n", -1);  // Mostrar en TextView
        return;
    }

    Caja caja;
    double total_bs = 0, total_dolares = 0, total_pesos = 0, total_euros = 0;
    rewind(archivo_cajas);

    // Leer las ventas del archivo
    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        for (int i = 0; i < MAX_DIAS; i++) {
            total_bs += caja.total_bs[i][mes - 1];
            total_dolares += caja.total_dolares[i][mes - 1];
            total_pesos += caja.total_pesos_colombianos[i][mes - 1];
            total_euros += caja.total_euros[i][mes - 1];
        }
    }

    // Crear el texto con la información de ventas mensuales
    gchar texto_mensual[1024];
    snprintf(texto_mensual, sizeof(texto_mensual),
             "TOTAL DE VENTAS DEL SUPERMERCADO EN EL MES %d:\n\n"
             "    TOTAL EN BS: %.2lf\n"
             "    TOTAL EN DOLARES: %.2lf\n"
             "    TOTAL EN PESOS COLOMBIANOS: %.2lf\n"
             "    TOTAL EN EUROS: %.2lf\n",
             mes, total_bs, total_dolares, total_pesos, total_euros);

    // Insertar el texto en el GtkTextView
    gtk_text_buffer_set_text(buffer, texto_mensual, -1);
}

void mostrar_ultimas_10_facturas(GtkTextView *text_mostrar_ventas) {
    FILE *archivo_factura = fopen("factura.txt", "r");
    if (archivo_factura == NULL) {
        gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(text_mostrar_ventas), "Error al abrir el archivo de facturas.\n", -1);
        return;
    }

    char facturas[10][1024];  // Array para almacenar las últimas 10 facturas completas
    int contador = 0;         // Contador de facturas leídas
    char linea[256];          // Buffer para leer cada línea del archivo
    char factura_actual[1024] = ""; // Buffer para construir la factura actual

    // Leer todas las líneas del archivo
    while (fgets(linea, sizeof(linea), archivo_factura)) {
        // Concatenar la línea actual a la factura actual
        strcat(factura_actual, linea);

        // Si la línea es el final de una factura, guardar la factura actual
        if (strstr(linea, "===============================================") != NULL) {
            // Desplazar las facturas hacia arriba en el array si ya hay 10
            if (contador >= 10) {
                for (int i = 0; i < 9; i++) {
                    strcpy(facturas[i], facturas[i + 1]);
                }
            }

            // Guardar la factura actual en el array
            strcpy(facturas[contador < 10 ? contador : 9], factura_actual);
            contador++;

            // Reiniciar el buffer de la factura actual
            factura_actual[0] = '\0';
        }
    }

    fclose(archivo_factura);

    // Mostrar las últimas 10 facturas en el GtkTextView
    gchar texto[2048] = "";  // Buffer para almacenar el texto completo a mostrar
    strcat(texto, "\n=================================================");
    strcat(texto, "\n=              ULTIMAS 10 FACTURAS              =\n");
    strcat(texto, "=================================================\n\n");

    int inicio = contador < 10 ? 0 : contador - 10;
    for (int i = inicio; i < contador; i++) {
        strcat(texto, facturas[i - inicio]);
        strcat(texto, "\n===============================================\n");
    }

    // Insertar el texto en el GtkTextView
    gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(text_mostrar_ventas), texto, -1);
}


