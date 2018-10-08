#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int menu_init(eMenu* menu, int menu_tam)
{
    int i;
    int retorno=-1;
    if(menu != NULL && menu_tam > 0)
    {
        for(i=0;i<menu_tam;i++)
        {
            (menu+i)->flagEstado = MENU_VACIO;
        }
        retorno = 0;
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int menu_agregar(eMenu* menu, int menu_tam,char descripcion[],float importe)
{

    int retorno=-1;
    int id,index;
    if(menu != NULL && menu_tam > 0)
    {
        index = menu_findEmptyPlace(menu, menu_tam);
        if(index != -1)
        {
            id = menu_findNextId(menu, menu_tam);
            strcpy((menu+index)->descripcion,descripcion);
            (menu+index)->importe = importe;
            (menu+index)->id = id;
            (menu+index)->flagEstado = MENU_PEDIDO;
            retorno=0;
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int menu_findEmptyPlace(eMenu* menu, int menu_tam)
{
    int i;
    int retorno=-1;
    if(menu != NULL && menu_tam > 0)
    {
        for(i=0;i<menu_tam;i++)
        {
            if((menu+i)->flagEstado == MENU_VACIO)
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

int menu_findNextId(eMenu* menu, int menu_tam)
{
    int i, maxId=-1;
    int retorno=-1;
    if(menu != NULL && menu_tam > 0)
    {
        for(i=0;i<menu_tam;i++)
        {
            if((menu+i)->flagEstado == MENU_PEDIDO || (menu+i)->flagEstado == MENU_BORRADO)
            {
                if((menu+i)->id > maxId || maxId == -1)
                    maxId = (menu+i)->id;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int menu_borrar(eMenu* menu, int menu_tam, int idMenu)
{
    eMenu* auxMenu;
    int retorno = -1;

    auxMenu = menu_buscar(menu, menu_tam, idMenu);
    if(auxMenu != NULL)
    {
        auxMenu->flagEstado = MENU_BORRADO;
        retorno = 0;
    }

    printf("Menu eliminado correctamente.\n\n");

    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

eMenu* menu_buscar(eMenu* menu, int menu_tam, int idMenu)
{
    eMenu* retorno= NULL;
    int i;
    if(menu != NULL && menu_tam > 0)
    {
        for(i=0;i<menu_tam;i++)
        {
            if((menu+i)->id == idMenu && (menu+i)->flagEstado == MENU_PEDIDO)
            {
                retorno = (menu+i);
                break;
            }
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int menu_modificar(eMenu* menu, int menu_tam, int idMenu, char descripcion[],float importe)
{
    int retorno=-1;
    eMenu* auxMenu;

    if(menu != NULL && menu_tam > 0)
    {
        auxMenu = menu_buscar(menu, menu_tam,idMenu);
        if(auxMenu != NULL)
        {
            strcpy(auxMenu->descripcion,descripcion);
            (auxMenu)->importe = importe;
            retorno=0;
        }
    }
    printf("Menu modificado correctamente");
    return retorno;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTA LOS DATOS DE UN EMPLEADO.
void menu_mostrar(eMenu menu, int menu_tam)
{

    printf("%d %s %.2f\n\n", menu.id, menu.descripcion, menu.importe);

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL LISTADO DE EMPLEADOS DADOS DE ALTA.
void menu_listarMenues(eMenu nomina[], int menu_tam)
{
    for(int i=0; i< menu_tam; i++)
    {
        if( nomina[i].flagEstado == MENU_PEDIDO)
        {
            menu_mostrar(nomina[i],menu_tam);
        }
    }
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void menu_harcodear(eMenu y[])
{

    eMenu x[]=
    {
        {1,"Hamburguesa",200,MENU_PEDIDO},
        {2,"Milanesa",175,MENU_PEDIDO},
        {3,"Vacio",150,MENU_PEDIDO},
        {4,"Sopa",40,MENU_PEDIDO},
        {5,"Papas Fritas",50,MENU_PEDIDO},
        {6,"Ensalada",75,MENU_PEDIDO},
        {7,"Fideos",120,MENU_PEDIDO},
    };

    for(int i=0; i<7; i++)
    {
        y[i] = x[i];
    }

}
