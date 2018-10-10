#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"
#include "alquileres.h"
#include "ejecutar.h"
#include "informes.h"

#define JUEGOS_CANT 10
#define CLIENTES_CANT 20
#define ALQUILER_CANT 200

int main()
{

     int menuOpcionElegida;
    char menuPrincipalMensaje[] =                                //MENU DE OPCIONES

                "\n***JUEGOS***\
                 \n1-Alta de Juego\
                 \n2-Modificar datos del Juego\
                 \n3-Baja del Juego\
                 \n4-Listar Juegos\
                 \n***CLIENTES***\
                 \n5-Alta de Cliente\
                 \n6-Baja de Cliente\
                 \n7-Modificar datos del Cliente\
                 \n8-Listar Clientes\
                 \n***ALQUILERES***\
                 \n9-Agregar Alquiler\
                 \n10-Listar Alquileres\
                 \n***INFORMES***\
                 \n11-Promedio y total\
                 \n12-Cantidad de juegos de menor importe al promedio\
                 \n13-Listar clientes por juego\
                 \n14-Listar juegos por cliente\
                 \n15-Listar por Juegos Fecha\
                 \n16-Listar Clientes por Fecha\
                 \n17-Listar Clientes de forma alfabetica\
                 \n18-SALIR\n\
                 \nIngrese opcion: ";
    char menuPrincipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 18";

    //DECLARACION E INICIALIZACION DE JUEGOS
    eJuegos juegos[JUEGOS_CANT];
    juegos_init(juegos,JUEGOS_CANT);

    //DECLARACION E INICIALIZACION DE CLIENTES
    eCliente clientes[CLIENTES_CANT];
    clientes_init(clientes,CLIENTES_CANT);

    //DECLARACION E INICIALIZACION DE ALQUILERES
   eAlquileres alquiler[ALQUILER_CANT];
   alquiler_init(alquiler,ALQUILER_CANT);

  //ALQUILERES HARDCODEADOS
  /*eAlquileres alquiler[ALQUILER_CANT] =
   {
        {1, 1000, 2,{25,10,2015},1},
        {2, 1001, 1,{25,10,2017},1},
        {3, 1002, 3,{25,10,2016},1},
        {4, 1003, 4,{25,10,2018},1},
        {5, 1004, 1,{25,10,2014},1},
        {6, 1005, 5,{25,10,2015},1},
        {7, 1006, 2,{25,10,2018},1},
        {8, 1000, 5,{25,10,2016},1},
        {9, 1001, 2,{25,10,2017},1},
        {10, 1002, 1,{25,10,2015},1},
        {11, 1003, 1,{25,10,2018},1},
        {12, 1004, 4,{25,10,2015},1},
        {13, 1005, 3,{25,10,2015},1},
        {14, 1006, 5,{25,10,2018},1},
        {15, 1000, 2,{25,10,2017},1},
        {16, 1001, 5,{25,10,2015},1},
        {17, 1002, 2,{25,10,2018},1},
        {18, 1003, 3,{25,10,2017},1},
        {19, 1004, 2,{25,10,2016},1},
        {20, 1005, 1,{25,10,2018},1},
        {21, 1006, 3,{25,10,2016},1},

    };*/

    //FUNCION DE HARDCODEO DE JUEGOS Y CLIENTES
    //juegos_harcodear(juegos);
    //cliente_harcodear(clientes);


    //INICIO DE DE WHILE
     do{
        system("cls");
        menuOpcionElegida = 0;
        getValidInt(menuPrincipalMensaje,menuPrincipalMensajeError,&menuOpcionElegida,1,18,3); //PIDE UNA OPCION DEL MENU DE OPCIONES

        switch(menuOpcionElegida)
        {
        case 1:
            ejecutar_nuevoJuego(juegos,JUEGOS_CANT);    //CARGA UN NUEVO JUEGO
            system("pause");
            break;
        case 2:
            ejecutar_modificarJuego(juegos,JUEGOS_CANT);    //MODIFICA LAS CARACTERISTICAS DE UN JUEGO
            system("pause");
            break;
        case 3:
            ejecutar_borrarJuego(juegos,JUEGOS_CANT);       //ELIMINA UN JUEGO DE LA LISTA
            system("pause");
            break;
        case 4:
            juegos_listarJuegos(juegos,JUEGOS_CANT);        //MUESTRA EL LISTADO DE JUEGOS CARGADOS
            system("pause");
            break;
        case 5:
            ejecutar_nuevoCliente(clientes,CLIENTES_CANT);      //CARGA UN NUEVO CLIENTE
            system("pause");
            break;
        case 6:
            ejecutar_borrarCliente(clientes,CLIENTES_CANT);     //BORRA UN CLIENTE DE LA LISTA
            system("pause");
            break;
        case 7:
            ejecutar_modificarCliente(clientes,CLIENTES_CANT);      //MODIFICA LOS DATOS DE UN CLIENTE
            system("pause");
            break;
        case 8:
            cliente_listarClientes(clientes,CLIENTES_CANT);     //LISTA LOS CLIENTES
            system("pause");
            break;
        case 9:
            ejecutar_nuevoAlquiler(alquiler,ALQUILER_CANT,clientes,CLIENTES_CANT,juegos,JUEGOS_CANT);   //PERMITE EL INGRESO DE UN NUEVO ALQUILER
            system("pause");
            break;
        case 10:
            alquiler_listar(alquiler,ALQUILER_CANT,clientes,CLIENTES_CANT,juegos,JUEGOS_CANT);      //MUESTRA EL LISTADO DE ALQUILERES REALIZADOS
            system("pause");
            break;
        case 11:
            informes_promedioYTotal(juegos,JUEGOS_CANT);
            system("pause");
            break;
        case 12:
            informes_menorPromedio(juegos,JUEGOS_CANT);
            system("pause");
            break;
        case 13:
            informes_clientesPorJuego(alquiler,ALQUILER_CANT,clientes,CLIENTES_CANT,juegos,JUEGOS_CANT);
            system("pause");
            break;
        case 14:
            informes_juegoPorCliente(alquiler,ALQUILER_CANT,clientes,CLIENTES_CANT,juegos,JUEGOS_CANT);
            system("pause");
            break;
        case 15:
            informes_alquilerPorFecha(alquiler,ALQUILER_CANT,juegos,JUEGOS_CANT);
            system("pause");
            break;
        case 16:
            informes_clientePorFecha(alquiler,ALQUILER_CANT,clientes,CLIENTES_CANT);
            system("pause");
            break;
        case 17:
            informes_clientesPorInsercion(clientes,CLIENTES_CANT);
            system("pause");
            break;
        case 18:
            //SALIR
            break;
        default:
            printf("\nNo es una opcion valida.\n\n");   //MENSAJE DE ERROR SI NO SE ELIGE UNA OPCION VALIDA
            system("pause");
            break;

        }

    }while(menuOpcionElegida != 18);//FIN DE DO WHILE


    return 0;
}
