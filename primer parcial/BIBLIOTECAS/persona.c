#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

//-------------------------------------------------------------
//-------------------------------------------------------------

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Listar\n");
    printf("5- Listar empleados por apellido y sector\n");
    printf("6- Listar empleados con mayor salario al promedio\n");
    printf("0- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//-------------------------------------------------------------
//-------------------------------------------------------------

void inicializarEmpleados( eEmpleado x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}


//-------------------------------------------------------------
//-------------------------------------------------------------
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector, int nroDeOrden)
{
    eEmpleado nuevoEmpleado;
    int indice;
    char seguir='s';

    do{
    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }else{


            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.isEmpty = 1;

            nuevoEmpleado.legajo = nroDeOrden++;

            empleados[indice] = nuevoEmpleado;

            printf("\nDesea agregar otro empleado?(s/n)\n");
            fflush(stdin);
            scanf("%c",&seguir);


            }
       }while(seguir != 'n');
}





//-------------------------------------------------------------
//-------------------------------------------------------------
int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//-------------------------------------------------------------
//-------------------------------------------------------------

int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++){
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %s %.2f %s \n\n", emp.legajo, emp.nombre, emp.apellido, emp.sueldo, descripcion);

}

//-------------------------------------------------------------
//-------------------------------------------------------------

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}


//-------------------------------------------------------------
//-------------------------------------------------------------
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

int legajo;
int indice;
char modificar = 's';
int opcion;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);


    printf("\n\n ***QUE DESEA MODIFICAR?***\n");
    printf("1-NOMBRE\n");
    printf("2-APELLIDO\n");
    printf("3-SUELDO\n");
    printf("4-SECTOR\n");
    printf("0-CANCELAR\n");

    scanf("%d",&opcion);

        switch(opcion){
        case 1:
            printf("Ingrese nuevo Nombre: ");
            scanf("%s", empleados[indice].nombre);
            break;
        case 2:
            printf("Ingrese nuevo Apellido: ");
            scanf("%s", empleados[indice].apellido);
            break;
        case 3:
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &empleados[indice].sueldo);
            break;
        case 4:
           empleados[indice].idSector = elegirSector(sectores,5);
           break;
        case 0:
            modificar = 'n';
            break;
        }


    fflush(stdin);

    if(modificar != 's'){
        printf("Modificacion cancelada\n\n");
        }
    }
}


//-------------------------------------------------------------
//-------------------------------------------------------------
void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

int legajo;
int indice;
char borrar;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
        }
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------

void ordenarPorApellidoYSector(eEmpleado x[], int tam)
{
    eEmpleado empleadoAux;
    int flag = 0;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam ; j++){
            if(x[i].idSector < x[j].idSector){
               empleadoAux = x[i];
               x[i] = x[j];
               x[j] = empleadoAux;
            }
            if(x[i].idSector == x[j].idSector && strcmp(x[i].apellido,x[j].apellido)<0){
               empleadoAux = x[i];
               x[i] = x[j];
               x[j] = empleadoAux;
            }
            flag = 1;
        }
    }
    if(flag == 0){printf("OCURRIO UN ERROR VERIFIQUE LOS DATOS");}
}

//-------------------------------------------------------------
//-------------------------------------------------------------

int cantidadDeEmpleadosCargados(eEmpleado x[],int tam)
{
    int cantidad = 0;

    for(int i = 0; i<tam ; i++){

        if(x[i].isEmpty == 1){
            cantidad++;
        }
    }
    return cantidad;
}

//-------------------------------------------------------------
//-------------------------------------------------------------

void promedioYTotal(eEmpleado x[], int tam,eSector sectores[], int tamSectores){

    float total=0;
    float promedio = 0;

    for(int i=0; i<tam; i++){

        total = total + x[i].sueldo;

    }

    promedio = (total / cantidadDeEmpleadosCargados(x,tam));

    printf("EL TOTAL DEL SUELDO ES DE: %.4f \n\n",&total);
    printf("EL PROMEDIO ES DE: %.4f \n\n",&promedio);

    for(int i = 0; i<tam ; i++){

        if(x[i].sueldo > promedio){
            mostrarEmpleado(x[i],sectores,tamSectores);
        }
    }

}


//-------------------------------------------------------------
//-------------------------------------------------------------


int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




