#include "sistema_de_usuarios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>


void registrarUsuario(char *rol) {
    FILE *f = fopen(strcmp(rol, "Admin") == 0 ? "admins.txt" : "empleados.txt", "a");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(f, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            u.nombre, u.apellido, u.usuario, u.password,
            u.direccion, u.telefono, u.cedula, u.pregunta, u.respuesta);

    fclose(f);
    printf("\n%s registrado exitosamente!\n", rol);
}

int autenticar(const char *archivo, const char *usuario, const char *pass) {
    FILE *f = fopen(archivo, "r");
    if (!f) return 0; // Si no se puede abrir el archivo, retornar falso

    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",u.nombre, u.apellido, u.usuario, u.password,u.direccion, u.telefono, u.cedula, u.pregunta, u.respuesta) != EOF){
        // Comparar usuario y contraseña
        if (strcmp(u.usuario, usuario) == 0 && strcmp(u.password, pass) == 0) {
            fclose(f);
            return 1; // Retornar verdadero si coinciden
        }
    }

    fclose(f);
    return 0; // Retornar falso si no se encontró coincidencia
}

/*void verificarRespuestaSeguridad(GtkWidget *label_recuperarcontra, GtkWidget *label_ingresarusuario_recuperar, char usuario_login[MAX_LENGTH]) {
    char usuario[MAX_LENGTH], respuesta[MAX_LENGTH];
    Usuario u;
    int encontrado = 0;

    // Leer el nombre de usuario y la respuesta desde el Entry
//    strncpy(usuario, usuario_login, MAX_LENGTH-1);  // Usamos usuario_login en vez de entry_usuario directamente
//    strncpy(respuesta, gtk_entry_get_text(entry_usuario), MAX_LENGTH-1); // La respuesta desde entry_usuario

    FILE *f = fopen("admins.txt", "r");
    if (!f) f = fopen("empleados.txt", "r");

    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  u.nombre, u.apellido, u.usuario, u.password,
                  u.direccion, u.telefono, u.cedula, u.pregunta, u.respuesta) != EOF) {

        if (strcmp(u.usuario, usuario) == 0) {
            encontrado = 1;

            // Verificar si la respuesta es correcta
            if (strcmp(u.respuesta, respuesta) == 0) {
                // Mostrar la contraseña en el label
//                gtk_label_set_text(label_recuperarcontra, g_strdup_printf("Contraseña: %s", u.password));
            } else {
                // Si la respuesta es incorrecta
//                gtk_label_set_text(label_recuperarcontra, "Respuesta incorrecta!");
            }
            break;
        }
    }

    if (!encontrado) {
//        gtk_label_set_text(label_recuperarcontra, "Usuario no encontrado!");
    }

    fclose(f);
}

//    if (!encontrado) {
        gtk_label_set_text(GTK_LABEL(label_recuperarcontra), "Usuario no encontrado!");
    }

    fclose(f);
}

void recuperarContrasena(GtkWidget *label_recuperarcontra, GtkWidget *label_ingresarusuario_recuperar, GtkEntry *entry_usuario) {
    char usuario[MAX_LENGTH], respuesta[MAX_LENGTH];
    Usuario u;
    int encontrado = 0;

    // Leer el nombre de usuario desde el Entry
    strncpy(usuario, gtk_entry_get_text(entry_usuario), MAX_LENGTH-1);  // Usamos entry_usuario directamente para obtener el usuario

    FILE *f = fopen("admins.txt", "r");
    if (!f) f = fopen("empleados.txt", "r");

    while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  u.nombre, u.apellido, u.usuario, u.password,
                  u.direccion, u.telefono, u.cedula, u.pregunta, u.respuesta) != EOF) {

        if (strcmp(u.usuario, usuario) == 0) {
            encontrado = 1;

            // Mostrar la pregunta de seguridad en el label
            gtk_label_set_text(label_recuperarcontra, g_strdup_printf("Pregunta de seguridad: %s", u.pregunta));

            // Cambiar el texto del label para indicar que deben ingresar la respuesta
            gtk_label_set_text(label_ingresarusuario_recuperar, "Ingresar respuesta de seguridad:");

            // Ahora podemos esperar que el usuario ingrese la respuesta
            break;
        }
    }

    if (!encontrado) {
        gtk_label_set_text(label_recuperarcontra, "Usuario no encontrado!");
    }

    fclose(f);
}*/



void iniciar_sesion_empleado_caja(int *numero_empleado, int *numero_caja, char *nombre_responsable) {
    FILE *archivo_cajas = fopen("cajas.dat", "rb+");
    if (archivo_cajas == NULL) {
        printf("Error al abrir el archivo de cajas.\n");
        return;
    }

    printf("Ingrese su número de empleado: ");
    scanf("%d", numero_empleado);
    limpiarBuffer();

    printf("Ingrese su nombre: ");
    fgets(nombre_responsable, 50, stdin);
    nombre_responsable[strcspn(nombre_responsable, "\n")] = '\0';

    printf("Ingrese el número de caja: ");
    scanf("%d", numero_caja);
    limpiarBuffer();

    Caja caja;
    int caja_encontrada = 0;
    rewind(archivo_cajas);

    while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
        if (caja.numero_caja == *numero_caja) {
            caja_encontrada = 1;
            if (caja.ocupado) {
                printf("La caja %d ya está ocupada.\n", *numero_caja);
                fclose(archivo_cajas);
                return;
            } else {
                caja.ocupado = 1;
                caja.numero_empleado = *numero_empleado;
                strcpy(caja.nombre_responsable, nombre_responsable);

                fseek(archivo_cajas, -((long)sizeof(Caja)), SEEK_CUR);
                fwrite(&caja, sizeof(Caja), 1, archivo_cajas);
                fflush(archivo_cajas);
                break;
            }
        }
    }

    fclose(archivo_cajas);

    if (!caja_encontrada) {
        printf("Caja no encontrada.\n");
    }
}


