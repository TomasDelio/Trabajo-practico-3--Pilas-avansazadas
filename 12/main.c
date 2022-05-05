#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila cargarPila();
Pila ordenarPila(Pila pila);


int main()
{
Pila origen,aux;
    inicpila(&origen);
    inicpila(&aux);
    origen=cargarPila(origen);
    printf("La pila inicial es:");
    mostrar(&origen);
    aux=ordenarPila(origen);
    inicpila(&origen);
    while(!pilavacia(&aux))
    {
        apilar(&origen,desapilar(&aux));
    }
    printf("La pila ordenada es:");
    mostrar(&origen);

    return 0;
}

Pila cargarPila()
{
    Pila pilaAux;
    char continuar;
    inicpila(&pilaAux);
    printf("Ingrese los elementos de la pila:\n\n");
    do
    {
        leer(&pilaAux);
        printf("Desea ingresar otro elemento? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    while(continuar!='n');
    return pilaAux;
}
Pila ordenarPila(Pila pilaDesordenada)
{
    Pila ordenada,aux;
    inicpila(&ordenada);
    inicpila(&aux);
    while(!pilavacia(&pilaDesordenada))
    {
        if(tope(&pilaDesordenada)<tope(&ordenada))
        {
            apilar(&ordenada,desapilar(&pilaDesordenada));
        }
        else
        {
            while(tope(&pilaDesordenada)>tope(&ordenada))
            {
                apilar(&aux,desapilar(&ordenada));
            }
            apilar(&ordenada,desapilar(&pilaDesordenada));
            while(!pilavacia(&aux))
            {
                apilar(&ordenada,desapilar(&aux));
            }
        }
    }
    return ordenada;
}
