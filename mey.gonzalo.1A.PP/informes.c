#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"
#include "alquileres.h"
#include "ejecutar.h"
#include "informes.h"


//-----------------------------------------------
//-----------------------------------------------
float informes_promedioYTotal(eJuegos* juegos, int juegos_tam)
{
    float promedio = 0;
    float total = 0;
    int cantidad;

    for(int i = 0;i<juegos_tam;i++)
        {
            total = total + juegos[i].importe;

        }
    cantidad = cantidadDeJuegosCargados(juegos,juegos_tam);

    promedio = total/cantidad;

    printf("\nPROMEDIO: %.2f   TOTAL:%.2f\n",promedio,total);

    return promedio;
}

//-----------------------------------------------
//-----------------------------------------------

int cantidadDeJuegosCargados(eJuegos x[],int tam)
{
    float cantidad = 0;

    for(int i = 0; i<tam ; i++){

        if(x[i].flagEstado == JUEGOS_PEDIDO){
            cantidad++;
        }
    }
    return cantidad;
}

//-----------------------------------------------
//-----------------------------------------------

void informes_menorPromedio(eJuegos* juegos,int juegos_tam)
{
    float promedio = informes_promedioYTotal(juegos,juegos_tam);
    int cantidad=0;

    for(int i = 0; i<juegos_tam ; i++)
    {
        if(juegos[i].importe < promedio)
        {
            cantidad++;
        }
    }
        printf("\nPROMEDIO: %.2f",promedio);
        printf("\nLa cantidad de juegos que su importe es MENOR al promedio: %d\n", cantidad);
}

//-----------------------------------------------
//-----------------------------------------------

void informes_clientesPorJuego(eAlquileres* alquiler, int alquiler_tam , eCliente* cliente,int cliente_tam,eJuegos* juegos, int juegos_tam)
{

    int idJuego;
    int flag = 0;

    system("cls");

    idJuego = elegirJuego(juegos,juegos_tam);
    system("cls");
    printf("  *** Listado de Juegos ID: %d ***\n\n", idJuego);

    for(int i=0; i < alquiler_tam ; i++)
    {
        if( alquiler[i].idJuego == idJuego)
        {
            for(int j=0; j < cliente_tam; j++)
            {
                if( cliente[j].legajo == alquiler[i].idCliente)
                {
                    printf("%d  %10s\n", alquiler[i].id, cliente[j].nombre);
                }
            }
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El Juego no presenta clientes");
    }
    printf("\n\n");
}


//-----------------------------------------------
//-----------------------------------------------

void informes_juegoPorCliente(eAlquileres* alquiler, int alquiler_tam , eCliente* cliente,int cliente_tam,eJuegos* juegos, int juegos_tam)
{

    int legajo;
    int flag = 0;

    system("cls");

    legajo = elegirCliente(cliente,cliente_tam);
    system("cls");
    printf("  *** Listado de Cliente Legajo: %d ***\n\n", legajo);

    for(int i=0; i < alquiler_tam ; i++)
    {
        if( alquiler[i].idCliente == legajo)
        {
            for(int j=0; j < juegos_tam; j++)
            {
                if( juegos[j].id == alquiler[i].idJuego)
                {
                    printf("%d  %10s\n", alquiler[i].id, juegos[j].descripcion);
                }
            }
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El Juego no presenta clientes");
    }
    printf("\n\n");
}

//-----------------------------------------------
//-----------------------------------------------

void informes_alquilerPorFecha(eAlquileres* alquiler,int alquiler_tam, eJuegos* juegos,int juegos_tam)
{
    int dia;
    int mes;
    int anio;
    char descripcion[20];
    int flag = 1;

    do{
    printf("\nDIA: \n");
    scanf("%d",&dia);
    }while(dia < 1 || dia > 31);

    do{
    printf("\nMES: \n");
    scanf("%d",&mes);
    }while(mes < 1 || mes > 12);

    do{
    printf("\nANIO: \n");
    scanf("%d",&anio);
    }while(anio < 1950 || anio > 2018);


    for(int i = 0; i < alquiler_tam;i++)
    {
        if(alquiler[i].fecha.dia == dia && alquiler[i].fecha.mes == mes && alquiler[i].fecha.anio == anio && alquiler[i].flagEstado == ALQUILER_USADO)
        {
            juego_cargarDescripcion(juegos,juegos_tam,alquiler[i].idJuego,descripcion);
            printf("\n%d   %s\n",alquiler[i].id,descripcion);
            flag = 0;
        }
    }

    if(flag == 1)
    {
            printf("NO HAY ALQUILERES PARA ESA FECHA");
    }
}

//-----------------------------------------------
//-----------------------------------------------

void informes_clientePorFecha(eAlquileres* alquiler,int alquiler_tam, eCliente* clientes,int clientes_tam)
{
    int dia;
    int mes;
    int anio;
    char nombre[20];
    int flag = 1;

    do{
    printf("\nDIA: \n");
    scanf("%d",&dia);
    if(dia < 1 || dia > 31 )
    {
        printf("ERROR. Intente nuevamente\n");
    }
    }while(dia < 1 || dia > 31);

    do{
    printf("\nMES: \n");
    scanf("%d",&mes);
     if(mes < 1 || mes > 12)
    {
        printf("ERROR. Intente nuevamente\n");
    }
    }while(mes < 1 || mes > 12);

    do{
    printf("\nANIO: \n");
    scanf("%d",&anio);
     if(anio < 1950 || anio > 2018)
    {
        printf("ERROR. Intente nuevamente\n");
    }
    }while(anio < 1950 || anio > 2018);


    for(int i = 0; i < alquiler_tam;i++)
    {
        if(alquiler[i].fecha.dia == dia && alquiler[i].fecha.mes == mes && alquiler[i].fecha.anio == anio && alquiler[i].flagEstado == ALQUILER_USADO)
        {
            cliente_cargarNombre(clientes,clientes_tam,alquiler[i].idCliente,nombre);
            printf("\n%d   %s\n",alquiler[i].id,nombre);
            flag = 0;
        }
    }

    if(flag == 1)
    {
            printf("NO HAY ALQUILERES PARA ESA FECHA");
    }
}


//-----------------------------------------------
//-----------------------------------------------

void informes_clientesPorInsercion(eCliente* clientes, int clientes_tam)
{

int p, j;

eCliente auxCliente;

    for (p = 1; p < clientes_tam; p++)
    {
        auxCliente = clientes[p];
        j = p - 1;

            while ((j >= 0) && (auxCliente.apellido < clientes[j].apellido))
            {

            clientes[j + 1] = clientes[j];
            j--;

            }
        clientes[j + 1] = auxCliente;
    }
    cliente_listarClientes(clientes,clientes_tam);
}
