#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"


int juegos_init(eJuegos* juegos, int juegos_tam)
{
    int i;
    int retorno=-1;
    if(juegos != NULL && juegos_tam > 0)
    {
        for(i=0;i<juegos_tam;i++)
        {
            (juegos+i)->flagEstado = JUEGOS_VACIO;
        }
        retorno = 0;
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int juegos_agregar(eJuegos* juegos, int juegos_tam,char descripcion[],float importe)
{

    int retorno=-1;
    int id,index;
    if(juegos != NULL && juegos_tam > 0)
    {
        index = juegos_findEmptyPlace(juegos, juegos_tam);
        if(index != -1)
        {
            id =1+ juegos_findNextId(juegos, juegos_tam);
            strcpy((juegos+index)->descripcion,descripcion);
            (juegos+index)->importe = importe;
            (juegos+index)->id = id;
            (juegos+index)->flagEstado = JUEGOS_PEDIDO;
            retorno=0;
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int juegos_findEmptyPlace(eJuegos* juegos, int juegos_tam)
{
    int i;
    int retorno=-1;
    if(juegos != NULL && juegos_tam > 0)
    {
        for(i=0;i<juegos_tam;i++)
        {
            if((juegos+i)->flagEstado == JUEGOS_VACIO)
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

int juegos_findNextId(eJuegos* juegos, int juegos_tam)
{
    int i, maxId=-1;
    int retorno=-1;
    if(juegos != NULL && juegos_tam > 0)
    {
        for(i=0;i<juegos_tam;i++)
        {
            if((juegos+i)->flagEstado == JUEGOS_PEDIDO || (juegos+i)->flagEstado == JUEGOS_BORRADO)
            {
                if((juegos+i)->id > maxId || maxId == -1)
                    maxId = (juegos+i)->id;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int juegos_borrar(eJuegos* juegos, int juegos_tam, int idJuegos)
{
    eJuegos* auxJuegos;
    int retorno = -1;

    auxJuegos = juegos_buscar(juegos, juegos_tam, idJuegos);
    if(auxJuegos != NULL)
    {
        auxJuegos->flagEstado = JUEGOS_BORRADO;
        retorno = 0;
    }

    printf("Juego eliminado correctamente.\n\n");

    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

eJuegos* juegos_buscar(eJuegos* juegos, int juegos_tam, int idJuegos)
{
    eJuegos* retorno= NULL;
    int i;
    if(juegos != NULL && juegos_tam > 0)
    {
        for(i=0;i<juegos_tam;i++)
        {
            if((juegos+i)->id == idJuegos && (juegos+i)->flagEstado == JUEGOS_PEDIDO)
            {
                retorno = (juegos+i);
                break;
            }
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int juegos_modificar(eJuegos* juegos, int juegos_tam, int idJuegos, char descripcion[],float importe)
{
    int retorno=-1;
    eJuegos* auxJuegos;

    if(juegos != NULL && juegos_tam > 0)
    {
        auxJuegos = juegos_buscar(juegos, juegos_tam,idJuegos);
        if(auxJuegos != NULL)
        {
            strcpy(auxJuegos->descripcion,descripcion);
            (auxJuegos)->importe = importe;
            retorno=0;
        }
    }
    printf("Juego modificado correctamente");
    return retorno;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTA LOS DATOS DE UN EMPLEADO.
void juegos_mostrar(eJuegos juegos, int juegos_tam)
{

    printf("%d %s %.2f\n\n", juegos.id, juegos.descripcion, juegos.importe);

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL LISTADO DE EMPLEADOS DADOS DE ALTA.
void juegos_listarJuegos(eJuegos nomina[], int juegos_tam)
{
   eJuegos auxJuego;

    for(int i=0; i< juegos_tam-1; i++)
    {
        for(int j = i+1;j<juegos_tam;j++){

            if(nomina[i].importe < nomina[j].importe){

                auxJuego = nomina[i];
                nomina[i] = nomina[j];
                nomina[j] = auxJuego;
            }

            if(nomina[i].importe < nomina[j].importe && strcmp(nomina[i].descripcion,nomina[j].descripcion)<0){

                 auxJuego = nomina[i];
                 nomina[i] = nomina[j];
                 nomina[j] = auxJuego;
            }

        }
                if( nomina[i].flagEstado == JUEGOS_PEDIDO)
        {
            juegos_mostrar(nomina[i],juegos_tam);
        }
    }
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void juego_cargarDescripcion(eJuegos juegos[], int juegos_tam, int idJuego, char cadena[])
{

    for(int i=0; i < juegos_tam; i++)
    {
        if( juegos[i].id == idJuego)
        {
            strcpy(cadena, juegos[i].descripcion);
            break;
        }
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------
void juegos_harcodear(eJuegos y[])
{

    eJuegos x[]=
    {
        {1,"Mortal Komabat",200,JUEGOS_PEDIDO},
        {2,"Call of Duty",175,JUEGOS_PEDIDO},
        {3,"FIFA 18",150,JUEGOS_PEDIDO},
        {4,"PES 18",40,JUEGOS_PEDIDO},
        {5,"League Of Legends",50,JUEGOS_PEDIDO},
        {6,"CS GO",75,JUEGOS_PEDIDO},
        {7,"Battlefield",120,JUEGOS_PEDIDO},
    };

    for(int i=0; i<7; i++)
    {
        y[i] = x[i];
    }

}
