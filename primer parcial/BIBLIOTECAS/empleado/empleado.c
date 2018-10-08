#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"


int empleado_init(eEmpleado* empleado, int empleado_tam)
{
    int i;
    int retorno=-1;
    if(empleado != NULL && empleado_tam > 0)
    {
        for(i=0;i<empleado_tam;i++)
        {
            (empleado+i)->flagEstado = EMPLEADO_VACIO;
        }
        retorno = 0;
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int empleado_agregar(eEmpleado* empleado, int empleado_tam,char nombre[],char apellido[],char sexo[],float sueldo,eFecha fecha_ingreso)
{

    int retorno=-1;
    int legajo,index;
    if(empleado != NULL && empleado_tam > 0)
    {
        index = empleado_findEmptyPlace(empleado, empleado_tam);
        if(index != -1)
        {
            legajo = 1000+empleado_findNextId(empleado, empleado_tam);
            strcpy((empleado+index)->nombre,nombre);
            strcpy((empleado+index)->apellido,apellido);
            strcpy((empleado+index)->sexo,sexo);
            (empleado+index)->sueldo = sueldo;
            (empleado+index)->legajo = legajo;
            (empleado+index)->fecha_ingreso.dia = fecha_ingreso.dia;
            (empleado+index)->fecha_ingreso.mes = fecha_ingreso.mes;
            (empleado+index)->fecha_ingreso.anio = fecha_ingreso.anio;
            (empleado+index)->flagEstado = EMPLEADO_CARGADO;
            retorno=0;
        }
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int empleado_findEmptyPlace(eEmpleado* empleado, int empleado_tam)
{
    int i;
    int retorno=-1;
    if(empleado != NULL && empleado_tam > 0)
    {
        for(i=0;i<empleado_tam;i++)
        {
            if((empleado+i)->flagEstado == EMPLEADO_VACIO)
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

int empleado_findNextId(eEmpleado* empleado, int empleado_tam)
{
    int i, maxId=-1;
    int retorno=-1;
    if(empleado != NULL && empleado_tam > 0)
    {
        for(i=0;i<empleado_tam;i++)
        {
            if((empleado+i)->flagEstado == EMPLEADO_CARGADO || (empleado+i)->flagEstado == EMPLEADO_ELIMINADO)
            {
                if((empleado+i)->legajo > maxId || maxId == -1)
                    maxId = (empleado+i)->legajo;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int empleado_borrar(eEmpleado* empleado, int empleado_tam, int legajo)
{
    eEmpleado* auxEmpleado;
    int retorno = -1;

    auxEmpleado = empleado_buscar(empleado, empleado_tam, legajo);
    if(auxEmpleado != NULL)
    {
        auxEmpleado->flagEstado = EMPLEADO_ELIMINADO;
        retorno = 0;
    }

    printf("Empleado eliminado correctamente.\n\n");

    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

eEmpleado* empleado_buscar(eEmpleado* empleado, int empleado_tam, int legajo)
{
    eEmpleado* retorno= NULL;
    int i;
    if(empleado != NULL && empleado_tam > 0)
    {
        for(i=0;i<empleado_tam;i++)
        {
            if((empleado+i)->legajo == legajo && (empleado+i)->flagEstado == EMPLEADO_CARGADO)
            {
                retorno = (empleado+i);
                break;
            }
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int empleado_modificar(eEmpleado* empleado, int empleado_tam, int legajo, char nombre[],char apellido[],float sueldo)
{
    int retorno=-1;
    eEmpleado* auxEmpleado;

    if(empleado != NULL && empleado_tam > 0)
    {
        auxEmpleado = empleado_buscar(empleado, empleado_tam,legajo);
        if(auxEmpleado != NULL)
        {
            strcpy(auxEmpleado->nombre,nombre);
            strcpy(auxEmpleado->apellido,apellido);
            (auxEmpleado)->sueldo = sueldo;
            retorno=0;
        }
    }
    printf("Empleado modificado correctamente");
    return retorno;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTA LOS DATOS DE UN EMPLEADO.
void empleado_mostrar(eEmpleado empleado, int empleado_tam)
{

    printf("%d %s %s %s %.2f %d/%d/%d\n\n", empleado.legajo, empleado.nombre, empleado.apellido,empleado.sexo,empleado.sueldo,empleado.fecha_ingreso.dia,empleado.fecha_ingreso.mes,empleado.fecha_ingreso.anio);

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL LISTADO DE EMPLEADOS DADOS DE ALTA.
void empleado_listarEmpleados(eEmpleado nomina[], int empleado_tam)
{
    for(int i=0; i< empleado_tam; i++)
    {
        if( nomina[i].flagEstado == EMPLEADO_CARGADO)
        {
            empleado_mostrar(nomina[i],empleado_tam);
        }
    }
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void empleados_harcodear(eEmpleado y[])
{

    eEmpleado x[]=
    {
        {1000,"Roberto","Gimenez","m",20000,{24,10,18},EMPLEADO_CARGADO},
        {1001,"Franco","Gonzalez","m",21000,{24,10,18},EMPLEADO_CARGADO},
        {1002,"Juan","Perez","m",30000,{24,10,18},EMPLEADO_CARGADO},
        {1003,"Gonzalo","Mey","m",17000,{24,10,18},EMPLEADO_CARGADO},
        {1004,"Brian","Lamela","m",20000,{24,10,18},EMPLEADO_CARGADO},
        {1005,"Alan","Martinez","m",23000,{24,10,18},EMPLEADO_CARGADO},
        {1006,"Anuel","AA","m",15000,{24,10,18},EMPLEADO_CARGADO},
    };

    for(int i=0; i<7; i++)
    {
        y[i] = x[i];
    }

}
