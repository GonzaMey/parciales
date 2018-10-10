#include "juegos.h"
#include "utn.h"
#include "cliente.h"

#ifndef INCLUDE_H_EJECUTAR
#define INCLUDE_H_EJECUTAR



#endif // INCLUDE_H_EJECUTAR


/** \brief carga un juego al array de eJuegos
 *
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int ejecutar_nuevoJuego(eJuegos juegos[], int juegos_tam);

/** \brief carga un cliente al array de eClientes
 *
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int ejecutar_nuevoCliente(eCliente cliente[], int cliente_tam);

/** \brief modifica las caracteristicas de un juego que se haya cargado previamente
 *
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int ejecutar_modificarJuego(eJuegos* juegos, int juegos_tam);

/** \brief modifica los datos de un cliente previamente cargado
 *
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int ejecutar_modificarCliente(eCliente* cliente, int cliente_tam);

/** \brief elimina un juego de forma logica del array juegos[]
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return devuelve 0 si se realizo correctamente
 */

int ejecutar_borrarJuego(eJuegos* juegos, int juegos_tam);

/** \brief elimina un cliente de forma logica del array clientes[]
 *
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \return devuelve 0 si se realizo correctamente
 *
 */


int ejecutar_borrarCliente(eCliente* cliente, int cliente_tam);

/** \brief agrega al array un nuevo pedido de alquiler al array alquiler[]
 *
 * \param array de tipo eAlquileres
 * \param tamaño del array alquiler[]
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return devuelve 0 si se realizo correctamente
 *
 */


int ejecutar_nuevoAlquiler(eAlquileres* alquiler, int alquiler_tam,eCliente* cliente, int cliente_tam,eJuegos* juegos, int juegos_tam);






