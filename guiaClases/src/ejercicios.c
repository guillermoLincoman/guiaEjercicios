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
	fac=factorial(numero);
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
	char nombre[tam][40];
	char apellido[tam][60];
	/*for (i = 0; i < tam; ++i) {
		getUsuario(nombre[i], "Ingrese su nombre: ", "Error, ingrese un nombre valido: ", 1, 40, 4);
		getUsuario(apellido[i], "Ingrese su apellido: ", "Error, ingrese un apellido valido: ", 1, 40, 4);
	}*/
	getUsuario(nombre[0], "Ingrese su nombre: ", "Error, ingrese un nombre valido: ", 1, 40, 4);
	getUsuario(apellido[0], "Ingrese su apellido: ", "Error, ingrese un apellido valido: ", 1, 60, 4);
	strcat(apellido[0], " ,");
	strcat(apellido[0], nombre[0]);
	printf("%s", apellido[0]);
}

void ejercicioSieteUno()
{
	eProductos producto[3];
	int opcion;
	int proxId;
	proxId = 1000;
	inicializarEstructura(producto, 3);
	 do{
		    	printf("\n******************************\n");
		    	printf("*    Menu Opciones           *\n");
		    	printf("******************************\n");
		    	printf("*                            *\n");
		    	printf("* 1. ALTA                    *\n");
		    	printf("* 2. BAJA                    *\n");
		    	printf("* 3. MODIFICACION            *\n");
		    	printf("* 4. LISTADO Productos       *\n");
		    	printf("* 5. LISTADO por precio      *\n");
		    	printf("  6. LISTADO por descripcion *\n");
		    	printf("* 0. SALIR                   *\n");
		    	printf("******************************\n");
		    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 6, 4);
				switch(opcion)
				{
					case 1:
						cargarProducto(producto, proxId, 3);
						proxId++;
						limpiar();
						break;
					case 2:
						borrarProducto(producto, 3, proxId);
						limpiar();
						break;
					case 3:
						modificarProducto(producto, proxId, 3);
						limpiar();
						break;
					case 4:
						mostrarProductos(producto, 3);
						limpiar();
						break;
					case 5:
						sortEstructuraPrecio(producto, 3, 0);
						mostrarProductos(producto, 3);
						limpiar();
						break;
					case 6:
						sortEstructuraDesc(producto, 3, 0);
						mostrarProductos(producto, 3);
						limpiar();
						break;
				}
		    }while(opcion != 0);
}
void ejercicioOchoUno()
{
	eJugador jugador[3];
	int opcion;
	do{
	    	printf("\n******************************\n");
	    	printf("*    Menu Opciones           *\n");
		   	printf("******************************\n");
		   	printf("*                            *\n");
		   	printf("* 1. ALTA JUGADOR            *\n");
	    	printf("* 2. MOSTRAR JUGADORES       *\n");
	    	printf("* 0. SALIR                   *\n");
	    	printf("******************************\n");
	    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 3, 4);
			switch(opcion)
			{
				case 1:
					altaJugador(jugador, 3);
					limpiar();
					break;
				case 2:
					mostrarJugadores(jugador, 3);
					limpiar();
					break;
			}
		    }while(opcion != 0);
}

void ejercicioOchoDos()
{
	eProductos producto[3];
	int opcion;
	int proxId;
	proxId = 1000;
	inicializarEstructura(producto, 3);
	 do{
		    	printf("\n******************************\n");
		    	printf("*    Menu Opciones           *\n");
		    	printf("******************************\n");
		    	printf("*                            *\n");
		    	printf("* 1. ALTA                    *\n");
		    	printf("* 2. BAJA                    *\n");
		    	printf("* 3. MODIFICACION            *\n");
		    	printf("* 4. LISTADO Productos       *\n");
		    	printf("* 5. LISTADO por precio      *\n");
		    	printf("  6. LISTADO por descripcion *\n");
		    	printf("* 0. SALIR                   *\n");
		    	printf("******************************\n");
		    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 6, 4);
				switch(opcion)
				{
					case 1:
						cargarProducto(producto, proxId, 3);
						proxId++;
						limpiar();
						break;
					case 2:
						borrarProducto(producto, 3, proxId);
						limpiar();
						break;
					case 3:
						modificarProducto(producto, proxId, 3);
						limpiar();
						break;
					case 4:
						mostrarProductos(producto, 3);
						limpiar();
						break;
					case 5:
						sortEstructuraPrecio(producto, 3, 0);
						mostrarProductos(producto, 3);
						limpiar();
						break;
					case 6:
						sortEstructuraDesc(producto, 3, 0);
						mostrarProductos(producto, 3);
						limpiar();
						break;
				}
		    }while(opcion != 0);
}

void ejercicioNueveUno()
{
	eProductos producto[3]={{1000, "Guillermo",2,2,820,1},
							{1001,"Ruben",3,2,830,1},
							{1002,"lincoman",2,2,504,1}};
	int opcion;
	int proxId;
	int criterio;
	int band;
	//inciar en 0 cuando no hay datos harcodeados
	band = 1;
	proxId = 1000;
	//inicializarEstructura(producto, 3);
	 do{
		    	printf("\n*************************************\n");
		    	printf("*    Menu Opciones                  *\n");
		    	printf("*************************************\n");
		    	printf("*                                   *\n");
		    	printf("* 1. ALTA                           *\n");
		    	printf("* 2. BAJA                           *\n");
		    	printf("* 3. MODIFICACION                   *\n");
		    	printf("* 4. LISTADO Productos              *\n");
		    	printf("* 5. LISTADO por precio             *\n");
		    	printf("* 6. LISTADO por descripcion        *\n");
		    	printf("* 7. El/los  productos más caros.   *\n");
		    	printf("* 8. $ promedio x tipo de producto. *\n");
		    	printf("* 9. De los Iphone el más barato    *\n");
		    	printf("* 10.Los productos MADE IN CHINA.   *\n");
		    	printf("* 11. Las MAC que salen + de $700   *\n");
		    	printf("* 12. El/Los Accesorios más caros   *\n");
		    	printf("* 0. SALIR                          *\n");
		    	printf("*************************************\n");
		    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 12, 4);
				switch(opcion)
				{
					case 1:
						band = 1;
						cargarProducto(producto, proxId, 3);
						proxId++;
						limpiar();
						break;
					case 2:
						if(band == 1)
						{
							borrarProducto(producto, 3, proxId);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 3:
						if(band == 1)
						{
							modificarProducto(producto, proxId, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 4:
						if(band == 1)
						{
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 5:
						if(band == 1)
						{
							sortEstructuraPrecio(producto, 3, 0);
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 6:
						if(band == 1)
						{
							sortEstructuraDesc(producto, 3, 0);
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 7:
						if(band == 1)
						{
							prodMasCaros(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 8:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							promedioTipoProd(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 9:
						if(band == 1)
						{
							masBaratoTipo(producto, 3, 1);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 10:
						if(band == 1)
						{
							menuNacionalidad();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							mostrarProdNac(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 11:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							masMontoTipo(producto, 3, 700, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 12:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							tipoMasCaros(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
				}
		    }while(opcion != 0);

}

void ejercicioDiezUno()
{
	eCurso cursos[4]={
	{100, "Java", 10},
	{101, "VB", 20},
	{102, "Phyton", 15},
	{103, "Java Script", 30}
	};
	eAlumno listaAlumnos[6]={
	{1, "Juan", 7, 101},
	{2, "Ana", 4, 100},
	{3, "Luis", 8, 101},
	{4, "Maria", 5, 102},
	{5, "Alberto", 6, 100},
	{6, "Carlos", 2, 103}
	};
	int i;
	int j;
	printf("Ejercicio 10-1:\nDada la estructura eAlumno (legajo, nombre, nota1, nota2, promedio), de qué manera la podría\nrelacionar con la estructura eCurso (idCurso, descripcion, duracion), teniendo en cuenta que un\nalumno puede cursar solo un curso\n\n");
	for (i = 0; i < 6; ++i) {
		for (j = 0; j < 4; ++j) {
			if(listaAlumnos[i].idCurso == cursos[j].idCurso){
				printf("%d	%10s	%.2f	%s\n", listaAlumnos[i].legajo, listaAlumnos[i].nombre, listaAlumnos[i].promedio, cursos[j].descripcion);
				break;
			}
		}
	}

	for (i = 0; i < 4; ++i)
	{
		printf("Alumnos en el curso de %s\n", cursos[i].descripcion);
		for (j = 0; j < 6; ++j)
		{
			if(listaAlumnos[j].idCurso == cursos[i].idCurso)
			{
				printf("%d	%10s	%.2f\n", listaAlumnos[j].legajo, listaAlumnos[j].nombre, listaAlumnos[j].promedio);
			}
		}
	}

}


void ejercicioDiezDos()
{

	printf("Ejercicio 10-2:\nCrear las siguientes estructuras en c, y definir la manera mas optima de relacionarlas.\n\n");
/*
 *
//RELACION eProvedor - eProducto
typedef struct
{
    int altura;
    char calle[30];
    int idLocalidad;
    char descripcion[30];
    int codigoPostal;

}eDireccion;
typedef struct
{
    int idProveedor; //PK
    char razonSocial[30];
    eDireccion direccion;
}eProveedor;

typedef struct
{
    int idProducto;
    char descripcion[30];
    float precio;
    int idProveedor; //FK
}eProducto;

//RELACION eDueño - eMascota
typedef struct
{
    int idDuenio; //PK
    char nombre[30];
    int edad;
    char sexo;

}eDuenio;

typedef struct
{
    int idMascota;
    char nombre[30];
    eRaza raza;
    char sexo;
    int idDuenio; //FK
}eMascota;

//RELACION eAlumno - eLocalidad
typedef struct
{
    int idAlumno;
    char nombre[30];
    int idLocalidad; //PK
}eAlumno;

typedef struct
{
    int altura;
    char calle[30];
    int idLocalidad//FK
    char descripcion[30];
    int codigoPostal;
}eLocalidad;
*/
}

void ejercicioOnceUno()
{
	eProductos producto[3]={{1000, "Guillermo",2,4,820,1},
							{1001,"Ruben",3,4,830,1},
							{1002,"lincoman",1,4,504,1}};
	eNacionalidad nacionalidad[3]={{1, "EEUU"},
								   {2,"CHINA"},
								   {3,"OTRO"}};

	eTipoProduco tipoProducto[4]={{1, "Iphone"},
								  {2,"Ipad"},
								  {3,"Mac"},
								  {4,"Accesorios"}};
	int opcion;
	int proxId;
	int criterio;
	int band;
	//inciar en 0 cuando no hay datos harcodeados
	band = 1;
	proxId = 1000;
	//inicializarEstructura(producto, 3);
	 do{
		    	printf("\n********************************************\n");
		    	printf("*    Menu Opciones                         *\n");
		    	printf("********************************************\n");
		    	printf("*                                          *\n");
		    	printf("* 1. ALTA                                  *\n");
		    	printf("* 2. BAJA                                  *\n");
		    	printf("* 3. MODIFICACION                          *\n");
		    	printf("* 4. LISTADO Productos                     *\n");
		    	printf("* 5. LISTADO por precio                    *\n");
		    	printf("* 6. LISTADO por descripcion               *\n");
		    	printf("* 7. El/los  productos más caros.          *\n");
		    	printf("* 8. $ promedio x tipo de producto.        *\n");
		    	printf("* 9. De los Iphone el más barato           *\n");
		    	printf("* 10.Los productos MADE IN CHINA.          *\n");
		    	printf("* 11.Las MAC que salen + de $700           *\n");
		    	printf("* 12.El/Los Accesorios más caros           *\n");
		    	printf("* 13.LISTA productos y descripción         *\n");
		    	printf("* 14.LISTA de productos por tipo           *\n");
		    	printf("* 15.El/los tipos con mas productos        *\n");
		    	printf("* 0. SALIR                                 *\n");
		    	printf("********************************************\n");
		    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 15, 4);
				switch(opcion)
				{
					case 1:
						band = 1;
						cargarProducto(producto, proxId, 3);
						proxId++;
						limpiar();
						break;
					case 2:
						if(band == 1)
						{
							borrarProducto(producto, 3, proxId);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 3:
						if(band == 1)
						{
							modificarProducto(producto, proxId, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 4:
						if(band == 1)
						{
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 5:
						if(band == 1)
						{
							sortEstructuraPrecio(producto, 3, 0);
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 6:
						if(band == 1)
						{
							sortEstructuraDesc(producto, 3, 0);
							mostrarProductos(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 7:
						if(band == 1)
						{
							prodMasCaros(producto, 3);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 8:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							promedioTipoProd(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 9:
						if(band == 1)
						{
							masBaratoTipo(producto, 3, 1);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 10:
						if(band == 1)
						{
							menuNacionalidad();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							mostrarProdNac(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 11:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							masMontoTipo(producto, 3, 700, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 12:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							tipoMasCaros(producto, 3, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 13:
						if(band == 1)
						{
							mostrarProductosCompleto(producto, nacionalidad, tipoProducto, 3, 3, 4);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 14:
						if(band == 1)
						{
							menuTipo();
							criterio = cargarUnEntero("Ingrese un tipo: ", "Error, Ingrese un tipo valido (entre 1 y 4):", 1, 4, 5);
							mostrarProductosCompletoSegunTipo(producto, nacionalidad, tipoProducto, 3, 3, 4, criterio);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
					case 15:
						if(band == 1)
						{
							tiposConMasProd(producto, nacionalidad, tipoProducto, 3, 3, 4);
						}else{
							printf("\n\nNo hay productos cargados....\n");
						}
						limpiar();
						break;
				}
		    }while(opcion != 0);
}

void ejercicioQuinceUno()
{
	printf("Ejercicio 15-1:\nRealizar el ordenamiento de un vector de enteros. Para ello deberán crear una función\n que se encargue de realizar el intercambio de los dos valores que se van a ordenar (función swap),\n que solo puede recibir dos parámetros.\n\n");

	int vectorEntero[5]={3,2,4,5,1};
	int i;
	int j;
	mostrarVector(vectorEntero, 5);
	for (i = 0; i < 5-1; ++i) {
		for (j = i+1; j < 5; ++j) {
			if(vectorEntero[i]>vectorEntero[j])
			{
				swapArray(&vectorEntero[i], &vectorEntero[j]);
			}
		}
	}
	printf("\nOrednados\n");
	mostrarVector(vectorEntero, 5);

}

void ejercicioQuinceDos()
{
	int error;
	int numero;
	printf("\nEjercicio 15-2:\nRealizar una función que reciba como parámetro un puntero a entero. La función le pedirá\nal usuario que cargue un valor por medio del puntero. Retornará si pudo cargarlo o no.\n\n");

	printf("Ingrese un numero: ");
	error = cargarNumero(&numero);
	if(error == 0)
	{
		printf("\nEl numero %d se ingreso correctamente...\n", numero);
	}
}

void ejercicioQuinceTres()
{
	printf("\nEjercicio 15-3: (No entregar)\nModificar la biblioteca input.h para que a partir de ahora trabaje con punteros. El retorno de cada\nfunción será exclusivamente para el manejo de estados.\n\n");
}

void ejercicioQuinceCuatro()
{
	printf("\nEjercicio 15-4: (No entregar)\nRefactorizar el TP2 para que trabaje con punteros.\n\n");
}

void ejercicioQuinceCinco()
{
	int numUno;
	int numDos;
	int error;
	printf("\nEjercicio 15-5\nEscriba una función que reciba dos números enteros y los devuelva ordenados. Es decir que\nen el primer parámetro debe devolver el menor valor y en el 2do. el mayor.\n\n");
	printf("\nIngrese un numero:");
	cargarNumero(&numUno);
	printf("\nIngrese un otro numero:");
	cargarNumero(&numDos);

	printf("NumUno: %d NumDos: %d\n", numUno, numDos);
	error = numeroMasGrande(&numUno, &numDos);
	if(error == 0)
	{
		printf("\nEl numero se swapeo...\n");
		printf("NumUno: %d NumDos: %d\n", numUno, numDos);
	}else{
		printf("\nEl numero no se swapeo...\n");
	}

}

void ejercicioQuinceSeis()
{
	printf("\nEjercicio 15-6\nRealizar una función que reciba como parámetros dos vectores. La función\ndeberá determinar si el segundo vector está contenido en el primero.\n\n");
	int vectorUno[5]={1,4,3,5,2};
	int vectorDos[5]={2,5,6,3,2};
	int vectorTres[5]={4,1,5,3,2};
	int error;
	error = cargarUnEntero("Prueba.. (1)Error | (2)Contenido", "Error, Prueba.. (1)Error | (2)Contenido", 1, 2, 4);
	if(error == 1){
		printf("\nComparamos el vector 1\n");
		mostrarVector(vectorUno, 5);
		printf("\nCon el vector 2\n");
		mostrarVector(vectorDos, 5);

		error = vectorContenido(vectorUno, vectorDos,5);
	}else{
		printf("\nComparamos el vector 1\n");
		mostrarVector(vectorUno, 5);
		printf("\nCon el vector 3\n");
		mostrarVector(vectorDos, 5);
		error = vectorContenido(vectorUno, vectorTres,5);
	}
	if(error == 0){
		printf("\nEl vector Esta contenido....");
	}else{
		printf("\nEl vector no esta contenido....");
	}
}

void anexoQuince()
{
	int ejercicio;
    do{
    	printf("\n*******************************\n");
    	printf("* GUIA DE EJERCICIOS - ANEXO 15*\n");
    	printf("********************************\n");
    	printf("* Seleccione Ejercicio         *\n");
    	printf("*                              *\n");
    	printf("* 1. Ejercicio Anexo 15-1:     *\n");
    	printf("* 2. Ejercicio Anexo 15-2:     *\n");
    	printf("* 0. SALIR                     *\n");
    	printf("********************************\n");
    	ejercicio = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 2, 4);
		switch(ejercicio)
		{
			case 1:
				ejercicioQuinceUnoAnexo();
				limpiar();
				break;
			case 2:
				ejercicioQuinceDosAnexo();
				limpiar();
				break;
		}
    }while(ejercicio != 0);
}

void ejercicioQuinceUnoAnexo()
{
	printf("\nEjercicio 15-1 ANEXO\nRealizar una función que reciba un puntero a char y dos char.\nLa función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,\npor el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.\n\n");
	char palabra[10]={"juanitato"};
	int cantidad;
	printf("La palabra es: %s", palabra);
	cantidad = remplazarLetras(palabra,'a','f');
	printf("\nLa palabra es: %s y se cambiaron %d letras", palabra, cantidad);
}

void ejercicioQuinceDosAnexo()
{
	printf("\nEjercicio 15-2 ANEXO\nRealizar una función que reciba como parámetros un array de enteros."
			"\nLa función calculará el valor máximo de ese array y utilizará"
			"\nel valor por referencia para retornar ese valor.\n\n");
	int vectorUno[5]={5,12,3,7,9};
	int valor;
	valor = 0;
	numMaximoEnArray(vectorUno, &valor, 5);

	mostrarVector(vectorUno, 5);
	printf("\nEl mayor numero del array es %d", valor);
}

