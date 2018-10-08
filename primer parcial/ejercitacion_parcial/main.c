/*Desarrollar en ANSI C:
Una empresa necesita administrar los almuerzos de su comedor en planta, y para ello se deber� realizar un programa de acuerdo a lo siguiente:

	Menu:
�	C�digo de menu (autoincremental)
�	Descripci�n (m�ximo 51 caracteres)  Validar
�	Importe (debe ser mayor a cero)  Validar

	Empleados:
�	Legajo (autoincremental)
�	Apellido (m�ximo 51 caracteres) Validar
�	Nombre (m�ximo 51 caracteres) Validar
�	sexo Validar
�	salario (debe ser mayor a cero) Validar
�	fecha de ingreso (el dia, mes y a�o debe estar en los rangos correspondientes) Validar

Almuerzo:
�	Codigo de almuerzo (autoincremental)
�	Codigo de menu (debe existir) Validar
�	Legajo de empleado (debe existir) Validar
�	Fecha (el dia, mes y a�o debe estar en los rangos correspondientes) Validar

MENUES:
A)	Altas: No es necesario el ingreso de todos los menues.
B)	Modificar: Se ingresar� el c�digo de menu, permitiendo en un submen� modificar:
�	Descripci�n
�	importe
B)	Baja:  Se ingresar� el c�digo de menu y se realizar� una baja l�gica.
C)	Listar: Hacer un �nico listado de todos los menues ordenados por importe (descendente) y descripcion (ascendente).

EMPLEADOS:
A)	Altas: No es necesario el ingreso de todos los empleados.
B)	Modificar: Se ingresar� el C�digo de Empleado, permitiendo en un submen� modificar:
�	Apellido
�	Nombre
�	Sexo
�	Salario
�	Fecha de ingreso
B)	Baja:  Se ingresar� el C�digo de Empleado y se realizar� una baja l�gica.
C)	Listar: Hacer un �nico listado de todos los Empleados ordenados por apellido (ascendente) y nombre (ascendente).

ALMUERZOS: Se dar� de alta cada ocurrencia de Almuerzo, relacionando Menu � Empleado, Fecha y Codigo de Almuerzo.


NOTAS:
I.	Se deber� desarrollar bibliotecas por cada entidad, las cuales contendr�n las funciones Alta, Baja, Modificar y Listar.
II.	Las validaciones deber�n estar en una biblioteca aparte.
III.	Tener en cuenta que no se podr� ingresar a los casos Modificar, Baja y Listar; sin antes haber realizado al menos un Alta (utilizar banderas).
IV.	El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las reglas de estilo de la c�tedra*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ejecutar.h"
#include "utn.h"
#include "empleado.h"


#define MENU_CANTIDAD 10
#define EMPLEADO_CANTIDAD 20

int main()
{
    int menuOpcionElegida;
    char menuPrincipalMensaje[] =
                "\n1-Alta de Menu\
                 \n2-Modificar datos del Menu\
                 \n3-Baja del Menu\
                 \n4-Listar Menues\
                 \n5-Alta de Empleado\
                 \n6-Baja de Empleado\
                 \n7-Modificar datos del Empleado\
                 \n8-Listar Empleados\
                 \n9-Salir\n\
                 \nIngrese opcion: ";
    char menuPrincipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 4";


    //DECLARACION E INICIALIZACION DE MENUES:
    eMenu menu[MENU_CANTIDAD];
    menu_init(menu,MENU_CANTIDAD);

    //DECLARACION E INICIALIZACION DE EMPLEADOS:
    eEmpleado empleado[EMPLEADO_CANTIDAD];
    eFecha fecha_ingreso;
    empleado_init(empleado,EMPLEADO_CANTIDAD);


    //HARCODEO DE MENUES Y EMPLEADOS:
    menu_harcodear(menu);
    empleados_harcodear(empleado);



    do{
        system("cls");
        menuOpcionElegida = 0;
        getValidInt(menuPrincipalMensaje,menuPrincipalMensajeError,&menuOpcionElegida,1,9,3);

        switch(menuOpcionElegida)
        {
        case 1:
            ejecutar_nuevoMenu(menu,MENU_CANTIDAD);
            system("pause");
            break;
        case 2:
            ejecutar_modificarMenu(menu,MENU_CANTIDAD);
            system("pause");
            break;
        case 3:
            ejecutar_borrarMenu(menu,MENU_CANTIDAD);
            system("pause");
            break;
        case 4:
            menu_listarMenues(menu,MENU_CANTIDAD);
            system("pause");
            break;
        case 5:
            ejecutar_nuevoEmpleado(empleado,EMPLEADO_CANTIDAD,fecha_ingreso);
            system("pause");
            break;
        case 6:
            ejecutar_borrarEmpleado(empleado,EMPLEADO_CANTIDAD);
            system("pause");
            break;
        case 7:
            ejecutar_modificarEmpleado(empleado,EMPLEADO_CANTIDAD);
            system("pause");
            break;
        case 8:
            empleado_listarEmpleados(empleado,EMPLEADO_CANTIDAD);
            system("pause");
            break;
        case 9:
            //SALIR
            break;
        default:
            printf("\nNo es una opcion valida.\n\n");
            system("pause");
            break;

        }

    }while(menuOpcionElegida != 9);

    return 0;
}
