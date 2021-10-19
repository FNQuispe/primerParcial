#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Salon.h"
#include "utn_quispe.h"

#define TRUE 1
#define FALSE 0
#define TAM_CADENAS 63
#define REINTENTOS 3

static int generarID(void);
static int iniciarMenuSalones(void);

/// @brief imprime el salon con sus datos en la consola
/// @param Salon* salon: estructura del salon
void imprimirSalon(Salon *salon) {
	printf("	%d	%s		%s		%d",
			salon->idSalon,
			salon->nombre,
			salon->direccion,
			salon->tipoSalon);
}

void imprimirSalones(Salon *listaSalones, int tam) {
	printf("  |---------------------------------------------------------------------|\n");
	printf("  |                    ****** Listado de Salones *****                  | \n\n");
	printf("  |	idSalon |	nombre  |	direccion	| tipoSalon \n");
	for (int i = 0; i < tam; ++i) {
		imprimirSalon(&listaSalones[i]);
	}
}

/// @brief Indica que todas las posiciones del vector estan vacias.
///        Esta funcion pone la bandera isEmpty en TRUE en todas las posiciones del vector.
/// @param list Salon* Puntero al vectorer Salones.
/// @param tam int Longitud del vector.
/// @return int Retorna (0) si hay ERROR (longitud invalida o puntero NULL)
///         (1) si esta todo bien.
int inicializarSalones(Salon* listaSalones, int tam) {
	int retorno = FALSE;

	if (listaSalones != NULL && tam > 0) {
		retorno = 0;
		for (int i = 0; i < tam; i++) {
			listaSalones[i].isEmpty = TRUE;
		}
	}

	return retorno;
}

/// @brief Busca un lugar libre en la estructura de salones
/// @param Salon* vec: vectores de salones
/// @param int len: tamaño del vector
/// @return el indice del primer elemento libre que encuentre
int buscarSalonVacio(Salon* listaSalones, int tam) {
	int indice = -1;

	if (listaSalones != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (listaSalones[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}

/// @brief Agrega un salon al sistema
/// @param salon* listaSalones: vectores de salones
/// @param int len: tamaño del vector
/// @return Retorna 0 si no pudo dar de alta, 1 si se pudo de dar de alta al salon
int agregarSalon(Salon* listaSalones, int tam) {
	int retorno = FALSE;
	int indice = buscarSalonVacio(listaSalones, tam);

	char nombreAux[TAM_CADENAS];
	char direccionAux[TAM_CADENAS];
	int tipoSalonAux;

	if (indice == -1) {
			printf("  |   Sistema Completo\n\n");
	} else {
		if (listaSalones != NULL) {
			system("cls");
			printf("  |------------------------------------|\n");
			printf("  |   	******	Alta Salon	******	   |\n");

			if (utn_getNombre(nombreAux, TAM_CADENAS, "Ingrese el nombre del salon: ", "Error, reingrese nombre", REINTENTOS) == 0) {
				if (utn_getDescripcion(direccionAux, TAM_CADENAS, "Ingrese la direccion del salon: ", "Error, reingrese direccion", REINTENTOS) == 0) {
					if (utn_getNumero(&tipoSalonAux, "Ingrese el tipo del salon: ", "Error, reingrese tipo salon ", 0, 1, REINTENTOS) == 0) {

						retorno = TRUE;
						listaSalones[indice].idSalon = generarID();
						strncpy(listaSalones[indice].nombre, nombreAux, TAM_CADENAS);
						strncpy(listaSalones[indice].direccion, direccionAux, TAM_CADENAS);
						listaSalones[indice].tipoSalon = tipoSalonAux;
						listaSalones[indice].isEmpty = FALSE;
					}
				}
			}
		}
	}
	return retorno;
}

/// @brief Busca salon por numero de id
/// @param int id: numero de id para buscar salon
/// @param Salon* listaSalon: vectores de salones
/// @param int len: tamaño del vector
/// @return Retorna -1 si no encontro salon con ese id o el indice de dicho empleado si lo encontro
int buscarSalonPorId(Salon *listaSalones, int len, int id) {
	int indice = -1;
	if (listaSalones != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (listaSalones[i].idSalon == id && listaSalones[i].isEmpty == FALSE) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

/// @brief Elimina salon del sistema
/// @param Salon* vec: vectores de salones
/// @param int len: tamaño del vector
/// @return -1 si no encuentra salon con el id ingresado, 0 si encontro el salon y pudo removerlo con exito
int eliminarSalon(Salon *list, int len) {
	int id;
	int existe;
	int retorno = -1;
	system("cls");
	imprimirSalones(list, len);
	printf("  |------------------------------------|\n");
	printf("  |  	******	Baja Salon	******     |\n");
	printf("  |  Ingrese id: \n");
	scanf("%d", &id);
	existe = buscarSalonPorId(list, len, id);
	if (existe != -1) {
		retorno = 0;
		printf("\n  |  Se ha encontrado el salon con id: %d\n", id);
		imprimirSalon(&list[existe]);
		list[existe].isEmpty = TRUE;
		printf("\n  |  Se ha realizado la baja con exito.\n\n");
	}

	return retorno;
}

int iniciarMenuSalones(void) {
	int opcion;
	system("cls");
	printf("  |---------------------------------------------|\n");
	printf("  |  ******		Gestion de Salones 		******  |\n");
	printf("  |  1- Alta		                			|\n");
	printf("  |  2- Baja		                			|\n");
	printf("  |  Ingrese numero de opcion: ");
	scanf("%d", &opcion);
	while (opcion > 2 || opcion < 1) {
		printf("  |   Error. Opcion incorrecta.\n");
		printf("  |   Ingrese numero de opcion: ");
		scanf("%d", &opcion);
	}
	return opcion;
}

void iniciarGestionSalones(Salon* listaSalones, int tam) {
	int opcion = iniciarMenuSalones();
	switch(opcion) {
		case 1:
			if(agregarSalon(listaSalones, tam) == 0) {
				printf("  |   Error al dar de alta un salon.\n");
			}
			break;
		case 2:
			if(eliminarSalon(listaSalones, tam) == 0) {
				printf("  |   Error al eliminar un salon.\n");
			}
			break;
	}
}

/// @brief funcion estatica que va incrementando en 1 un id
/// @return un id autogenerado
static int generarID(void) {
	static int id = 0;
	id++;
	return id;
}


