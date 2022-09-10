/******************************************************************************
* Fecha: 10/08/2022
* Autor: Juan
* Materia: Parallel and Distributed Computing
* Tema: Diseño de Benchmark
* Fase 01: Multiplicación de Matrices Clásica
*******************************************************************************/

#include <unistd.h>
#include "mm_lib.h"
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

struct timespec punto_inicio, punto_final;


/******* Se presentan las funciones *********/

//Funcion tiempo inicial
void tiempo_inicial(){
	clock_gettime(CLOCK_MONOTONIC, &punto_inicio);
}

//Funcion tiempo final
void tiempo_final(){
	double suma_tiempo;
	clock_gettime(CLOCK_MONOTONIC, &punto_final);
	
	//sumar segundos y pasarlos a nanosegundos
	suma_tiempo = (punto_final.tv_sec - punto_inicio.tv_sec)*1e9;
	//Sumar los nanosegundos
	suma_tiempo = (suma_tiempo + punto_final.tv_nsec - punto_inicio.tv_nsec)*1e-9;
	printf("%f \n", suma_tiempo);
}

/**************BenchMark 1 int ***************/
//Funcion de inicializar las matrices
void inicializar_matrices_int(int n, int *a, int *b, int *c){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i+j*n] = 3*(i+j);
			b[i+j*n] = 2*j + 3*i;
			c[i+j*n] = 0;
		}
	}
}

//Funcion para imprimir las matrices
void imprimir_matrices_int(int n, int *m){
	int i, j;
	if (n<5){
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %d ", m[j+i*n]);
			}
		printf("\n");
		}
	printf("\n");
	}
}

//Funcion Algoritmo clasico FilasxColumnas
void producto_matrices_int(int n, int *a, int *b, int *c){
	int i, j, k;
	int suma_parcial;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			suma_parcial = 0;
			int *pA, *pB;
			pA=(a+i*n);
			pB=(b+j);
			for(k=0; k<n; k++,pA++,pB+=n){
				suma_parcial += (*pA* *pB);
				}
			c[j+i*n] = suma_parcial;
		}
}



/**Benchmark 2 int y random***/
int funcionRandom(){
         int min = 0, max = 9;
         static int flag = -1;
         if ((flag = (flag<0))){
                 //Se genera la semilla <al usar la función
                 srand(time(NULL) + getpid());
         }
         if (min > max)
                 return errno = EDOM, NAN;
         return min + (int)rand()/((int)RAND_MAX/(max-min));
}


//Funcion de inicializar las matrices
void inicializar_matrices_int_rnd(int n, int *a, int *b, int *c){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i+j*n] = funcionRandom();
			b[i+j*n] = funcionRandom();
			c[i+j*n] = 0;
		}
	}
}



/**Benchmark 3 double***/

void inicializar_matrices_double(int n, double *a, double *b, double *c){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i+j*n] = 3*(i+j);
			b[i+j*n] = 2*j + 3*i;
			c[i+j*n] = 0;
		}
	}
}

//Funcion para imprimir las matrices
void imprimir_matrices_double(int n, double *m){
	int i, j;
	if (n<5){
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %f ", m[j+i*n]);
			}
		printf("\n");
		}
	printf("\n");
	}
}

//Funcion Algoritmo clasico FilasxColumnas
void producto_matrices_double(int n, double *a, double *b, double *c){
	int i, j, k;
	double suma_parcial;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			suma_parcial = 0;
			double *pA, *pB;
			pA=(a+i*n);
			pB=(b+j);
			for(k=0; k<n; k++,pA++,pB+=n){
				suma_parcial += (*pA* *pB);
				}
			c[j+i*n] = suma_parcial;
		}
}

/**Benchmark 4 double random***/

double funcionRandom_double(){
         double min = 0, max = 9;
         static double flag = -1;
         if ((flag = (flag<0))){
                 //Se genera la semilla <al usar la función
                 srand(time(NULL) + getpid());
         }
         if (min > max)
                 return errno = EDOM, NAN;
	 double f = 0.01+rand()/((RAND_MAX +1u/max-1.0));

         return min + f * (max - min);
}


//Funcion de inicializar las matrices
void inicializar_matrices_double_rnd(int n, double *a, double *b, double *c){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i+j*n] = funcionRandom_double();
			b[i+j*n] = funcionRandom_double();
			c[i+j*n] = 0;
		}
	}
}

















