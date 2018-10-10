
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


int clientes_init(eCliente* cliente, int cliente_tam)
{
    int i;
    int retorno=-1;
    if(cliente != NULL && cliente_tam > 0)
    {
        for(i=0;i<cliente_tam;i++)
        {
            (cliente+i)->flagEstado = CLIENTE_VACIO;
        }
        retorno = 0;
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int cliente_agregar(eCliente* cliente, int cliente_tam,char nombre[],char apellido[],char sexo,char domicilio[])
{

    int retorno=-1;
    int legajo,index;
    if(cliente != NULL && cliente_tam > 0)
    {
        index = cliente_findEmptyPlace(cliente, cliente_tam);
        if(index != -1)
        {
            legajo = 1+cliente_findNextId(cliente, cliente_tam);
            strcpy((cliente+index)->nombre,nombre);
            strcpy((cliente+index)->apellido,apellido);
            cliente[index].sexo = sexo;
            strcpy((cliente+index)->domicilio,domicilio);
            (cliente+index)->legajo = legajo;
            (cliente+index)->flagEstado = CLIENTE_CARGADO;
            retorno=0;
        }
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int cliente_findEmptyPlace(eCliente* cliente, int cliente_tam)
{
    int i;
    int retorno=-1;
    if(cliente != NULL && cliente_tam > 0)
    {
        for(i=0;i<cliente_tam;i++)
        {
            if((cliente+i)->flagEstado == CLIENTE_VACIO)
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

int cliente_findNextId(eCliente* cliente, int cliente_tam)
{
    int i, maxId=-1;
    int retorno=-1;
    if(cliente != NULL && cliente_tam > 0)
    {
        for(i=0;i<cliente_tam;i++)
        {
            if((cliente+i)->flagEstado == CLIENTE_CARGADO || (cliente+i)->flagEstado == CLIENTE_ELIMINADO)
            {
                if((cliente+i)->legajo > maxId || maxId == -1)
                    maxId = (cliente+i)->legajo;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int cliente_borrar(eCliente* cliente, int cliente_tam, int legajo)
{
    eCliente* auxCliente;
    int retorno = -1;

    auxCliente = cliente_buscar(cliente, cliente_tam, legajo);
    if(auxCliente != NULL)
    {
        auxCliente->flagEstado = CLIENTE_ELIMINADO;
        retorno = 0;
    }

    printf("Cliente eliminado correctamente.\n\n");

    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

eCliente* cliente_buscar(eCliente* cliente, int cliente_tam, int legajo)
{
    eCliente* retorno= NULL;
    int i;
    if(cliente != NULL && cliente_tam > 0)
    {
        for(i=0;i<cliente_tam;i++)
        {
            if((cliente+i)->legajo == legajo && (cliente+i)->flagEstado == CLIENTE_CARGADO)
            {
                retorno = (cliente+i);
                break;
            }
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int cliente_modificar(eCliente* cliente, int cliente_tam, int legajo, char nombre[],char apellido[],char sexo,char domicilio[])
{
    int retorno=-1;
    eCliente* auxCliente;

    if(cliente != NULL && cliente_tam > 0)
    {
        auxCliente = cliente_buscar(cliente, cliente_tam,legajo);
        if(auxCliente != NULL)
        {
            strcpy(auxCliente->nombre,nombre);
            strcpy(auxCliente->apellido,apellido);
            auxCliente->sexo = sexo;
            strcpy(auxCliente->domicilio,domicilio);
            retorno=0;
        }
    }
    printf("Cliente modificado correctamente");
    return retorno;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTA LOS DATOS DE UN EMPLEADO.
void cliente_mostrar(eCliente cliente, int cliente_tam)
{

    printf("%d %s %s %c %s \n\n", cliente.legajo, cliente.nombre, cliente.apellido,cliente.sexo,cliente.domicilio);

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL LISTADO DE EMPLEADOS DADOS DE ALTA.
void cliente_listarClientes(eCliente nomina[], int cliente_tam)
{
    eCliente auxCliente;

    for(int i=0; i< cliente_tam-1; i++)
    {
        for(int j = i+1;j<cliente_tam;j++){

            if(strcmp(nomina[i].apellido,nomina[j].apellido)>0){

                auxCliente = nomina[i];
                nomina[i] = nomina[j];
                nomina[j] = auxCliente;
            }

            if(strcmp(nomina[i].apellido,nomina[j].apellido)==0 && strcmp(nomina[i].nombre,nomina[j].nombre)>0){

                 auxCliente = nomina[i];
                 nomina[i] = nomina[j];
                 nomina[j] = auxCliente;
            }

        }
                if( nomina[i].flagEstado == CLIENTE_CARGADO)
        {
            cliente_mostrar(nomina[i],cliente_tam);
        }
    }

}
//-------------------------------------------------------------
//-------------------------------------------------------------
void cliente_harcodear(eCliente y[])
{

    eCliente x[]=
    {
        {1000,"Roberto","Gimenez",'m',"Iriarte 1647",CLIENTE_CARGADO},
        {1001,"Franco","Gonzalez",'m',"Pinzon 745",CLIENTE_CARGADO},
        {1002,"Juan","Perez",'m',"Montes de Oca 1548",CLIENTE_CARGADO},
        {1003,"Gonzalo","Mey",'m',"Juana Manso 35",CLIENTE_CARGADO},
        {1004,"Brian","Lamela",'m',"Isabel la Catolica 654",CLIENTE_CARGADO},
        {1005,"Alan","Martinez",'m',"Peru 756",CLIENTE_CARGADO},
        {1006,"Anuel","AA",'m',"Bolivar 45",CLIENTE_CARGADO},
    };

    for(int i=0; i<7; i++)
    {
        y[i] = x[i];
    }

}
