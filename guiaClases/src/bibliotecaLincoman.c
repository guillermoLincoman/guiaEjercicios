/*
 * bibliotecaLincoman.c
 *
 *  Created on: 9 sep. 2021
 *      Author: Compumar
 */
#include "bibliotecaLincoman.h"


void limpiar()
{
	printf("\n");
    system("pause");
    system("cls");
}

int suma(int numUno, int numDos)
{
	int resultado;

	resultado = numUno + numDos;
	return resultado;
}

int numMayorTres(int numUno, int numDos, int numTres)
{
	int numMayor;

	if(numUno >numDos){
		if(numUno>numTres)
		{
			numMayor = numUno;
		}else
		{
			numMayor = numTres;
		}
	}else
	{
		if(numDos>numTres)
		{
			numMayor = numDos;
		}
	}

	return numMayor;
}
void numMedioTres(int numUno, int numDos, int numTres)
{
	int numMedio;
	int band = 1;
	if((numUno >numDos && numUno<numTres) || (numUno <numDos && numUno>numTres)){
		numMedio = numUno;
	}else
	{
		if((numDos >numUno && numDos<numTres) || (numDos <numUno && numDos>numTres))
		{
			numMedio = numDos;
		}else{
			if((numTres >numUno && numTres<numDos) || (numTres <numUno && numTres>numDos))
			{
				numMedio = numTres;
			}else
			{
				printf("\nNo existe numero del medio...\n");
				band = 0;
			}
		}
	}
	if(band ==1)
	{
		printf("\nEl numero del medio es %d\n", numMedio);
	}
}

float promedio(int num, int tam)
{
	float promedio;

	promedio = num/tam;
	return promedio;
}
float promedioVector(int lista[], int tam)
{
	float prom;
	int acum;
	acum = 0;
	int i;
	for (i = 0; i < tam; ++i) {
		acum = acum + lista[i];
	}
	prom = promedio(acum, tam);
	return prom;
}

void sort(int* numUno, int* numDos)
{
	int aux;

	aux = *numUno;
	*numUno = *numDos;
	*numDos = aux;
}
//mayor menor = 1 // menor mayor = 0
void sortArrayCriterio(int lista[], int tam, int criterio)
{
	int i;
	int j;
	if(criterio == 1)
	{
		for (i = 0; i < tam-1; ++i)
		{
			for (j = i+1; j < tam; ++j) {
				if(lista[i]<lista[j])
				{
					sort(&lista[i], &lista[j]);
				}
			}
		}
	}else{
		if(criterio == 0)
		{
			for (i = 0; i < tam-1; ++i)
			{
				for (j = i+1; j > tam; ++j) {
					if(lista[i]<lista[j])
					{
						sort(&lista[i], &lista[j]);
					}
				}
			}
		}
	}

}


int buscarLibre(int lista[], int tam)
{
	int i;
	int index;
	index = -1;


	for(i=0;i<tam;i++)
	{
		if(lista[i]==-1)
		{
			index = i;
			break;
		}
	}
	return index;

}

void inicializarArray(int lista[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i]= -1;
	}
}
//si devuelve -1 no hay clientes, si devuelve 0 hay clientes;
int mostrarClientes(int id[], char civil[][10], int edad[], int temperatura[], char genero[][10], int tam)
{
	int i;
	int clientes;
	int numCliente;
	numCliente = 1;
	clientes = -1;
	printf("\n*************************\n");
	printf("* Lista de pasajeros *\n");
	printf("*************************\n");
	printf("*   ID 	ESTADO CIVIL   EDAD   TEMPERATURA    GENERO *\n");
	for(i=0;i<tam;i++)
	{
		if(id[i]!=-1)
		{
			printf("%d. ", numCliente);
			mostrarUnClientes(id[i], civil[i], edad[i], temperatura[i], genero[i]);
			numCliente++;
			clientes = 0;
		}
	}
	return clientes;
}
void mostrarUnClientes(int id, char civil[], int edad, int temperatura, char genero[])
{
    printf("%d  --   %s   --    %d    --    %d    --    %s\n", id, civil, edad, temperatura, genero);
}
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=0;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=1;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    			strncpy(guardar, stringAux, rangoMax);
    			error = 1;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}

int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=0;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    char aux;
    int i;
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	strlwr(stringAux);
    	aux = toupper(stringAux[0]);
    	stringAux[0] = aux;
    	for (i = 0; i < strlen(stringAux); ++i)
    	{
    		if(stringAux[i] == ' ')
    		{
    			aux = toupper(stringAux[i+1]);
    			stringAux[i+1] = aux;
    			break;
    		}
    		i++;
    	}
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=1;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    	    	strlwr(stringAux);
    	    	aux = toupper(stringAux[0]);
    	    	stringAux[0] = aux;
    	    	for (i = 0; i < strlen(stringAux); ++i)
    	    	{
    	    		if(stringAux[i] == ' ')
    	    		{
    	    			aux = toupper(stringAux[i+1]);
    	    			stringAux[i+1] = aux;
    	    			break;
    	    		}
    	    		i++;
    	    	}
    			strncpy(guardar, stringAux, rangoMax);
    			error = 1;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}

int validarLetra(char num[])
{
   int i=0;
   //repite hasta llegar al final de la cadena
   while(num[i] != '\0')
   {
       if (i == 0 && num[i] == '-')
       {
           i++;
           continue;
       }
       if(num[i] < '0' || num[i] > '9')
       {
          return 0;
       }
       i++;
   }
   return 1;
}



float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	float aux;
	int band;

	auxInt = malloc(sizeof(float));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atof(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atof(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atof(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atof(auxInt);
	}
    return aux;
}

int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	int aux;
	int band;

	auxInt = malloc(sizeof(int));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atoi(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atoi(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atoi(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atoi(auxInt);
	}
    return aux;
}
void cargarArrayLetras(char array[], int tam, int max, int min)
{
	int i;
	for(i=0; i<tam; i++)
	{
		getString(&array[i], "Ingrese una letra: ", "Error, ingrese una letra: ", min, max, 5);
	}
}

void cargarArray(int array[], int tam, int max, int min)
{
	int i;
	for(i=0; i<tam; i++)
	{
		array[i] = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un numero: ", min, max, 4);
	}
}

void mostrarVector(int array[], int tam)
{
	int i;
	printf("Listado de numeros ingresado: \n");
	for(i=0; i<tam; i++)
	{
		printf("%d ", array[i]);
	}
}
void mostrarUnaEdad(int edad)
{
	printf("%d \n", edad);
}
void mostrarEdad(int array[], int tam)
{
	int i;
	printf("Listado de edades: \n");
	for(i=0; i<tam; i++)
	{
		printf("%d. ", i);
		mostrarUnaEdad(array[i]);
	}
}

//criterio: 1 = negativo
//			0 = positivo
int cantPosNeg(int array[], int tam, int criterio)
{
	int i;
	int contPos;
	int contNeg;
	int cant;
	contPos = 0;
	contNeg = 0;
	if(criterio == 1)
	{
		for(i=0; i<tam;i++)
		{
			if(array[i]<0)
			{
				contNeg++;
			}
		}
		cant = contNeg;
	}else{
		if(criterio == 0)
		{
			for(i=0; i<tam;i++)
			{
				if(array[i]>=0)
				{
					contPos++;
				}
			}
			cant = contPos;
		}else
		{
			printf("El criterio no es valido...");
		}
	}
	return cant;
}
//criterio: 1 = impar
//			0 = par
int cantParImpar(int array[], int tam, int criterio)
{
	int i;
	int contPar;
	int contImp;
	int cant;
	contPar = 0;
	contImp = 0;
	if(criterio == 1)
	{
		for(i=0; i<tam;i++)
		{
			if(array[i]%2!=0)
			{
				contImp++;
			}
		}
		cant = contImp;
	}else{
		if(criterio == 0)
		{
			for(i=0; i<tam;i++)
			{
				if(array[i]%2==0)
				{
					contPar++;
				}
			}
			cant = contPar;
		}else
		{
			printf("El criterio no es valido...");
		}
	}
	return cant;
}
int sumaPar(int array[], int tam)
{
	int i;
	int sumPar;
	sumPar = 0;
	for(i=0;i<tam;i++)
	{
		if(array[i]%2==0)
		{
			sumPar = sumPar + array[i];
		}
	}
	return sumPar;
}
int sumaPos(int array[], int tam)
{
	int i;
	int sumaPos;
	sumaPos = 0;
	for(i=0;i<tam;i++)
	{
		if(array[i]>0)
		{
			sumaPos = sumaPos + array[i];
		}
	}
	return sumaPos;
}

int numMin(int array[], int tam)
{
	int i;
	int numMenor;
	for(i=0;i<tam;i++)
	{
		if(i == 0 || array[i]<numMenor)
		{
			numMenor = array[i];
		}
	}
	return numMenor;
}
int mayorPar(int array[], int tam)
{
	int i;
	int mayorImpar;
	for(i=0;i<tam;i++)
	{
		if(i == 0 || (array[i]%2==0 && array[i]> mayorImpar))
		{
			mayorImpar = array[i];
		}
	}
	return mayorImpar;
}

int mayorImpar(int array[], int tam)
{
	int i;
	int mayorImpar;
	for(i=0;i<tam;i++)
	{
		if(i == 0 || (array[i]%2!=0 && array[i]> mayorImpar))
		{
			mayorImpar = array[i];
		}
	}
	return mayorImpar;
}

//criterio: 1 = impar
//			0 = par
void mostrarVectorCriterio(int array[], int tam, int criterio)
{
	int i;

	if(criterio == 1)
	{
		printf("Numeros impares: \n");
		for(i=0; i<tam;i++)
		{
			if(array[i]%2!=0)
			{

				printf("%d ", array[i]);
			}
		}
	}else{
		if(criterio == 0)
		{
			printf("Numeros pares: \n");
			for(i=0; i<tam;i++)
			{
				if(array[i]%2==0)
				{

					printf("%d ", array[i]);
				}
			}
		}else
		{
			printf("El criterio no es valido...");
		}
	}
}
int sumarVector(int array[], int tam)
{
	int i;
	int acum;
	acum = 0;
	for (i = 0; i < tam; ++i)
	{
		acum = acum + array[i];
	}
	return acum;
}
void posImparVector(int array[], int tam)
{
	int i;
		printf("Numeros en posiciones impares: \n");
		for(i=0; i<tam;i++)
		{
			if(i%2!=0 )
			{

				printf("%d ", array[i]);
			}
		}
}

void mostrarNumF(float num)
{
	printf("El numero es: %.2f", num);
}
//La función retorna 1 si es par y 0 en caso contrario
int numParImpar(int num)
{
	int parImpar;
	if(num%2==0)
	{
		parImpar = 1;
	}else
	{
		parImpar = 0;
	}
	return parImpar;
}
//funciones no usar
int Sumar1(int numUno, int numDos)
{
	int suma;
	suma = numUno + numDos;
	return suma;
}
int Sumar2(void)
{
	int numUno;
	int numDos;
	int suma;
	numUno = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	numDos = cargarUnEntero("Ingrese otro numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	suma = numUno + numDos;
	return suma;
}

void  Sumar3(int numUno, int numDos)
{
	int suma;
	suma = numUno + numDos;
	printf("El resultado de %d + %d es: %d", numUno, numDos, suma);
}
void Sumar4(void)
{
	int numUno;
	int numDos;
	int suma;
	numUno = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	numDos = cargarUnEntero("Ingrese otro numero: ", "Error, ingrese un caracter numerico: ", -2147483647, 2147483647, 4);
	suma = numUno + numDos;
	printf("El resultado de %d + %d es: %d\n", numUno, numDos, suma);
}
int factorial(int fact, int num){
	if(num>0){
		fact=factorial(fact,num-1);
	    fact=fact*num;
	}else{
	    fact=1;
	}
	return fact;
}
//criterio 1 = °F a °C | criterio 0 = °C a °F
float celAFarCriterio(float num, int criterio)
{
	float temperatura;
	if(criterio == 0)
	{
		temperatura = (num * 1.8) + 32;
	}else
	{
		temperatura = (num - 32) / 1.8;
	}
	return temperatura;

}
