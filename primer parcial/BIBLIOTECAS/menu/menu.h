#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_VACIO 0
#define MENU_PEDIDO 1
#define MENU_BORRADO 2


typedef struct{

    int id;
    char descripcion[20];
    float importe;
    int flagEstado;

}eMenu;

#endif // MENU_H_INCLUDED

int menu_init(eMenu* menu, int menu_tam);

int menu_agregar(eMenu* menu, int menu_tam,char descripcion[],float importe);

int menu_findEmptyPlace(eMenu* menu, int menu_tam);

int menu_findNextId(eMenu* menu, int menu_tam);

int menu_borrar(eMenu* menu, int menu_tam, int idMenu);

eMenu* menu_buscar(eMenu* menu, int menu_tam, int idMenu);

int menu_borrar(eMenu* menu, int menu_tam, int idMenu);

int menu_modificar(eMenu* menu, int menu_tam, int idMenu, char descripcion[],float importe);

void menu_harcodear(eMenu y[]);

void menu_listarMenues(eMenu nomina[], int menu_tam);

void menu_mostrar(eMenu menu, int menu_tam);
