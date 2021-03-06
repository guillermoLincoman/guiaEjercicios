/*
 * bibliotecaLincoman.c
 *
 *  Created on: 9 sep. 2021
 *      Author: Compumar
 */
#include "bibliotecaLincoman.h"


void menuTipo()
{
	printf("\n******************\n");
	printf("* MENU TIPOS     *\n");
	printf("******************\n");
	printf("*                *\n");
    printf("* 1. IPHONE      *\n");
    printf("* 2. IPAD         *\n");
    printf("* 3. MAC        *\n");
    printf("* 4. ACCESORIOS  *\n");
    printf("******************\n");
}
void menuNacionalidad()
{
	printf("\n*********************\n");
	printf("* MENU NACIONALIDAD *\n");
	printf("*********************\n");
	printf("*                   *\n");
    printf("* 1. EEUU           *\n");
    printf("* 2. CHINA          *\n");
    printf("* 3. OTRO           *\n");
    printf("*********************\n");
}

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
    //2.creo una cadena auxiliar con el tama?o maximo ingresado por el usuario
    char stringAux[rangoMax];
    char aux;
    int i;
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tama?o de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tama?o de auxiliar es mayor o igual al minimo y menor o igual al maximo
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
    //2.creo una cadena auxiliar con el tama?o maximo ingresado por el usuario
    char stringAux[rangoMax];
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tama?o de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tama?o de auxiliar es mayor o igual al minimo y menor o igual al maximo
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
 * \param int tam: el tama?o de lugares que se desea inicializar
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
 * \param int tam: el tama?o de lugares disponibles
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
 * \param int tam: el tama?o de lugares disponibles
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
	menuNacionalidad();
	productoIngresado.nacionalidad=cargarUnEntero("Ingrese una naciondalidad: ", "Error, ingrese una naciondalidad valida(entre 1 y 3): ", 1, 3, 4);
	productoIngresado.tipo =cargarUnEntero("Ingrese un tipo: ", "Error, ingrese un tipo valido(entre 1 y 4): ", 1, 4, 4);
	productoIngresado.precio =cargarUnEntero("Ingrese el precio: ", "Error, ingrese un precio mayor a 0: ", 0, 2147483647, 4);
	productoIngresado.isEmpty = 1;


	return productoIngresado;
}

/** \brief Pide datos y carga una estructura
 *
 * \param int newId: recibe el id de la nueva estructura
 *
 * \return retorna una estructura con datos cargados
 *
 */
eProductos altaProductoConListas(eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo, int newId)
{
	eProductos productoIngresado;
	productoIngresado.idProducto = newId;
	printf("Ingrese descripcion: ");
	fflush(stdin);
	scanf("%[^\n]", productoIngresado.descripcion);
	mostrarNacionalidades(nac, tamNac);
	productoIngresado.nacionalidad=cargarUnEntero("Ingrese una naciondalidad: ", "Error, ingrese una naciondalidad valida(entre 1 y 3): ", 1, 3, 4);
	mostrarTipos(tipoProd, tamTipo);
	productoIngresado.tipo =cargarUnEntero("Ingrese un tipo: ", "Error, ingrese un tipo valido(entre 1 y 4): ", 1, 4, 4);
	productoIngresado.precio =cargarUnEntero("Ingrese el precio: ", "Error, ingrese un precio mayor a 0: ", 0, 2147483647, 4);
	productoIngresado.isEmpty = 1;


	return productoIngresado;
}


/** \brief Pide datos y carga una estructura
 *
 * \return retorna una estructura con datos cargados
 *
 */
eJugador cargarJugador()
{
	eJugador nuevoJugador;
	getUsuario(nuevoJugador.nombre, "Ingrese nombre:", "Error, ingrese un nombre valido:", 1, 40, 4);
	nuevoJugador.golesMetidos=cargarUnEntero("Ingrese la cantidad de goles metidos: ", "Error, ingrese una cantidad valida(entre 0 y 500): ", 0, 500, 4);
	nuevoJugador.partidosJugados =cargarUnEntero("Ingrese la cantidad de partidos jugados: ", "Error, Ingrese la cantidad de partidos jugados: ", 1, 400, 4);
	nuevoJugador.promedioGoles = (float)nuevoJugador.golesMetidos/nuevoJugador.partidosJugados;
	return nuevoJugador;
}


/** \brief Libera el lugar e inicializa todo en 0
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int id: recibe el id del producto que se va a borrar
 * \param int tam: el tama?o de lugares disponibles
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
 * \param int tam: el tama?o de lugares disponibles
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
 * \param int tam: el tama?o de lugares disponibles
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


/** \brief Carga un producto en un indice vacio de la estructura
 *
 * \param eProductos lista[] recibe la estructura a cargar
 * \param int newId: recibe el id que se le va a otorgar al producto
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void cargarProductoConListados(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo, int newIde)
{
	int index;
	if(lista != NULL)
	{
		index = indexLibre(lista, tam);
		if(index>=0)
		{
			lista[index] = altaProductoConListas(nac, tipoProd, tam, tamNac, tamTipo, newIde);
		}else{
			printf("\nNo hay lugar....\n");
		}
	}
}

/** \brief Carga un producto en un indice vacio de la estructura
 *
 * \param eProductos lista[] recibe la estructura a cargar
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void altaJugador(eJugador lista[], int tam)
{
	int i;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i) {

			lista[i] = cargarJugador();
		}
	}
}


/** \brief Modifica un producto de la estructura segun id
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int ultimoId: recibe el ultimo id ingreado para validad
 * \param int tam: el tama?o de lugares disponibles
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
		idMod = cargarUnEntero("Ingrese el id de producto a modificar: ", "Error, ingrese un id valido: ", 999, 1003, 4);
		indexMod = buscarIndexId(lista, tam, idMod);
		do{
			   	printf("\n***************************\n");
			   	printf("*    Menu Modificar       *\n");
			   	printf("***************************\n");
			   	printf("*  ?Que desear modificar? *\n");
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
						menuNacionalidad();
						mostrarUnProducto(lista[indexMod]);
						printf("\n");
						lista[indexMod].nacionalidad=cargarUnEntero("Ingrese una nueva naciondalidad: ", "Error, ingrese una naciondalidad valida(entre 1 y 3): ", 1, 3, 4);
						error = 0;
						limpiar();
						break;
					case 3:
						mostrarUnProducto(lista[indexMod]);
						menuTipo();
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
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void mostrarNacionalidades(eNacionalidad nac[], int tam)
{
	int i;
	if(nac != NULL)
	{
		printf("---------------------\n");
		printf("\nID	DESCRIPCION	 \n");
		for (i = 0; i < tam; ++i) {
			mostrarUnaNacionalidad(nac[i]);
		}
	}
}


/** \brief Muestra una de las estructuras cargadas
 *
 * \param eProductos lista recibe la estructura en una posicion a mostrar
 *
 */
void mostrarUnaNacionalidad(eNacionalidad nac)
{
	printf("---------------------\n");
	printf("%4d %15s\n",nac.idNacionalidad, nac.descripcionNacionalidad);
	printf("---------------------\n");
}

/** \brief Muestra los campos de las estructuras cargadas
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void mostrarTipos(eTipoProduco tipos[], int tam)
{
	int i;
	if(tipos != NULL)
	{
		printf("---------------------\n");
		printf("\nID	DESCRIPCION	 \n");
		for (i = 0; i < tam; ++i) {
				mostrarUnTipo(tipos[i]);
		}
	}
}


/** \brief Muestra una de las estructuras cargadas
 *
 * \param eProductos lista recibe la estructura en una posicion a mostrar
 *
 */
void mostrarUnTipo(eTipoProduco tipos)
{
	printf("---------------------\n");
	printf("%4d %15s\n",tipos.idTipo, tipos.descripcionTipo);
	printf("---------------------\n");
}

/** \brief Muestra los campos de las estructuras cargadas
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
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

/** \brief Muestra los campos de las estructuras cargadas con su descripcion y tipo
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void mostrarProductosCompleto(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo)
{
	int i;
	if(lista != NULL)
	{
		printf("\nID	DESCRIPCION	 NACIONALIDAD  	 TIPO 	PRECIO\n");
		for (i = 0; i < tam; ++i) {
			if(lista[i].isEmpty ==1)
			{
				mostrarUnProductosCompleto(lista[i], nac, tipoProd, tamNac, tamTipo);
			}
		}
	}
}


void mostrarProductosCompletoSegunTipo(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo, int criterio)
{
	int i;
	if(lista != NULL){
		printf("\nID	DESCRIPCION	 NACIONALIDAD  	 TIPO 	PRECIO\n");
		for (i = 0; i < tam; ++i) {
			if(lista[i].isEmpty ==1 && lista[i].tipo == criterio){
				mostrarUnProductosCompleto(lista[i], nac, tipoProd, tamNac, tamTipo);
			}
		}
	}
}

/** \brief Muestra una de las estructuras cargadas con sus descripcionesy tipo
 *
 * \param eProductos lista recibe la estructura en una posicion a mostrar
 * \param eNacionalidad nac recibe la estructura en una posicion a mostrar
 * \param eTipoProduco tipoProd recibe la estructura en una posicion a mostrar
 *
 */
void mostrarUnProductosCompleto(eProductos lista, eNacionalidad nac[], eTipoProduco tipoProd[], int tamNac, int tamTipo)
{
	int n;
	int t;
	for (n = 0; n < tamNac; ++n) {
		if(lista.nacionalidad == nac[n].idNacionalidad)
		{
			for (t = 0; t < tamTipo; ++t) {
				if(lista.tipo == tipoProd[t].idTipo)
				{
					printf("%4d %15s    \t%8s  \t%8s\t%.2f\n",lista.idProducto, lista.descripcion,
						     nac[n].descripcionNacionalidad, tipoProd[t].descripcionTipo, lista.precio);
					break;
				}
			}
		}
	}

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
 * \param int tam: el tama?o de lugares disponibles
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


/** \brief Muestra El o los productos mas caros
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
 */
void prodMasCaros(eProductos lista[], int tam)
{

	int prodMayor;
	int idMayor;
	int auXiDMayor[tam];
	int auxPrecio[tam];
	int contAux;
	int index;
	contAux=-1;
	int i;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i){
			//si lista es mayor a prodMayor o i es igual igual a 0
			if(lista[i].precio>=prodMayor || i==0)
			{
					if(lista[i].precio == prodMayor)
					{
						contAux++;
						auxPrecio[contAux]=lista[i].precio;
						auXiDMayor[contAux]=lista[i].idProducto;
					}else{
						prodMayor = lista[i].precio;
						idMayor = lista[i].idProducto;
					}
			}
		}
		if(auxPrecio[contAux] == prodMayor)
		{
			printf("\nProductos Mas Caros: \n");
			index = buscarIndexId(lista, tam, idMayor);
			mostrarUnProducto(lista[index]);
			for (i = 0; i <= contAux; ++i) {
				index = buscarIndexId(lista, tam, auXiDMayor[i]);
				mostrarUnProducto(lista[index]);
			}
		}else{
			index = buscarIndexId(lista, tam, idMayor);
			mostrarUnProducto(lista[index]);
		}
	}
}

/** \brief Muestra El o los productos mas caros segun el tipo
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: obtiene el tipo de producto+
 * \param int tam: el tama?o de lugares disponibles
 */
void tipoMasCaros(eProductos lista[], int tam, int criterio)
{
	eProductos aux[tam];
	int cont;
	cont=0;
	int i;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i) {
			if(lista[i].tipo == criterio)
			{
				aux[cont] = lista[i];
				cont++;
			}
		}
		prodMasCaros(aux, cont);
	}
}
/** \brief Muestra El o los productos mas caros segun el tipo
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param eNacionalidad nac[] recibe la estructura a analizar
 * \param eTipoProduco tipoProd[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
 * \param int tamNac: cantidad de nacionalidades
 * \param int tamTipo: cantidad de tipos
 * \param int criterio: obtiene el tipo de producto
 */
int tiposConMasProd(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo)
{
	int error;
	int i;
	int j;
	int contador[tamTipo];
	int mayor;
	//1. inicializo los contadores en 0
	inicializarContador(contador, tamTipo);
	error = 0;
	if(lista != NULL && tipoProd != NULL && nac != NULL)
	{
		//2. recorro la lista de productos
		for (i = 0; i < tam; ++i){
			//3. recorro el tipo de producto por cada producto
			for (j = 0; j < tamTipo; ++j){
				//4. sumo 1 al contador correspondiente al producto
				if(lista[i].tipo == tipoProd[j].idTipo){
					contador[j]++;
					error = 1;
				}
			}
		}
		//5. obtengo el valor del contador con mayor valor
		mayor = numMayor(contador, tamTipo);
		printf("\n\nLos tipos con mas productos son:\n");
		//6. recorro los contadores buscando los que igualen el numero mayor
		//e imprimo los tipos relacionando el indice del contador con el tipo
		for (i = 0; i < tamTipo; ++i) {
			if (contador[i] == mayor){
				printf("%s con %d productos\n", tipoProd[i].descripcionTipo, mayor);
			}
		}
	}
	return error;
}
//necesito saber el ide de que nacionalidad fabrica los tipos indicados
int nacionalidadSoloUnTipo(eProductos lista[], eNacionalidad nac[], eTipoProduco tipoProd[], int tam, int tamNac, int tamTipo, int criterioTipo)
{
	int i;
	int j;
	//int p;
	int auxNac[tamNac];
	int cont;
	cont=0;
	int error;
	error = 0;
	//inicializo el array donde voy a guardar los id en -1
	inicializarArray(auxNac, tamNac);
	//valido que las estructuras no sean nulas
	if(lista != NULL && tipoProd != NULL && nac != NULL)
	{
		//recorro la lista de productos
		for (i = 0; i < tam; ++i) {
			//si el tipo de la lista es igual al criterio "iphone en este caso" entra al if
			if(lista[i].tipo == criterioTipo){
				//si se cumple la condicion guardo el id del producto en el array de ids
				auxNac[cont] = lista[i].nacionalidad;
				//si el id anterior es igual el id actual entra al if
				if(auxNac[cont-1]==auxNac[cont])
				{
					//el id actual vuelve a setearse en -1
					auxNac[cont]=-1;
					//vuelvo a la posicion anterior
					cont--;
				}
				//sumo uno una vez cargado, en caso de entrar al if anterior vuelvo al proximo Id
				//Una vez recorrido el array
				cont++;
				//Una vez cargado un Id indico que funciono y error = 1
				error=1;
			}
		}
		//Con los id que tiene al menos un iphone
		//vuelvo a recorrer los productos "i"
		for (i = 0; i < tam; ++i) {
			//recorro las nacionalidades que tienen iphone "j"
			for (j = 0; j < cont-1; ++j) {
				//si la nacionalidad del producto en i es igual a la nacionalidad en j
				if(lista[i].nacionalidad == auxNac[j]){
					//si el producto de la nacionalidad cargada anteriormente
					//tiene un producto diferente al del criterio de tipo entra
					if(lista[i].tipo != criterioTipo)
					{
						//borro el id cargado y borro un lugar del contador
						auxNac[j]=-1;
						cont--;
					}
				}
			}
		}
		//recorro las nacionalidade
		for (i = 0; i < tamNac; ++i) {
				if(nac[i].idNacionalidad==auxNac[0])
				{
					printf("La nacionalidad %s solo hace ", nac[i].descripcionNacionalidad);
				}
		}
	}
	return error;


}


/** \brief Muestra El producto mas barato
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: tipo de producto a analizar
 * \param int tam: el tama?o de lugares disponibles
 */
void masBaratoTipo(eProductos lista[], int tam, int criterio)
{
	eProductos auxLista;
	int i;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i){
			if((lista[i].tipo == criterio && lista[i].isEmpty == 1) || i ==0)
			{
				if(lista[i].precio<auxLista.precio || i==0)
				{
					auxLista = lista[i];
				}
			}
		}
	}
	menuTipo();
	printf("\nEl producto mas barato de tipo %d es:\n\n", criterio);
	mostrarUnProducto(auxLista);
}

/** \brief Muestra los productos mayores al precio indicado por el usuario
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: tipo de producto a analizar
 * \param int precio: precio minimo de producto
 * \param int tam: el tama?o de lugares disponibles
 */
void masMontoTipo(eProductos lista[], int tam, int precio, int criterio)
{
	int i;
	int band;
	band = 1;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i){
			if((lista[i].tipo == criterio && lista[i].isEmpty == 1)){
				if(lista[i].precio>=precio){
					mostrarUnProducto(lista[i]);
					band = 0;
				}
			}
		}
		if(band==1){
			printf("No hay productos de tipo %d con un precio mayor a $%d", criterio, precio);
		}
	}
}

/** \brief Muestra productos segun nacionalidad
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: nacionalidad a analizar
 * \param int tam: el tama?o de lugares disponibles
 */
void mostrarProdNac(eProductos lista[], int tam, int criterio)
{
	int i;
	if(lista != NULL){
		for (i = 0; i < tam; ++i){
			if((lista[i].nacionalidad == criterio && lista[i].isEmpty == 1)){
				mostrarUnProducto(lista[i]);
			}
		}
	}

}


/** \brief Muestra el promedio de los productos segun el tipo
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: segun el criterio se imprime el tipo
 * \param int tam: el tama?o de lugares disponibles
 */
void promedioTipoProd(eProductos lista[], int tam, int criterio)
{
	eProductos auxLista[tam];
	int i;
	int j;
	float prom;
	char tipo[14];
	j=0;
	if(lista != NULL)
	{
		for (i = 0; i < tam; ++i) {
			if(lista[i].tipo == criterio)
			{
				auxLista[j]=lista[i];
				j++;
			}
		}
		prom = promedioProductos(auxLista, j);
		switch(criterio)
		{
			case 1:
				strcpy(tipo, "IPHONE");
				break;
			case 2:
				strcpy(tipo, "MAC");
				break;
			case 3:
				strcpy(tipo, "IPAD");
				break;
			case 4:
				strcpy(tipo, "ACCESORIOS");
				break;
		}
		printf("El promedio de %s es: $%.2f", tipo, prom);
	}
}


/** \brief Saca el promedio de los numeros cargados en un vector
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tama?o del array
 *
 * \return retorna el promedio de los numeros del array.
 *
 */
float promedioProductos(eProductos lista[], int tam)
{
	float prom;
	int acum;
	acum = 0;
	int i;
	for (i = 0; i < tam; ++i) {
		if(lista[i].isEmpty==1){
			acum = acum + lista[i].precio;
		}
	}
	prom = promedio(acum, tam);

	return prom;
}


/** \brief Ordena una estructura segun la descripcion
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int criterio: criterio de ordenamiento mayor menor = 1 // menor mayor = 0
 * \param int tam: el tama?o de lugares disponibles
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
 * \param int tam: el tama?o de lugares de la estructura
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

/** \brief Inicializa los campos de un array contador
 *
 * \param int lista[] recibe el array a inicializar
 * \param int tam: el tama?o de lugares de la estructura
 *
 */
void inicializarContador(int lista[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i]= 0;
	}
}

/** \brief Busca un lugar indice libre para cargar
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tama?o de lugares disponibles
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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


/** \brief busca el numero mayor de un array
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tama?o del array
 *
 * \return retorna el numero mayor del array
 *
 */
int numMayor(int array[], int tam)
{
	int numMayor;
	int i;

	for (i = 0; i < tam; ++i) {
		if (array[i]> numMayor || i == 0){
			numMayor = array[i];
		}
	}

	return numMayor;
}

/** \brief Saca el promedio de los numeros cargados en un vector
 *
 * \param int lista[] recibe el array a analizar
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
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
 * \param int tam: el tama?o del array
 *
 */
void mostrarUnClientes(int id, char civil[], int edad, int temperatura, char genero[])
{
    printf("%d  --   %s   --    %d    --    %d    --    %s\n", id, civil, edad, temperatura, genero);
}


/** \brief Muestra todos los numeros cargados en un vector
 *
 * \param int array[]: recibe el array a mostrar
 * \param int tam: el tama?o del array
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

/** \brief Muestra todos los numeros cargados en un vector
 *
 * \param int array[]: recibe el array a mostrar
 * \param int tam: el tama?o del array
 *
 */
void swapArray(int *numUno, int *numDos)
{
	int aux;
	 aux = *numUno;
	*numUno = *numDos;
	*numDos =  aux;
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


/** \brief Verifica que el numero sea par o impar
 *
 * \param int numUno: recibe el dato a analizar
 *
 * \return La funci?n retorna 1 si es par y 0 en caso contrario
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
//criterio 1 = ?F a ?C | criterio 0 = ?C a ?F
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

/** \brief Muestra una de las estructuras cargadas
 *
 * \param eProductos lista recibe la estructura en una posicion a mostrar
 *
 */
void mostrarUnJugador(eJugador lista)
{
	printf("%10s\t%4d\t%4d\t%.2f\n",lista.nombre, lista.golesMetidos,
		    lista.partidosJugados, lista.promedioGoles);
}

/** \brief Muestra los campos de las estructuras cargadas
 *
 * \param eProductos lista[] recibe la estructura a analizar
 * \param int tam: el tama?o de lugares disponibles
 *
 */
void mostrarJugadores(eJugador lista[], int tam)
{
	int i;
	if(lista != NULL)
	{
		printf("\nNOMBRE	GOLES	 PARTIDOS  	 PROMEDIOGOLES\n");
		for (i = 0; i < tam; ++i) {
			mostrarUnJugador(lista[i]);
		}
	}
}

/** \brief Carga un numero por puntero
 *
 * \param int *num = el numero ingresado
 *
 * \return Retorna 0 si se carga y 1 si hubo error
*/
int cargarNumero(int *num)
{
	int error;
	error = 1;
	if(num != NULL)
	{
		scanf("%d", num);
		error = 0;
	}
	return error;
}

/** \brief Carga un numero por puntero
 *
 * \param int *numUno = Primer numero a analizar
 * \param int *numDos = Segundo numero a analizar
 *
 * \return Retorna 0 si se swape y 1 si no se swapeo o hubo un error
*/
int numeroMasGrande(int *numUno, int *numDos)
{
	int error= 1;
	int aux;
	if(numUno != NULL && numDos != NULL)
	{

		if(*numUno < *numDos)
		{
			error = 0;
			aux = *numUno;
			*numUno = *numDos;
			*numDos = aux;
		}
	}
	return error;
}

int vectorContenido(int *vectorUno, int *vectorDos, int tam)
{
	int error = 1;
	int verificador[tam];
	int i;
	int j;
	if(vectorUno != NULL && vectorDos != NULL)
	{
		inicializarArray(verificador, tam);
		error = 0;
		for (i = 0; i < tam; ++i) {
			for (j = 0; j < tam; ++j) {
				if(vectorUno[i] == vectorDos[j]){
					verificador[i]=0;
				}
			}
		}

		for (i = 0; i < tam; ++i) {
			if(verificador[i]==0){
				error=0;
			}else{
				error=1;
				break;
			}
		}


	}
	return error;
}

int remplazarLetras(char *palabra, char letra, char letraDos)
{
	int tam;
	int i;
	int cont;
	cont = 0;
	tam = strlen(palabra);
	for (i = 0; i < tam; ++i) {
		if(palabra[i] == letra)
		{
			palabra[i]=letraDos;
			cont++;
		}
	}
	return cont;
}

void numMaximoEnArray(int *arrayNumero, int *mayorValor, int tam)
{
	int i;

	for (i = 0; i < tam; ++i) {
		if(i == 0 || *mayorValor < arrayNumero[i])
		{
			*mayorValor = arrayNumero[i];
		}
	}
}

eAlumnito* cargarAlumno()//constructor
{
	eAlumnito* pAlumno;
	pAlumno = (eAlumnito*) malloc(sizeof(eAlumnito));

	if(pAlumno != NULL)
	{
		pAlumno->legajo=500;
		strcpy(pAlumno->nombre, "Robertito");
		pAlumno->edad =32;
	}
	return pAlumno;
}

int restructurador(int *arrayNumero, int tam, int remove)
{
	int error;
	int i;
	int j;
	int contador;
	error = 1;
	contador = 0;
	if(arrayNumero != NULL && tam > 0)
	{
		//1. Recorro el array
		for (i = 0; i < tam; ++i) {
			//2. Busco el numero al cual quiero sacar
			if(*(arrayNumero+i)==remove)
			{
				//3. Restructuro el array hasta dejar en la ultima posicion al dato basura
				for (j = 0; j < (tam-contador); ++j) {
					//4. Piso el dato basura con el siguiente numero hasta llegar al final
					*(arrayNumero+i) = *(arrayNumero+(i+1));
					i++;
					error = 0;
				}
				//5. Una vez restructurado  borro un entero del array
				arrayNumero = (int*) realloc(arrayNumero, sizeof(int)*(tam-1));
				break;
			}
			//Por cada posicion que recorra sumo uno para descontar
			//en la restructuracion del array
			contador++;
		}
	}
	return error;
}

int push(int *arrayNumero, int tam, int valor, int indice)
{
	int i;
	int *arrayAux;
	int error;
	error = 1;
	if(arrayNumero != NULL)
	{
		//1. Le sumo un int mas al array utilizando el auxiliar
		//para asegurar que hay espacio en memoria
		arrayAux= (int*) realloc(arrayNumero, sizeof (int) * (tam + 1));
		if(arrayAux != NULL)
		{
			//2. Una vez verificado que hay espacio en memoria apunto mi array al auxiliar
			arrayNumero = arrayAux;
			//3. Libero el espacio utilizado por el array Auxiliar
			free(arrayAux);
			//4. En el nuevo entero agregado copio el ultimo numero del array
			//asi consecutivamente hasta dejar el indice solicitado con dato basura
            for(i=tam+1;i>indice;i--)
            {
               (*(arrayNumero+i))=(*(arrayNumero+i-1));
            }
			//5.Copio el valor solicitado en el indice solicitado
			*(arrayNumero+indice) = valor;
			error = 0;
		}
	}
	return error;
}

