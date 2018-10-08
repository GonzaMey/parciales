
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


void inicializarEmpleados( eEmpleado x[], int tam);

int menu();

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector,int nroDeOrden);

int buscarLibre( eEmpleado x[], int tam);

int elegirSector(eSector sectores[], int tam);

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

void ordenarPorApellidoYSector(eEmpleado x[], int tam);

int cantidadDeEmpleadosCargados(eEmpleado x[],int tam);

void promedioYTotal(eEmpleado x[], int tam,eSector sectores[], int tamSectores);

int buscarEmpleado(eEmpleado x[], int tam, int legajo);

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
