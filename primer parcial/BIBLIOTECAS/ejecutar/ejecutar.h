#include "menu.h"
#include "utn.h"
#include "empleado.h"

#ifndef INCLUDE_H_EJECUTAR
#define INCLUDE_H_EJECUTAR



#endif // INCLUDE_H_EJECUTAR

int ejecutar_nuevoMenu(eMenu menu[], int menu_tam);

int ejecutar_modificarMenu(eMenu menu[], int menu_tam);

int ejecutar_borrarMenu(eMenu menu[], int menu_tam);

int ejecutar_nuevoEmpleado(eEmpleado empleado[], int empleado_tam,eFecha fecha_ingreso);

int ejecutar_modificarEmpleado(eEmpleado* empleado, int empleado_tam);

int ejecutar_borrarEmpleado(eEmpleado* empleado, int empleado_tam);
