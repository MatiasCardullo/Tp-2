#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void agregaPersona(EPersona [],int,int);
int validaDNI(EPersona [],int,int);
void borrarPersona(EPersona []);
void ordenarPersona(EPersona []);
void mostrarPersona(EPersona []);
void graficarPersona(EPersona [],int);
void inicializaEstructura(EPersona [],int);
int validaNumero(char [],int);
int getInt(char [],char [],int ,int ,int);
void getChar(char [],char [],char [],int);
int obtenerEspacioLibre(EPersona [],int);
int buscarPorDni(EPersona [], int ,int);

#endif // FUNCIONES_H_INCLUDED
