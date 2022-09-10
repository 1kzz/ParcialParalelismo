/******************************************************************************
* Fecha: 10/08/2022
* Autor: Juan
* Materia: Parallel and Distributed Computing
* Tema: Diseño de Benchmark
* Fase 01: Multiplicación de Matrices Clásica
*******************************************************************************/

#define RESERVA_MEMORIA (1024*1024*64*3)

static int MEM_CHUNK[RESERVA_MEMORIA];


#include <unistd.h>
#include "mm_lib.h"
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]){ 
	//Se pide la dimensión de la matriz
	int N, SIZE;
	//int i, j, k;
	int *matrizA, *matrizB, *matrizC;
	N = (int)atoi(argv[1]);
	SIZE = N*N;
	/**Se apuntan los punteros a la direccion de memoria resevada segun el tamano de la matriz
	NxB**/
	matrizA=MEM_CHUNK;
	matrizB=matrizA+SIZE;
	matrizC=matrizB+SIZE;


	inicializar_matrices_int(N, matrizA, matrizB, matrizC);	
	imprimir_matrices_int(N,matrizA);
	imprimir_matrices_int(N,matrizB);
	
	tiempo_inicial();
	producto_matrices_int(N, matrizA, matrizB, matrizC);
	tiempo_final();
	imprimir_matrices_int(N,matrizC);

	return 0;
}
