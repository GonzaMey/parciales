#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menu.h"
#include "empleado.h"

int ejecutar_nuevoMenu(eMenu menu[], int menu_tam)
{
    char descripcion[20];
    float importe;
    int retorno=-1;

    system("clear");
    retorno = getValidString("\nDescripcion: ","\nNo es una descripcion valida","\nLongitud maxima 20", descripcion,20,3);
    if(retorno == 0)
    {
        retorno = getValidFloat("\nImporte: ","\nNo es un Importe valido", &importe,0,1000,3);
        if(retorno == 0)
            {
                retorno = menu_agregar(menu, menu_tam, descripcion, importe);
            }
        }

    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_nuevoEmpleado(eEmpleado empleado[], int empleado_tam,eFecha fecha_ingreso)
{
    char nombre[51];
    char apellido[51];
    char sexo[2];
    float sueldo;
    int retorno=-1;

    system("clear");
    retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 51", nombre,51,3);
    if(retorno == 0)
    {
         retorno = getValidString("\nApellido: ","\nNo es un apellido valido","\nLongitud maxima 51", apellido,51,3);
         if(retorno == 0)
         {
              retorno = getValidString("\nSexo: ","\nNo es un sexo valido","\nLongitud maxima una letra",sexo,3,3);
              if(retorno == 0)
              {
                    retorno = getValidFloat("\nSueldo: ","\nNo es un Sueldo valido", &sueldo,0,1000000,3);
                    if(retorno == 0)
                        {
                            retorno = getValidInt("\nDia de Ingreso: ","\nNo es un Dia valido", &fecha_ingreso.dia,0,31,3);
                            if(retorno == 0)
                                {
                                    retorno = getValidInt("\nMes de Ingreso: ","\nNo es un mes valido", &fecha_ingreso.mes,0,12,3);
                                    if(retorno == 0)
                                        {
                                            retorno = getValidInt("\nAnio de ingreso: ","\nNo es un anio valido", &fecha_ingreso.anio,1950,2018,3);
                                            if(retorno == 0)
                                                {

                                                    retorno = empleado_agregar(empleado,empleado_tam,nombre,apellido,sexo,sueldo,fecha_ingreso);
                                                }
                                        }
                                }

                        }

              }
         }
    }


    return retorno;
}



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_modificarMenu(eMenu* menu, int menu_tam)
{
    char descripcion[20];
    float importe;
    int id;

    int retorno=-1;

    clearScreen();
    menu_listarMenues(menu,menu_tam);
    retorno = getValidInt("\nID a Modificar: ","\nRango valido 0-999", &id,0,999,3);

    if(retorno == 0)
    {
        if(menu_buscar(menu, menu_tam, id) == NULL)
        {
            printf("El menu elegido no existe\n");
            pause();

        }
        else
        {
            retorno = getValidString("\nDescripcion: ","\nNo es una descripcion valida","\nLongitud maxima 20", descripcion,20,3);
            if(retorno == 0)
            {
                retorno = getValidFloat("\nImporte: ","\nNo es un Importe valido",&importe,0,1000,3);
                if(retorno == 0)
                {
                    retorno = menu_modificar(menu, menu_tam, id, descripcion, importe);
                }
            }
        }
    }
    return retorno;
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_modificarEmpleado(eEmpleado* empleado, int empleado_tam)
{
    char nombre[51];
    char apellido[51];
    float sueldo;
    int legajo;

    int retorno=-1;

    clearScreen();
    empleado_listarEmpleados(empleado,empleado_tam);
    retorno = getValidInt("\nLegajo a Modificar: ","\nRango valido 1000-9999", &legajo,1000,9999,3);

    if(retorno == 0)
    {
        if(empleado_buscar(empleado, empleado_tam, legajo) == NULL)
        {
            printf("El empleado elegido no existe\n");
            pause();

        }
        else
        {
            retorno = getValidString("\nNombre: ","\nNo es un Nombre valido","\nLongitud maxima 51", nombre,51,3);
            if(retorno == 0)
            {
                 retorno = getValidString("\nApellido: ","\nNo es un Apellido valido","\nLongitud maxima 51", apellido,51,3);
                if(retorno == 0)
                    {
                        retorno = getValidFloat("\nSueldo: ","\nNo es un Sueldo valido",&sueldo,0,1000000,3);
                        if(retorno == 0)
                        {
                    retorno = empleado_modificar(empleado, empleado_tam, legajo, nombre,apellido, sueldo);
                        }
                    }
            }
        }
    }
    return retorno;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_borrarMenu(eMenu* menu, int menu_tam)
{
    int id;

    int retorno=-1;

    clearScreen();
    menu_listarMenues(menu,menu_tam);
    retorno = getValidInt("\nID a dar de Baja: ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(menu_buscar(menu, menu_tam, id) == NULL)
        {
            printf("El Menu elegido no existe\n");
            pause();
        }
        else
        {
            retorno = menu_borrar(menu, menu_tam, id);
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_borrarEmpleado(eEmpleado* empleado, int empleado_tam)
{
    int legajo;

    int retorno=-1;

    clearScreen();
    empleado_listarEmpleados(empleado,empleado_tam);
    retorno = getValidInt("\nLegajo a dar de Baja: ","\nRango valido 1000-9999", &legajo,1000,9999,3);

    if(retorno == 0)
    {
        if(empleado_buscar(empleado, empleado_tam, legajo) == NULL)
        {
            printf("El Empleado elegido no existe\n");
            pause();
        }
        else
        {
            retorno = empleado_borrar(empleado, empleado_tam, legajo);
        }
    }
    return retorno;
}
