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
/** \brief Valida que el dato sea una letra
 *
 * \param char num[]: recibe el dato a analizar
 *
 * \return retorna 0 si es un numero, en caso de ser una letra retorna 1
 *
 */
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
/** \brief Intercambia el valor de dos datos
 *
 * \param int* numUno: recibe un puntero al primer numero
 * \param int* numDos: recibe un puntero al segundo numero
 *
 *
 */
void sort(int* numUno, int* numDos)
{
	int aux;

	aux = *numUno;
	*numUno = *numDos;
	*numDos = aux;
}

/** \brief Pide, valida y devuelve un numero entero
 *
 * \param char* mensaje: Recibe el mensaje para pedir entero
 * \param char* mensajeError: Recibe el mensaje de error al pedir entero
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el entero
 *
 */
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
/** \brief Pide, valida y devuelve un numero Float
 *
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el Float
 *
 */
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
/** \brief Pide, valida, devuelve y pone primer caracter Mayuscula a una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=1;
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
    	error=0;
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
    			error = 0;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}
/** \brief Pide, valida y devuelve una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
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
/** \brief Inicializa los campos de una estructura en 0
 *
 * \param eProductos lista[] recibe la estructura a inicializar
 * \param int tam: el tamaño de lugares que se desea inicializar
 *
 */
void inicializarEstructura(eProductos lista[], int tam)
{
	int i;
		for(i=0;i<tam;i++)
		{
			lista[i].isEmpty = 0;
		}
}
/** \brief Busca un lugar indice libre para cargar
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna un indice libre, en caso de error retorna -1
 *
 */
int indexLibre(eProductos lista[], int tam)
{
	int i;
	int index;
	index = -1;

	if(lista != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief Busca el indice donde se encuentra el id recibido
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int id: recibe el id que se desea buscar
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna el indice donde se encuentra el id, en caso de error retorna -1
 *
 */
int buscarIndexId(eProductos lista[], int tam, int id)
{
	int i;
	int index;
	index =-1;
	if(lista != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].idProducto==id)
			{
				index = i;
			}
		}
	}
	return index;
}

/** \brief Pide datos y carga una estructura
 *
 * \param int newId: recibe el id de la nueva estructura
 *
 * \return retorna una estructura con datos cargados
 *
 */
eProductos altaProducto(int newId)
{
	eProductos productoIngresado;

	productoIngresado.idProducto = newId;
	printf("Ingrese descripcion: ");
	fflush(stdin);
	scanf("%[^\n]", productoIngresado.descripcion);
	productoIngresado.nacionalidad=cargarUnEntero("Ingrese una naciondalidad: ", "Error, ingrese una naciondalidad valida(entre 1 y 3): ", 1, 3, 4);
	productoIngresado.tipo =cargarUnEntero("Ingrese un tipo: ", "Error, ingrese un tipo valido(entre 1 y 4): ", 1, 4, 4);
	productoIngresado.precio =cargarUnEntero("Ingrese el precio: ", "Error, ingrese un precio mayor a 0: ", 0, 2147483647, 4);
	productoIngresado.isEmpty = 1;


	return productoIngresado;
}

/** \brief Libera el lugar e inicializa todo en 0
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int id: recibe el id del producto que se va a borrar
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna 0 si el producto es borrado, en caso de error retorna -1
 *
 */
int bajaProducto(eProductos lista[], int id, int tam)
{
	int i;
	int error;
	error = 1;
	if(lista != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].idProducto==id)
			{
				lista[i].idProducto=0;
				strcpy(lista[i].descripcion, " ");
				lista[i].nacionalidad= 0;
				lista[i].tipo = 0;
				lista[i].precio = 0.00;
				lista[i].isEmpty = 0;
				error = 0;
				break;
			}
		}
	}

	return error;
}

/** \brief Borra un producto de la estructura segun el id que indique el usuario
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int ultimoId: recibe el ultimo id ingreado para validad
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna 0 si el producto es borrado, en caso de error retorna -1
 *
 */
int borrarProducto(eProductos lista[], int tam, int ultimoId)
{
	int idBorrar;
	int error;
	error = 1;
	if(lista != NULL)
	{
		mostrarProductos(lista, tam);
		idBorrar = cargarUnEntero("Ingrese el id a borrar: ", "Error, ingrese un id valido: ", 999, ultimoId, 4);
		error = bajaProducto(lista, idBorrar, tam);
		if(error == 1){
			printf("\n\nError, el id no es valido....\n");
		}
	}

	return error;
}

/** \brief Carga un producto en un indice vacio de la estructura
 *
 * \param eProductos lista[] recibe la estructura a cargar
 * \param int newId: recibe el id que se le va a otorgar al producto
 * \param int tam: el tamaño de lugares disponibles
 *
 */
void cargarProducto(eProductos lista[], int newId, int tam)
{
	int index;
	if(lista != NULL)
	{
		index = indexLibre(lista, tam);
		if(index>=0)
		{
			lista[index] = altaProducto(newId);
		}else{
			printf("\nNo hay lugar....\n");
		}
	}
}

/** \brief Modifica un producto de la estructura segun id
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int ultimoId: recibe el ultimo id ingreado para validad
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna 0 si se realizo el cambio, en caso de error retorna 1
 *
 */
int modificarProducto(eProductos lista[], int ultimoId, int tam)
{
	int idMod;
	int indexMod;
	int opcion;
	int error;
	error = 1;
	if(lista != NULL)
	{
		mostrarProductos(lista, tam);
		idMod = cargarUnEntero("Ingrese el id de producto a modificar: ", "Error, ingrese un id valido: ", 999, ultimoId, 4);
		indexMod = buscarIndexId(lista, tam, idMod);
		do{
			   	printf("\n***************************\n");
			   	printf("*    Menu Modificar       *\n");
			   	printf("***************************\n");
			   	printf("*  ¿Que desear modificar? *\n");
			   	printf("* 1. Descripcion          *\n");
			   	printf("* 2. Nacionalidad         *\n");
			   	printf("* 3. Tipo                 *\n");
			   	printf("* 4. Precio               *\n");
			   	printf("* 0. SALIR                *\n");
			   	printf("***************************\n");
			    opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 0, 4, 4);

				switch(opcion)
				{
					case 1:
						mostrarUnProducto(lista[indexMod]);
						printf("\n");
						printf("Ingrese nueva descripcion: ");
						fflush(stdin);
						scanf("%[^\n]", lista[indexMod].descripcion);
						error = 0;
						limpiar();
						break;
					case 2:
						mostrarUnProducto(lista[indexMod]);
						printf("\n");
						lista[indexMod].nacionalidad=cargarUnEntero("Ingrese una nueva naciondalidad: ", "Error, ingrese una naciondalidad valida(entre 1 y 3): ", 1, 3, 4);
						error = 0;
						limpiar();
						break;
					case 3:
						mostrarUnProducto(lista[indexMod]);
						printf("\n");
						lista[indexMod].tipo =cargarUnEntero("Ingrese un nuevo tipo: ", "Error, ingrese un tipo valido(entre 1 y 4): ", 1, 4, 4);
						error = 0;
						limpiar();
						break;
					case 4:
						mostrarUnProducto(lista[indexMod]);
						printf("\n");
						lista[indexMod].precio =cargarUnEntero("Ingrese el nuevo precio: ", "Error, ingrese un precio mayor a 0: ", 0, 2147483647, 4);
						error = 0;
						limpiar();
						break;
				}
		}while(opcion != 0);
	}

	return error;
}

/** \brief Muestra los campos de las estructuras cargadas
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tamaño de lugares disponibles
 *
 */
void mostrarProductos(eProductos lista[], int tam)
{
	int i;
	if(lista != NULL)
	{
		printf("\nID	DESCRIPCION	 NACIONALIDAD  	 TIPO 	PRECIO\n");
		for (i = 0; i < tam; ++i) {
			if(lista[i].isEmpty==1)
			{
				mostrarUnProducto(lista[i]);
			}

		}
	}
}
/** \brief Muestra una de las estructuras cargadas
 *
 * \param eProductos lista recibe la estructura en una posicion a mostrar
 *
 */
void mostrarUnProducto(eProductos lista)
{
	printf("%4d %15s    \t%4d  \t%4d\t%.2f\n",lista.idProducto, lista.descripcion,
		    lista.nacionalidad, lista.tipo, lista.precio);
}

/** \brief Intercambia el valor de dos datos de una estructura
 *
 * \param eProductos *prodUno: recibe un puntero a la primer  estructura
 * \param eProductos *prodDos: recibe un puntero a la segunda  estructura
 *
 */
void eSort(eProductos *prodUno, eProductos *prodDos)
{
	eProductos prodAux;

	prodAux = *prodUno;
	*prodUno = *prodDos;
	*prodDos = prodAux;
}
/** \brief Ordena una estructura segun el precio
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: criterio de ordenamiento mayor menor = 1 // menor mayor = 0
 * \param int tam: el tamaño de lugares disponibles
 */
void sortEstructuraPrecio(eProductos lista[], int tam, int criterio)
{
	int i;
	int j;
	if(lista != NULL)
	{
		if(criterio == 1)
		{
			for (i = 0; i < tam-1; ++i){
				for (j = i+1; j < tam; ++j){
					if(lista[i].precio<lista[j].precio){
						eSort(&lista[i], &lista[j]);
					}
				}
			}
		}else{
			if(criterio == 0){
				for (i = 0; i < tam-1; ++i) {
					for (j = i+1; j < tam; ++j) {
						if(lista[i].precio>lista[j].precio){
							eSort(&lista[i], &lista[j]);
						}
					}
				}
			}
		}
	}
}
/** \brief Ordena una estructura segun la descripcion
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: criterio de ordenamiento mayor menor = 1 // menor mayor = 0
 * \param int tam: el tamaño de lugares disponibles
 */
void sortEstructuraDesc(eProductos lista[], int tam, int criterio)
{
	int i;
	int j;
	if(lista != NULL)
	{
		if(criterio == 1)
		{
			for (i = 0; i < tam-1; ++i){
				for (j = i+1; j < tam; ++j){
					if(strcmp(lista[i].descripcion, lista[j].descripcion)>0){
						eSort(&lista[i], &lista[j]);
					}
				}
			}
		}else{
			if(criterio == 0){
				for (i = 0; i < tam-1; ++i) {
					for (j = i+1; j < tam; ++j) {
						if(strcmp(lista[i].descripcion, lista[j].descripcion)<0){
							eSort(&lista[i], &lista[j]);
						}
					}
				}
			}
		}
	}
}

/** \brief Inicializa los campos de un array en -1
 *
 * \param int lista[] recibe el array a inicializar
 * \param int tam: el tamaño de lugares de la estructura
 *
 */
void inicializarArray(int lista[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i]= -1;
	}
}
/** \brief Busca un lugar indice libre para cargar
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tamaño de lugares disponibles
 *
 * \return retorna un indice libre, en caso de error retorna -1
 *
 */
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

/** \brief Carga un producto en un indice vacio del array
 *
 * \param int array[] recibe el array a cargar
 * \param int min: El numero menor que recibe el array
 * \param int max: El numero mayor que recibe el array
 * \param int tam: el tamaño del array
 *
 */
void cargarArray(int array[], int tam, int max, int min)
{
	int i;
	for(i=0; i<tam; i++)
	{
		array[i] = cargarUnEntero("Ingrese un numero: ", "Error, ingrese un numero: ", min, max, 4);
	}
}

/** \brief Carga un array con letras
 *
 * \param int array[] recibe el array a cargar
 * \param int min: La menor cantidad de letras que recibe el array
 * \param int max: La mayor cantidad de letras que recibe el array
 * \param int tam: el tamaño del array
 *
 */
void cargarArrayLetras(char array[], int tam, int max, int min)
{
	int i;
	for(i=0; i<tam; i++)
	{
		getString(&array[i], "Ingrese una letra: ", "Error, ingrese una letra: ", min, max, 5);
	}
}

/** \brief Saca el promedio de los numeros cargados en un vector
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna el promedio de los numeros del array.
 *
 */
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

/** \brief Saca la suma de numeros cargados en un vector
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna la suma de los numeros del array.
 *
 */
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
/** \brief Muestra en la pantalla los numeros en las posiciones impares
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 *
 */
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

/** \brief Muestra la cantidad de numeros positivos o negativos segun el criterio
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 * \param int criterio: 1 para negativos, 0 para positivos
 *
 * \return retorna la cantidad de positivos o negativos segun el criterio
 *
 */
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

/** \brief Muestra la cantidad de numeros pares o impares segun el criterio
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 * \param int criterio: 1 para impares, 0 para pares
 *
 * \return retorna la cantidad de pares o impares segun el criterio
 *
 */
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

/** \brief Da la suma de los numeros pares de un array
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna la suma de los numeros pares de un array
 *
 */
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
/** \brief Da la suma de los numeros positivos de un array
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna la suma de los numeros positivos de un array
 *
 */
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

/** \brief Muestra el numero mayor de los pares
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna el numero mayor de los pares de un array
 *
 */
int mayorPar(int array[], int tam)
{
	int i;
	int mayorPar;
	for(i=0;i<tam;i++)
	{
		if(i == 0 || (array[i]%2==0 && array[i]> mayorPar))
		{
			mayorPar = array[i];
		}
	}
	return mayorPar;
}

/** \brief Muestra el numero mayor de los impares
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna el numero mayor de los impares de un array
 *
 */
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

/** \brief Muestra el numero menor de un array
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 *
 * \return retorna el numero menor de un array
 *
 */
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

/** \brief Muestra un vector segun el criterio
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 * \param int criterio: 1 para impares, 0 para pares
 *
 */
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


//mayor menor = 1 // menor mayor = 0
/** \brief Ordena un array segun el criterio
 *
 * \param int lista[]: recibe el array a analizar
 * \param int tam: el tamaño del array
 * \param int criterio: 1 mayor menor, 0 menor mayor
 *
 */
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


/** \brief Muestra todos los clientes cargados en un array
 *
 * \param int id[]: recibe el id a mostrar
 * \param char civil[][10]: recibe el estado civil a mostrar
 * \param int edad[]: recibe la edad a mostrar
 * \param int temperatura[]: recibe la temperatura a mostrar
 * \param genero[][10]: recibe el genero a mostrar
 * \param int tam: el tamaño del array
 *
 * \return si devuelve -1 no hay clientes, si devuelve 0 hay clientes
 *
 */
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

/** \brief Muestra un cliente segun la ubicacion indicada
 *
 * \param int id[]: recibe el id a mostrar
 * \param char civil[][10]: recibe el estado civil a mostrar
 * \param int edad[]: recibe la edad a mostrar
 * \param int temperatura[]: recibe la temperatura a mostrar
 * \param genero[][10]: recibe el genero a mostrar
 * \param int tam: el tamaño del array
 *
 */
void mostrarUnClientes(int id, char civil[], int edad, int temperatura, char genero[])
{
    printf("%d  --   %s   --    %d    --    %d    --    %s\n", id, civil, edad, temperatura, genero);
}
/** \brief Muestra todos los numeros cargados en un vector
 *
 * \param int array[]: recibe el array a mostrar
 * \param int tam: el tamaño del array
 *
 */
void mostrarVector(int array[], int tam)
{
	int i;
	printf("Listado de numeros ingresado: \n");
	for(i=0; i<tam; i++)
	{
		printf("%d ", array[i]);
	}
}
/** \brief Suma Dos numeros enteros.
 *
 * \param int numUno recibe el primer operando
 * \param int numDos recibe el segundo  operando
 *
 * \return retorna la suma de los Dos operando
 *
 */
int suma(int numUno, int numDos)
{
	int resultado;

	resultado = numUno + numDos;
	return resultado;
}

/** \brief Saca el promedio de la suma de numeros y la cantidad de numeros que eran
 *
 * \param int num: Suma de los numeros de la que se quiere sacar el promedio
 * \param int tam: cantidad de numeros que se ingreso
 * \return retorna la resta de los Dos operando
 *
 */
float promedio(int num, int tam)
{
	float promedio;

	promedio =(float) num/tam;
	return promedio;
}

/** \brief Busca el numero mayor de Tres numeros
 *
 * \param int numUno: primer numero
 * \param int numDos: segundo numero
 * \param int numTres: tercer numero
 *
 * \return retorna el numero mayor de los tres
 *
 */
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
/** \brief Busca el numero del medio de Tres numeros, muestra el numero del medio de los 3 en caso de que lo haya
 *
 * \param int numUno: primer numero
 * \param int numDos: segundo numero
 * \param int numTres: tercer numero
 *

 *
 */
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

//
/** \brief Verifica que el numero sea par o impar
 *
 * \param int numUno: recibe el dato a analizar
 *
 * \return La función retorna 1 si es par y 0 en caso contrario
 *
 */
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

/** \brief Calcula el factorial de un numero
 *
 * \param int num recibe un operando
 * \return retorna el factorial del operando recibido
 *
 */
unsigned long factorial(int num)
{
	long fact;
	fact = 0;
	if(num>0){
		fact=factorial(num-1);
	    fact=fact*num;
	}else{
	    fact=1;
	}
	return fact;
}
//FUNCIONES NO USAAR
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
void mostrarNumF(float num)
{
	printf("El numero es: %.2f", num);
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



