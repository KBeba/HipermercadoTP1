// clientes.h
#ifndef SISTEMA_DE_USUARIOS_H
#define SISTEMA_DE_USUARIOS_H

#define MAX_LENGTH 50
#define MAX_DIAS 30
#define MAX_MESES 12

#include "gestion_cajas.h"


// Definición de la estructura Cliente
typedef struct {
    char usuario[MAX_LENGTH];
    char nombre[MAX_LENGTH];
    char apellido[MAX_LENGTH];
    char password[MAX_LENGTH];
    char direccion[MAX_LENGTH];
    char telefono[MAX_LENGTH];
    char cedula[MAX_LENGTH];
    char pregunta[MAX_LENGTH];
    char respuesta[MAX_LENGTH];
} Usuario;
extern Usuario u;
// Prototipos de funciones

// Sistema de usuarios
void registrarUsuario(char *rol); // implementada
int autenticar(const char *archivo, const char *usuario, const char *pass); // implementada
void recuperarContrasena(); // implementada
//void registrarEmpleado(); // implementada
void iniciar_sesion_empleado_caja(int *numero_empleado, int *numero_caja, char *nombre_responsable);  // implementada
//void verificarRespuestaSeguridad(GtkWidget *label_recuperarcontra, GtkWidget *label_ingresarusuario_recuperar, char usuario_login[MAX_LENGTH]);

// Cerrar la guardia de inclusión
#endif // CLIENTES_H
