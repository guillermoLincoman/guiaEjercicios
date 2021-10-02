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

typedef struct
{
	char nombre[40];
	int golesMetidos;
	int partidosJugados;
	float promedioGoles;
}eJugador;

typedef struct
{
    int idCurso;//fk
    char descripcion[30];
    int duracionCurso;
}eCurso;

typedef struct
{
    int legajo;
    char nombre[30];
    float promedio;
    int idCurso;//pk
}eAlumno;

typedef struct
{
    int idNacionalidad ;
    char descripcionNacionalidad[30];
}eNacionalidad;


typedef struct
{
    int idTipo  ;
    char descripcionTipo[30];
}eTipoProduco;
void menuTipo();
void menuNacionalidad();
//Funciones Extras
void limpiar();
int validarLetra(char num[]);
void sort(int* numUno, int* numDos);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
/************************************************************************/
//FUNCIONES ESTRUCTURAS
//Principales Estructuras
void inicializarEstructura(eProductos lista[], int tam);
int indexLibre(eProductos lista[], int tam);
int buscarIndexId(eProductos lista[], int tam, int id);

//Carga y descarga de datos Estructuras
eProductos altaProducto(int newId);
int bajaProducto(eProductos lista[], int id, int tam);
int borrarProducto(eProductos lista[], int tam, int ultimoId);
void cargarProducto(eProductos lista[], int newId, int tam);
void altaJugador(eJugador lista[], int tam);

//Manipulacion de datos Estructuras
int modificarProducto(eProductos lista[], int ultimoId, int tam);
void mostrarProductos(eProductos lista[], int tam);
void mostrarUnProducto(eProductos lista);
void mostrarProductosCompleto(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo);
void mostrarUnProductosCompleto(eProductos lista, eNacionalidad nac[], eTipoProduco tipoProd[], int tamNac, int tamTipo);
void mostrarProductosCompletoSegunTipo(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo, int criterio);
void eSort(eProductos *prodUno, eProductos *prodDos);
void sortEstructuraPrecio(eProductos lista[], int tam, int criterio);
void sortEstructuraDesc(eProductos lista[], int tam, int criterio);
void prodMasCaros(eProductos lista[], int tam);
void tipoMasCaros(eProductos lista[], int tam, int criterio);
void masBaratoTipo(eProductos lista[], int tam, int criterio);
void masMontoTipo(eProductos lista[], int tam, int precio, int criterio);
void mostrarProdNac(eProductos lista[], int tam, int criterio);
void promedioTipoProd(eProductos lista[], int tam, int criterio);
float promedioProductos(eProductos lista[], int tam);
/************************************************************************/

//FUNCIONES ARRAYS
//Principales ARRAYS
void inicializarArray(int lista[], int tam);
int buscarLibre(int lista[], int tam);

//Carga y descarga de datos ARRAYS
void cargarArray(int array[], int tam, int max, int min);
void cargarArrayLetras(char array[], int tam, int max, int min);

//Operaciones matematicas ARRAYS
float promedioVector(int lista[], int tam);
int sumarVector(int array[], int tam);
//imprime numeros en posiciones impares
void posImparVector(int array[], int tam);
//cantidad positivos y negativos segun el criterio
int cantPosNeg(int array[], int tam, int criterio);
//cantidad par e impar segun el criterio
int cantParImpar(int array[], int tam, int criterio);
int sumaPar(int array[], int tam);
int sumaPos(int array[], int tam);
int mayorPar(int array[], int tam);
int mayorImpar(int array[], int tam);
int numMin(int array[], int tam);

//Manipulacion de datos ARRAY
//numeros pares e impares
void mostrarVectorCriterio(int array[], int tam, int criterio);
void sortArrayCriterio(int lista[], int tam, int criterio);
int mostrarClientes(int id[], char civil[][10], int edad[], int temperatura[], char genero[][10], int tam);
void mostrarUnClientes(int id, char civil[], int edad, int temperatura, char genero[]);
void mostrarVector(int array[], int tam);

/************************************************************************/

//Operaciones matematicas
int suma(int numUno, int numDos);
float promedio(int num, int tam);
int numMayorTres(int numUno, int numDos, int numTres);
void numMedioTres(int numUno, int numDos, int numTres);
//retorna 1 si es par y 0 en caso contrario
int numParImpar(int num);
unsigned long factorial(int num);
//manipulacion de datos
//NO CARGADAS

//void cargarArrayEstructura(eProductos producto, int tam);
void mostrarUnaEdad(int edad);
void mostrarEdad(int array[], int tam);
void mostrarNumF(float num);
float celAFarCriterio(float num, int criterio);
//funciones no usar
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);
void mostrarJugadores(eJugador lista[], int tam);
void mostrarUnJugador(eJugador lista);
eJugador cargarJugador();
#endif /* BIBLIOTECALINCOMAN_H_ */
