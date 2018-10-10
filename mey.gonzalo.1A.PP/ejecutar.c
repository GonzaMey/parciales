#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"

int ejecutar_nuevoJuego(eJuegos juegos[], int juegos_tam)
{
    char descripcion[51];
    float importe;
    int retorno=-1;

    system("cls");
    getString("\nDescripcion: ", descripcion);

        retorno = getValidFloat("\nImporte: ","\nNo es un Importe valido", &importe,0,10000,3);
        if(retorno == 0)
            {
                retorno = juegos_agregar(juegos, juegos_tam, descripcion, importe);
            }
    return retorno;
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_nuevoCliente(eCliente cliente[], int cliente_tam)
{
    char nombre[51];
    char apellido[51];
    char sexo = 'p';
    char domicilio[51];
    int retorno=-1;

    system("cls");
    retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 51", nombre,51,3);
    if(retorno == 0)
    {
         retorno = getValidString("\nApellido: ","\nNo es un apellido valido","\nLongitud maxima 51", apellido,51,3);
         if(retorno == 0)
         {
              sexo = getValidSexo("\nSexo: ","\nNo es un sexo valido",sexo,3);

                    getString("\nDomicilio: ",domicilio);
                    if(retorno == 0)
                        {
                                retorno = cliente_agregar(cliente,cliente_tam,nombre,apellido,sexo,domicilio);
                        }
          }


    }

    return retorno;
}



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_modificarJuego(eJuegos* juegos, int juegos_tam)
{
    char descripcion[20];
    float importe;
    int id;

    int retorno=-1;

    system("cls");
    juegos_listarJuegos(juegos,juegos_tam);
    retorno = getValidInt("\nID a Modificar: ","\nRango valido 0-999", &id,0,999,3);

    if(retorno == 0)
    {
        if(juegos_buscar(juegos, juegos_tam, id) == NULL)
        {
            printf("El Juego elegido no existe\n");
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
                    retorno = juegos_modificar(juegos, juegos_tam, id, descripcion, importe);
                }
            }
        }
    }
    return retorno;
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_modificarCliente(eCliente* cliente, int cliente_tam)
{
    char nombre[51];
    char apellido[51];
    char sexo = 'q';
    char domicilio[51];
    int legajo;

    int retorno=-1;

    system("cls");
    cliente_listarClientes(cliente,cliente_tam);
    retorno = getValidInt("\nLegajo a Modificar: ","\nRango valido 1000-9999", &legajo,1,9999,3);

    if(retorno == 0)
    {
        if(cliente_buscar(cliente, cliente_tam, legajo) == NULL)
        {
            printf("El Cliente elegido no existe\n");
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
                        retorno = getValidSexo("\nSexo: ","\nNo es un Sexo valido",sexo,3);
                        if(retorno == 0)
                        {
                            retorno = getValidString("\nDomicilio: ","\nNo es un Domicilio valido","\nLongitud maxima 51",domicilio,51,3);
                            if(retorno == 0)
                            {

                                retorno = cliente_modificar(cliente, cliente_tam, legajo, nombre,apellido, sexo,domicilio);
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

int ejecutar_borrarJuego(eJuegos* juegos, int juegos_tam)
{
    int id;

    int retorno=-1;

    system("cls");
    juegos_listarJuegos(juegos,juegos_tam);
    retorno = getValidInt("\nID a dar de Baja: ","\nRango valido 0-999", &id,0,9999,3);

    if(retorno == 0)
    {
        if(juegos_buscar(juegos, juegos_tam, id) == NULL)
        {
            printf("El Juego elegido no existe\n");
            pause();
        }
        else
        {
            retorno = juegos_borrar(juegos, juegos_tam, id);
        }
    }
    return retorno;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int ejecutar_borrarCliente(eCliente* cliente, int cliente_tam)
{
    int legajo;

    int retorno=-1;

    system("cls");
    cliente_listarClientes(cliente,cliente_tam);
    retorno = getValidInt("\nLegajo a dar de Baja: ","\nRango valido 1000-9999", &legajo,1,9999,3);

    if(retorno == 0)
    {
        if(cliente_buscar(cliente, cliente_tam, legajo) == NULL)
        {
            printf("El Cliente elegido no existe\n");
            pause();
        }
        else
        {
            retorno = cliente_borrar(cliente, cliente_tam, legajo);
        }
    }
    return retorno;
}


int ejecutar_nuevoAlquiler(eAlquileres* alquiler, int alquiler_tam,eCliente* cliente, int cliente_tam,eJuegos* juegos, int juegos_tam)
{
    int idCliente;
    int idJuego;
    int dia,mes,anio;
    int retorno = -1;


    system("cls");
    idCliente = elegirCliente(cliente,cliente_tam);

    idJuego = elegirJuego(juegos,juegos_tam);

    retorno = getValidInt("Ingrese el dia: ","Error Dia invalido",&dia,1,31,3);
    if(retorno == 0)
    {
        retorno = getValidInt("Ingrese el mes: ","Error Mes invalido",&mes,1,12,3);
        if(retorno == 0)
        {
            retorno = getValidInt("Ingrese el anio: ","Error Anio invaldo",&anio,1990,2018,3);
            if(retorno == 0)
            {
                retorno = alquiler_agregar(alquiler,alquiler_tam,idJuego,idCliente,dia,mes,anio);
            }
        }

    }
    return retorno;
}


