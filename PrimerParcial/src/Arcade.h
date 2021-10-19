/*
 * Arcade.h
 *
 *  Created on: 19 oct. 2021
 *      Author: niqotery
 */

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct {
	int idArcade;
	char nacionalidad[63];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadMaxFichas;
	int idSalon;
	char juegoCargado[63];
	int isEmpty;

} Arcade;


int iniciarMenuArcades(void);
int inicializarArcades(Arcade* listaArcades, int tam);
void imprimirArcade(Arcade *arcade);
void imprimirArcades(Arcade* listaArcades, int tam);
void modificarArcade(Arcade* listaArcades, int len);
int eliminarArcade(Arcade *listaArcades, int len);
int buscarArcadePorIdArcade(Arcade *listaArcades, int len, int idArcade);
int buscarArcadePorIdSalon(Arcade *listaArcades, int len, int idSalon);
int agregarArcade(Arcade* listaArcades, int tam, int idSalon);
int buscarArcadeVacio(Arcade* listaArcades, int tam);
void imprimirJuegos(Arcade* listaArcades, int tam);

#endif /* ARCADE_H_ */
