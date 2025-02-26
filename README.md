# HIPERMERCADO CACHAMAY
# **Proyecto TP1 Sección 4**

---

## **PASOS PARA CONFIGURAR**

---

### **Paso 1: Descargar Code::Blocks**
1. Ve al sitio oficial de Code::Blocks: [http://www.codeblocks.org/downloads](http://www.codeblocks.org/downloads).
2. En la sección **"Download the binary release"**, busca la versión adecuada para Windows.
   - **Recomendado**: Descarga la versión que incluye **MinGW** (compilador GCC para Windows). Por ejemplo:
     - `codeblocks-20.03mingw-setup.exe` (o la versión más reciente).
3. Haz clic en el enlace de descarga y guarda el archivo en tu computadora.

---

### **Paso 2: Instalar Code::Blocks**
1. Localiza el archivo descargado (por ejemplo, `codeblocks-20.03mingw-setup.exe`) y haz doble clic para iniciar la instalación.
2. Selecciona el idioma y haz clic en **"Aceptar"**.
3. Sigue las instrucciones del instalador:
   - Acepta los términos de la licencia.
   - Selecciona los componentes que deseas instalar. Asegúrate de que **MinGW** esté seleccionado (si descargaste la versión con MinGW).
   - Elige la ubicación donde deseas instalar Code::Blocks (puedes dejar la predeterminada).
4. Haz clic en **"Instalar"** y espera a que se complete la instalación.

---

## **Métodos para configurar GTK3**

Puedes seguir dos métodos principales: usando **MSYS** o descargando el archivo directamente a `C:`.

---

### **Método 1: Instalar MSYS2**
1. Descarga el instalador de MSYS2 desde [aquí](https://www.msys2.org/).
2. Instálalo y sigue las instrucciones. Asegúrate de instalar MSYS2 en un directorio sin espacios, por ejemplo: `C:\msys64`.
3. **Actualizar MSYS2**:
   - Abre el terminal de MSYS2 (MSYS2 MinGW 64-bit o MSYS2 MinGW 32-bit, dependiendo de tu arquitectura).
   - Ejecuta los siguientes comandos para asegurarte de que tienes las últimas actualizaciones:
     ```bash
     pacman -Syu
     pacman -Su
     ```
4. **Instalar GTK3**:
   - Para instalar GTK3, ejecuta el siguiente comando:
     ```bash
     pacman -S mingw-w64-x86_64-gtk3
     ```
5. **Configurar Code::Blocks**:
   - Abre Code::Blocks y ve a **Settings > Compiler**.
   - En la pestaña **Search directories**, agrega los directorios de MSYS2 para incluir las bibliotecas y encabezados de GTK3:
     - Para los encabezados: `C:\msys64\mingw64\include\gtk-3.0`
     - Para las bibliotecas: `C:\msys64\mingw64\lib`
   - En **Linker settings**, agrega la biblioteca `gtk-3` a los archivos de enlace:
     - `gtk-3` y otras bibliotecas necesarias.
   - En **Search directories** (incluyendo directorios para encabezados):
     - `C:\gtk3\include\gtk-3.0`
     - `C:\gtk3\include\gdk-3.0`
     - `C:\gtk3\include\pango-1.0`
     - `C:\gtk3\include\cairo`
     - `C:\gtk3\include\glib-2.0`
     - `C:\gtk3\include\gdk-pixbuf-2.0`
     - `C:\gtk3\include\atk-1.0`
   - En **Linker settings** (añadir bibliotecas):
     - `gtk-3`
     - `gdk-3`
     - `cairo`
     - `pango-1.0`
     - `atk-1.0`
     - `gdk-pixbuf-2.0`
     - `gio-2.0`
     - `glib-2.0`

---

### **Método 2: Descargar el archivo directamente a C:**
Este método es un poco más manual y requiere descargar los archivos binarios de GTK3. Aquí te dejo los pasos:

1. **Descargar GTK3**:
   - Visita la página de descargas de GTK3 en [GTK.org](https://www.gtk.org/).
   - Descarga el archivo comprimido correspondiente a la versión de GTK3 que necesitas.
2. **Extraer los archivos**:
   - Extrae el archivo descargado en un directorio de tu elección, por ejemplo: `C:\gtk3`.
3. **Configurar Code::Blocks**:
   - Abre Code::Blocks y ve a **Settings > Compiler**.
   - En la pestaña **Search directories**, agrega las rutas de los encabezados y bibliotecas de GTK3 que has extraído:
     - Para los encabezados: `C:\gtk3\include\gtk-3.0`
     - Para las bibliotecas: `C:\gtk3\lib`
   - En **Search directories** (incluyendo directorios para encabezados):
     - `C:\gtk3\include\gtk-3.0`
     - `C:\gtk3\include\gdk-3.0`
     - `C:\gtk3\include\pango-1.0`
     - `C:\gtk3\include\cairo`
     - `C:\gtk3\include\glib-2.0`
     - `C:\gtk3\include\gdk-pixbuf-2.0`
     - `C:\gtk3\include\atk-1.0`
   - En **Linker settings** (añadir bibliotecas):
     - `gtk-3`
     - `gdk-3`
     - `cairo`
     - `pango-1.0`
     - `atk-1.0`
     - `gdk-pixbuf-2.0`
     - `gio-2.0`
     - `glib-2.0`
4. **Asegúrate de tener los archivos DLL de GTK3** en la misma carpeta que el ejecutable de tu programa o en un directorio accesible.

---

### **Método 3: Tutorial en video**
Si prefieres seguir un tutorial en video, puedes ver este enlace:  
[Configurar GTK3 en Code::Blocks](https://www.youtube.com/watch?v=VNQUEQnc9m8)

---

# **Proyecto TP1 Sección 4**

---

## **Tabla de Bibliotecas**

| **Nombre**   | **Descripción**                                                                 | **Funciones**                                                                                   |
|--------------|---------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| `stdio.h`    | Proporciona funciones para entrada y salida estándar.                           | `printf`, `scanf`, `fgets`, `fprintf`, `fscanf`, `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, `rewind`, `remove`, `rename` |
| `stdlib.h`   | Proporciona funciones para manejo de memoria dinámica, conversión de números, generación de números aleatorios, etc. | `rand`, `srand`, `exit`                                                                        |
| `string.h`   | Proporciona funciones para manipulación de cadenas de caracteres.               | `strcpy`, `strcmp`, `strlen`, `strcspn`, `strcat`, `strstr`                                    |
| `ctype.h`    | Proporciona funciones para manejo de caracteres (verificación de tipos de caracteres). | `isdigit`, `isspace`                                                                           |
| `time.h`     | Proporciona funciones para manejo de fecha y hora.                              | `time`, `localtime`                                                                            |

---

## **Funciones y Procedimientos**

| **Tipo de Retorno** | **Nombre**                     | **Parámetros**                                                                 | **Variables Locales**                                                                 | **Descripción**                                                                                   |
|----------------------|--------------------------------|--------------------------------------------------------------------------------|--------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| `void`               | `limpiarBuffer`                | `int c`                                                                       |                                                                                      | Limpia el buffer de entrada para evitar problemas con `scanf` y `fgets`.                         |
| `int`                | `esNumero`                     | `char *str`                                                                   | `size_t i`                                                                           | Verifica si una cadena es un número.                                                             |
| `void`               | `obtenerEntrada`               | `char *mensaje`, `char *dato`, `int esNum`, `int espacios`                    | `int valido`                                                                         | Solicita una entrada al usuario y valida si es un número o si permite espacios.                  |
| `void`               | `registrarUsuario`             | `char *rol`                                                                   | `FILE *f`, `Usuario u`                                                               | Registra un nuevo usuario (admin o empleado) en el archivo correspondiente.                      |
| `int`                | `autenticar`                   | `char *archivo`                                                               | `char usuario[MAX_LENGTH]`, `char pass[MAX_LENGTH]`, `Usuario u`, `int encontrado`    | Autentica a un usuario (admin o empleado) comparando con los datos del archivo.                  |
| `void`               | `recuperarContrasena`          |                                                                               | `char usuario[MAX_LENGTH]`, `char respuesta[MAX_LENGTH]`, `Usuario u`, `int encontrado` | Permite recuperar la contraseña de un usuario mediante una pregunta de seguridad.                |
| `void`               | `menuPrincipal`                |                                                                               | `int opcion`                                                                         | Muestra el menú principal del sistema.                                                          |
| `void`               | `menuAdmin`                    |                                                                               | `int opcion`                                                                         | Muestra el menú de administrador con opciones para gestionar inventario, empleados, cajas, ventas y clientes. |
| `void`               | `menuEmpleadoCaja`             |                                                                               | `int opcion`, `int numero_caja`, `int numero_empleado`, `char nombre_responsable[50]`, `Caja caja`, `int caja_encontrada` | Muestra el menú de empleado de caja.                                                             |
| `void`               | `liberar_caja`                 | `int numero_caja`                                                             | `FILE *archivo_cajas`, `Caja caja`                                                   | Libera una caja que estaba ocupada por un empleado.                                              |
| `void`               | `generarCodigoProducto`        | `char *codigo`, `char *segmento`                                              | `int contador`, `int randomPart`, `char prefijo[4]`                                   | Genera un código único para un producto basado en su segmento.                                   |
| `void`               | `agregarProductoPorSegmento`   |                                                                               | `Producto producto`, `int opcionSegmento`, `char nombreArchivo[MAXLENGTH2]`, `FILE *file` | Agrega un producto al inventario según su segmento.                                              |
| `void`               | `consultarSegmentoPorArchivo`  | `char *segmento`                                                              | `char nombreArchivo[MAXLENGTH2]`, `FILE *file`, `Producto producto`, `int productoCount` | Muestra los productos de un segmento específico.                                                 |
| `void`               | `mostrarMenuSegmentos`         |                                                                               | `int opcionSegmento`                                                                 | Muestra un menú para consultar productos por segmento.                                           |
| `void`               | `mostrarinventario`            |                                                                               | `int opcion`                                                                         | Muestra el menú de inventario con opciones para agregar productos y consultar por segmento.      |
| `void`               | `procesarunacompra`            | `int numero_caja`, `int numero_empleado`                                      | `FILE *archivo_clientes`, `Producto producto`, `int cedula_cliente`, `char nombreArchivo[MAX_LENGTH]`, `char codigoproducto[20]`, `int opcionsegmento`, `int cantidadcompra`, `float subtotal`, `float totalconivaUSD`, `float subtbolivares`, `float subtpesos`, `float subteuros`, `float totalIVABS`, `float totalIVAEUR`, `float totalIVAPESOS`, `int opcion` | Procesa una compra, permitiendo agregar productos al carrito, mostrar el carrito, oficializar la venta o cancelar la compra. |
| `void`               | `agregarproductoalcarrito`     | `Producto producto`, `int cantidad`                                           |                                                                                      | Agrega un producto al carrito de compras.                                                        |
| `void`               | `mostrarcarrito`               | `float tasabolivares`, `float tasaeuros`, `float tasapesoscolombianos`        | `float subtotalUSD`, `float subtotalBolivares`, `float subtotalEuros`, `float subtotalPesosColombianos`, `float totalconivaUSD`, `float totalconivaBolivares`, `float totalconivaEuros`, `float totalconivaPesos` | Muestra el contenido del carrito de compras con los subtotales y totales en diferentes monedas.  |
| `void`               | `oficializarventa`             | `int cedula_cliente`, `int numero_caja`, `int numero_empleado`                | `time_t t`, `struct tm tm`, `int numero_factura`, `FILE *archivo_numero_factura`, `FILE *archivo_factura`, `FILE *archivo_clientes`, `Cliente cliente`, `int encontrado`, `float subtotalUSD`, `float totalconivaUSD`, `FILE *archivo_cajas`, `Caja caja`, `int caja_encontrada` | Oficializa una venta, generando una factura y registrando la venta en la caja correspondiente.    |
| `void`               | `imprimirFactura`              |                                                                               | `FILE *archivo_factura`, `char linea[256]`                                           | Imprime las facturas registradas en el archivo de facturas.                                       |
| `void`               | `cancelarcompra`               |                                                                               | `char nombreArchivo[MAX_LENGTH]`, `Producto producto`, `FILE *archivo`, `int encontrado`, `long pos` | Cancela una compra, devolviendo los productos al inventario y vaciando el carrito.               |
| `void`               | `menu_gestion_empleados`       |                                                                               | `int opcion`                                                                         | Muestra el menú de gestión de empleados con opciones para mostrar, modificar, eliminar y contar empleados. |
| `void`               | `registrarEmpleado`            |                                                                               | `FILE *archivo_empleados`, `Usuario empleado`                                        | Registra un nuevo empleado en el archivo de empleados.                                            |
| `void`               | `mostrarEmpleados`             |                                                                               | `FILE *archivo_empleados`, `Usuario empleado`                                        | Muestra la lista de empleados registrados.                                                       |
| `void`               | `modificarEmpleado`            | `char cedula[MAX_LENGTH]`                                                     | `FILE *archivo_empleados`, `FILE *temp`, `Usuario empleado`, `int encontrado`         | Modifica los datos de un empleado existente.                                                     |
| `void`               | `eliminarEmpleado`             | `char cedula[MAX_LENGTH]`                                                     | `FILE *archivo_empleados`, `FILE *temp`, `Usuario empleado`, `int encontrado`         | Elimina un empleado del archivo de empleados.                                                    |
| `void`               | `cantidad_de_empleados`        |                                                                               |                                                                                      | Muestra la cantidad de empleados registrados.                                                    |
| `void`               | `menu_cajas`                   |                                                                               | `FILE *archivo_cajas`, `int opcion`                                                  | Muestra el menú de gestión de cajas con opciones para crear, eliminar y mostrar cajas.           |
| `void`               | `crear_caja`                   |                                                                               | `FILE *archivo_cajas`, `Caja nueva_caja`                                             | Crea una nueva caja en el archivo de cajas.                                                      |
| `void`               | `modificar_tasas`              |                                                                               |                                                                                      | Modifica las tasas de cambio para diferentes monedas.                                            |
| `void`               | `eliminar_caja`                | `FILE *archivo_cajas`                                                         | `int numero_caja`, `FILE *archivo_temporal`, `Caja caja`, `int encontrado`            | Elimina una caja del archivo de cajas.                                                           |
| `void`               | `mostrar_cajas`                | `FILE *archivo_cajas`                                                         | `Caja caja`                                                                          | Muestra la lista de cajas registradas.                                                           |
| `void`               | `menu_clientes`                |                                                                               | `FILE *archivo_clientes`, `int opc`                                                  | Muestra el menú de gestión de clientes con opciones para mostrar, modificar, eliminar y contar clientes. |
| `void`               | `datos_cliente`                | `Cliente *cliente`                                                            |                                                                                      | Solicita los datos de un cliente.                                                                |
| `void`               | `guardar_cliente`              | `Cliente *cliente`, `FILE *archivo_clientes`                                  |                                                                                      | Guarda los datos de un cliente en el archivo de clientes.                                         |
| `void`               | `leer_y_mostrar_clientes`      | `FILE *archivo_clientes`                                                      | `Cliente cliente`                                                                    | Muestra la lista de clientes registrados.                                                        |
| `void`               | `modificar_cliente`            | `FILE *archivo_clientes`, `int cedula`                                        | `FILE *temp_archivo`, `Cliente cliente`, `int encontrado`                             | Modifica los datos de un cliente existente.                                                      |
| `void`               | `eliminar_cliente`             | `FILE *archivo_clientes`, `int cedula`                                        | `FILE *temp_archivo`, `Cliente cliente`, `int encontrado`                             | Elimina un cliente del archivo de clientes.                                                      |
| `void`               | `cantidad_de_clientes`         | `FILE *archivo_clientes`                                                      |                                                                                      | Muestra la cantidad de clientes registrados.                                                     |
| `int`                | `verificar_clientes_existente` | `FILE *archivo_clientes`, `int cedula_cliente`                                | `char linea[300]`, `int cedula`                                                      | Verifica si un cliente ya está registrado en el archivo de clientes.                             |
| `void`               | `menu_ventas`                  |                                                                               | `FILE *archivo_cajas`, `int opcion`                                                  | Muestra el menú de ventas con opciones para consultar ventas diarias, mensuales y mostrar las últimas 10 facturas. |
| `void`               | `consulta_diaria_por_caja`     | `FILE *archivo_cajas`                                                         | `int numero_caja`, `int dia`, `int mes`, `Caja caja`, `int encontrado`                | Muestra las ventas diarias de una caja específica.                                               |
| `void`               | `ventas_mensuales_por_caja`    | `FILE *archivo_cajas`                                                         | `int numero_caja`, `int mes`, `Caja caja`, `int encontrado`, `double total_bs`, `double total_dolares`, `double total_pesos`, `double total_euros` | Muestra las ventas mensuales de una caja específica.                                             |
| `void`               | `total_ventas_mensuales_supermercado` | `FILE *archivo_cajas`                                                      | `int mes`, `Caja caja`, `double total_bs`, `double total_dolares`, `double total_pesos`, `double total_euros` | Muestra el total de ventas mensuales de todo el supermercado.                                    |
| `void`               | `mostrar_ultimas_10_facturas`  |                                                                               | `FILE *archivo_factura`, `char facturas[10][1024]`, `int contador`, `char linea[256]`, `char factura_actual[1024]`, `int inicio` | Muestra las últimas 10 facturas generadas.                                                       |
| `void`               | `on_boton_registrardatos_clicked` | `GtkButton *b`                                                             | `err`, `u`, `rol`, `err_nombre`, `err_apellido`, `err_direccion`, `err_cedula`, `err_tlf`, `err_usuario`, `err_contra`, `err_respt`, `err_preg`, `err_espaciovacio`, `ventana_menu_principal`, `ventana_registro_administrador` | Esta función se ejecuta cuando el usuario hace clic en el botón de registro. Su propósito es validar que todos los campos obligatorios en un formulario de registro hayan sido rellenados correctamente. Si algún campo está vacío, se muestra un mensaje de error en la interfaz gráfica junto al campo correspondiente. Si todos los campos están rellenados correctamente, se llama a la función `registrarUsuario` para registrar al usuario en el sistema y luego se muestra la ventana del menú principal mientras se oculta la ventana de registro. |
| `void`               | `on_salir_menu_principal_clicked` | `GtkButton *b`                                                           | `ventana_inicio`, `ventana_menu_principal`, `ventana_registro_administrador`          | Esta función se ejecuta cuando el usuario hace clic en el botón de salir en el menú principal. Su propósito es cerrar todas las ventanas abiertas de la aplicación y finalizar el bucle principal de GTK (`gtk_main_quit`), lo que resulta en la terminación de la aplicación. |
| `void`               | `on_ingresar_nombreprod_changed` | `GtkEntry *e`                                                             | `nombre`, `producto`                                                                  | Esta función se ejecuta cuando el contenido del campo de entrada de texto (`GtkEntry`) cambia. Su propósito es capturar el texto ingresado por el usuario en el campo de nombre del producto y almacenarlo en la estructura `producto.nombre`. Además, se asegura de que la cadena esté correctamente terminada con un carácter nulo (`\0`) para evitar problemas de desbordamiento de búfer. |
| `void`               | `on_boton_aceptar_login_clicked` | `GtkButton *b`                                                           | `login`, `usuario_login`, `contrasena`, `ventana_menuempleado`, `ventana_login`, `ventana_menu_admin`, `label_err_login` | Esta función se ejecuta cuando el usuario hace clic en el botón de aceptar en la ventana de inicio de sesión. Su propósito es autenticar al usuario como empleado o administrador, dependiendo del valor de la variable `login`. Si la autenticación es exitosa, se muestra la ventana correspondiente (menú del empleado o menú del administrador) y se oculta la ventana de inicio de sesión. Si la autenticación falla, se muestra un mensaje de error en la interfaz gráfica. |
| `void`               | `on_boton_aceptarguardarproducto_clicked` | `GtkButton *button`, `gpointer user_data`                              | `segmento`, `cantidad`, `producto`                                                    | Esta función se ejecuta cuando el usuario hace clic en el botón de aceptar/guardar producto. Su propósito es validar los datos ingresados por el usuario (segmento, cantidad y precio) y, si son válidos, llamar a la función `agregarProductoPorSegmento` para agregar el producto al inventario. Luego, oculta la ventana actual de agregar producto y muestra la ventana de inventario. |

---

¡Y eso es todo! Ahora tienes una tabla bien estructurada y fácil de leer en tu `README.md`. Si necesitas más ayuda, no dudes en preguntar. 😊



