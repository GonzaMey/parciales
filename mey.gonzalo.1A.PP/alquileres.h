#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED



#define ALQUILER_VACIO 0
#define ALQUILER_USADO 1
#define ALQUILER_BORRADO 2

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;



typedef struct{

    int id;
    int idCliente;
    int idJuego;
    eFecha fecha;
    int flagEstado;

}eAlquileres;

#endif // ALQUILER_H_INCLUDED
/** \brief Inicializa al array alquiler[] seteando flagEstado en 0
 *
 * \param array de tipo eAlquileres
 * \param tamaño del array alquiler[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int alquiler_init(eAlquileres* alquiler, int alquiler_tam);

/** \brief Muestra la lista de clientes disponibles y pide el legajo de uno de los clientes
 *
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \return devuelve el nuemero de legajo del cliente ingresado
 *
 */


int elegirCliente(eCliente clientes[], int clientes_tam);

/** \brief Muestra la lista de juegos disponibles y pide el id de uno de los juegos
 *
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return devuelve el nuemero de id del juego ingresado
 *
 */

int elegirJuego(eJuegos juegos[], int juegos_tam);

/** \brief agrega los datos al array alquiler[] de tipo eAlquileres
 *
 * \param array de tipo eAlquileres
 * \param tamaño de array alquiler[]
 * \param id del juego a ingresar
 * \param legajo del cliente a ingresar
 * \param dia de realizacion del alquiler
 * \param mes de realizacion del alquiler
 * \param anio de realizacion del alquiler
 * \return devuelve 0 si se realizo correctamente
 *
 */


int alquiler_agregar(eAlquileres* alquiler, int alquiler_tam,int idJuego, int idCliente,int dia,int mes ,int anio);

/** \brief busca en el array de alquiler de tipo eAlquileres el primer espacio disponible
 *
 * \param array de tipo eAlquileres
 * \param tamaño de array alquiler[]
 * \return devuelve 0 si se realizo correctamente
 *
 */


int alquiler_findEmptyPlace(eAlquileres* alquiler, int alquiler_tam);

/** \brief calcula el id del proximo alquiler a ingresar
 *
 * \param array de tipo eAlquileres
 * \param tamaño de array alquiler[]
 * \return devuelve 0 si se realizo correctamente
 *
 */

int alquiler_findNextId(eAlquileres* alquiler, int alquiler_tam);

/** \brief muestra la lista de los alquileres ingresados
 *
 * \param array de tipo eAlquileres
 * \param tamaño de array alquiler[]
 * \param array de tipo eCliente
 * \param tamaño del array clientes[]
 * \param array de tipo eJuegos
 * \param tamaño del array juegos[]
 * \return
 *
 */


void alquiler_listar(eAlquileres* alquiler, int alquiler_tam,eCliente* cliente,int cliente_tam, eJuegos* juegos,int juegos_tam);




