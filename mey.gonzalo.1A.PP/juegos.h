#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

#define JUEGOS_VACIO 0
#define JUEGOS_PEDIDO 1
#define JUEGOS_BORRADO 2

typedef struct{

    int id;
    char descripcion[51];
    float importe;
    int flagEstado;

}eJuegos;


#endif // JUEGOS_H_INCLUDED

int juegos_init(eJuegos* juegos, int juegos_tam);

int juegos_agregar(eJuegos* juegos, int juegos_tam,char descripcion[],float importe);

int juegos_findEmptyPlace(eJuegos* juegos, int juegos_tam);

int juegos_findNextId(eJuegos* juegos, int juegos_tam);

int juegos_borrar(eJuegos* juegos, int juegos_tam, int idJuegos);

eJuegos* juegos_buscar(eJuegos* juegos, int juegos_tam, int idJuegos);

int juegos_modificar(eJuegos* juegos, int juegos_tam, int idJuegos, char descripcion[],float importe);

void juegos_mostrar(eJuegos juegos, int juegos_tam);

void juegos_listarJuegos(eJuegos nomina[], int juegos_tam);

void juego_cargarDescripcion(eJuegos juegos[], int juegos_tam, int idJuego, char cadena[]);

void juegos_harcodear(eJuegos y[]);






