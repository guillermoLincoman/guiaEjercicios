/*
 * bibliotecaLincoman.h
 *
 *  Created on: 9 sep. 2021
 *      Author: Compumar
 */
//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
//int maximo 2147483647

#ifndef BIBLIOTECALINCOMAN_H_
#define BIBLIOTECALINCOMAN_H_

typedef struct
{
	int idProducto;
	char descripcion[240];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}eProductos;
//funciones estructuras
eProductos altaProducto(int newId);
void inicializarEstructura(eProductos lista[], int tam);
int indexLibre(eProductos lista[], int tam);
int bajaProducto(eProductos lista[], int id, int tam);
int modificarProducto(eProductos lista[], int ultimoId, int tam);
int buscarIndexId(eProductos lista[], int tam, int id);
int borrarProducto(eProductos lista[], int tam, int ultimoId);
void cargarProducto(eProductos lista[], int newId, int tam);
void mostrarProductos(eProductos lista[], int tam);
void sortEstructuraPrecio(eProductos lista[], int tam, int criterio);
void sortEstructuraDesc(eProductos lista[], int tam, int criterio);
void mostrarUnProducto(eProductos lista);
void eSort(eProductos *prodUno, eProductos *prodDos);
void limpiar();
int suma(int numUno, int numDos);
float promedio(int num, int tam);
float promedioVector(int lista[], int tam);
void sort(int* numUno, int* numDos);
void sortArrayCriterio(int lista[], int tam, int criterio);
void inicializarArray(int lista[], int tam);
int buscarLibre(int lista[], int tam);
int mostrarClientes(int id[], char civil[][10], int edad[], int temperatura[], char genero[][10], int tam);
void mostrarUnClientes(int id, char civil[], int edad, int temperatura, char genero[]);
int numMayorTres(int numUno, int numDos, int numTres);
void numMedioTres(int numUno, int numDos, int numTres);
int validarLetra(char num[]);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
void cargarArray(int array[], int tam, int max, int min);
//void cargarArrayEstructura(eProductos producto, int tam);
void cargarArrayLetras(char array[], int tam, int max, int min);
void mostrarVector(int array[], int tam);
int sumarVector(int array[], int tam);
void mostrarUnaEdad(int edad);
void mostrarEdad(int array[], int tam);
void mostrarVectorCriterio(int array[], int tam, int criterio);
void posImparVector(int array[], int tam);
int cantPosNeg(int array[], int tam, int criterio);
int cantParImpar(int array[], int tam, int criterio);
int sumaPar(int array[], int tam);
int sumaPos(int array[], int tam);
int mayorImpar(int array[], int tam);
int mayorPar(int array[], int tam);
int numMin(int array[], int tam);
void mostrarNumF(float num);
int numParImpar(int num);
float celAFarCriterio(float num, int criterio);
//funciones no usar
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);
//
int factorial(int fact, int num);
#endif /* BIBLIOTECALINCOMAN_H_ */
