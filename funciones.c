#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define E 20

void inicializaEstructura(EPersona lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].nombre['\0']=0;
        lista[i].edad=0;
        lista[i].estado=0;
        lista[i].dni=0;
    }
}

int obtenerEspacioLibre(EPersona lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

void agregaPersona(EPersona lista[],int tam,int indice)
{
    int documento,edad,vale=0;
    char auxNombre[50];

    while(vale==0)
    {
        documento=getInt("\nIngrese el DNI: ","\nDNI invalido",1,99999999,8);
        vale=validaDNI(lista,E,documento);
    }
    lista[indice].dni=documento;

    getChar(auxNombre,"\nIngrese el nombre: ","\nNombre invalido",50);
    strcpy(lista[indice].nombre,auxNombre);

    edad=getInt("\nIngrese la edad: ","\nEdad invalida",0,99,2);
    lista[indice].edad=edad;

    lista[indice].estado=1;
}

void borrarPersona(EPersona lista[],int tam)
{
    int i,dni;
    dni=getInt("\nIngrese DNI a eliminar: ","DNI invalido",1,99999999,8);
    i=buscarPorDni(lista,dni,E);
    if(i!=-1 && lista[i].estado!=0)
    {
        lista[i].estado=0;
        printf("\nDNI eliminado\n");
    }
}

void ordenarPersona(EPersona lista[],int tam)
{
    EPersona listaAux;
    int i,j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(lista[i].nombre,lista[j].nombre)>0)
            {
                listaAux=lista[i];
                lista[i]=lista[j];
                lista[j]=listaAux;
            }
        }
    }
}

void mostrarPersona(EPersona lista[],int tam)
{
    int i;
    printf("\nDNI\t\tNombre\tEdad\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=0)
        {
            printf("%d\t%s\t%d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        }
    }
}

int buscarPorDni(EPersona lista[],int dni,int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].dni == dni && lista[i].estado!=0)
        {
            return i;
        }
    }
    printf("El DNI no existe en el sistema\n");
    return -1;
}

int validaLetra(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
    {
        if((isdigit(dato[i])) || ((dato[i]<'a' || dato[i]>'z')))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}

int validaNumero(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
    {
        if(!(isdigit(dato[i])))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}

int getInt(char mensaje[],char error[],int min,int max,int largo)
{

    int flag,valido,num;
    char auxNum[largo];
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        scanf("%s",auxNum);
        valido=validaNumero(auxNum,largo);
        if(valido!=0)
        {
            num=atoi(auxNum);
            if(num>=min && num<=max)
            {
                return num;
            }
            else
            {
                printf(error);
                flag++;
            }
        }
        else
        {
            printf(error);
            flag++;
        }
    }
    while(flag!=0);
}

void getChar(char input[],char mensaje[],char error[],int largo)
{
    int flag,valido;
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        gets(input);
        valido=validaLetra(input,largo);
        if(valido==0)
        {
            printf(error);
            flag++;
        }
    }
    while(flag!=0);
}

int validaDNI(EPersona lista[],int tam,int documento)
{
    int i,flag=0;
    for(i=0; i<tam; i++)
    {
        if (documento==lista[i].dni && lista[i].estado==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        return 1;
    }
    printf("El DNI ya se encuentra en el sistema\n");
    return 0;
}

void graficarPersona(EPersona lista[],int tam)
{
    int menor18=0,de19a35=0,mayor35=0,i,max=0,flag=0;
    system("cls");
    for(i=0; i<E; i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].edad<=18)
            {
                menor18++;
            }
            else
            {
                if(lista[i].edad>35)
                {
                    mayor35++;
                }
                else
                {
                    de19a35++;
                }
            }
        }
    }
    if(menor18 >= de19a35 && menor18 >= mayor35)
    {
        max = menor18;
    }
    else
    {
        if(mayor35 >= menor18 && mayor35 >= de19a35)
        {
            max = mayor35;
        }
        else
        {
            max = de19a35;
        }
    }
//Imprime y numera las ordenadas
    for(i=max; i>0; i--)
    {
        printf("%02d|",i);
//Imprime los * dependiendo las edades
        if(i<= menor18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayor35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", menor18, de19a35, mayor35);
}
