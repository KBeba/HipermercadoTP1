#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include <time.h> // obtener la fecha y hora actuales, se utiliza en facturas y ventas

#include "sistema_de_usuarios.h"
#include "gestion_de_clientes.h"
#include "gestion_cajas.h"
#include "gestion_de_empleados.h"
#include "Gestion_de_Procutos_e_inventario.h"
#include "Gestion_de_ventas.h"
#include "sistema_de_usuarios.h"
#include "validaciones.h"


// ================= VARIABLES DE LA INTERFAZ GRAFICA =================
//VENTANA DE INICIO
    GtkWidget *ventana_inicio;
    GtkWidget *box_inicio;
    GtkWidget *boton_inicio;
    GtkWidget *boton_salir_inicio;
    GtkWidget *titulo;
    GtkWidget *informacion_inicio;

//VENTANA MENU PRINCIPAL
    GtkWidget *ventana_menu_principal;
    GtkWidget *box_menu_principal;
    GtkWidget *regis_admin;
    GtkWidget *inicio_empleado;
    GtkWidget *inicio_admin;
    GtkWidget *regis_empleado;
    GtkWidget *salir_menu_principal;
    GtkWidget *recuperar_contra;
    GtkWidget *label_menuprincipal;
    //RECUPERAR CONTRASENNIA
    GtkWidget *ventana_recuperar_contra;
    GtkWidget *fixed_recuperar;
    GtkWidget *label_titulo_recuperarcontra;
    GtkWidget *label_ingresarusuario_recuperar;
    GtkWidget *ingresar_usuario_recuperar;
    GtkWidget *boton_salir_recuperarcontra;
    GtkWidget *boton_buscarcontra;
    GtkWidget *label_contrasena;

//VENTANA REGISTRO ADMIN
    GtkWidget *ventana_registro_administrador;
    GtkWidget *fixed_registro;
    GtkWidget *label_ingresarnombre;
    GtkWidget *ingresar_nombre_admin;
    GtkWidget *clear_registro_admin_nombre;
    GtkWidget *label_ingresarapellido;
    GtkWidget *ingresar_apellido_admin;
    GtkWidget *clear_registro_admin_apellido;
    GtkWidget *label_ingresardireccion;
    GtkWidget *ingresar_direccion_admin;
    GtkWidget *clear_registro_admin_direccion;
    GtkWidget *label_ingresartlf;
    GtkWidget *ingresar_tlf_admin;
    GtkWidget *clear_registro_admin_telefono;
    GtkWidget *label_ingresarcedula;
    GtkWidget *ingresar_cedula_admin;
    GtkWidget *clear_registro_admin_cedula;
    GtkWidget *label_ingresarpregunta;
    GtkWidget *ingresar_usuario_admin;
    GtkWidget *clear_registro_admin_usuario;
    GtkWidget *label_ingresarusuario;
    GtkWidget *ingresar_preg_admin;
    GtkWidget *clear_registro_admin_respt;
    GtkWidget *label_ingresarrespuesta;
    GtkWidget *ingresar_respt_admin;
    GtkWidget *clear_registro_admin_preg;
    GtkWidget *label_ingresarcontra;
    GtkWidget *ingresar_contra_admin;
    GtkWidget *clear_registro_admin_contra;
    GtkWidget *salir_ingresardatos;
    GtkWidget *boton_registrardatos;
    GtkWidget *err_cedula;
    GtkWidget *err_tlf;
    GtkWidget *err_usuario;
    GtkWidget *err_contra;
    GtkWidget *err_respt;
    GtkWidget *err_preg;
    GtkWidget *err_direccion;
    GtkWidget *err_apellido;
    GtkWidget *err_nombre;
    GtkWidget *err_espaciovacio;

//VENTANA MENU ADMIN
    GtkWidget *ventana_menu_admin;
    GtkWidget *box_menu_admin;
    GtkWidget *label_titulo_menu_admin;
    GtkWidget *boton_inventario;
    GtkWidget *boton_gestionar_empleados;
    GtkWidget *boton_gestionar_caja;
    GtkWidget *boton_gestionar_ventas;
    GtkWidget *boton_gestionar_clientes;
    GtkWidget *boton_mostrar_admin_registrados;
    GtkWidget *boton_salir_menu_admin;

    //MENU VENTAS
    GtkWidget *ventana_ventas;
    GtkWidget *box_menu_ventas;
    GtkWidget *label_titulo_ventas;
    GtkWidget *boton_ventas_diaria;
    GtkWidget *boton_ventas_mensuales_porcaja;
    GtkWidget *boton_ventas_total_mensuales;
    GtkWidget *boton_mostrar_facturas;
    GtkWidget *boton_salir_ventas;

        //VENTAS MENSUALES TOTALES
        GtkWidget *ventana_ventas_mensuales_super;
        GtkWidget *fixed_ventas_mensuales_super;
        GtkWidget *label_titulo_ventas_mensuales_super;
        GtkWidget *spin_mes_venta_super;
        GtkWidget *label_ingresar_mes_super;
        GtkWidget *boton_buscar_ventas_mensuales_super;
        GtkWidget *boton_salir_ventas_mensuales_super;
        //VENTAS MENSUALES
        GtkWidget *ventana_ventas_mensuales;
        GtkWidget *fixed_ventas_mensuales;
        GtkWidget *label_titulo_ventas_mensuales;
        GtkWidget *ingresar_num_caja_mensuales;
        GtkWidget *label_num_caja1;
        GtkWidget *spin_mes_venta1;
        GtkWidget *label_ingresar_mes1;
        GtkWidget *boton_buscar_ventas_mensuales;
        GtkWidget *boton_salir_ventas_mensuales;
        //VENTAS DIARIAS
        GtkWidget *ventana_ventas_diarias;
        GtkWidget *fixed_ventas_diarias;
        GtkWidget *label_titulo_ventas_diarias;
        GtkWidget *ingresar_num_caja_ventasd;
        GtkWidget *label_num_caja;
        GtkWidget *spin_dia_venta;
        GtkWidget *label_ingresar_dia;
        GtkWidget *spin_mes_venta;
        GtkWidget *label_ingresar_mes;
        GtkWidget *boton_buscar_ventas_diarias;
        GtkWidget *boton_salir_ventas_diarias;

        //MOSTRAR VENTAS
        GtkWidget *ventana_ventas_consulta;
        GtkWidget *scrolledwindow_mostrar_ventas;
        GtkWidget *viewport_mostrar_ventas;
        GtkWidget *box_mostrar_ventas;
        GtkWidget *text_mostrar_ventas;


    //MENU INVENTARIO
    GtkWidget *ventana_inventario;
    GtkWidget *box_inventario;
    GtkWidget *label_titulo_inventario;
    GtkWidget *boton_agregar_producto;
    GtkWidget *boton_consultar_inventario;
    GtkWidget *boton_salir_inventario;

    //GESTION DE CAJA
    GtkWidget *ventana_menu_caja;
    GtkWidget *box_menu_caja;
    GtkWidget *label_menu_cajas;
    GtkWidget *boton_crear_caja;
    GtkWidget *boton_eliminar_caja;
    GtkWidget *boton_mostrar_cajas;
    GtkWidget *salir_menu_caja;
        //CREAR CAJA
        GtkWidget *ventana_crear_caja;
        GtkWidget *fixed_crear_caja;
        GtkWidget *ingresar_num_caja;
        GtkWidget *label_numero_caja;
        GtkWidget *label_titulo_crear_caja;
        GtkWidget *label_numero_empleado;
        GtkWidget *label_nombre_encargado;
        GtkWidget *boton_agregar_caja;
        GtkWidget *boton_salir_crear_caja;
        GtkWidget *ingresar_num_empleado_caja;
        GtkWidget *ingresar_nombre_empleado_caja;

        //ELIMINAR CAJA
        GtkWidget *ventana_eliminarcaja;
        GtkWidget *fixed_eliminarcaja;
        GtkWidget *label_eliminar_caja;
        GtkWidget *ingresar_numcaja_eliminar;
        GtkWidget *boton_salir_eliminar_caja;
        GtkWidget *boton_eliminar_caj;
        GtkWidget *label_titulo_eliminarcaja;

        //MOSTRAR CAJAS
        GtkWidget *ventana_mostrar_cajas;
        GtkWidget *scrolledwindow_mostrar_cajas;
        GtkWidget *viewport_mostrar_cajas;
        GtkWidget *box_mostrar_cajas;
        GtkWidget *text_mostrar_cajas;

        //GESTION DE EMPLEADOS
        GtkWidget *ventana_gestion_empleados;
        GtkWidget *box_gestion_empleados;
        GtkWidget *label_titulo_gestionempleados;
        GtkWidget *boton_mostrar_empleado;
        GtkWidget *boton_modificar_empleado;
        GtkWidget *boton_eliminar_empleado;
        GtkWidget *boton_cantidad_empleado;
        GtkWidget *boton_salir_gestionempleados;
            //CANTIDAD DE EMPLEADOS
            GtkWidget *ventana_cantidad_empleados;
            GtkWidget *box_cant_empleados;
            GtkWidget *label_cant_empleados;

            //MOSTRAR EMPLEADO
            GtkWidget *venta_mostrar_empleados;
            GtkWidget *scrolledwindow_mostrar_empleados;
            GtkWidget *viewport_mostrar_empleados;
            GtkWidget *box_mostrar_empleado;
            GtkWidget *text_mostrar_empleados;
            //ELIMINAR EMPLEADO
            GtkWidget *ventana_eliminar_empleado_cedula;
            GtkWidget *fixed_eliminar_empleado;
            GtkWidget *label_eliminarempleado_ingresarcedula;
            GtkWidget *ingresar_cedula_eliminar_empleado;
            GtkWidget *label_ingresar_cedula_eliminar;
            GtkWidget *boton_salir_eliminarempleado;
            GtkWidget *boton_buscar_empleado_eliminar;
            GtkWidget *label_noencontrado_eliminar;

            //MODIFICAR EMPLEADO
            GtkWidget *ventana_modificar_empleado_cedula;
            GtkWidget *fixed_modificar_empleado;
            GtkWidget *label_noencontrado;
            GtkWidget *label_modificarempleado_ingresarcedula;
            GtkWidget *label_ingresar_cedula;
            GtkWidget *ingresar_cedula_modificar_empleado;
            GtkWidget *boton_salir_modificarempleado;
            GtkWidget *boton_buscar_empleado;

                //MODIFICAR EMPLEADO
                GtkWidget *ventana_modificar_empleado;
                GtkWidget *fixed_registro1;
                GtkWidget *label_ingresarnombre1;
                GtkWidget *ingresar_nombre_admin1;
                GtkWidget *clear_registro_admin_nombre1;
                GtkWidget *label_ingresarapellido1;
                GtkWidget *ingresar_apellido_admin1;
                GtkWidget *clear_registro_admin_apellido1;
                GtkWidget *label_ingresardireccion1;
                GtkWidget *ingresar_direccion_admin1;
                GtkWidget *clear_registro_admin_direccion1;
                GtkWidget *label_ingresartlf1;
                GtkWidget *ingresar_tlf_admin1;
                GtkWidget *clear_registro_admin_telefono1;
                GtkWidget *label_ingresarpregunta1;
                GtkWidget *ingresar_usuario_admin1;
                GtkWidget *clear_registro_admin_usuario1;
                GtkWidget *label_ingresarusuario1;
                GtkWidget *ingresar_preg_admin1;
                GtkWidget *clear_registro_admin_respt1;
                GtkWidget *label_ingresarrespuesta1;
                GtkWidget *ingresar_respt_admin1;
                GtkWidget *clear_registro_admin_preg1;
                GtkWidget *label_ingresarcontra1;
                GtkWidget *ingresar_contra_admin1;
                GtkWidget *clear_registro_admin_contra1;
                GtkWidget *salir_ingresardatos1;
                GtkWidget *boton_registrardatos1;
                GtkWidget *err_tlf1;
                GtkWidget *err_usuario1;
                GtkWidget *err_contra1;
                GtkWidget *err_respt1;
                GtkWidget *err_preg1;
                GtkWidget *err_direccion1;
                GtkWidget *err_apellido1;
                GtkWidget *err_nombre1;
                GtkWidget *err_espaciovacio1;

        //AGREGAR PRODUCTOS
        GtkWidget *ingresar_nombreprod;
        GtkWidget *label_nombre_producto;
        GtkWidget *ventana_agregar_producto;
        GtkWidget *fixed_agregar_producto;
        GtkWidget *combotext_agregarinventario;
        GtkWidget *label_ingresar_invent;
        GtkWidget *label_titulo_agregarprod;
        GtkWidget *label_cantprod;
        GtkWidget *spin_cantprod;
        GtkWidget *label_precio_prod;
        GtkWidget *ingresar_precioprod;
        GtkWidget *boton_aceptarguardarproducto;
        GtkWidget *boton_salirguardarproducto;
        //CONSULTAR PRODUCTOS GUARDADOS
        GtkWidget *ventana_consultar_invt;
        GtkWidget *box_consultainvt;
        GtkWidget *label_titulo_consultainvt;
        GtkWidget *licores;
        GtkWidget *hortalizas;
        GtkWidget *charcuteria;
        GtkWidget *productos_de_limpieza;
        GtkWidget *varios;
        GtkWidget *salir_menu_consultainvt;
            //MOSTRAR VENTANA CON LOS PRODUCTOS
            GtkWidget *ventana_consultar_invt_producto;
            GtkWidget *scrolledwindow_consultarprod;
            GtkWidget *viewport_consultarprod;
            GtkWidget *box3;
            GtkWidget *text_consultainvt;





//VENTANA MENU EMPLEADOS
    GtkWidget *ventana_menuempleado;
    GtkWidget *box_menuempleado;
    GtkWidget *label_menuempleadocaja;
    GtkWidget *boton_modificar_tasas;
    GtkWidget *boton_registrar_cliente;
    GtkWidget *boton_imprimir_factura;
    GtkWidget *boton_venta;
    GtkWidget *boton_salir_menuempleado;

        //VENTANA INGRESAR TASA DEL DIA
            GtkWidget *ventana_tasas;
            GtkWidget *fixed_tasas;
            GtkWidget *label_tasa;
            GtkWidget *label_bolivares;
            GtkWidget *label_peso_colombiano;
            GtkWidget *label_dolar;
            GtkWidget *label_euros;
            GtkWidget *boton_salir_tasa;
            GtkWidget *boton_aceptar_tasa;
            GtkWidget *ingresar_euros;
            GtkWidget *ingresar_peso_colombiano;
            GtkWidget *ingresar_dolar;
            GtkWidget *ingresar_bs;

        //PROCESAR UNA COMPRA menu
        GtkWidget *ventana_procesarcompra_enter;
        GtkWidget *label_err_procesarcompraenter;
        GtkWidget *fixed_procesarcompra_enter;
        GtkWidget *label_titulo_procesarcompra_enter;
        GtkWidget *label_numero_empleado1;
        GtkWidget *boton_procesarcompra_enter;
        GtkWidget *boton_salir_procesarcompra_enter;
        GtkWidget *ingresar_num_empleado_caja1;
        GtkWidget *label_numero_caja1;
        GtkWidget *salir_menu_venta;
        GtkWidget *ingresar_num_caja1;
            //verificar cedulacliente
            GtkWidget *ventana_cedula_cliente;
            GtkWidget *fixed_cedulacliente;
            GtkWidget *label_cedcliente;
            GtkWidget *ingresarcedula;
            GtkWidget *boton_procesarcompra_enter2;
            GtkWidget *boton_salir_procesarcompra_enter2;
            GtkWidget *label_errcedula;

                //  MENU VENTA
                GtkWidget *ventana_menu_venta;
                GtkWidget *box_opciones;
                GtkWidget *label_titulo_procesarcompra;
                GtkWidget *boton_agregar_al_carrito;
                GtkWidget *boton_mostrar_carrito;
                GtkWidget *boton_oficializar_venta;
                GtkWidget *boton_salir_ventas;
                        // Agregar a carrito
                        GtkWidget *ventana_agregar_carrito;
                        GtkWidget *fixed_agregar_carrito;
                        GtkWidget *label_titulo_agregar_producto;
                        GtkWidget *label_select_segmento;
                        GtkWidget *label_ingresar_cod_prod;
                        GtkWidget *label_err_prod;
                        GtkWidget *label_cant_compra;
                        GtkWidget *combotext_agregar_carrito;
                        GtkWidget *ingresar_cod_producto;
                        GtkWidget *sub_fixed_prod;
                        GtkWidget *scrolledwindow_mostrar_prod;
                        GtkWidget *viewport_mostrar_prod;
                        GtkWidget *box_mostrar_prod;
                        GtkWidget *text_mostrar_prod;
                        GtkWidget *spin_cant_prod;
                        GtkWidget *boton_aceptar_compra;
                        GtkWidget *boton_salir_carrito;


//VENTANA REGISTRO CLIENTE
    GtkWidget *ventana_registrar_cliente;
    GtkWidget *fixed_registro_cliente;
    GtkWidget *label_titulo_registrocliente;
    GtkWidget *boton_aceptar_registrocliente;
    GtkWidget *boton_salir_registrocliente;
    GtkWidget *ingresar_nombrecliente;
    GtkWidget *ingresar_apellidocliente;
    GtkWidget *ingresar_tlfcliente;
    GtkWidget *ingresar_direccioncliente;
    GtkWidget *ingresar_cedulacliente;
    GtkWidget *label_ingresardireccion_cliente;
    GtkWidget *label_ingresarcedula_cliente;
    GtkWidget *label_ingresarapellido_cliente;
    GtkWidget *label_ingresartelefono_cliente;
    GtkWidget *label_ingresarnombre_cliente;
    GtkWidget *label_err_cliente;

//VENTANA LOGIN
    GtkWidget *ventana_login;
    GtkWidget *fixed_login;
    GtkWidget *ingresar_usuario_login;
    GtkWidget *clear_registro_admin_usuario2;
    GtkWidget *label_ingresarusuario2;
    GtkWidget *label_ingresarclave2;
    GtkWidget *ingresar_clave_admin2;
    GtkWidget *clear_registro_admin_clave2;
    GtkWidget *boton_salir_login;
    GtkWidget *boton_aceptar_login;
    GtkWidget *label_err_login;


//hacer opcion del menu principal global para que pueda ser usada por todas las funciones
int opcion;
int login;
int err = 0;
char usuario_login[MAX_LENGTH];
char contrasena[MAX_LENGTH];
int cedula_cliente;
int numero_caja;
int numero_empleado;
float tasa_bs,tasa_pesos,tasa_euros;

Usuario u;





// ================= BUILD DEL ARCHIVO .GLADE =================
    GtkBuilder *builder;

// ================= FUNCIONES DE LA INTERFAZ GRAFICA =================

// ================= BOTONES DEL INICIO =================
void on_boton_inicio_clicked (GtkButton *b){
     // Cerrar la primera ventana
    gtk_widget_show_all(ventana_menu_principal);
    gtk_widget_hide(ventana_inicio);
}

void on_boton_salir_inicio_clicked (GtkButton *b){
    g_print("Bot�n clickeado. Cerrando la aplicaci�n...\n");
     // Cerrar todas las ventanas abiertas
    if (ventana_inicio != NULL) {
        gtk_widget_destroy(ventana_inicio);
    }
    if (ventana_menu_principal != NULL) {
        gtk_widget_destroy(ventana_menu_principal);
    }
    if (ventana_registro_administrador != NULL) {
        gtk_widget_destroy(ventana_registro_administrador);
    }

    gtk_main_quit();
}

//globalizar la variable que hace el cambio de archivo
char *rol;
// ================= BOTONES MENU PRINCIPAL =================
void on_regis_admin_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_registro_administrador);
    gtk_widget_hide(ventana_menu_principal);
    // user_data es un puntero a los datos que pasaste al conectar la se�al

    rol = "Admin";
}

void on_regis_empleado_clicked (GtkButton *b){
    gtk_widget_show_all(ventana_registro_administrador);
    gtk_widget_hide(ventana_menu_principal);

    rol = "trabajador";
}

void on_inicio_admin_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_login);
    gtk_widget_hide(ventana_menu_principal);
    login = 1;
}

void on_inicio_empleado_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_login);
    gtk_widget_hide(ventana_menu_principal);
    login = 0;
}


//variable global para verificar el estado de la pregunta
int preguntaMostrada = 0;

void on_recuperar_contra_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_recuperar_contra);
    gtk_widget_hide(ventana_menu_principal);
}
    //RECUP CONTRA
    /*
    void on_ingresar_usuario_recuperar_changed(GtkEntry *e){
        strncpy(usuario_login, gtk_entry_get_text(e), MAX_LENGTH-1);
    }
    void on_boton_salir_recuperarcontra_clicked(GtkButton *b){
        gtk_widget_show_all(ventana_menu_principal);
        gtk_widget_hide(ventana_recuperar_contra);
    }
    void on_boton_buscarcontra_clicked(GtkButton *b) {
        char usuario[MAX_LENGTH];

        // Si la pregunta aún no ha sido mostrada, llamar a recuperarContrasena para mostrar la pregunta
        if (!preguntaMostrada) {
            // Llamamos a la función recuperarContrasena pasando los parámetros
            recuperarContrasena(GTK_LABEL(label_contrasena), GTK_LABEL(label_ingresarusuario_recuperar), GTK_ENTRY(ingresar_usuario_recuperar));
            preguntaMostrada = 1; // Se marca que la pregunta ha sido mostrada
        }
        // Si la pregunta ya ha sido mostrada, se verifica la respuesta
        else {
            // Llamamos a la función verificarRespuestaSeguridad pasando los parámetros
            verificarRespuestaSeguridad(GTK_LABEL(label_contrasena), GTK_LABEL(label_ingresarusuario_recuperar), GTK_ENTRY(ingresar_usuario_recuperar));
            preguntaMostrada = 0; // Se restablece el estado para la siguiente vez
        }
    }*/



// ================= BOTONES REGISTRO =================
//botones de borrar datos
void on_clear_registro_admin_nombre_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_nombre_admin), 0 , -1);
}
void on_clear_registro_admin_apellido_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_apellido_admin), 0 , -1);
}
void on_clear_registro_admin_direccion_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_direccion_admin), 0 , -1);
}
void on_clear_registro_admin_telefono_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_tlf_admin), 0 , -1);
}
void on_clear_registro_admin_cedula_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_cedula_admin), 0 , -1);
}
void on_clear_registro_admin_usuario_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_usuario_admin), 0 , -1);
}
void on_clear_registro_admin_contra_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_contra_admin), 0 , -1);
}
void on_clear_registro_admin_preg_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_preg_admin), 0 , -1);
}
void on_clear_registro_admin_respt_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_respt_admin), 0 , -1);
}


// =================  ENTRADAS DE TEXTO REGISTRO =================

void on_ingresar_nombre_admin_changed(GtkEntry *e){
    strncpy(u.nombre, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_apellido_admin_changed(GtkEntry *e){
    strncpy(u.apellido, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_direccion_admin_changed(GtkEntry *e){
    strncpy(u.direccion, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_tlf_admin_changed(GtkEntry *e){
    strncpy(u.telefono, gtk_entry_get_text(e), MAX_LENGTH-1);
    if(esNumero(u.telefono) == 0){
            gtk_label_set_text(GTK_LABEL(err_tlf),"En este campo no se permiten letras");
    }
    else {
            gtk_label_set_text(GTK_LABEL(err_tlf), "");
    }
}
void on_ingresar_cedula_admin_changed(GtkEntry *e){
    strncpy(u.cedula, gtk_entry_get_text(e), MAX_LENGTH-1);
    if(esNumero(u.cedula) == 0){
            gtk_label_set_text(GTK_LABEL(err_cedula),"En este campo no se permiten letras");
    }
    else {
            gtk_label_set_text(GTK_LABEL(err_cedula), "");
    }
}
void on_ingresar_usuario_admin_changed(GtkEntry *e){
    strncpy(u.usuario, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_contra_admin_changed(GtkEntry *e){
    strncpy(u.password, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_preg_admin_changed(GtkEntry *e){
    strncpy(u.pregunta, gtk_entry_get_text(e), MAX_LENGTH-1);
}
void on_ingresar_respt_admin_changed(GtkEntry *e){
    strncpy(u.respuesta, gtk_entry_get_text(e), MAX_LENGTH-1);
}

// BOTON CONFIRMAR REGISTRAR DATOS
void on_boton_registrardatos_clicked(GtkButton *b){
    err = 0;  // Reiniciar el contador de errores

    // Verificar todos los campos
    if (u.nombre[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_nombre), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_nombre), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.apellido[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_apellido), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_apellido), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.direccion[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_direccion), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_direccion), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.cedula[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_cedula), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_cedula), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.telefono[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_tlf), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_tlf), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.usuario[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_usuario), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_usuario), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.password[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_contra), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_contra), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.respuesta[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_respt), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_respt), "");  // Limpiar mensaje de error si el campo est� lleno
    }

    if (u.pregunta[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(err_preg), "Rellenar campo");
        err++;
    } else {
        gtk_label_set_text(GTK_LABEL(err_preg), "");  // Limpiar mensaje de error si el campo est� lleno
    }
    if(err == 0){
        registrarUsuario(rol);
        gtk_widget_show_all(ventana_menu_principal);
        gtk_widget_hide(ventana_registro_administrador);
    }else gtk_label_set_text(GTK_LABEL(err_espaciovacio),"Error, rellenar todos los campos correctamente");
}

// BOTON SALIR REGISTRO

void on_salir_ingresardatos_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_menu_principal);
    gtk_widget_hide(ventana_registro_administrador);
}

//BOTON SALIR MENUPRINCIPAL
void on_salir_menu_principal_clicked(GtkButton *b){
    g_print("Bot�n clickeado. Cerrando la aplicaci�n...\n");
     // Cerrar todas las ventanas abiertas
    if (ventana_inicio != NULL) {
        gtk_widget_destroy(ventana_inicio);
    }
    if (ventana_menu_principal != NULL) {
        gtk_widget_destroy(ventana_menu_principal);
    }
    if (ventana_registro_administrador != NULL) {
        gtk_widget_destroy(ventana_registro_administrador);
    }

    gtk_main_quit();
}

// ================= BOTONES LOGIN =================

void on_boton_salir_login_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_menu_principal);
    gtk_widget_hide(ventana_login);
}

void on_boton_aceptar_login_clicked(GtkButton *b){
    if (login == 0) { // Autenticar como empleado
        if (autenticar("empleados.txt", usuario_login, contrasena)) {
            gtk_widget_show_all(ventana_menuempleado);
            gtk_widget_hide(ventana_login);
        } else {
            gtk_label_set_text(GTK_LABEL(label_err_login), "Error, no hay un usuario con esos datos");
        }
    } else if (login == 1) { // Autenticar como administrador
        if (autenticar("admins.txt", usuario_login, contrasena)) {
            gtk_widget_show_all(ventana_menu_admin);
            gtk_widget_hide(ventana_login);
        } else {
            gtk_label_set_text(GTK_LABEL(label_err_login), "Error, no hay un usuario con esos datos");
        }
    }
}

void on_clear_registro_admin_clave2_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_clave_admin2), 0 , -1);
}

void on_clear_registro_admin_usuario2_clicked(GtkButton *b){
    gtk_editable_delete_text(GTK_EDITABLE(ingresar_usuario_login), 0 , -1);
}
// ================= ENTRADAS LOGIN =================
void on_ingresar_usuario_login_changed (GtkEntry *e){
    strncpy(usuario_login, gtk_entry_get_text(e), MAX_LENGTH-1);
}

void on_ingresar_clave_admin2_changed (GtkEntry *e){
    strncpy(contrasena, gtk_entry_get_text(e), MAX_LENGTH-1);
}
// ================= MENU ADMINISTRADOR ===============================
void on_boton_inventario_clicked (GtkButton *b){
    gtk_widget_show_all(ventana_inventario);
    gtk_widget_hide(ventana_menu_admin);
}
void on_boton_gestionar_empleados_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_gestion_empleados);
    gtk_widget_hide(ventana_menu_admin);
}
void on_boton_gestionar_caja_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_menu_caja);
    gtk_widget_hide(ventana_menu_admin);
}
void on_boton_gestionar_ventas_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_ventas);
    gtk_widget_hide(ventana_menu_admin);
}
void on_boton_gestionar_clientes_clicked(GtkButton *b){
    //gtk_widget_show_all(ventana_menu_principal);
    //gtk_widget_hide(ventana_menuempleado);
}
void on_boton_mostrar_admin_registrados_clicked(GtkButton *b){
    //gtk_widget_show_all(ventana_menu_principal);
    //gtk_widget_hide(ventana_menuempleado);
}
void on_boton_salir_menu_admin_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_menu_principal);
    gtk_widget_hide(ventana_menu_admin);
}

        //MENU VENTAS
        void on_boton_ventas_diaria_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas_diarias);
            gtk_widget_hide(ventana_ventas);
        }
        int numero_caja_ventasd;
            //ventas diarias
            void on_ingresar_num_caja_ventasd_changed(GtkEntry *e) {
                const char *num_caja_str = gtk_entry_get_text(e);
                numero_caja_ventasd = atoi(num_caja_str);  // Guardamos el valor de caja
            }
            void on_boton_buscar_ventas_diarias_clicked(GtkButton *b, gpointer user_data) {
                // Obtener el día y el mes de los spin buttons
                int dia = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_dia_venta));
                int mes = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mes_venta));


                // Limpiar el GtkTextView antes de mostrar la nueva consulta
                GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_ventas));
                gtk_text_buffer_set_text(buffer, "", -1);  // Limpiar el contenido del TextView

                // Abrir archivo de cajas
                FILE *archivo_cajas = fopen("cajas.dat", "rb");
                if (archivo_cajas == NULL) {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                // Llamar a la función para hacer la consulta
                consulta_diaria_por_caja(archivo_cajas, numero_caja_ventasd, dia, mes, text_mostrar_ventas);

                // Mostrar la ventana
                gtk_widget_show(ventana_ventas_consulta);
            }
            void on_boton_salir_ventas_diarias_clicked(GtkButton *b){
                gtk_widget_show_all(ventana_ventas);
                gtk_widget_hide(ventana_ventas_diarias);
            }






        int numero_caja;
        void on_boton_ventas_mensuales_porcaja_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas_mensuales);
            gtk_widget_hide(ventana_ventas);
        }
        void on_ingresar_num_caja_mensuales_changed(GtkEntry *e) {
            const char *num_caja = gtk_entry_get_text(e);
            numero_caja = atoi(num_caja); // Asignamos el número de caja global
        }
        void on_boton_buscar_ventas_mensuales_clicked(GtkButton *b) {
            int mes = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mes_venta1));

            // Limpiar el GtkTextView antes de mostrar la nueva consulta
                GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_mostrar_ventas));
                gtk_text_buffer_set_text(buffer, "", -1);  // Limpiar el contenido del TextView

                // Abrir archivo de cajas
                FILE *archivo_cajas = fopen("cajas.dat", "rb");
                if (archivo_cajas == NULL) {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
            // Llamamos a la función que consulta las ventas mensuales y muestra los resultados
            ventas_mensuales_por_caja(archivo_cajas, numero_caja, mes, text_mostrar_ventas);
            gtk_widget_show(ventana_ventas_consulta);
        }
        void on_boton_salir_ventas_mensuales_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas);
            gtk_widget_hide(ventana_ventas_mensuales);
        }





        void on_boton_ventas_total_mensuales_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas_mensuales_super);
            gtk_widget_hide(ventana_ventas);
        }

        void on_boton_salir_ventas_mensuales_super_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas);
            gtk_widget_hide(ventana_ventas_mensuales_super);
        }
        void on_boton_buscar_ventas_mensuales_super_clicked(GtkButton *b) {
            // Obtener el mes desde el spin button
            int mes = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mes_venta_super));

            // Verificar que el mes sea válido
            if (mes < 1 || mes > MAX_MESES) {
                printf("Mes no válido\n");
                return;
            }

            // Abrir el archivo de cajas para leer las ventas
            FILE *archivo_cajas = fopen("cajas.dat", "rb");
            if (archivo_cajas == NULL) {
                printf("ERROR AL ABRIR EL ARCHIVO DE CAJAS\n");
                return;
            }

            // Llamar a la función que obtiene las ventas mensuales, pasando también el mes
            total_ventas_mensuales_supermercado(archivo_cajas, mes, text_mostrar_ventas);

            fclose(archivo_cajas);

            // Mostrar la ventana de consulta de ventas
            gtk_widget_show(ventana_ventas_consulta);
        }





        void on_boton_mostrar_facturas_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_ventas_consulta);

            mostrar_ultimas_10_facturas(text_mostrar_ventas);
        }

        void on_boton_salir_ventas_clicked(GtkButton *b) {
            gtk_widget_show_all(ventana_menu_admin);
            gtk_widget_hide(ventana_ventas);
            gtk_widget_hide(ventana_ventas_consulta);
        }







        //GESTION CAJA
        void on_boton_crear_caja_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_crear_caja);
            gtk_widget_hide(ventana_menu_caja);
        }

         void on_salir_menu_caja_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_menu_admin);
            gtk_widget_hide(ventana_menu_caja);
            gtk_widget_hide(ventana_mostrar_cajas);
        }

        void on_boton_mostrar_cajas_clicked(GtkButton *b) {
            // Llamar a la función mostrar_cajas y pasarle los parámetros necesarios
            mostrar_cajas(ventana_mostrar_cajas, text_mostrar_cajas);
        }
            //CREAR CAJA
            //set una variable global del struct
            Caja nueva_caja;
            // Callbacks para capturar datos de las entradas
            void on_ingresar_num_empleado_caja_changed(GtkEntry *e) {
                const char *num_empleado = gtk_entry_get_text(e);
                nueva_caja.numero_empleado = atoi(num_empleado);
            }

            void on_ingresar_nombre_empleado_caja_changed(GtkEntry *e) {
                const char *nombre = gtk_entry_get_text(e);
                strncpy(nueva_caja.nombre_responsable, nombre, MAX_LENGTH - 1);
                nueva_caja.nombre_responsable[MAX_LENGTH - 1] = '\0';
            }

            void on_ingresar_num_caja_changed(GtkEntry *e) {
                const char *num_caja = gtk_entry_get_text(e);
                nueva_caja.numero_caja = atoi(num_caja);
            }

            // Callback del botón "Agregar Caja"
            void on_boton_agregar_caja_clicked(GtkButton *button, gpointer user_data) {
                FILE *archivo_cajas = fopen("cajas.dat", "rb+");
                if (archivo_cajas == NULL) {
                    archivo_cajas = fopen("cajas.dat", "wb+");
                    if (archivo_cajas == NULL) {
                        printf("ERROR, NO SE PUDO ABRIR O CREAR EL ARCHIVO DE CAJAS\n\n");
                        return;
                    }
                }

                Caja nueva_caja;

                nueva_caja.numero_caja = atoi(gtk_entry_get_text(GTK_ENTRY(ingresar_num_caja)));
                nueva_caja.numero_empleado = atoi(gtk_entry_get_text(GTK_ENTRY(ingresar_num_empleado_caja)));
                strcpy(nueva_caja.nombre_responsable, gtk_entry_get_text(GTK_ENTRY(ingresar_nombre_empleado_caja)));

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

                fseek(archivo_cajas, 0, SEEK_END);
                fwrite(&nueva_caja, sizeof(Caja), 1, archivo_cajas);
                fclose(archivo_cajas);

                printf("NUEVA CAJA CREADA\n\n");
            }


            void on_boton_salir_crear_caja_clicked( GtkButton *b){
                gtk_widget_show_all(ventana_menu_caja);
                gtk_widget_hide(ventana_crear_caja);
            }



            //ELIMINAR CAJA
            int numero_caja_eliminar = 0;
            void on_boton_eliminar_caja_clicked(GtkButton *button, gpointer user_data) {
                gtk_widget_show_all(ventana_eliminarcaja);
            }

            void on_boton_eliminar_caj_clicked(GtkButton *b, gpointer user_data) {
                // Usamos la variable global 'numero_caja_eliminar' que ya tiene el valor actualizado
                eliminar_caja(numero_caja_eliminar);  // Llamar a la función para eliminar la caja
            }

            void on_ingresar_numcaja_eliminar_changed(GtkEntry *e) {
                const char *num_caja = gtk_entry_get_text(e);
                numero_caja_eliminar = atoi(num_caja);  // Almacenar el número de caja
            }
            void on_boton_salir_eliminar_caja_clicked(GtkButton *b) {
                gtk_widget_show_all(ventana_menu_caja);
                gtk_widget_hide(ventana_eliminarcaja);
            }


        //GESTION DE EMPLEADOS
        void on_boton_mostrar_empleado_clicked(GtkButton *b){
            // Mostrar la ventana de empleados y ocultar el menú de administrador
            gtk_widget_show_all(venta_mostrar_empleados);
            gtk_widget_hide(ventana_menu_admin);

            // Llamar a la función para mostrar los empleados en el GtkTextView
            mostrarEmpleados(GTK_TEXT_VIEW(text_mostrar_empleados));
        }
        void on_boton_modificar_empleado_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_modificar_empleado_cedula);
            gtk_widget_hide(ventana_menu_admin);
        }
        void on_boton_eliminar_empleado_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_eliminar_empleado_cedula);
            gtk_widget_hide(ventana_gestion_empleados);
        }
        void on_boton_cantidad_empleado_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_cantidad_empleados);
            int cantidad = cantidad_de_empleados();

            // Verificar si hubo un error al abrir el archivo
            if (cantidad == -1) {
                gtk_label_set_text(GTK_LABEL(label_cant_empleados), "Error al abrir el archivo de empleados");
                return;
            }

            // Mostrar la cantidad de empleados en el GtkLabel
            char mensaje[50];
            snprintf(mensaje, sizeof(mensaje), "Cantidad de empleados: %d", cantidad);
            gtk_label_set_text(GTK_LABEL(label_cant_empleados), mensaje);

        }
        void on_boton_salir_gestionempleados_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_menu_admin);
            gtk_widget_hide(ventana_gestion_empleados);
            gtk_widget_hide(ventana_modificar_empleado_cedula);
            gtk_widget_hide(ventana_cantidad_empleados);
        }
        //ELIMINAR EMPLEADO
        void on_boton_salir_eliminarempleado_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_gestion_empleados);
            gtk_widget_hide(ventana_eliminar_empleado_cedula);
        }
        void on_boton_buscar_empleado_eliminar_clicked(GtkButton *b){
            const char *cedula = u.cedula;
            eliminarEmpleado(cedula);
            gtk_widget_show_all(ventana_gestion_empleados);
            gtk_widget_hide(ventana_eliminar_empleado_cedula);
        }
        void on_ingresar_cedula_eliminar_empleado_changed(GtkEntry *e){
                    strncpy(u.cedula, gtk_entry_get_text(e), MAX_LENGTH-1);
                }



        //modificar empleado
        void buscarEmpleadoPorCedula(const char *cedula) {
                FILE *archivo_empleados = fopen("empleados.txt", "r");
                if (archivo_empleados == NULL) {
                    printf("Error al abrir el archivo de empleados.\n");
                    return;
                }

                Usuario empleado;
                int encontrado = 0;

                while (fscanf(archivo_empleados, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                              empleado.nombre, empleado.apellido, empleado.usuario, empleado.password,
                              empleado.direccion, empleado.telefono, empleado.cedula, empleado.pregunta, empleado.respuesta) != EOF) {
                    if (strcmp(empleado.cedula, cedula) == 0) {
                        encontrado = 1;
                        break; // Empleado encontrado
                    }
                }

                fclose(archivo_empleados);

                if (encontrado) {
                    // Abrir la ventana de modificar empleado
                    gtk_widget_show_all(ventana_modificar_empleado);
                    gtk_widget_hide(ventana_modificar_empleado_cedula);
                } else {
                    gtk_label_set_text(GTK_LABEL(label_noencontrado),"Error, empleado no encontrado" );
                }
            }

                //MODIFICAR EMPLEADO
                //primera ventana cedula

                void on_ingresar_cedula_modificar_empleado_changed(GtkEntry *e){
                    strncpy(u.cedula, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_boton_salir_modificarempleado_clicked(GtkButton *b){
                    gtk_widget_show_all(ventana_gestion_empleados);
                    gtk_widget_hide(ventana_modificar_empleado_cedula);
                }
                void on_boton_buscar_empleado_clicked(GtkButton *b){
                    // Obtener la cédula ingresada en el GtkEntry
                    const char *cedula = u.cedula;

                    // Validar que la cédula no esté vacía
                    if (strlen(cedula) == 0) {
                        gtk_label_set_text(GTK_LABEL(label_noencontrado),"Error, rellenar campo" );
                        return;
                    }

                    // Buscar la cédula en el archivo de empleados
                    buscarEmpleadoPorCedula(cedula);
                }

                //segunda ventana modificar
                void on_ingresar_nombre_admin1_changed(GtkEntry *e){
                    strncpy(u.nombre, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_apellido_admin1_changed(GtkEntry *e){
                    strncpy(u.apellido, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_direccion_admin1_changed(GtkEntry *e){
                    strncpy(u.direccion, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_tlf_admin1_changed(GtkEntry *e){
                    strncpy(u.telefono, gtk_entry_get_text(e), MAX_LENGTH-1);
                    if(esNumero(u.telefono) == 0){
                            gtk_label_set_text(GTK_LABEL(err_tlf),"En este campo no se permiten letras");
                    }
                    else {
                            gtk_label_set_text(GTK_LABEL(err_tlf), "");
                    }
                }
                void on_ingresar_cedula_admin1_changed(GtkEntry *e){
                    strncpy(u.cedula, gtk_entry_get_text(e), MAX_LENGTH-1);
                    if(esNumero(u.cedula) == 0){
                            gtk_label_set_text(GTK_LABEL(err_cedula),"En este campo no se permiten letras");
                    }
                    else {
                            gtk_label_set_text(GTK_LABEL(err_cedula), "");
                    }
                }
                void on_ingresar_usuario_admin1_changed(GtkEntry *e){
                    strncpy(u.usuario, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_contra_admin1_changed(GtkEntry *e){
                    strncpy(u.password, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_preg_admin1_changed(GtkEntry *e){
                    strncpy(u.pregunta, gtk_entry_get_text(e), MAX_LENGTH-1);
                }
                void on_ingresar_respt_admin1_changed(GtkEntry *e){
                    strncpy(u.respuesta, gtk_entry_get_text(e), MAX_LENGTH-1);
                }

                // BOTON CONFIRMAR REGISTRAR DATOS
                void on_boton_registrardatos1_clicked(GtkButton *b){
                    err = 0;  // Reiniciar el contador de errores

                    if (u.nombre[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_nombre1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_nombre1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.apellido[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_apellido1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_apellido1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.direccion[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_direccion1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_direccion1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }


                    if (u.telefono[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_tlf1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_tlf1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.usuario[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_usuario1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_usuario1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.password[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_contra1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_contra1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.respuesta[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_respt1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_respt1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }

                    if (u.pregunta[0] == '\0') {
                        gtk_label_set_text(GTK_LABEL(err_preg1), "Rellenar campo");
                        err++;
                    } else {
                        gtk_label_set_text(GTK_LABEL(err_preg1), "");  // Limpiar mensaje de error si el campo est� lleno
                    }
                    if(err == 0){
                            // Llamar a la función modificarEmpleado con los datos de los GtkEntry
                            modificarEmpleado(u.cedula, u.nombre, u.apellido, u.direccion, u.telefono,
                            u.usuario, u.password, u.pregunta, u.respuesta);
                            gtk_widget_show_all(ventana_gestion_empleados);
                            gtk_widget_hide(ventana_modificar_empleado);
                            gtk_widget_hide(ventana_modificar_empleado_cedula);
                    }else gtk_label_set_text(GTK_LABEL(err_espaciovacio),"Error, rellenar todos los campos correctamente");
                }

                // BOTON SALIR REGISTRO

                void on_salir_ingresardatos1_clicked(GtkButton *b){
                    gtk_widget_show_all(ventana_menu_admin);
                    gtk_widget_hide(ventana_modificar_empleado);
                }











        //MENU INVENTARIO
        void on_boton_agregar_producto_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_agregar_producto);
            gtk_widget_hide(ventana_inventario);
        }
        void on_boton_consultar_inventario_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_consultar_invt);
            gtk_widget_hide(ventana_inventario);
        }
        void on_boton_salir_inventario_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_menu_admin);
            gtk_widget_hide(ventana_inventario);
        }
            //AGREGAR PRODUCTO
            Producto producto;
            void on_ingresar_nombreprod_changed(GtkEntry *e) {
                const gchar *nombre = gtk_entry_get_text(e);
                if (nombre != NULL) {
                    strncpy(producto.nombre, nombre, MAX_LENGTH - 1);
                    producto.nombre[MAX_LENGTH - 1] = '\0';  // Asegurar terminación nula
                }
            }

            // Función para manejar el cambio en el campo de precio
            void on_ingresar_precioprod_changed(GtkEntry *e) {
                const gchar *precio_text = gtk_entry_get_text(e);
                if (precio_text != NULL) {
                    producto.precioUSD = atof(precio_text);
                }
            }
            void on_boton_aceptarguardarproducto_clicked(GtkButton *button, gpointer user_data) {
                // Obtener el segmento seleccionado
                const gchar *segmento = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combotext_agregarinventario));
                if (segmento == NULL) {
                    g_print("Error: No se selecciono un segmento.\n");
                    return;
                }

                // Obtener la cantidad del spin button
                int cantidad = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_cantprod));

                // Validar que el precio sea un n�mero decimal positivo
                if (producto.precioUSD <= 0) {
                    g_print("Error: El precio debe ser un n�mero decimal positivo. Valor ingresado: %lf\n", producto.precioUSD);
                    return;
                }

                // Llamar a la funci�n para agregar el producto
                agregarProductoPorSegmento(segmento, cantidad, producto);

                // Ocultar la ventana actual y mostrar la ventana de inventario
                gtk_widget_hide(ventana_agregar_producto);
                gtk_widget_show_all(ventana_inventario);
            }

            // "Salir"
            void on_boton_salirguardarproducto_clicked(GtkButton *button) {
                gtk_widget_hide(ventana_agregar_producto);
                gtk_widget_show_all(ventana_menu_admin);
            }
            //CONSULTAR INVENTARIO
            void on_licores_clicked(GtkButton *b) {
                // Mostrar la ventana de consultar inventario
                gtk_widget_show_all(ventana_consultar_invt_producto);

                // Consultar el segmento "licores" en el GtkTextView "text_consultainvt"
                consultarSegmentoPorArchivo(GTK_TEXT_VIEW(text_consultainvt), "Licores");
            }

            void on_hortalizas_clicked(GtkButton *b) {
                gtk_widget_show_all(ventana_consultar_invt_producto);
                consultarSegmentoPorArchivo(GTK_TEXT_VIEW(text_consultainvt), "Hortalizas");
            }

            void on_charcuteria_clicked(GtkButton *b) {
                gtk_widget_show_all(ventana_consultar_invt_producto);
                consultarSegmentoPorArchivo(GTK_TEXT_VIEW(text_consultainvt), "Charcuteria");
            }

            void on_varios_clicked(GtkButton *b) {
                gtk_widget_show_all(ventana_consultar_invt_producto);
                consultarSegmentoPorArchivo(GTK_TEXT_VIEW(text_consultainvt), "Varios");
            }
            void on_salir_menu_consultainvt_clicked(GtkButton *b) {
                gtk_widget_hide(ventana_consultar_invt);
                gtk_widget_hide(ventana_consultar_invt_producto);
                gtk_widget_show_all(ventana_inventario);
            }

// ====================================================================
// ================= MENU EMPLEADO CAJA ===============================
void on_boton_salir_menuempleado_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_menu_principal);
    gtk_widget_hide(ventana_menuempleado);
}

void on_boton_modificar_tasas_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_tasas);
    gtk_widget_hide(ventana_menuempleado);
}

void on_boton_imprimir_factura_clicked(GtkButton *b) {
    gtk_widget_show_all(ventana_mostrar_cajas);

    imprimirFactura(text_mostrar_cajas);
}

void on_boton_venta_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_procesarcompra_enter);
    gtk_widget_hide(ventana_menuempleado);
}

void on_boton_registrar_cliente_clicked(GtkButton *b){
    gtk_widget_show_all(ventana_registrar_cliente);
    gtk_widget_hide(ventana_menuempleado);
}

        // ================= VENTANA TASA DEL DIA =================
        //entrys
        void on_ingresar_bs_changed(GtkEntry *e) {
            char text[MAX_LENGTH];
            strncpy(text, gtk_entry_get_text(e), MAX_LENGTH-1);
            tasa_bs = atof(text); // Convertir el texto a double
        }

        void on_ingresar_peso_colombiano_changed(GtkEntry *e) {
            char text[MAX_LENGTH];
            strncpy(text, gtk_entry_get_text(e), MAX_LENGTH-1);
            tasa_pesos = atof(text); // Convertir el texto a double
        }
        void on_ingresar_euros_changed(GtkEntry *e) {
            char text[MAX_LENGTH];
            strncpy(text, gtk_entry_get_text(e), MAX_LENGTH-1);
            tasa_euros = atof(text); // Convertir el texto a double
        }
        void on_boton_aceptar_tasa_clicked(GtkButton *b){
            FILE *archivo_cajas = fopen("cajas.dat", "rb+");
            if (archivo_cajas == NULL) {
                archivo_cajas = fopen("cajas.dat", "wb+");
                if (archivo_cajas == NULL) {
                    printf("ERROR, NO SE PUDO ABRIR O CREAR EL ARCHIVO DE CAJAS\n\n");
                    return;
                }
            }

            modificar_tasas(tasa_bs,tasa_pesos,tasa_euros);

            //gtk_widget_show_all(ventana_menuempleado);
            //gtk_widget_hide(ventana_tasas);
        }
        void on_boton_salir_tasa_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_menuempleado);
            gtk_widget_hide(ventana_tasas);
        }


        // ================= REGISTRAR CLIENTE =================
        Cliente c;

        void on_ingresar_nombrecliente_changed (GtkEntry *e){
            strncpy(c.nombres_cliente, gtk_entry_get_text(e), MAX_LENGTH-1);
        }
        void on_ingresar_apellidocliente_changed(GtkEntry *e){
            strncpy(c.apellido_cliente, gtk_entry_get_text(e), MAX_LENGTH-1);
        }
        void on_ingresar_tlfcliente_changed(GtkEntry *e){
            strncpy(c.telefono_cliente, gtk_entry_get_text(e), 20);
        }
        void on_ingresar_cedulacliente_changed(GtkEntry *e){
            char cedula[MAX_LENGTH];
            strncpy(cedula, gtk_entry_get_text(e), MAX_LENGTH-1);
            c.cedula_cliente = atoi(cedula);
        }
        void on_ingresar_direccioncliente_changed(GtkEntry *e) {
            strncpy(c.direccion_cliente, gtk_entry_get_text(e), MAX_LENGTH - 1);
            c.direccion_cliente[MAX_LENGTH - 1] = '\0'; // Asegúrate de que la cadena esté terminada correctamente
            g_print("Dirección ingresada: %s\n", c.direccion_cliente); // Depuración
        }
        void on_boton_salir_registrocliente_clicked(GtkButton *b){
            gtk_widget_show_all(ventana_menuempleado);
            gtk_widget_hide(ventana_registrar_cliente);
        }
        void on_boton_aceptar_registrocliente_clicked(GtkButton *b){
            FILE *f = fopen("datos_cliente.txt", "a+");
            if (f == NULL) {
                printf("Error al abrir el archivo.\n");
            }


            guardar_cliente(&c, f);
            fclose(f);
            gtk_widget_show_all(ventana_menuempleado);
            gtk_widget_hide(ventana_registrar_cliente);
        }

        //PROCESAR UNA COMPRA

        void on_ingresar_num_caja1_changed(GtkEntry *e) {
            const char *texto = gtk_entry_get_text(e);
            numero_caja = atoi(texto);

            // Validar que el texto ingresado sea un número
            if (!esNumero(texto)) {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), "No se aceptan letras en el número de caja.");
            } else {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), ""); // Limpiar error si es un número
            }
        }
        void on_ingresar_num_empleado_caja1_changed(GtkEntry *e) {
            const char *texto = gtk_entry_get_text(e);
            numero_empleado = atoi(texto);

            // Validar que el texto ingresado sea un número
            if (!esNumero(texto)) {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), "No se aceptan letras en el número de empleado.");
            } else {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), ""); // Limpiar error si es un número
            }
        }

        void on_boton_procesarcompra_enter_clicked(GtkButton *b) {
            // Obtener los valores de los Entry
            const char *texto_num_caja = gtk_entry_get_text(GTK_ENTRY(ingresar_num_caja1));
            const char *texto_num_empleado = gtk_entry_get_text(GTK_ENTRY(ingresar_num_empleado_caja1));

            // Verificar que los valores sean números
            if (!esNumero(texto_num_caja) || !esNumero(texto_num_empleado)) {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), "No se aceptan letras.");
                return;
            }

            // Convertir los valores de texto a enteros
            int numero_caja = atoi(texto_num_caja);
            int numero_empleado = atoi(texto_num_empleado);

            // Abrir el archivo de cajas para leer
            FILE *archivo_cajas = fopen("cajas.dat", "rb");
            if (archivo_cajas == NULL) {
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), "Error al abrir el archivo de cajas.");
                return;
            }

            Caja caja;
            int encontrado = 0;

            // Leer el archivo y buscar la caja y el empleado
            while (fread(&caja, sizeof(Caja), 1, archivo_cajas) == 1) {
                if (caja.numero_caja == numero_caja && caja.numero_empleado == numero_empleado) {
                    encontrado = 1;
                    break; // Encontramos el registro
                }
            }

            fclose(archivo_cajas);

            if (encontrado) {
                // Si la caja y el empleado existen, cerramos la ventana actual y mostramos la siguiente
                gtk_widget_hide(ventana_procesarcompra_enter); // Ocultar ventana actual
                gtk_widget_show(ventana_cedula_cliente); // Mostrar la ventana de ventas
            } else {
                // Si no se encuentra la caja o el empleado
                gtk_label_set_text(GTK_LABEL(label_err_procesarcompraenter), "Caja o empleado no encontrados.");
            }
        }
        void on_boton_salir_procesarcompra_enter_clicked(GtkButton *b){
            gtk_widget_hide(ventana_procesarcompra_enter);
            gtk_widget_show(ventana_menuempleado);
        }

        //cedula
        void on_ingresarcedula_changed(GtkEntry *e) {
            const char *cedula_texto = gtk_entry_get_text(GTK_ENTRY(e));
            cedula_cliente = atoi(cedula_texto);

            // Verificar si la cédula ingresada es un número
            if (!esNumero(cedula_texto)) {
                // Si no es un número, mostrar un mensaje de error en el label
                gtk_label_set_text(GTK_LABEL(label_errcedula), "Cédula inválida. Solo se permiten números.");
            } else {
                // Limpiar el mensaje de error si la cédula es un número
                gtk_label_set_text(GTK_LABEL(label_errcedula), "");
            }
        }
        void on_boton_salir_procesarcompra_enter2_clicked(GtkButton *b){
            gtk_widget_hide(ventana_cedula_cliente);
            gtk_widget_show(ventana_menuempleado);
        }
        void on_boton_procesarcompra_enter2_clicked(GtkButton *b) {
            const char *cedula_texto = gtk_entry_get_text(GTK_ENTRY(ingresarcedula));

            // Verificar que la cédula sea un número
            if (!esNumero(cedula_texto)) {
                gtk_label_set_text(GTK_LABEL(label_errcedula), "Cédula inválida. Solo se permiten números.");
                return;
            }

            int cedula_cliente = atoi(cedula_texto);  // Convertir la cédula a un número entero
            FILE *archivo_clientes = fopen("datos_cliente.txt", "r");
            if (archivo_clientes == NULL) {
                perror("Error al abrir archivo de clientes");
                gtk_label_set_text(GTK_LABEL(label_errcedula), "Error al abrir archivo de clientes.");
                return;
            }
            // Verificar si la cédula está registrada
            if (verificar_clientes_existente(archivo_clientes, cedula_cliente)) {
                // Si el cliente existe, esconder la ventana de cédula y mostrar la ventana de venta
                gtk_widget_hide(ventana_cedula_cliente);  // Esconder ventana de cédula
                gtk_widget_show(ventana_menu_venta);     // Mostrar ventana de venta
            } else {
                // Si no está registrado, mostrar mensaje de error en el label
                gtk_label_set_text(GTK_LABEL(label_errcedula), "Cédula no encontrada. Registre al cliente primero.");
            }

            fclose(archivo_clientes);
        }


        // ================= MENU VENTA PROD =====================================================
            void on_boton_agregar_al_carrito_clicked(GtkButton){
                gtk_widget_hide(ventana_menu_venta);
                gtk_widget_show(ventana_agregar_carrito);
            }
            void on_boton_mostrar_carrito_clicked(GtkButton *button) {

                // Mostrar la ventana de consulta
                gtk_widget_show(ventana_ventas_consulta);

                // Mostrar el contenido del carrito en el GtkTextView
                mostrarcarrito(tasabolivares, tasaeuros, tasapesoscolombianos, GTK_TEXT_VIEW(text_mostrar_ventas));
            }
            void on_boton_oficializar_venta_clicked(GtkButton *button) {
                // Ocultar la ventana actual
                gtk_widget_hide(ventana_ventas_consulta);
                gtk_widget_show(ventana_mostrar_cajas);

                // Llamar a la función oficializarventa y mostrar la información en el GtkTextView
                oficializarventa(cedula_cliente, numero_caja, numero_empleado, GTK_TEXT_VIEW(text_mostrar_cajas));
            }


            void on_salir_menu_venta_clicked(GtkButton){
                gtk_widget_hide(ventana_menu_venta);
                gtk_widget_show(ventana_menuempleado);
            }


        //agregar prod a carrito

        void on_combotext_agregar_carrito_changed(GtkComboBoxText *combobox) {
            // Obtener el segmento seleccionado
            const char *segmento = gtk_combo_box_text_get_active_text(combobox);

            // Mostrar los productos del segmento en el GtkTextView
            consultarSegmentoPorArchivo(GTK_TEXT_VIEW(text_mostrar_prod), segmento);
        }
        int es_codigo_valido(const char *codigo) {
            return strlen(codigo) > 0;
        }

        void on_ingresar_cod_producto_changed(GtkEntry *entry) {
            const char *codigo = gtk_entry_get_text(entry);
            if (!es_codigo_valido(codigo)) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Ingrese un código de producto.");
            } else {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "");
            }
        }

        void actualizar_inventario(const char *nombreArchivo, Producto *producto) {
            // Abrir el archivo para leer
            FILE *file = fopen(nombreArchivo, "r");
            if (file == NULL) {
                printf("Error al abrir el archivo de inventario.\n");
                return;
            }

            // Leer todo el archivo en memoria
            char buffer[MAX_FILE_SIZE];
            char *lineas[1000];  // Suponemos que hay máximo 1000 productos en el archivo
            int numLineas = 0;
            while (fgets(buffer, sizeof(buffer), file) != NULL && numLineas < 1000) {
                lineas[numLineas] = strdup(buffer);  // Guardar cada línea en memoria
                numLineas++;
            }
            fclose(file);

            // Buscar y modificar el producto en memoria
            int encontrado = 0;
            for (int i = 0; i < numLineas; i++) {
                Producto tempProducto;
                if (sscanf(lineas[i], "%49[^,],%49[^,],%24[^,],%d,%f\n", tempProducto.codigo, tempProducto.nombre, tempProducto.segmento, &tempProducto.cantidad, &tempProducto.precioUSD) == 5) {
                    if (strcmp(tempProducto.codigo, producto->codigo) == 0) {
                        // Si encontramos el producto, actualizamos su cantidad
                        tempProducto.cantidad = producto->cantidad;
                        // Actualizamos la línea con la nueva cantidad
                        snprintf(lineas[i], MAX_LENGTH, "%s,%s,%s,%d,%.2f\n", tempProducto.codigo, tempProducto.nombre, tempProducto.segmento, tempProducto.cantidad, tempProducto.precioUSD);
                        encontrado = 1;
                        break;
                    }
                }
            }

            if (!encontrado) {
                printf("Producto no encontrado.\n");
                return;
            }

            // Abrir el archivo nuevamente para escribir
            file = fopen(nombreArchivo, "w");
            if (file == NULL) {
                printf("Error al abrir el archivo para escritura.\n");
                return;
            }

            // Escribir todas las líneas de vuelta al archivo
            for (int i = 0; i < numLineas; i++) {
                fputs(lineas[i], file);
                free(lineas[i]);  // Liberar la memoria
            }

            fclose(file);
        }

        // Función principal para agregar el producto al carrito y actualizar inventario
        void on_boton_aceptar_compra_clicked(GtkButton *button) {
            const char *segmento = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combotext_agregar_carrito));
            const char *codigo = gtk_entry_get_text(GTK_ENTRY(ingresar_cod_producto));
            int cantidad = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_cant_prod));

            if (segmento == NULL) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Seleccione un segmento.");
                return;
            }
            if (strlen(codigo) == 0) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Ingrese un código de producto.");
                return;
            }
            if (cantidad <= 0) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "La cantidad debe ser mayor que 0.");
                return;
            }

            char nombreArchivo[MAX_LENGTH];
            obtenerNombreArchivoSegmento(segmento, nombreArchivo);

            FILE *file = fopen(nombreArchivo, "r");
            if (file == NULL) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Error al abrir el archivo de inventario.");
                return;
            }

            Producto producto;
            int encontrado = 0;
            while (fscanf(file, "%49[^,],%49[^,],%24[^,],%d,%f\n", producto.codigo, producto.nombre, producto.segmento, &producto.cantidad, &producto.precioUSD) != EOF) {
                if (strcmp(producto.codigo, codigo) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            fclose(file);

            if (!encontrado) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Producto no encontrado.");
                return;
            }

            if (cantidad > producto.cantidad) {
                gtk_label_set_text(GTK_LABEL(label_err_prod), "Cantidad insuficiente en el inventario.");
                return;
            }

            // Reducir la cantidad del producto
            producto.cantidad -= cantidad;

            // Actualizar el archivo con el nuevo inventario
            actualizar_inventario(nombreArchivo, &producto);

            // Agregar el producto al carrito
            agregarproductoalcarrito(producto, cantidad);

            // Mostrar mensaje de éxito
            gtk_label_set_text(GTK_LABEL(label_err_prod), "Producto agregado al carrito.");
        }
        void on_boton_salir_carrito_clicked(GtkButton *button) {
            gtk_widget_hide(ventana_agregar_carrito);
            gtk_widget_show(ventana_menu_venta);
        }


//cerrar ventanas
// Callback para evitar que la ventana se destruya al hacer clic en la "X"
gboolean on_ventana_agregar_producto_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_agregar_producto); // Ocultamos la ventana en lugar de destruirla
    return TRUE; // Retornamos TRUE para evitar que la ventana se destruya
}

gboolean on_venta_mostrar_empleados_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(venta_mostrar_empleados);
    return TRUE;
}

gboolean on_ventana_consultar_invt_producto_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_consultar_invt_producto);
    return TRUE;
}

gboolean on_ventana_mostrar_cajas_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_mostrar_cajas);
    return TRUE;
}

gboolean on_ventana_cantidad_empleados_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_cantidad_empleados);
    return TRUE;
}

gboolean on_ventana_consultar_invt_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_consultar_invt);
    return TRUE;
}

gboolean on_ventana_crear_caja_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_crear_caja);
    return TRUE;
}

gboolean on_ventana_eliminar_empleado_cedula_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_eliminar_empleado_cedula);
    return TRUE;
}

gboolean on_ventana_eliminarcaja_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_eliminarcaja);
    return TRUE;
}

gboolean on_ventana_menu_caja_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_menu_caja);
    return TRUE;
}

gboolean on_ventana_ventas_consulta_delete(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    gtk_widget_hide(ventana_ventas_consulta);
    return TRUE;
}



// ================= MAIN =================
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("GUI.glade");

    ventana_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_inicio"));



    box_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "box_inicio"));
    boton_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inicio"));
    boton_salir_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salida_inicio"));
    titulo = GTK_WIDGET(gtk_builder_get_object(builder, "titulo"));
    informacion_inicio = GTK_WIDGET(gtk_builder_get_object(builder, "informacion_inicio"));

    // Crear la segunda ventana, menu principal
    ventana_menu_principal = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_menu_principal"));
    box_menu_principal = GTK_WIDGET(gtk_builder_get_object(builder, "box_menu_principal"));
    regis_admin = GTK_WIDGET(gtk_builder_get_object(builder, "regis_admin"));
    inicio_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "inicio_empleado"));
    inicio_admin = GTK_WIDGET(gtk_builder_get_object(builder, "inicio_admin"));
    regis_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "regis_empleado"));
    salir_menu_principal = GTK_WIDGET(gtk_builder_get_object(builder, "salir_menu_principal"));
    recuperar_contra = GTK_WIDGET(gtk_builder_get_object(builder, "recuperar_contra"));
    label_menuprincipal = GTK_WIDGET(gtk_builder_get_object(builder, "labelmenuprincipal"));

        //RECUPERAR CONTRASENNIA
        ventana_recuperar_contra = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_recuperar_contra"));
        fixed_recuperar = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_recuperar"));
        label_titulo_recuperarcontra = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_recuperarcontra"));
        label_ingresarusuario_recuperar = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarusuario_recuperar"));
        ingresar_usuario_recuperar = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_usuario_recuperar"));
        boton_salir_recuperarcontra = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_recuperarcontra"));
        boton_buscarcontra = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscarcontra"));
        label_contrasena = GTK_WIDGET(gtk_builder_get_object(builder, "label_contrasena"));


    //Crear ventana registro de administrador
    ventana_registro_administrador = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_registro_administrador"));
    fixed_registro= GTK_WIDGET(gtk_builder_get_object(builder, "fixed_registro"));
    label_ingresarnombre= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarnombre"));
    ingresar_nombre_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_nombre_admin"));
    clear_registro_admin_nombre= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_nombre"));
    label_ingresarapellido= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarapellido"));
    ingresar_apellido_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_apellido_admin"));
    clear_registro_admin_apellido= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_apellido"));
    label_ingresardireccion= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresardireccion"));
    ingresar_direccion_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_direccion_admin"));
    clear_registro_admin_direccion= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_direccion"));
    label_ingresartlf= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresartlf"));
    ingresar_tlf_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_tlf_admin"));
    clear_registro_admin_telefono= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_telefono"));
    label_ingresarcedula= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarcedula"));
    ingresar_cedula_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_cedula_admin"));
    clear_registro_admin_cedula= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_cedula"));
    label_ingresarpregunta= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarpregunta"));
    ingresar_usuario_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_usuario_admin"));
    clear_registro_admin_usuario= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_usuario"));
    label_ingresarusuario= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarusuario"));
    ingresar_preg_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_preg_admin"));
    clear_registro_admin_respt= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_respt"));
    label_ingresarrespuesta= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarrespuesta"));
    ingresar_respt_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_respt_admin"));
    clear_registro_admin_preg= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_preg"));
    label_ingresarcontra= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarcontra"));
    ingresar_contra_admin= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_contra_admin"));
    clear_registro_admin_contra= GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_contra"));
    salir_ingresardatos= GTK_WIDGET(gtk_builder_get_object(builder, "salir_ingresardatos"));
    boton_registrardatos= GTK_WIDGET(gtk_builder_get_object(builder, "boton_registrardatos"));
    err_cedula= GTK_WIDGET(gtk_builder_get_object(builder, "err_cedula"));
    err_tlf= GTK_WIDGET(gtk_builder_get_object(builder, "err_tlf"));
    err_usuario= GTK_WIDGET(gtk_builder_get_object(builder, "err_usuario"));
    err_contra= GTK_WIDGET(gtk_builder_get_object(builder, "err_contra"));
    err_respt= GTK_WIDGET(gtk_builder_get_object(builder, "err_respt"));
    err_preg= GTK_WIDGET(gtk_builder_get_object(builder, "err_preg"));
    err_direccion= GTK_WIDGET(gtk_builder_get_object(builder, "err_direccion"));
    err_apellido= GTK_WIDGET(gtk_builder_get_object(builder, "err_apellido"));
    err_nombre= GTK_WIDGET(gtk_builder_get_object(builder, "err_nombre"));
    err_espaciovacio= GTK_WIDGET(gtk_builder_get_object(builder, "err_espaciovacio"));

    //CREAR MENU ADMIN
    ventana_menu_admin = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_menu_admin"));
    box_menu_admin = GTK_WIDGET(gtk_builder_get_object(builder, "box_menu_admin"));
    label_titulo_menu_admin = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_menu_admin"));
    boton_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "boton_inventario"));
    boton_gestionar_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "boton_gestionar_empleados"));
    boton_gestionar_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_gestionar_caja"));
    boton_gestionar_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_gestionar_ventas"));
    boton_gestionar_clientes = GTK_WIDGET(gtk_builder_get_object(builder, "boton_gestionar_clientes"));
    boton_mostrar_admin_registrados = GTK_WIDGET(gtk_builder_get_object(builder, "boton_mostrar_admin_registrados"));
    boton_salir_menu_admin = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_menu_admin"));

        //MENU VENTAS
        ventana_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ventas"));
        box_menu_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "box_menu_ventas"));
        label_titulo_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_ventas"));
        boton_ventas_diaria = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ventas_diaria"));
        boton_ventas_mensuales_porcaja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ventas_mensuales_porcaja"));
        boton_ventas_total_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "boton_ventas_total_mensuales"));
        boton_mostrar_facturas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_mostrar_facturas"));
        boton_salir_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_ventas"));

            //VENTAS MENSUALES TOTALES
            ventana_ventas_mensuales_super = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ventas_mensuales_super"));
            fixed_ventas_mensuales_super = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_ventas_mensuales_super"));
            label_titulo_ventas_mensuales_super = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_ventas_mensuales_super"));
            spin_mes_venta_super = GTK_WIDGET(gtk_builder_get_object(builder, "spin_mes_venta_super"));
            label_ingresar_mes_super = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_mes_super"));
            boton_buscar_ventas_mensuales_super = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscar_ventas_mensuales_super"));
            boton_salir_ventas_mensuales_super = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_ventas_mensuales_super"));

            // VENTAS MENSUALES
            ventana_ventas_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ventas_mensuales"));
            fixed_ventas_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_ventas_mensuales"));
            label_titulo_ventas_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_ventas_mensuales"));
            ingresar_num_caja_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_caja_mensuales"));
            label_num_caja1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_num_caja1"));
            spin_mes_venta1 = GTK_WIDGET(gtk_builder_get_object(builder, "spin_mes_venta1"));
            label_ingresar_mes1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_mes1"));
            boton_buscar_ventas_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscar_ventas_mensuales"));
            boton_salir_ventas_mensuales = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_ventas_mensuales"));

            //VENTAS DIARIAS
            ventana_ventas_diarias = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ventas_diarias"));
            fixed_ventas_diarias = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_ventas_diarias"));
            label_titulo_ventas_diarias = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_ventas_diarias"));
            ingresar_num_caja_ventasd = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_caja_ventasd"));
            label_num_caja = GTK_WIDGET(gtk_builder_get_object(builder, "label_num_caja"));
            spin_dia_venta = GTK_WIDGET(gtk_builder_get_object(builder, "spin_dia_venta"));
            label_ingresar_dia = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_dia"));
            spin_mes_venta = GTK_WIDGET(gtk_builder_get_object(builder, "spin_mes_venta"));
            label_ingresar_mes = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_mes"));
            boton_buscar_ventas_diarias = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscar_ventas_diarias"));
            boton_salir_ventas_diarias = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_ventas_diarias"));

            //MOSTRAR VENTAS
            ventana_ventas_consulta = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_ventas_consulta"));
            scrolledwindow_mostrar_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow_mostrar_ventas"));
            viewport_mostrar_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "viewport_mostrar_ventas"));
            box_mostrar_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "box_mostrar_ventas"));
            text_mostrar_ventas = GTK_WIDGET(gtk_builder_get_object(builder, "text_mostrar_ventas"));


        //GESTION CAJA
        ventana_menu_caja = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_menu_caja"));
        box_menu_caja = GTK_WIDGET(gtk_builder_get_object(builder, "box_menu_caja"));
        label_menu_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "label_menu_cajas"));
        boton_crear_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_crear_caja"));
        boton_eliminar_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_eliminar_caja"));
        boton_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_mostrar_cajas"));
        salir_menu_caja = GTK_WIDGET(gtk_builder_get_object(builder, "salir_menu_caja"));
            //CREAR CAJA
            ventana_crear_caja = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_crear_caja"));
            fixed_crear_caja = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_crear_caja"));
            label_numero_caja = GTK_WIDGET(gtk_builder_get_object(builder, "label_numero_caja"));
            ingresar_num_caja = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_caja"));
            label_titulo_crear_caja = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_crear_caja"));
            label_numero_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "label_numero_empleado"));
            label_nombre_encargado = GTK_WIDGET(gtk_builder_get_object(builder, "label_nombre_encargado"));
            boton_agregar_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_agregar_caja"));
            boton_salir_crear_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_crear_caja"));
            ingresar_num_empleado_caja = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_empleado_caja"));
            ingresar_nombre_empleado_caja = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_nombre_empleado_caja"));

            //ELIMINAR CAJA
            ventana_eliminarcaja = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_eliminarcaja"));
            boton_eliminar_caj = GTK_WIDGET(gtk_builder_get_object(builder, "boton_eliminar_caj"));
            fixed_eliminarcaja = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_eliminarcaja"));
            label_eliminar_caja = GTK_WIDGET(gtk_builder_get_object(builder, "label_eliminar_caja"));
            ingresar_numcaja_eliminar = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_numcaja_eliminar"));
            boton_salir_eliminar_caja = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_eliminar_caja"));
            label_titulo_eliminarcaja = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_eliminarcaja"));

            //MOSTRAR CAJAS
            ventana_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_mostrar_cajas"));
            scrolledwindow_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow_mostrar_cajas"));
            viewport_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "viewport_mostrar_cajas"));
            box_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "box_mostrar_cajas"));
            text_mostrar_cajas = GTK_WIDGET(gtk_builder_get_object(builder, "text_mostrar_cajas"));


        //GESTION DE EMPLEADOS
        ventana_gestion_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_gestion_empleados"));
        box_gestion_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "box_gestion_empleados"));
        label_titulo_gestionempleados = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_gestionempleados"));
        boton_mostrar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_mostrar_empleado"));
        boton_modificar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_modificar_empleado"));
        boton_eliminar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_eliminar_empleado"));
        boton_cantidad_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_cantidad_empleado"));
        boton_salir_gestionempleados = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_gestionempleados"));

            //CANTIDAD DE EMPLEADOS
            ventana_cantidad_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_cantidad_empleados"));
            box_cant_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "box_cant_empleados"));
            label_cant_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "label_cant_empleados"));

            //ELIMINAR EMPLEADO
            ventana_eliminar_empleado_cedula = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_eliminar_empleado_cedula"));
            fixed_eliminar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_eliminar_empleado"));
            label_eliminarempleado_ingresarcedula = GTK_WIDGET(gtk_builder_get_object(builder, "label_eliminarempleado_ingresarcedula"));
            ingresar_cedula_eliminar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_cedula_eliminar_empleado"));
            label_ingresar_cedula_eliminar = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_cedula_eliminar"));
            boton_salir_eliminarempleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_eliminarempleado"));
            boton_buscar_empleado_eliminar = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscar_empleado_eliminar"));
            label_noencontrado_eliminar = GTK_WIDGET(gtk_builder_get_object(builder, "label_noencontrado_eliminar"));

            //MODIFICAR EMPLEADO
            //primera ventana
            ventana_modificar_empleado_cedula = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_modificar_empleado_cedula"));
            fixed_modificar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_modificar_empleado"));
            label_noencontrado = GTK_WIDGET(gtk_builder_get_object(builder, "label_noencontrado"));
            label_modificarempleado_ingresarcedula = GTK_WIDGET(gtk_builder_get_object(builder, "label_modificarempleado_ingresarcedula"));
            label_ingresar_cedula = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_cedula"));
            ingresar_cedula_modificar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_cedula_modificar_empleado"));
            boton_salir_modificarempleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_modificarempleado"));
            boton_buscar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_buscar_empleado"));
            //segunda ventana
            ventana_modificar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_modificar_empleado"));
            fixed_registro1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_registro1"));
            label_ingresarnombre1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarnombre1"));
            ingresar_nombre_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_nombre_admin1"));
            clear_registro_admin_nombre1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_nombre1"));
            label_ingresarapellido1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarapellido1"));
            ingresar_apellido_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_apellido_admin1"));
            clear_registro_admin_apellido1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_apellido1"));
            label_ingresardireccion1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresardireccion1"));
            ingresar_direccion_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_direccion_admin1"));
            clear_registro_admin_direccion1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_direccion1"));
            label_ingresartlf1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresartlf1"));
            ingresar_tlf_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_tlf_admin1"));
            clear_registro_admin_telefono1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_telefono1"));
            label_ingresarpregunta1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarpregunta1"));
            ingresar_usuario_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_usuario_admin1"));
            clear_registro_admin_usuario1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_usuario1"));
            label_ingresarusuario1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarusuario1"));
            ingresar_preg_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_preg_admin1"));
            clear_registro_admin_respt1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_respt1"));
            label_ingresarrespuesta1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarrespuesta1"));
            ingresar_respt_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_respt_admin1"));
            clear_registro_admin_preg1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_preg1"));
            label_ingresarcontra1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarcontra1"));
            ingresar_contra_admin1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_contra_admin1"));
            clear_registro_admin_contra1 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_contra1"));
            salir_ingresardatos1 = GTK_WIDGET(gtk_builder_get_object(builder, "salir_ingresardatos1"));
            boton_registrardatos1 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_registrardatos1"));
            err_tlf1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_tlf1"));
            err_usuario1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_usuario1"));
            err_contra1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_contra1"));
            err_respt1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_respt1"));
            err_preg1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_preg1"));
            err_direccion1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_direccion1"));
            err_apellido1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_apellido1"));
            err_nombre1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_nombre1"));
            err_espaciovacio1 = GTK_WIDGET(gtk_builder_get_object(builder, "err_espaciovacio1"));



            //MOSTRAR EMPLEADO
            venta_mostrar_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "venta_mostrar_empleados"));
            scrolledwindow_mostrar_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow_mostrar_empleados"));
            viewport_mostrar_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "viewport_mostrar_empleados"));
            box_mostrar_empleado = GTK_WIDGET(gtk_builder_get_object(builder, "box_mostrar_empleado"));
            text_mostrar_empleados = GTK_WIDGET(gtk_builder_get_object(builder, "text_mostrar_empleados"));




        //MENU INVENTARIO
        ventana_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_inventario"));
        box_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "box_inventario"));
        label_titulo_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_inventario"));
        boton_agregar_producto = GTK_WIDGET(gtk_builder_get_object(builder, "boton_agregar_producto"));
        boton_consultar_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "boton_consultar_inventario"));
        boton_salir_inventario = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_inventario"));
            //INGRESAR PROD
            ventana_agregar_producto = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_agregar_producto"));
            fixed_agregar_producto = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_agregar_producto"));
            ingresar_nombreprod = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_nombreprod"));
            label_nombre_producto = GTK_WIDGET(gtk_builder_get_object(builder, "label_nombre_producto"));
            combotext_agregarinventario = GTK_WIDGET(gtk_builder_get_object(builder, "combotext_agregarinventario"));
            label_ingresar_invent = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_invent"));
            label_titulo_agregarprod = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_agregarprod"));
            label_cantprod = GTK_WIDGET(gtk_builder_get_object(builder, "label_cantprod"));
            spin_cantprod = GTK_WIDGET(gtk_builder_get_object(builder, "spin_cantprod"));
            label_precio_prod = GTK_WIDGET(gtk_builder_get_object(builder, "label_precio_prod"));
            ingresar_precioprod = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_precioprod"));
            boton_aceptarguardarproducto = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aceptarguardarproducto"));
            boton_salirguardarproducto = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salirguardarproducto"));
            // CONSULTAR INVENTARIO
            ventana_consultar_invt = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_consultar_invt"));
            box_consultainvt= GTK_WIDGET(gtk_builder_get_object(builder, "box_consultainvt"));
            label_titulo_consultainvt= GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_consultainvt"));
            licores= GTK_WIDGET(gtk_builder_get_object(builder, "licores"));
            hortalizas= GTK_WIDGET(gtk_builder_get_object(builder, "hortalizas"));
            charcuteria= GTK_WIDGET(gtk_builder_get_object(builder, "charcuteria"));
            productos_de_limpieza= GTK_WIDGET(gtk_builder_get_object(builder, "productos_de_limpieza"));
            varios= GTK_WIDGET(gtk_builder_get_object(builder, "varios"));
            salir_menu_consultainvt= GTK_WIDGET(gtk_builder_get_object(builder, "salir_menu_consultainvt"));
                //VENTANA MOSTRAR INV
                ventana_consultar_invt_producto = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_consultar_invt_producto"));
                scrolledwindow_consultarprod = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow_consultarprod"));
                viewport_consultarprod = GTK_WIDGET(gtk_builder_get_object(builder, "viewport_consultarprod"));
                box3 = GTK_WIDGET(gtk_builder_get_object(builder, "box3"));
                text_consultainvt = GTK_WIDGET(gtk_builder_get_object(builder, "text_consultainvt"));



    //CREAR MENU EMPLEADOS
    ventana_menuempleado = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_menuempleado"));
    box_menuempleado  = GTK_WIDGET(gtk_builder_get_object(builder, "box_menuempleado"));
    label_menuempleadocaja = GTK_WIDGET(gtk_builder_get_object(builder, "label_menuempleadocaja"));
    boton_modificar_tasas = GTK_WIDGET(gtk_builder_get_object(builder, "boton_modificar_tasas"));
    boton_registrar_cliente = GTK_WIDGET(gtk_builder_get_object(builder, "boton_registrar_cliente"));
    boton_imprimir_factura = GTK_WIDGET(gtk_builder_get_object(builder, "boton_imprimir_factura"));
    boton_venta = GTK_WIDGET(gtk_builder_get_object(builder, "boton_venta"));
    boton_salir_menuempleado = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_menuempleado"));

            //CREAR VENTANA DE TASA DEL DIA
            ventana_tasas = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_tasas"));
            fixed_tasas = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_tasas"));
            label_tasa = GTK_WIDGET(gtk_builder_get_object(builder, "label_tasa"));
            label_bolivares = GTK_WIDGET(gtk_builder_get_object(builder, "label_bolivares"));
            label_peso_colombiano = GTK_WIDGET(gtk_builder_get_object(builder, "label_peso_colombiano"));
            label_dolar = GTK_WIDGET(gtk_builder_get_object(builder, "label_dolar"));
            label_euros = GTK_WIDGET(gtk_builder_get_object(builder, "label_euros"));
            ingresar_bs = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_bs"));
            ingresar_dolar = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_dolar"));
            ingresar_peso_colombiano = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_peso_colombiano"));
            ingresar_euros = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_euros"));
            boton_salir_tasa = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_tasa"));
            boton_aceptar_tasa = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aceptar_tasa"));

            //PROCESAR UNA COMPRA
            ventana_procesarcompra_enter = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_procesarcompra_enter"));
            fixed_procesarcompra_enter = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_procesarcompra_enter"));
            label_err_procesarcompraenter = GTK_WIDGET(gtk_builder_get_object(builder, "label_err_procesarcompraenter"));
            label_titulo_procesarcompra_enter = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_procesarcompra_enter"));
            label_numero_empleado1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_numero_empleado1"));
            boton_procesarcompra_enter = GTK_WIDGET(gtk_builder_get_object(builder, "boton_procesarcompra_enter"));
            boton_salir_procesarcompra_enter = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_procesarcompra_enter"));
            ingresar_num_empleado_caja1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_empleado_caja1"));
            label_numero_caja1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_numero_caja1"));
            ingresar_num_caja1 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_num_caja1"));
                //reivsar ced
                ventana_cedula_cliente = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_cedula_cliente"));
                fixed_cedulacliente = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_cedulacliente"));
                label_cedcliente = GTK_WIDGET(gtk_builder_get_object(builder, "label_cedcliente"));
                ingresarcedula = GTK_WIDGET(gtk_builder_get_object(builder, "ingresarcedula"));
                boton_procesarcompra_enter2 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_procesarcompra_enter2"));
                boton_salir_procesarcompra_enter2 = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_procesarcompra_enter2"));
                label_errcedula = GTK_WIDGET(gtk_builder_get_object(builder, "label_errcedula"));
                    //ventana menu_procesar compra
                    ventana_menu_venta = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_menu_venta"));
                    box_opciones = GTK_WIDGET(gtk_builder_get_object(builder, "box_opciones"));
                    label_titulo_procesarcompra = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_procesarcompra"));
                    boton_agregar_al_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_agregar_al_carrito"));
                    boton_mostrar_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_mostrar_carrito"));
                    boton_oficializar_venta = GTK_WIDGET(gtk_builder_get_object(builder, "boton_oficializar_venta"));
                    salir_menu_venta = GTK_WIDGET(gtk_builder_get_object(builder, "salir_menu_venta"));
                            //agregar carrito
                            ventana_agregar_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_agregar_carrito"));
                            fixed_agregar_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_agregar_carrito"));
                            label_titulo_agregar_producto = GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_agregar_producto"));
                            label_select_segmento = GTK_WIDGET(gtk_builder_get_object(builder, "label_select_segmento"));
                            label_ingresar_cod_prod = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresar_cod_prod"));
                            label_err_prod = GTK_WIDGET(gtk_builder_get_object(builder, "label_err_prod"));
                            label_cant_compra = GTK_WIDGET(gtk_builder_get_object(builder, "label_cant_compra"));
                            combotext_agregar_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "combotext_agregar_carrito"));
                            ingresar_cod_producto = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_cod_producto"));
                            sub_fixed_prod = GTK_WIDGET(gtk_builder_get_object(builder, "sub_fixed_prod"));
                            scrolledwindow_mostrar_prod = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow_mostrar_prod"));
                            viewport_mostrar_prod = GTK_WIDGET(gtk_builder_get_object(builder, "viewport_mostrar_prod"));
                            box_mostrar_prod = GTK_WIDGET(gtk_builder_get_object(builder, "box_mostrar_prod"));
                            text_mostrar_prod = GTK_WIDGET(gtk_builder_get_object(builder, "text_mostrar_prod"));
                            spin_cant_prod = GTK_WIDGET(gtk_builder_get_object(builder, "spin_cant_prod"));
                            boton_aceptar_compra = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aceptar_compra"));
                            boton_salir_carrito = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_carrito"));




    //CREAR VENTANA REGISTRO DE CLIENTE
    ventana_registrar_cliente = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_registrar_cliente"));
    fixed_registro_cliente = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_registro_cliente"));
    label_titulo_registrocliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_titulo_registrocliente"));
    boton_aceptar_registrocliente= GTK_WIDGET(gtk_builder_get_object(builder, "boton_aceptar_registrocliente"));
    boton_salir_registrocliente= GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_registrocliente"));
    ingresar_nombrecliente= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_nombrecliente"));
    ingresar_apellidocliente= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_apellidocliente"));
    ingresar_tlfcliente= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_tlfcliente"));
    ingresar_direccioncliente= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_direccioncliente"));
    ingresar_cedulacliente= GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_cedulacliente"));
    label_ingresardireccion_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresardireccion_cliente"));
    label_ingresarcedula_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarcedula_cliente"));
    label_ingresarapellido_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarapellido_cliente"));
    label_ingresartelefono_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresartelefono_cliente"));
    label_ingresarnombre_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarnombre_cliente"));
    label_err_cliente= GTK_WIDGET(gtk_builder_get_object(builder, "label_err_cliente"));

    //CREAR VENTANA LOGIN
    ventana_login = GTK_WIDGET(gtk_builder_get_object(builder, "ventana_login"));
    fixed_login = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_login"));
    ingresar_usuario_login = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_usuario_login"));
    clear_registro_admin_usuario2 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_usuario2"));
    label_ingresarusuario2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarusuario2"));
    label_ingresarclave2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_ingresarclave2"));
    ingresar_clave_admin2 = GTK_WIDGET(gtk_builder_get_object(builder, "ingresar_clave_admin2"));
    clear_registro_admin_clave2 = GTK_WIDGET(gtk_builder_get_object(builder, "clear_registro_admin_clave2"));
    boton_salir_login = GTK_WIDGET(gtk_builder_get_object(builder, "boton_salir_login"));
    boton_aceptar_login = GTK_WIDGET(gtk_builder_get_object(builder, "boton_aceptar_login"));
    label_err_login = GTK_WIDGET(gtk_builder_get_object(builder, "label_err_login"));

    //CONECTAR LAS SE�ALES DE LOS WIDGETS

    //VENTANAS
    gtk_builder_connect_signals(builder, NULL);
    g_signal_connect(ventana_inicio, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_menu_principal, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_registro_administrador, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_login, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_tasas, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_registrar_cliente, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_menu_admin, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(ventana_agregar_producto, "destroy", G_CALLBACK(gtk_main_quit), NULL);




    g_signal_connect(boton_inicio, "clicked", G_CALLBACK(on_boton_inicio_clicked), NULL);
    g_signal_connect(boton_salir_inicio, "clicked", G_CALLBACK(on_boton_salir_inicio_clicked), NULL);

    //BOTONES REGISTRO
    // registro admin
    g_signal_connect(regis_admin, "clicked", G_CALLBACK(on_regis_admin_clicked), NULL);
    // registro trabajador
    g_signal_connect(regis_empleado, "clicked", G_CALLBACK(on_regis_empleado_clicked), NULL);
    //logins
    g_signal_connect(inicio_admin, "clicked", G_CALLBACK(on_inicio_admin_clicked), NULL);
    g_signal_connect(inicio_empleado, "clicked", G_CALLBACK(on_inicio_empleado_clicked), NULL);


    //CONECTAR BOTON DE LIMPIAR CAMPO EN REGISTRO
    g_signal_connect(clear_registro_admin_nombre, "clicked", G_CALLBACK(on_clear_registro_admin_nombre_clicked), NULL);
    g_signal_connect(clear_registro_admin_apellido, "clicked", G_CALLBACK(on_clear_registro_admin_apellido_clicked), NULL);
    g_signal_connect(clear_registro_admin_direccion, "clicked", G_CALLBACK(on_clear_registro_admin_direccion_clicked), NULL);
    g_signal_connect(clear_registro_admin_telefono, "clicked", G_CALLBACK(on_clear_registro_admin_telefono_clicked), NULL);
    g_signal_connect(clear_registro_admin_cedula, "clicked", G_CALLBACK(on_clear_registro_admin_cedula_clicked), NULL);
    g_signal_connect(clear_registro_admin_usuario, "clicked", G_CALLBACK(on_clear_registro_admin_usuario_clicked), NULL);
    g_signal_connect(clear_registro_admin_contra, "clicked", G_CALLBACK(on_clear_registro_admin_contra_clicked), NULL);
    g_signal_connect(clear_registro_admin_preg, "clicked", G_CALLBACK(on_clear_registro_admin_preg_clicked), NULL);
    g_signal_connect(clear_registro_admin_respt, "clicked", G_CALLBACK(on_clear_registro_admin_respt_clicked), NULL);

    // BOTON DE REGISTRO Y SALIDA
    //registro admin
    g_signal_connect(boton_registrardatos, "clicked", G_CALLBACK(on_boton_registrardatos_clicked), NULL);
    g_signal_connect(salir_ingresardatos, "clicked", G_CALLBACK(on_salir_ingresardatos_clicked), NULL);

    //RECUPERAR CONTRA
    g_signal_connect(recuperar_contra, "clicked", G_CALLBACK(on_recuperar_contra_clicked), NULL);
//    g_signal_connect(boton_salir_recuperarcontra, "clicked", G_CALLBACK(on_boton_salir_recuperarcontra_clicked), NULL);
//    g_signal_connect(boton_buscarcontra, "clicked", G_CALLBACK(on_boton_buscarcontra_clicked), NULL);
//    g_signal_connect(ingresar_usuario_recuperar, "changed", G_CALLBACK(on_ingresar_usuario_recuperar_changed), NULL);


    //salir menu principal
    g_signal_connect(salir_menu_principal, "clicked", G_CALLBACK(on_salir_menu_principal_clicked), NULL);

    //CAMPOS DE ENTRADA REGISTRO
    g_signal_connect(ingresar_nombre_admin, "changed", G_CALLBACK(on_ingresar_nombre_admin_changed), NULL);
    g_signal_connect(ingresar_apellido_admin, "changed", G_CALLBACK(on_ingresar_apellido_admin_changed), NULL);
    g_signal_connect(ingresar_direccion_admin, "changed", G_CALLBACK(on_ingresar_direccion_admin_changed), NULL);
    g_signal_connect(ingresar_tlf_admin, "changed", G_CALLBACK(on_ingresar_tlf_admin_changed), NULL);
    g_signal_connect(ingresar_cedula_admin, "changed", G_CALLBACK(on_ingresar_cedula_admin_changed), NULL);
    g_signal_connect(ingresar_usuario_admin, "changed", G_CALLBACK(on_ingresar_usuario_admin_changed), NULL);
    g_signal_connect(ingresar_contra_admin, "changed", G_CALLBACK(on_ingresar_contra_admin_changed), NULL);
    g_signal_connect(ingresar_preg_admin, "changed", G_CALLBACK(on_ingresar_preg_admin_changed), NULL);
    g_signal_connect(ingresar_respt_admin, "changed", G_CALLBACK(on_ingresar_respt_admin_changed), NULL);


    //BOTONES Y ENTRADAS DEL LOGIN
    g_signal_connect(boton_salir_login, "clicked", G_CALLBACK(on_boton_salir_login_clicked), NULL);
    g_signal_connect(clear_registro_admin_clave2, "clicked", G_CALLBACK(on_clear_registro_admin_clave2_clicked), NULL);
    g_signal_connect(clear_registro_admin_usuario2, "clicked", G_CALLBACK(on_clear_registro_admin_usuario2_clicked), NULL);
    g_signal_connect(boton_aceptar_login, "clicked", G_CALLBACK(on_boton_aceptar_login_clicked), NULL);
    //entradas
    g_signal_connect(ingresar_clave_admin2, "changed", G_CALLBACK(on_ingresar_clave_admin2_changed), NULL);
    g_signal_connect(ingresar_usuario_login, "changed", G_CALLBACK(on_ingresar_usuario_login_changed), NULL);

    //BOTONES MENU ADMIN
    g_signal_connect(boton_inventario, "clicked", G_CALLBACK(on_boton_inventario_clicked), NULL);
    g_signal_connect(boton_gestionar_empleados, "clicked", G_CALLBACK(on_boton_gestionar_empleados_clicked), NULL);
    g_signal_connect(boton_gestionar_caja, "clicked", G_CALLBACK(on_boton_gestionar_caja_clicked), NULL);
    g_signal_connect(boton_gestionar_ventas, "clicked", G_CALLBACK(on_boton_gestionar_ventas_clicked), NULL);
    g_signal_connect(boton_gestionar_clientes, "clicked", G_CALLBACK(on_boton_gestionar_clientes_clicked), NULL);
    g_signal_connect(boton_mostrar_admin_registrados, "clicked", G_CALLBACK(on_boton_mostrar_admin_registrados_clicked), NULL);
    g_signal_connect(boton_salir_menu_admin, "clicked", G_CALLBACK(on_boton_salir_menu_admin_clicked), NULL);

        //VENTAS
        g_signal_connect(G_OBJECT(boton_salir_ventas), "clicked", G_CALLBACK(on_boton_salir_ventas_clicked), NULL);
        //DIARIAS
        g_signal_connect(G_OBJECT(boton_ventas_diaria), "clicked", G_CALLBACK(on_boton_ventas_diaria_clicked), NULL);
        g_signal_connect(G_OBJECT(boton_buscar_ventas_diarias), "clicked", G_CALLBACK(on_boton_buscar_ventas_diarias_clicked), NULL);
        g_signal_connect(G_OBJECT(ingresar_num_caja_ventasd), "changed", G_CALLBACK(on_ingresar_num_caja_ventasd_changed), NULL);
        g_signal_connect(G_OBJECT(boton_salir_ventas_diarias), "clicked", G_CALLBACK(on_boton_salir_ventas_diarias_clicked), NULL);
        //MENSUALES
        g_signal_connect(G_OBJECT(boton_buscar_ventas_mensuales), "clicked", G_CALLBACK(on_boton_buscar_ventas_mensuales_clicked), NULL);
        g_signal_connect(G_OBJECT(boton_salir_ventas_mensuales), "clicked", G_CALLBACK(on_boton_salir_ventas_mensuales_clicked), NULL);
        g_signal_connect(G_OBJECT(boton_ventas_mensuales_porcaja), "clicked", G_CALLBACK(on_boton_ventas_mensuales_porcaja_clicked), NULL);
        g_signal_connect(G_OBJECT(ingresar_num_caja_mensuales), "changed", G_CALLBACK(on_ingresar_num_caja_mensuales_changed), NULL);
        //MENSUALES TOTALES
        g_signal_connect(boton_salir_ventas_mensuales_super, "clicked", G_CALLBACK(on_boton_salir_ventas_mensuales_super_clicked), NULL);
        g_signal_connect(boton_buscar_ventas_mensuales_super, "clicked", G_CALLBACK(on_boton_buscar_ventas_mensuales_super_clicked), NULL);
        g_signal_connect(boton_ventas_total_mensuales, "clicked", G_CALLBACK(on_boton_ventas_total_mensuales_clicked), NULL);
        g_signal_connect(boton_mostrar_facturas, "clicked", G_CALLBACK(on_boton_mostrar_facturas_clicked), NULL);



        //GESTION CAJA
        g_signal_connect(boton_crear_caja, "clicked", G_CALLBACK(on_boton_crear_caja_clicked), NULL);
        g_signal_connect(boton_eliminar_caja, "clicked", G_CALLBACK(on_boton_eliminar_caja_clicked), NULL);
        g_signal_connect(boton_mostrar_cajas, "clicked", G_CALLBACK(on_boton_mostrar_cajas_clicked), text_mostrar_cajas);
        g_signal_connect(salir_menu_caja, "clicked", G_CALLBACK(on_salir_menu_caja_clicked), NULL);
            //CREAR CAJA
            g_signal_connect(boton_agregar_caja, "clicked", G_CALLBACK(on_boton_agregar_caja_clicked), NULL);
            g_signal_connect(boton_salir_crear_caja, "clicked", G_CALLBACK(on_boton_salir_crear_caja_clicked), NULL);
            g_signal_connect(ingresar_num_empleado_caja, "changed", G_CALLBACK(on_ingresar_num_empleado_caja_changed), NULL);
            g_signal_connect(ingresar_nombre_empleado_caja, "changed", G_CALLBACK(on_ingresar_nombre_empleado_caja_changed), NULL);
            g_signal_connect(ingresar_num_caja, "changed", G_CALLBACK(on_ingresar_num_caja_changed), NULL);
            //ELIMINAR CAJA
            g_signal_connect(boton_salir_eliminar_caja, "clicked", G_CALLBACK(on_boton_salir_eliminar_caja_clicked), NULL);
            g_signal_connect(boton_eliminar_caj, "clicked", G_CALLBACK(on_boton_eliminar_caj_clicked), NULL);
            g_signal_connect(ingresar_numcaja_eliminar, "changed", G_CALLBACK(on_ingresar_numcaja_eliminar_changed), NULL);


        //GESTION DE EMPLEADOS
        g_signal_connect(boton_mostrar_empleado, "clicked", G_CALLBACK(on_boton_mostrar_empleado_clicked), NULL);
        g_signal_connect(boton_modificar_empleado, "clicked", G_CALLBACK(on_boton_modificar_empleado_clicked), NULL);
        g_signal_connect(boton_eliminar_empleado, "clicked", G_CALLBACK(on_boton_eliminar_empleado_clicked), NULL);
        g_signal_connect(boton_cantidad_empleado, "clicked", G_CALLBACK(on_boton_cantidad_empleado_clicked), NULL);
        g_signal_connect(boton_salir_gestionempleados, "clicked", G_CALLBACK(on_boton_salir_gestionempleados_clicked), NULL);

            //ELIMINAR EMPLEADO
            g_signal_connect(boton_salir_eliminarempleado, "clicked", G_CALLBACK(on_boton_salir_eliminarempleado_clicked), NULL);
            g_signal_connect(boton_buscar_empleado_eliminar, "clicked", G_CALLBACK(on_boton_buscar_empleado_eliminar_clicked), NULL);
            g_signal_connect(ingresar_cedula_eliminar_empleado, "changed", G_CALLBACK(on_ingresar_cedula_eliminar_empleado_changed), NULL);


            //MODIFICAR EMPLEADO
            //buscar cedula
            g_signal_connect(boton_buscar_empleado, "clicked", G_CALLBACK(on_boton_buscar_empleado_clicked), NULL);
            g_signal_connect(boton_salir_modificarempleado, "clicked", G_CALLBACK(on_boton_salir_modificarempleado_clicked), NULL);
            g_signal_connect(ingresar_cedula_modificar_empleado, "changed", G_CALLBACK(on_ingresar_cedula_modificar_empleado_changed), NULL);
            //modificarempleado
            g_signal_connect(ingresar_nombre_admin1, "changed", G_CALLBACK(on_ingresar_nombre_admin1_changed), NULL);
            g_signal_connect(ingresar_apellido_admin1, "changed", G_CALLBACK(on_ingresar_apellido_admin1_changed), NULL);
            g_signal_connect(ingresar_direccion_admin1, "changed", G_CALLBACK(on_ingresar_direccion_admin1_changed), NULL);
            g_signal_connect(ingresar_tlf_admin1, "changed", G_CALLBACK(on_ingresar_tlf_admin1_changed), NULL);
            g_signal_connect(ingresar_usuario_admin1, "changed", G_CALLBACK(on_ingresar_usuario_admin1_changed), NULL);
            g_signal_connect(ingresar_contra_admin1, "changed", G_CALLBACK(on_ingresar_contra_admin1_changed), NULL);
            g_signal_connect(ingresar_preg_admin1, "changed", G_CALLBACK(on_ingresar_preg_admin1_changed), NULL);
            g_signal_connect(ingresar_respt_admin1, "changed", G_CALLBACK(on_ingresar_respt_admin1_changed), NULL);

            // Conexión para el botón de confirmar registro de datos
            g_signal_connect(boton_registrardatos1, "clicked", G_CALLBACK(on_boton_registrardatos1_clicked), NULL);

            // Conexión para el botón de salir del registro
            g_signal_connect(salir_ingresardatos1, "clicked", G_CALLBACK(on_salir_ingresardatos1_clicked), NULL);


        //BOTONES MENU INVENTARIO
        g_signal_connect(boton_agregar_producto, "clicked", G_CALLBACK(on_boton_agregar_producto_clicked), NULL);
        g_signal_connect(boton_consultar_inventario, "clicked", G_CALLBACK(on_boton_consultar_inventario_clicked), NULL);
        g_signal_connect(boton_salir_inventario, "clicked", G_CALLBACK(on_boton_salir_inventario_clicked), NULL);
            //Agregar producto
            g_signal_connect(ingresar_nombreprod, "changed", G_CALLBACK(on_ingresar_nombreprod_changed), NULL);
            g_signal_connect(boton_aceptarguardarproducto, "clicked", G_CALLBACK(on_boton_aceptarguardarproducto_clicked), NULL);
            g_signal_connect(boton_salirguardarproducto, "clicked", G_CALLBACK(on_boton_salirguardarproducto_clicked), NULL);
            g_signal_connect(ingresar_precioprod, "changed", G_CALLBACK(on_ingresar_precioprod_changed), NULL);
            //Consultar inventario
            g_signal_connect(licores, "clicked", G_CALLBACK(on_licores_clicked),NULL);
            g_signal_connect(charcuteria, "clicked", G_CALLBACK(on_charcuteria_clicked),NULL);
            g_signal_connect(hortalizas, "clicked", G_CALLBACK(on_hortalizas_clicked),NULL);
            g_signal_connect(varios, "clicked", G_CALLBACK(on_varios_clicked),NULL);
            g_signal_connect(salir_menu_consultainvt, "clicked", G_CALLBACK(on_salir_menu_consultainvt_clicked), NULL);

    //BOTONES MENU EMPLEADOS
    g_signal_connect(boton_salir_menuempleado, "clicked", G_CALLBACK(on_boton_salir_menuempleado_clicked), NULL);
    g_signal_connect(boton_modificar_tasas, "clicked", G_CALLBACK(on_boton_modificar_tasas_clicked), NULL);
    g_signal_connect(boton_registrar_cliente, "clicked", G_CALLBACK(on_boton_registrar_cliente_clicked), NULL);
    g_signal_connect(boton_imprimir_factura, "clicked", G_CALLBACK(on_boton_imprimir_factura_clicked), NULL);
    g_signal_connect(boton_venta, "clicked", G_CALLBACK(on_boton_venta_clicked), NULL);


    //cedula
    g_signal_connect(ingresarcedula, "changed", G_CALLBACK(on_ingresarcedula_changed), NULL);
    g_signal_connect(boton_procesarcompra_enter2, "clicked", G_CALLBACK(on_boton_procesarcompra_enter2_clicked), NULL);
    g_signal_connect(boton_salir_procesarcompra_enter2, "clicked", G_CALLBACK(on_boton_salir_procesarcompra_enter2_clicked), NULL);

        //MENU VENTA
        g_signal_connect(boton_agregar_al_carrito, "clicked", G_CALLBACK(on_boton_agregar_al_carrito_clicked), NULL);
        g_signal_connect(salir_menu_venta, "clicked", G_CALLBACK(on_salir_menu_venta_clicked), NULL);
        g_signal_connect(boton_mostrar_carrito, "clicked", G_CALLBACK(on_boton_mostrar_carrito_clicked), NULL);
        g_signal_connect(boton_oficializar_venta, "clicked", G_CALLBACK(on_boton_oficializar_venta_clicked), NULL);

            //agregar al carrito
            g_signal_connect(ingresar_cod_producto, "changed", G_CALLBACK(on_ingresar_cod_producto_changed), NULL);
            g_signal_connect(boton_aceptar_compra, "clicked", G_CALLBACK(on_boton_aceptar_compra_clicked), NULL);
            g_signal_connect(boton_salir_carrito, "clicked", G_CALLBACK(on_boton_salir_carrito_clicked), NULL);
            g_signal_connect(combotext_agregar_carrito, "changed", G_CALLBACK(on_combotext_agregar_carrito_changed), NULL);







    //BOTONES Y ENTRADA DE TASA DEL DIA
    //entradas
    g_signal_connect(ingresar_bs, "changed", G_CALLBACK(on_ingresar_bs_changed), NULL);
    g_signal_connect(ingresar_peso_colombiano, "changed", G_CALLBACK(on_ingresar_peso_colombiano_changed), NULL);
    g_signal_connect(ingresar_euros, "changed", G_CALLBACK(on_ingresar_euros_changed), NULL);

    //boton de aceptar y salir tasa
    g_signal_connect(boton_aceptar_tasa, "clicked", G_CALLBACK(on_boton_aceptar_tasa_clicked), NULL);
    g_signal_connect(boton_salir_tasa, "clicked", G_CALLBACK(on_boton_salir_tasa_clicked), NULL);

    //BOTONES Y ENTRADA DE REGISTRO CLIENTE
    //entry
    g_signal_connect(ingresar_nombrecliente, "changed", G_CALLBACK(on_ingresar_nombrecliente_changed), NULL);
    g_signal_connect(ingresar_apellidocliente, "changed", G_CALLBACK(on_ingresar_apellidocliente_changed), NULL);
    g_signal_connect(ingresar_cedulacliente, "changed", G_CALLBACK(on_ingresar_cedulacliente_changed), NULL);
    g_signal_connect(ingresar_tlfcliente, "changed", G_CALLBACK(on_ingresar_tlfcliente_changed), NULL);
    g_signal_connect(ingresar_direccioncliente, "changed", G_CALLBACK(on_ingresar_direccioncliente_changed), NULL);
    //botones
    g_signal_connect(boton_salir_registrocliente, "clicked", G_CALLBACK(on_boton_salir_registrocliente_clicked), NULL);
    g_signal_connect(boton_aceptar_registrocliente, "clicked", G_CALLBACK(on_boton_aceptar_registrocliente_clicked), NULL);

    g_signal_connect(G_OBJECT(ingresar_num_caja1), "changed", G_CALLBACK(on_ingresar_num_caja1_changed), NULL);
    g_signal_connect(G_OBJECT(ingresar_num_empleado_caja1), "changed", G_CALLBACK(on_ingresar_num_empleado_caja1_changed), NULL);
    g_signal_connect(G_OBJECT(boton_procesarcompra_enter), "clicked", G_CALLBACK(on_boton_procesarcompra_enter_clicked), NULL);
    g_signal_connect(G_OBJECT(boton_salir_procesarcompra_enter), "clicked", G_CALLBACK(on_boton_salir_procesarcompra_enter_clicked), NULL);

    g_signal_connect(G_OBJECT(boton_venta), "clicked", G_CALLBACK(on_boton_venta_clicked), NULL);

    //cerrar ventanas
    // Conectar las señales de cierre para cada ventana

// Para ventana_agregar_producto
g_signal_connect(G_OBJECT(ventana_agregar_producto), "delete-event", G_CALLBACK(on_ventana_agregar_producto_delete), NULL);

// Para venta_mostrar_empleados
g_signal_connect(G_OBJECT(venta_mostrar_empleados), "delete-event", G_CALLBACK(on_venta_mostrar_empleados_delete), NULL);

// Para ventana_consultar_invt_producto
g_signal_connect(G_OBJECT(ventana_consultar_invt_producto), "delete-event", G_CALLBACK(on_ventana_consultar_invt_producto_delete), NULL);

// Para ventana_mostrar_cajas
g_signal_connect(G_OBJECT(ventana_mostrar_cajas), "delete-event", G_CALLBACK(on_ventana_mostrar_cajas_delete), NULL);

// Para ventana_cantidad_empleados
g_signal_connect(G_OBJECT(ventana_cantidad_empleados), "delete-event", G_CALLBACK(on_ventana_cantidad_empleados_delete), NULL);

// Para ventana_consultar_invt
g_signal_connect(G_OBJECT(ventana_consultar_invt), "delete-event", G_CALLBACK(on_ventana_consultar_invt_delete), NULL);

// Para ventana_crear_caja
g_signal_connect(G_OBJECT(ventana_crear_caja), "delete-event", G_CALLBACK(on_ventana_crear_caja_delete), NULL);

// Para ventana_eliminar_empleado_cedula
g_signal_connect(G_OBJECT(ventana_eliminar_empleado_cedula), "delete-event", G_CALLBACK(on_ventana_eliminar_empleado_cedula_delete), NULL);

// Para ventana_eliminarcaja
g_signal_connect(G_OBJECT(ventana_eliminarcaja), "delete-event", G_CALLBACK(on_ventana_eliminarcaja_delete), NULL);

// Para ventana_menu_caja
g_signal_connect(G_OBJECT(ventana_menu_caja), "delete-event", G_CALLBACK(on_ventana_menu_caja_delete), NULL);

// Para ventana_ventas_consulta
g_signal_connect(G_OBJECT(ventana_ventas_consulta), "delete-event", G_CALLBACK(on_ventana_ventas_consulta_delete), NULL);





    gtk_widget_show_all(ventana_inicio);

    gtk_main();







   return 0;
}
