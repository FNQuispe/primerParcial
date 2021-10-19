/*
 * Salon.h
 *
 *  Created on: 19 oct. 2021
 *      Author: niqotery
 */

#ifndef SALON_H_
#define SALON_H_

typedef struct {
	int idSalon;
	char nombre[63];
	char direccion[63];
	int tipoSalon;
	int isEmpty;
} Salon;

void iniciarGestionSalones(void);
void imprimirSalon(Salon* salon);
void imprimirSalones(Salon* listaSalones, int tam);
int inicializarSalones(Salon* listaSalones, int tam);
int buscarSalonVacio(Salon* listaSalones, int tam);
int pedirDatosSalon(Salon* listaSalones, int tam);
int agregarSalon(Salon* listaSalones, int tam);
int buscarSalonPorId(Salon *listaSalones, int len, int id);
int eliminarSalon(Salon *list, int len);


#endif /* SALON_H_ */
