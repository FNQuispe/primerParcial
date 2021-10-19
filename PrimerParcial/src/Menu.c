#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

int generarMenu(void) {
	int opcion;
	system("cls");
	printf("  |---------------------------------------------|\n");
	printf("  |  *****Gestion de Salones | Arcades*****     |\n");
	printf("  |  1- Gestion Salones                			|\n");
	printf("  |  2- Gestion Arcades                			|\n");
	printf("  |  3- Informes	                			|\n");
	printf("  |  Ingrese numero de opcion: ");
	scanf("%d", &opcion);
	while (opcion > 3 || opcion < 1) {
		printf("  |   Error. Opcion incorrecta.\n");
		printf("  |   Ingrese numero de opcion: ");
		scanf("%d", &opcion);
	}
	return opcion;
}
