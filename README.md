# ParcialParalelismo

mm_lib.h es la interfaz donde se encuentran los prototipos de las funciones de los benchmarks de matrices enteras, enteras aleatorioas, doble y dobles aleatorias. 
En mm_lib.c se encuentran las funciones declaradas.
Se hace uso de la interfaz de tiempo para poder medir el tiempo del rendimiento del el calculo de cada una de las operaciones.

Están las funciones que inicializan respectivamente las matrices de enteros, y doble.
Esta la función para el producto de matrices, se realiza el algoritmo clásico mxm 
Hay dos funciones random para generar las matrices aleatorias, una de tipo entero y otra de tipo double.
Finalmente está la función que imprime las matrices correspondientes.
En los main para cada benchmark se realiza el código fuente principal.

El makefile posee las instrucciones para compilar cada programa automaticamente y para realizar una limpieza de la carpeta elimando los objetos y los ejecutables.
make clean para limpiar
make mm_main seguido de int o double para realizar la compilación de los otros benchmark.

Finalmente el lanzador es la automatizacion de los ejecutables para correr todos los ejecutables y almacenar los resultados en un txt y para cada programa se crea un txt distinto para poder diferenciarlos.
Para ejecutar el lanzador debe crear primero una carpeta llamada 'resultados' en la misma carpeta donde estan los archivos para crear los txt con los datos guardados.

