#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define E 20

int main(){
    char seguir='s',opcion=0;
    int libre=0;
    EPersona lista[E];
    inicializaEstructura(lista,E);
    while(seguir=='s'){
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        opcion=getInt("Ingrese una opcion: ","Opcion incorrecta\n",1,5,1);
        system("cls");
        switch(opcion){
        case 1:
            libre=obtenerEspacioLibre(lista,E);
            if(libre==-1){
                printf("No queda mas lugar\n");
            }else{
                agregaPersona(lista,E,libre);
            }break;
        case 2:
            borrarPersona(lista);
            break;
        case 3:
            ordenarPersona(lista);
            mostrarPersona(lista);
            break;
        case 4:
            graficarPersona(lista,E);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }return 0;
}
