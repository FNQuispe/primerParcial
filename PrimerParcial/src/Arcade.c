#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arcade.h"
#include "utn_quispe.h"

#define TRUE 1
#define FALSE 0
#define TAM_CADENAS 63
#define REINTENTOS 3

static int generarID(void);

void imprimirArcade(Arcade *arcade) {
	printf("%d	%s	%d	%d	%d	%d	%s \n",
			arcade->idArcade,
			arcade->nacionalidad,
			arcade->tipoSonido,
			arcade->cantidadJugadores,
			arcade->capacidadMaxFichas,
			arcade->idSalon,
			arcade->juegoCargado);
}

void imprimirArcades(Arcade* listaArcades, int tam) {
	printf("  |---------------------------------------------------------------------|\n");
	printf("  |                    ****** Listado de Arcades *****                 \n\n");
	printf("  |	idArcade |	nacionalidad  |	tipo sonido	| cantidad jugadores |	capacidad max fichas  | idSalon	 |	juego cargado\n");
	for (int i = 0; i < tam; ++i) {
		imprimirArcade(&listaArcades[i]);
	}
}

int inicializarArcades(Arcade* listaArcades, int tam) {
	int retorno = FALSE;

	if (listaArcades != NULL && tam > 0) {
		retorno = 0;
		for (int i = 0; i < tam; i++) {
			listaArcades[i].isEmpty = TRUE;
		}
	}

	return retorno;
}

int buscarArcadeVacio(Arcade* listaArcades, int tam) {
	int indice = -1;

	if (listaArcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (listaArcades[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}

/// @brief Agrega un arcade al sistema
/// @param Arcade* listaArcades: vectores de arcades
/// @param int len: tamaño del vector
/// @param int idSalon: id del salon al que se le asignara el arcade
/// @return Retorna 0 si no pudo dar de alta, 1 si se pudo de dar de alta al arcade
int agregarArcade(Arcade* listaArcades, int tam, int idSalon) {
	int retorno = FALSE;
	int indice = buscarArcadeVacio(listaArcades, tam);

	char nacionalidadAux[TAM_CADENAS];
	int tipoSonidoAux;
	int cantidadJugadoresAux;
	int capacidadMaxFichasAux;
	char juegoAux[TAM_CADENAS];

	if (indice == -1) {
			printf("  |   Sistema Completo\n\n");
	} else {
		if (listaArcades != NULL) {
			system("cls");
			printf("  |------------------------------------|\n");
			printf("  |   	******	Alta arcade	******	   |\n");

			if (utn_getNombre(nacionalidadAux, TAM_CADENAS, "Ingrese nacionalidad del arcade: ", "Error, reingrese nacionalidad", REINTENTOS) == 0) {
				if (utn_getDescripcion(juegoAux, TAM_CADENAS, "Ingrese nombre del juego: ", "Error, reingrese nombre del juego", REINTENTOS) == 0) {
					if (utn_getNumero(&tipoSonidoAux, "Ingrese el tipo de sonido: ", "Error, reingrese tipo de sonido ", 0, 1, REINTENTOS) == 0) {
						if (utn_getNumero(&cantidadJugadoresAux, "Ingrese cantidad de jugadores: ", "Error, reingrese cantidad de jugadores ", 1, 4, REINTENTOS) == 0) {
							if (utn_getNumero(&capacidadMaxFichasAux, "Ingrese capacidad max de fichas: ", "Error, reingrese max de fichas ", 0, 99, REINTENTOS) == 0) {
								retorno = TRUE;
								listaArcades[indice].idArcade = generarID();
								listaArcades[indice].idSalon = idSalon;
								strncpy(listaArcades[indice].nacionalidad, nacionalidadAux, TAM_CADENAS);
								strncpy(listaArcades[indice].juegoCargado, juegoAux, TAM_CADENAS);
								listaArcades[indice].tipoSonido = tipoSonidoAux;
								listaArcades[indice].cantidadJugadores = cantidadJugadoresAux;
								listaArcades[indice].tipoSonido = capacidadMaxFichasAux;
								listaArcades[indice].isEmpty = FALSE;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

/// @brief Busca arcade por numero de idArcade
/// @param int id: numero de id para buscar arcade
/// @param Arcade* listaArcades: vectores de arcades
/// @param int len: tamaño del vector
/// @return Retorna -1 si no encontro arcade con ese id o el indice de dicho arcade si lo encontro
int buscarArcadePorIdArcade(Arcade *listaArcades, int len, int id) {
	int indice = -1;
	if (listaArcades != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (listaArcades[i].idArcade == id && listaArcades[i].isEmpty == FALSE) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/// @brief Busca arcade por numero de idSalon
/// @param int id: numero de id para buscar arcade
/// @param Arcade* listaArcades: vectores de arcades
/// @param int len: tamaño del vector
/// @return Retorna 0 si no encontro arcade con ese id salon o 1 si encontro arcade asociado a salon
int buscarArcadePorIdSalon(Arcade *listaArcades, int len, int id) {
	int salida = FALSE;
	if (listaArcades != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (listaArcades[i].idSalon == id && listaArcades[i].isEmpty == FALSE) {
				salida = TRUE;
				break;
			}
		}
	}
	return salida;
}

/// @brief Elimina arcade del sistema
/// @param Arcade* vec: vectores de arcades
/// @param int len: tamaño del vector
/// @return -1 si no encuentra arcade con el id ingresado, 0 si encontro el arcade y pudo removerlo con exito
int eliminarArcade(Arcade *listaArcades, int tam) {
	int id;
	int existe;
	int retorno = -1;

	system("cls");
	imprimirArcades(listaArcades, tam);
	printf("  |------------------------------------|\n");
	printf("  |  	******	Baja Salon	******     |\n");
	printf("  |  Ingrese id: \n");
	scanf("%d", &id);
	existe = buscarArcadePorIdArcade(listaArcades, tam, id);
	if (existe != -1) {
		retorno = 0;
		printf("\n  |  Se ha encontrado el salon con id: %d\n", id);
		imprimirArcade(&listaArcades[existe]);
		listaArcades[existe].isEmpty = TRUE;
		printf("\n  |  Se ha realizado la baja con exito.\n\n");
	}

	return retorno;
}

/// @brief Modifica empleado del sistema
/// @param Arcade* listaArcades: vectores de arcades
/// @param int tam: tamaño de vector
void modificarArcade(Arcade* listaArcades, int tam) {
	int id;
	int existe;
	int opcion;
	system("cls");
	imprimirArcades(listaArcades, tam);
	printf("  |------------------------------------------|\n");
	printf("  |		****** Modificar Arcade ****** 		 |\n");
	printf("  |      Ingrese id: ");
	scanf("%d", &id);
	existe = buscarArcadePorIdArcade(listaArcades, tam, id);
	if (existe == -1) {
		printf("  |      No existe arcade con este id: %d\n", id);
	} else {

		printf("  |------------------------------------|\n");
		printf("  | *** Que dato desea modificar? ***  |\n");
		printf("  |  1- Cantidad de jugadores          |\n");
		printf("  |  2- Juego                          |\n");
		printf("  |  Ingrese el numero de opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
			case 1: {
				utn_getNumero(&listaArcades[existe].cantidadJugadores, "Ingrese Cantidad de jugadores: ", "Error, reingrese nombre",1,4, REINTENTOS);
				printf("  |  Se ha actualizado la cantidad de jugadores con exito.\n");
				break;
			}
			case 2: {
				utn_getDescripcion(listaArcades[existe].juegoCargado, TAM_CADENAS, "Ingrese el juego: ", "Error, reingrese juego", REINTENTOS);
				printf("  |  Se ha actualizado el juego con exito.\n");
				break;
			}
			default: {
				printf("  |  Error. Opcion incorrecta.");
			}
		}
	}
}

/// @brief Imprime la lista de juegos cargados en el sistema
/// @param Arcade* listaArcades: vectores de arcades
/// @param int tam: tamaño de vector
void imprimirJuegos(Arcade* listaArcades, int tam) {
	int hayJuegosCargados = FALSE;
	int contador;
	int j = 0;
	int z = 0;
	char juegoAux[TAM_CADENAS];
	char arrayListaJuegos[tam][TAM_CADENAS];
	char arrayListaJuegosFinal[tam][TAM_CADENAS];

	if (listaArcades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (listaArcades[i].isEmpty == FALSE) {
				hayJuegosCargados = TRUE;
				contador = 0;
				strncpy(juegoAux, listaArcades[i].juegoCargado, TAM_CADENAS);
				strncpy(arrayListaJuegos[j], juegoAux, TAM_CADENAS);
				j++;
				for (int k = 0; k < tam; k++)
					if (strcmp(arrayListaJuegos[k], juegoAux) == 0) {
						contador++;
					}

				if (contador == 1) {
					strncpy(arrayListaJuegosFinal[z], juegoAux, TAM_CADENAS);
					z++;
				}
			}
		}

		if (hayJuegosCargados == TRUE) {
			printf("|  Listado de juegos de todos los arcades: \n");
			for (int i = 0; i < z; i++) {
				printf("-	%s \n", arrayListaJuegosFinal[i]);
			}
		} else {
			printf("|  No hay juegos cargados en el sistema \n");
		}
	}
}

int iniciarMenuArcades(void) {
	int opcion;
	system("cls");
	printf("  |---------------------------------------------|\n");
	printf("  |  *****		Gestion de Arcades		*****   |\n");
	printf("  |  1- Alta                					|\n");
	printf("  |  2- Baja                					|\n");
	printf("  |  3- Modificacion	                		|\n");
	printf("  |  Ingrese numero de opcion: ");
	scanf("%d", &opcion);
	while (opcion > 3 || opcion < 1) {
		printf("  |   Error. Opcion incorrecta.\n");
		printf("  |   Ingrese numero de opcion: ");
		scanf("%d", &opcion);
	}
	return opcion;
}



/// @brief funcion estatica que va incrementando en 1 un id
/// @return un id autogenerado
static int generarID(void) {
	static int id = 0;
	id++;
	return id;
}
