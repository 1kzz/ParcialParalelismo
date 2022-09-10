#!/usr/bin/perl


=begin

Fecha: 26/08/2022
Autor: Juan
Materia: Parallel and Distributed Computing
Tema: Lanzador
Requerimentos:
	- Vecor de Benchmarks <ejecutables>
	- Vector de cargas
	- N: repeticiones
	- La idea es iterar por ejecutables*cargas*repeticiones
=cut
#Se crea el vector de ejecutables
@Ejecutables=("mm_main_int","mm_main_int_rnd","mm_main_double","mm_main_double_rnd");
#Se crea el vector de cargas
@Cargas=("440","480");
#Se crea la variable del numero de repeticiones
$N=2;

foreach $exes (@Ejecutables){
	foreach $carga(@Cargas){
		#Se crea un fichero
		$file="resultados/"."$exes","-$carga".".txt";
		for($i=0;$i<$N;$i++){
		system("./$exes $carga>>$file");
		#print("./$exes $carga\n");
		}
	close($file)
	}
}
		

