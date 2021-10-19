/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Salon.h"
#include "Arcade.h"
#include "NexoSalonArcade.h"

#define TAM_SALONES 4
#define TAM_ARCADES 4


int main(void) {
	setbuf(stdout, NULL);
	char seguir='s';
	char confirma;
	int opcion;
	Salon listaSalones[TAM_SALONES];
	Arcade listaArcades[TAM_ARCADES];
	inicializarSalones(listaSalones, TAM_SALONES);
	inicializarArcades(listaArcades, TAM_ARCADES);

	do {
			opcion = generarMenu();
			switch (opcion) {
				case 1: {
					iniciarGestionSalones();
					break;
				}
				case 2: {
					iniciarGestionArcades();
					break;
				}
//				case 3: {
//					if (checkCreatedEmployees(arrayEmployees, ELEMENTS) == -1) {
//						printf("  |  No hay empleados cargados en el sistema.\n");
//					} else if (removeEmployee(arrayEmployees, ELEMENTS) == -1){
//						printf("\n  |  No existe empleado con el id ingresado: \n");
//					}
//					break;
//				}
			}
			system("pause");
		} while (seguir == 's');

//	agregarSalon(listaSalones, TAM_SALONES);
//	imprimirSalon(&listaSalones[0]);
//	imprimirJuegos(listaArcades, TAM_ARCADES);
	return EXIT_SUCCESS;
}
