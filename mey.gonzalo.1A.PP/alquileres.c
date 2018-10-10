#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"
#include "alquileres.h"


int alquiler_init(eAlquileres* alquiler, int alquiler_tam)
{
    int i;
    int retorno=-1;
    if(alquiler != NULL && alquiler_tam > 0)
    {
        for(i=0;i<alquiler_tam;i++)
        {
            (alquiler+i)->flagEstado = ALQUILER_VACIO;
        }
        retorno = 0;
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int elegirCliente(eCliente clientes[], int clientes_tam)
{
    int idClientes;
    printf("\nClientes\n\n");
    for(int i=0; i < clientes_tam; i++)
    {   if(clientes[i].flagEstado!=CLIENTE_VACIO && clientes[i].flagEstado != CLIENTE_ELIMINADO)
        {
        printf("%d %s\n", clientes[i].legajo, clientes[i].nombre);
        }
    }
    printf("\nSeleccione Cliente: ");
    scanf("%d", &idClientes);
    return idClientes;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int elegirJuego(eJuegos juegos[], int juegos_tam)
{
    int idJuegos;
    printf("\nJuegos\n\n");
    for(int i=0; i < juegos_tam; i++)
    {   if(juegos[i].flagEstado!=JUEGOS_VACIO && juegos[i].flagEstado != JUEGOS_BORRADO)
        {
        printf("%d %s\n", juegos[i].id, juegos[i].descripcion);
        }
    }
    printf("\nSeleccione juego: ");
    scanf("%d", &idJuegos);
    return idJuegos;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int alquiler_agregar(eAlquileres* alquiler, int alquiler_tam,int idJuego, int idCliente,int dia, int mes, int anio)
{
     int retorno=-1;
     int id,index;

    if(alquiler != NULL && alquiler_tam > 0)
    {
        index = alquiler_findEmptyPlace(alquiler, alquiler_tam);
        if(index != -1)
        {
           id = alquiler_findNextId(alquiler, alquiler_tam);
           (alquiler+index)->id = id;
           (alquiler+index)->idJuego = idJuego;
           (alquiler+index)->idCliente = idCliente;
           alquiler[index].fecha.dia = dia;
           alquiler[index].fecha.mes = mes;
           alquiler[index].fecha.anio = anio;
           (alquiler+index)->flagEstado = ALQUILER_USADO;
           retorno = 0;
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int alquiler_findEmptyPlace(eAlquileres* alquiler, int alquiler_tam)
{
    int i;
    int retorno=-1;
    if(alquiler != NULL && alquiler_tam > 0)
    {
        for(i=0;i<alquiler_tam;i++)
        {
            if((alquiler+i)->flagEstado == ALQUILER_VACIO)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int alquiler_findNextId(eAlquileres* alquiler, int alquiler_tam)
{
    int i, maxId=-1;
    int retorno=-1;
    if(alquiler != NULL && alquiler_tam > 0)
    {
        for(i=0;i<alquiler_tam;i++)
        {
            if((alquiler+i)->flagEstado == ALQUILER_USADO || (alquiler+i)->flagEstado == ALQUILER_BORRADO)
            {
                if((alquiler+i)->id > maxId || maxId == -1)
                    maxId = (alquiler+i)->id;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void alquiler_listar(eAlquileres* alquiler, int alquiler_tam,eCliente* cliente,int cliente_tam, eJuegos* juegos,int juegos_tam)
{
    char descripcionJuego[51];
    char nombreCliente[51];


    for(int i = 0; i<alquiler_tam;i++)
    {

        for(int j = 0;j<cliente_tam;j++)
        {

            if(alquiler[i].idCliente == cliente[j].legajo)
            {
                strcpy(nombreCliente, cliente[j].nombre);

                    for(int k = 0;k<juegos_tam;k++)
                    {

                        if(alquiler[i].idJuego == juegos[k].id)
                        {
                        strcpy(descripcionJuego, juegos[k].descripcion);

                        }

                    }
            }

        }

            if(alquiler[i].flagEstado != ALQUILER_VACIO && alquiler[i].flagEstado != ALQUILER_BORRADO )
            {
            printf("%d    %s   %s  %d/%d/%d\n\n",alquiler[i].id,nombreCliente,descripcionJuego,alquiler[i].fecha.dia,alquiler[i].fecha.mes,alquiler[i].fecha.anio);
            }
    }

}
