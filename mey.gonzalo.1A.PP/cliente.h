#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define CLIENTE_VACIO 0
#define CLIENTE_CARGADO 1
#define CLIENTE_ELIMINADO 2


typedef struct{

    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char domicilio[51];
    int flagEstado;

}eCliente;

#endif // CLIENTE_H_INCLUDED


int clientes_init(eCliente* cliente, int cliente_tam);

int cliente_agregar(eCliente* cliente, int cliente_tam,char nombre[],char apellido[],char sexo,char domicilio[]);

int cliente_findEmptyPlace(eCliente* cliente, int cliente_tam);

int cliente_findNextId(eCliente* cliente, int cliente_tam);

int cliente_borrar(eCliente* cliente, int cliente_tam, int legajo);

eCliente* cliente_buscar(eCliente* cliente, int cliente_tam, int legajo);

int cliente_modificar(eCliente* cliente, int cliente_tam, int legajo, char nombre[],char apellido[],char sexo,char domicilio[]);

void cliente_mostrar(eCliente cliente, int cliente_tam);

void cliente_listarClientes(eCliente nomina[], int cliente_tam);

void cliente_cargarNombre(eCliente cliente[], int cliente_tam, int idCliente, char cadena[]);

void cliente_harcodear(eCliente y[]);

