#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NexoSalonArcade.h"
#include "utn_quispe.h"

#define TRUE 1
#define FALSE 0



/// @brief incorpora un arcade y lo asocia a un salon si este esta libre
/// @param Arcade* listaArcades: vectores de arcades
/// @param int tam: tamaño de vector
/// @return
int incorporarArcadeASalon(Salon* listaSalones, int tamListaSalones, Arcade* listaArcades, int tamListaArcades) {
	int salida = FALSE;
	int idSalon;
	int existeArcadeEnSalon;
	printf("  |---------------------------------------------------------|\n");
	printf("  |  		******Incorporar Arcade a Salon******			|\n");
	printf("  |---------------------------------------------------------|\n");

	imprimirSalones(listaSalones, tamListaSalones);

	printf("  |  Ingrese id del salon al que desea asociar el arcade: \n");
	scanf("%d", &idSalon);

	existeArcadeEnSalon = buscarArcadePorIdSalon(listaArcades, tamListaArcades, idSalon);

	if(existeArcadeEnSalon == 1) {
		printf("  |  El salon al que desea ingresar un arcade, ya tiene asociado uno. Ingrese otro salon \n");
	} else {
		salida = agregarArcade(listaArcades, tamListaArcades, idSalon);
	}

	return salida;
}

void iniciarGestionArcades(void) {
	int opcion = iniciarMenuArcades();
	switch() {
		case 1:
			break;
		case 2:
			break;
	}
}


