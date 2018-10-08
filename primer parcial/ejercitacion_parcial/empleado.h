#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#define EMPLEADO_VACIO 0
#define EMPLEADO_CARGADO 1
#define EMPLEADO_ELIMINADO 2


typedef struct{

    int dia;
    int mes;
    int anio;
    int flagEstadoFecha;

}eFecha;

typedef struct{

    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo[3];
    float sueldo;
    eFecha fecha_ingreso;
    int flagEstado;

}eEmpleado;


#endif // EMPLEADO_H_INCLUDED


int empleado_init(eEmpleado* empleado, int empleado_tam);

int empleado_agregar(eEmpleado* empleado, int empleado_tam,char nombre[],char apellido[],char sexo[],float sueldo,eFecha fecha_ingreso);

int empleado_findEmptyPlace(eEmpleado* empleado, int empleado_tam);

int empleado_findNextId(eEmpleado* empleado, int empleado_tam);

int empleado_borrar(eEmpleado* empleado, int empleado_tam, int legajo);

eEmpleado* empleado_buscar(eEmpleado* empleado, int empleado_tam, int legajo);

int empleado_modificar(eEmpleado* empleado, int empleado_tam, int legajo, char nombre[],char apellido[],float sueldo);

void empleado_mostrar(eEmpleado empleado, int empleado_tam);

void empleado_listarEmpleados(eEmpleado nomina[], int empleado_tam);

void empleados_harcodear(eEmpleado y[]);

