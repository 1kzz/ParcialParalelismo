/******************************************************************************
* Fecha: 10/08/2022
* Autor: Santiago Mora
* Materia: Parallel and Distributed Computing
* Tema: Diseño de Benchmark
* Fase 01: Multiplicación de Matrices Clásica
*******************************************************************************/
#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED


/******* Se presentan las funciones *********/

//Funcion tiempo inicial
void tiempo_inicial();

//Funcion tiempo final
void tiempo_final();


/**Benchmark01: MM Clasico con enteros **/
//Funcion de inicializar las matrices
void inicializar_matrices_int(int n, int *a, int *b, int *c);

//Funcion para imprimir las matrices
void imprimir_matrices_int(int n, int *m);

//Funcion Algoritmo clasico FilasxColumnas
void producto_matrices_int(int n, int *a, int *b, int *c);



/**Benchmark02: MM Clasico con enteros aleatorios **/
void inicializar_matrices_int_rnd(int n, int *a, int *b, int *c);
int funcionRandom();


/**Benchmark03: MM Clasico con doubles **/
void producto_matrices_double(int n, double *a, double *b, double *c);
void inicializar_matrices_double(int n, double *a, double *b, double *c);
void imprimir_matrices_double(int n, double *m);


/**Benchmark04: MM Clasico con doubles aleatorios**/
void inicializar_matrices_double_rnd(int n, double *a, double *b, double *c);
double funcionRandom_double();

#endif
