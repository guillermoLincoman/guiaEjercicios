/*
 * menus.c
 *
 *  Created on: 10 sep. 2021
 *      Author: Compumar
 */
#include "menus.h"
#include "ejercicios.h"
void menuClases()
{
	printf("\n*******************************\n");
	printf("* GUIA DE EJERCICIOS - CLASES *\n");
	printf("*******************************\n");
	printf("* Seleccione la clase         *\n");
	printf("*                             *\n");
    printf("* 1. CLASE 1                  *\n");
    printf("* 2. CLASE 2                  *\n");
    printf("* 3. CLASE 3                  *\n");
    printf("* 4. CLASE 4                  *\n");
    printf("* 5. CLASE 5                  *\n");
    printf("* 6. CLASE 6                  *\n");
    printf("* 0. SALIR                    *\n");
    printf("*******************************\n");
}

void clase1()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 1 *\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
        printf("* 1. Ejercicio 1-1:           *\n");
        printf("* 2. Ejercicio 1-2:           *\n");
        printf("* 3. Ejercicio 1-3:           *\n");
        printf("* 0. SALIR                    *\n");
        printf("*******************************\n");
        ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 3, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioUnoUno();
				limpiar();
				break;
			case 2:
				ejercicioUnoDos();
				limpiar();
				break;
			case 3:
				ejercicioUnoTres();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void clase2()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 2 *\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Ejercicio 2-1:           *\n");
    	printf("* 2. Ejercicio 2-2:           *\n");
    	printf("* 3. Ejercicio 2-3:           *\n");
    	printf("* 4. Ejercicio 2-4:           *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 4, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioDosUno();
				limpiar();
				break;
			case 2:
				ejercicioDosDos();
				limpiar();
				break;
			case 3:
				ejercicioDosTres();
				limpiar();
				break;
			case 4:
				ejercicioDosCuatro();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void clase3()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 3 *\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Ejercicio 3-1:           *\n");
    	printf("* 2. Ejercicio 3-2:           *\n");
    	printf("* 3. Ejercicio 3-3:           *\n");
    	printf("* 4. Ejercicio 3-4:           *\n");
    	printf("* 5. Ejercicio 3-5:           *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 5, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioTresUno();
				limpiar();
				break;
			case 2:
				ejercicioTresDos();
				limpiar();
				break;
			case 3:
				ejercicioTresTres();
				limpiar();
				break;
			case 4:
				ejercicioTresCuatro();
				limpiar();
				break;
			case 5:
				ejercicioTresCinco();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void clase4()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 4 *\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Ejercicio 4-1:           *\n");
    	printf("* 2. Ejercicio 4-2:           *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 2, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioCuatroUno();
				limpiar();
				break;
			case 2:
				ejercicioCuatroDos();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void anexoClase5()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("*  ANEXO VECTORES -- CLASE 5  *\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Anexo 5-1,2,3,4,5,6,8,9: *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 1, 4);
		switch(ejercicio)
		{
			case 1:
				anexoCincoUno();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void clase5()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 5*\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Ejercicio 5-1:           *\n");
    	printf("* 2. Ejercicio 5-2:           *\n");
    	printf("* 3. Anexo     5-3:           *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 3, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioCincoUno();
				limpiar();
				break;
			case 2:
				ejercicioCincoDos();
				limpiar();
				break;
			case 3:
				anexoClase5();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void clase6()
{
	int ejercicio;

    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - CLASE 6*\n");
    	printf("*******************************\n");
    	printf("* Seleccione Ejercicio        *\n");
    	printf("*                             *\n");
    	printf("* 1. Ejercicio 6-1:           *\n");
    	printf("* 2. Ejercicio 6-2:           *\n");
    	printf("* 3. Ejercicio 6-3:           *\n");
    	printf("* 0. SALIR                    *\n");
    	printf("*******************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 3, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioSeisUno();
				limpiar();
				break;
			case 2:
				ejercicioSeisDos();
				limpiar();
				break;
			case 3:
				ejercicioSeisTres();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

