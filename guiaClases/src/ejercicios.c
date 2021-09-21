/*
 * ejercicios.c
 *
 *  Created on: 12 sep. 2021
 *      Author: Compumar
 */
#include "ejercicios.h"

void ejercicioUnoUno()
{
	int numUno;
	int numDos;
	int resultado;

	printf("\nEjercicio 1-1: Ingresar dos numeros enteros, sumarlos y mostrar el resultado.\n\n");
	numUno = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
	numDos = cargarUnEntero("Ingrese otro un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
	resultado = suma(numUno, numDos);
	printf("El resultado de %d + %d = %d", numUno, numDos, resultado);
}

void ejercicioUnoDos()
{
	int numUno;
	int numDos;
	int numTres;
	int resultado;

	printf("\nEjercicio 1-2: ingresar 3 numeros y mostrar cual de los tres es el mayor.\n\n");
	numUno = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
	numDos = cargarUnEntero("Ingrese otro un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
	numTres = cargarUnEntero("Ingrese otro un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
	resultado = numMayorTres(numUno, numDos, numTres);
	printf("El mayor de los numeros es: %d", resultado);
}

void ejercicioUnoTres()
{
	int numUno;
		int numDos;
		int numTres;

		printf("\nEjercicio 1-3: ingresar 3 numeros y mostrar el numero del medio, solo si existe. En caso de que no exista tambien informarlo.\n\n");
		numUno = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
		numDos = cargarUnEntero("Ingrese otro un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
		numTres = cargarUnEntero("Ingrese otro un numero: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
		numMedioTres(numUno, numDos, numTres);
}

void ejercicioDosUno()
{
	printf("\nEjercicio 2-1: Ingresar 5 numeros enteros calcular y mostrar el promedio de los numeros. Probar la aplicacion con distintos valores.\n\n");
	int listaNumeros[5];
	float prom;
	int acum;
	int i;
	acum = 0;
	cargarArray(listaNumeros, 5, 2147483647, -2147483647);
	for(i=0;i<5;i++)
	{
		acum = acum + listaNumeros[i];
	}
	prom = promedio(acum, 5);
	printf("El promedio de ");
	for(i=0;i<5;i++)
	{
		printf("%d ", listaNumeros[i]);
	}
	printf("es: %.2f", prom);
}

void ejercicioDosDos()
{
	printf("\nEjercicio 2-2:Ingresar 10 números enteros, distintos de cero. Mostrar:\n\n");
	int listaNumeros[10];
	int cantPar;
	int cantImp;
	int numMenor;
	int maxPar;
	int sumaPositivos;
	//crear carga de arrray validando que no sea 0
	cargarArray(listaNumeros, 10, 2147483647, -2147483647);
	mostrarVector(listaNumeros, 10);
	cantImp= cantParImpar(listaNumeros, 10, 1);
	cantPar= cantParImpar(listaNumeros, 10, 0);
	printf("\n\na) Cantidad de pares %d e impares %d \n",cantPar, cantImp);
	numMenor = numMin(listaNumeros, 10);
	printf("b) El menor numero ingresado es: %d \n",numMenor);
	maxPar = mayorPar(listaNumeros, 10);
	printf("c) De los pares el mayor número ingresado es: %d\n",maxPar);
	sumaPositivos = sumaPos(listaNumeros, 10);
	printf("d) La suma de los positivos es: %d\n",sumaPositivos);
}

void ejercicioDosTres()
{
	int numCliente;
	int idCliente[10];
	char esCivil[3][10];
	int edad[10];
	int temperatura[10];
	char genero[3][10];
	int opcion;
	int index;
	int newId;
	numCliente = 1000;
	inicializarArray(idCliente, 10);
	do
	{
		printf("\nEjercicio 2-3:\nDebemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,\n de cada persona debemos obtener los siguientes datos:\n\n");
    	printf("\n*************************\n");
    	printf("* Bienvenido a su Viaje *\n");
    	printf("*************************\n");
    	printf("* 1. Cargar Pasajero    *\n");
    	printf("* 2. Mostrar Pasajeros  *\n");
    	printf("* 0. Salir              *\n");
    	opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion correcta: ", 0, 2, 5);
    	switch(opcion)
		{
    		case 1:
    			index = buscarLibre(idCliente, 10);
    			newId = numCliente;
    			idCliente[index] = newId;
    			getString(esCivil[index], "Ingrese su estado civil ('s', 'c' o 'v'): ", "Error, Ingrese su estado civil ('s' soltero, 'c' casado o 'v' viudo): ", 1, 3, 5);
    			edad[index] = cargarUnEntero("Ingrese su edad: ", "Error, ingrese una edad valida(Entre 5 y 110): ", 5, 110, 5);
    			temperatura[index] = cargarUnEntero("Ingrese su temperatura: ", "Error, ingrese una temperatura valida(Entre 36 y 42): ", 36, 42, 5);
    			getString(genero[index], "Ingrese su genero ('f', 'm' o 'o'): ", "Error, Ingrese su genero ('f' femenino, 'm' masculino o 'o' no binario): ", 1, 3, 5);
    			numCliente++;
    			break;
    		case 2:
    			mostrarClientes(idCliente, esCivil, edad, temperatura, genero, 10);
    			break;
		}
	}while(opcion!=0);


}

void ejercicioDosCuatro()
{
	char letras[5][2];
	int i;
	int contP;
	int band;
	int intentos;
	contP = 0;

	printf("Ejercicio 2-4:\nIngresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.\n\n");

	for(i=0; i<5; i++)
	{
		intentos = 4;
		printf("Ingrese una letra: ");
		fflush(stdin);
		scanf("%[^\n]", letras[i]);
		band = validarLetra(letras[i]);
		if(band == 1)
		{
			while(intentos>0)
			{
				printf("Error, Ingrese una letra: ");
				fflush(stdin);
				scanf("%[^\n]", letras[i]);
				band = validarLetra(letras[i]);
				if(band == 1)
				{
					intentos--;
				}else{
					intentos = 0;
				}
			}
		}
	}
	for (i = 0; i < 5; ++i)
	{
		printf("Letra: %s\n", letras[i]);
		if(!strcmp(letras[i], "p"))
		{
			contP++;
		}
	}
	printf("La cantidad de p es: %d", contP);
}

void ejercicioTresUno()
{

	printf("Ejercicio 3-1:\nCrear una función que muestre por pantalla el número flotante  que recibe como parámetro.\n\n");
	float numF= 4.20;
	mostrarNumF(numF);

}

void ejercicioTresDos()
{
	printf("Ejercicio 3-2:\nCrear una función que permita determinar si un número es par o no.\nLa función retorna 1 en caso afirmativo y 0 en caso contrario.\n\n");
	int num;
	int band;
	num = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	band = numParImpar(num);
	if(band == 1)
	{
		printf("\n\nEl numero %d es Par", num);
	}else
	{
		printf("\n\nEl numero %d es Impar", num);
	}
}
void ejercicioTresTres()
{
	printf("Ejercicio 3-3:\nCrear una función que pida el ingreso de un entero y lo retorne.\n\n");
	int num;
	num = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	printf("Numero: %d", num);
}
void ejercicioTresCuatro()
{
	printf("Ejercicio 3-4:\n Especializar la función anterior para que permita validar el entero ingresado en un rango determinado. \n\n");
	printf("\nFuncion ya realizada arriba...\n");
}

void ejercicioTresCinco()
{
	int num1;
	int num2;

	int resultado;
	num1=1;
	num2=4;
	resultado = Sumar1(num1, num2);
	printf("\nEl resultado de %d + %d es: %d\n", num1, num2, resultado);
	resultado = Sumar2();
	printf("\nEl resultado es: %d\n", resultado);
	Sumar3(num1, num2);
	Sumar4();
}

void ejercicioCuatroUno()
{
	printf("Ejercicio 4-1:\nRealizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.\n\n");
	int fac;
	int numero;
	fac=0;
	numero = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	fac=factorial(fac,numero);
	printf("%d",fac);
}

void ejercicioCuatroDos()
{
	printf("Ejercicio 4-2:\nRealizar un programa que permita la carga de temperaturas en celsius y fahrenheit,\n validando que las temperaturas ingresadas estén entre el punto de\n congelación y ebullición del agua para cada tipo de escala.\nRealizar funcion para pasar temperatura de °F a °C Y de °C a °F\n");

	float celsius;
	float fahrenheit;
	int band;
	float aux;
	band = cargarUnEntero("\n\nDesea cargar la temperatura en fahrenheit o celsius? (1=°F, 0=°C): ", "Error, ingrese un valor valido (0=°F, 1=°C): ", 0, 1, 4);
	if(band == 1)
	{
		fahrenheit = cargarUnFloat("Ingrese la temperatura °F: ", "Error, Ingrese la temperatura °F(entre 212°C y 32°F): ", 32, 212, 4);
		aux = celAFarCriterio(fahrenheit, 1);
		printf("\n\nSu temperatura es: %.2f °F, en celsius seria %.2f °C", fahrenheit, aux);
	}else{
		celsius = cargarUnFloat("Ingrese la temperatura °C: ", "Error, Ingrese la temperatura °C(entre 100°C y 0°C): ", 0, 100, 4);
		aux = celAFarCriterio(celsius, 0);
		printf("\n\nSu temperatura es: %.2f °C, en fahrenheit seria %.2f °F", celsius, aux);
	}
}
void ejercicioCincoUno()
{
	printf("Ejercicio 5-1:\nPedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.\n\n");

	int listaNumeros[5]={4,7,4,13,8};
	int suma;
	//cargarArray(&listaNumeros, 5, 2147483647, -2147483647);
	mostrarVector(listaNumeros, 5);
	suma = sumarVector(listaNumeros, 5);
	printf("\n\nLa suma del vector es: %d", suma);
}
void ejercicioCincoDos()
{
	int cantPos;
	int cantNeg;
	int sumPar;
	int mayImp;
	int listaNumeros[10]={5,8,4,6,7,3,2,1,9,2};
	//cargarArray(&listaNumeros, 5, 2147483647, -2147483647);
	cantPos = cantPosNeg(listaNumeros, 10, 0);
	cantNeg = cantPosNeg(listaNumeros, 10, 1);
	sumPar = sumaPar(listaNumeros, 10);
	mayImp = mayorImpar(listaNumeros, 10);
	printf("\n");
	mostrarVector(listaNumeros, 10);
	printf("\n");

	printf("La cantidad de positivos es: %d\n", cantPos);
	printf("La cantidad de negativos es: %d\n", cantNeg);
	printf("La sumatoria de los pares es: %d\n", sumPar);
	printf("El mayor de los impares es: %d\n", mayImp);
}

void anexoCincoUno()
{
	int opcion;
	int listaEdades[5];
	float prom;
	    do{
	    	printf("\n*************************\n");
	    	printf("*    Menu Opciones      *\n");
	    	printf("*************************\n");
	    	printf("*                       *\n");
	    	printf("* 1. Inicializar        *\n");
	    	printf("* 2. Cargar             *\n");
	    	printf("* 3. Mostrar            *\n");
	    	printf("* 4. Calcular Promedio  *\n");
	    	printf("* 5. Ordenar            *\n");
	    	printf("* 0. SALIR              *\n");
	    	printf("*************************\n");
	    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 5, 4);
			switch(opcion)
			{
				case 1:
					printf("\nUd. ha seleccionado lo opción 1. Inicializa\n");
					inicializarArray(listaEdades, 5);
					limpiar();
					break;
				case 2:
					printf("\nUd. ha seleccionado lo opción 2. Cargar\n");
					cargarArray(listaEdades, 5, 120, 0);
					limpiar();
					break;
				case 3:
					printf("\nUd. ha seleccionado lo opción 3. Mostrar\n");
					mostrarEdad(listaEdades, 5);
					limpiar();
					break;
				case 4:
					printf("\nUd. ha seleccionado lo opción 4. Calcular Promedio\n");
					prom = promedioVector(listaEdades, 5);
					printf("\nEl promedio de las edades es: %.2f\n", prom);
					limpiar();
					break;
				case 5:
					printf("\nUd. ha seleccionado lo opción 5. Ordenar\n");
					limpiar();
					break;
			}
	    }while(opcion != 0);
}

void ejercicioSeisUno()
{
	printf("\nEjercicio 6-1:\nDisponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio\n de valores de dichas variables.\n\n");
	int a;
	int b;
	a=5;
	b=1;

	printf("Numero a: %d Numero b: %d\n\n", a, b);
	sort(&a, &b);
	printf("Numero a: %d Numero b: %d\n\n", a, b);
}

void ejercicioSeisDos()
{
	printf("Ejercicio 6-2:\nRealizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).\nNecesito generar un listado de los números positivos de manera creciente y negativos de manera\n decreciente. (Como máximo 5 estructuras repetitivas)\n\n");
	int listaNumeros[10];
	int canPos;
	int canNeg;
	canNeg = 0;
	canPos = 0;
	int listaPos[10];
	int listaNeg[10];
	int i;
	int j;
	int g;
	j=0;
	g=0;

	cargarArray(listaNumeros, 10, 2147483647, -2147483647);
	printf("\n\n");
	mostrarVector(listaNumeros, 10);
	printf("\n\n");
	canNeg = cantPosNeg(listaNumeros, 10, 1);
	canPos = cantPosNeg(listaNumeros, 10, 0);
	inicializarArray(listaNeg, canNeg);
	inicializarArray(listaPos, canPos);

	for (i = 0; i < 10; ++i) {
		if(listaNumeros[i]<0){
			listaNeg[j] = listaNumeros[i];
			j++;
		}else{
			if(listaNumeros[i]>=0){
				listaPos[g] = listaNumeros[i];
				g++;
			}
		}
	}
	sortArrayCriterio(listaPos, canPos,0);
	sortArrayCriterio(listaNeg, canNeg,1);
	printf("\n\n");
	mostrarVector(listaPos, canPos);
	printf("\n\n");
	mostrarVector(listaNeg, canNeg);
}

void ejercicioSeisTres()
{
	int tam;
	tam = 1;
	char nombre[tam][30];
	char apellido[tam][30];
	char nombreCompleto[tam][60];
	/*for (i = 0; i < tam; ++i) {
		getUsuario(nombre[i], "Ingrese su nombre: ", "Error, ingrese un nombre valido: ", 1, 40, 4);
		getUsuario(apellido[i], "Ingrese su apellido: ", "Error, ingrese un apellido valido: ", 1, 40, 4);
	}*/
	getUsuario(nombre[0], "Ingrese su nombre: ", "Error, ingrese un nombre valido: ", 1, 60, 4);
	getUsuario(apellido[0], "Ingrese su apellido: ", "Error, ingrese un apellido valido: ", 1, 60, 4);
	strcat(nombreCompleto[0], " ,");
	strcat(nombreCompleto[0], nombre[0]);
	printf("%s", nombreCompleto[0]);
}
