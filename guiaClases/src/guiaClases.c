/*
 ============================================================================
 Name        : guiaClases.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "bibliotecaLincoman.h"
#include "menus.h"
int main()
{
	setbuf(stdout, NULL);
    int clase;
    do{
    	menuClases();
    	clase = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 10, 4);
        switch(clase)
        {
            case 1:
            	clase1();
            	limpiar();
                break;
            case 2:
            	clase2();
            	limpiar();
            	break;
            case 3:
            	clase3();
            	limpiar();
            	break;
            case 4:
            	clase4();
            	limpiar();
            	break;
            case 5:
            	clase5();
            	limpiar();
            	break;
            case 6:
            	clase6();
            	limpiar();
            	break;
            case 7:
            	clase7();
            	limpiar();
            	break;
        }
    }while(clase != 0);
    return 0;
}
