# HipermercadoTP1
Proyecto TP1 Sección 4 

PASOS PARA CONFIGURAR  
Paso 1: Descargar Code::Blocks  
Ve al sitio oficial de Code::Blocks: http://www.codeblocks.org/downloads.  
En la sección "Download the binary release", busca la versión adecuada para Windows.  
Recomendado: Descarga la versión que incluye MinGW (compilador GCC para Windows). Por ejemplo:  
codeblocks-20.03mingw-setup.exe (o la versión más reciente).  

Haz clic en el enlace de descarga y guarda el archivo en tu computadora.  
Paso 2: Instalar Code::Blocks  
Localiza el archivo descargado (por ejemplo, codeblocks-20.03mingw-setup.exe) y haz doble clic para iniciar la instalación.  
Selecciona el idioma y haz clic en "Aceptar".  
Sigue las instrucciones del instalador:  
Acepta los términos de la licencia.  
Selecciona los componentes que deseas instalar. Asegúrate de que MinGW esté seleccionado (si descargaste la versión con MinGW).  
Elige la ubicación donde deseas instalar Code::Blocks (puedes dejar la predeterminada).  
  
Haz clic en "Instalar" y espera a que se complete la instalación.  

Puedes seguir dos métodos principales: usando MSYS o descargando el archivo directamente a C:.  
  
METODO 1 Instalar MSYS2:  

Descarga el instalador de MSYS2 desde aquí https://www.msys2.org/.  
Instálalo y sigue las instrucciones. Asegúrate de instalar MSYS2 en un directorio sin espacios, por ejemplo: C:\msys64.  
Actualizar MSYS2:  
Abre el terminal de MSYS2 (MSYS2 MinGW 64-bit o MSYS2 MinGW 32-bit, dependiendo de tu arquitectura).  
Ejecuta los siguientes comandos para asegurarte de que tienes las últimas actualizaciones:  
  
pacman -Syu  
pacman -Su  
  
  
Instalar GTK3:  
Para instalar GTK3, ejecuta el siguiente comando:  
pacman -S mingw-w64-x86_64-gtk3  

  
Configurar Code::Blocks:  
  
Abre Code::Blocks y ve a Settings > Compiler.  
En la pestaña Search directories, agrega los directorios de MSYS2 para incluir las bibliotecas y encabezados de GTK3.  
Para los encabezados: C:\msys64\mingw64\include\gtk-3.0  
Para las bibliotecas: C:\msys64\mingw64\lib  
  
En Linker settings, agrega la biblioteca gtk-3 a los archivos de enlace:  
gtk-3 y otras bibliotecas necesarias   
En Search directories (incluyendo directorios para encabezados):  
C:\gtk3\include\gtk-3.0  
C:\gtk3\include\gdk-3.0  
C:\gtk3\include\pango-1.0  
C:\gtk3\include\cairo  
C:\gtk3\include\glib-2.0  
C:\gtk3\include\gdk-pixbuf-2.0  
C:\gtk3\include\atk-1.0  
En Linker settings (añadir bibliotecas):  
gtk-3  
gdk-3  
cairo  
pango-1.0  
atk-1.0  
gdk-pixbuf-2.0  
gio-2.0  
glib-2.0  

  
Método 2: Descargar el archivo directamente a C:  
Este método es un poco más manual y requiere descargar los archivos binarios de GTK3. Aquí te dejo los pasos:  
  
Descargar GTK3:  
Visita la página de descargas de GTK3 en GTK.org.  
Descarga el archivo comprimido correspondiente a la versión de GTK3 que necesitas.  
Extraer los archivos:  
  
Extrae el archivo descargado en un directorio de tu elección, por ejemplo: C:\gtk3.  
  
Configurar Code::Blocks:  
Abre Code::Blocks y ve a Settings > Compiler.  
En la pestaña Search directories, agrega las rutas de los encabezados y bibliotecas de GTK3 que has extraído:  
Para los encabezados: C:\gtk3\include\gtk-3.0  
Para las bibliotecas: C:\gtk3\lib  
En Search directories (incluyendo directorios para encabezados):  
C:\gtk3\include\gtk-3.0  
C:\gtk3\include\gdk-3.0  
C:\gtk3\include\pango-1.0  
C:\gtk3\include\cairo  
C:\gtk3\include\glib-2.0  
C:\gtk3\include\gdk-pixbuf-2.0  
C:\gtk3\include\atk-1.0  
En Linker settings (añadir bibliotecas):  
gtk-3  
gdk-3  
cairo  
pango-1.0  
atk-1.0  
gdk-pixbuf-2.0  
gio-2.0  
glib-2.0  
Asegúrate de tener los archivos DLL de GTK3 en la misma carpeta que el ejecutable de tu programa o en un directorio accesible.  
  
Metodo 3:  
https://www.youtube.com/watch?v=VNQUEQnc9m8  


