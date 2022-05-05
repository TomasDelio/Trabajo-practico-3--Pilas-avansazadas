#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila cargarPila();
Pila ordenarPila(Pila pila);
Pila unir2Pilas(Pila pila1,Pila pila2);


int main()
{
    Pila pila1,pila2,ordenada1,ordenada2,ordenadaFinal;

    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);

    pila1=cargarPila(pila1);
    pila2=cargarPila(pila2);
    printf("La pila1 es:");
    mostrar(&pila1);

    printf("La pila2 es:");
    mostrar(&pila2);

    ordenada1=ordenarPila(pila1);
    ordenada2=ordenarPila(pila2);

    printf("La pila1 ordenada es:");
    mostrar(&ordenada1);

    printf("La pila2 ordenada es:");
    mostrar(&ordenada2);

    ordenadaFinal=unir2Pilas(ordenada1,ordenada2);

    printf("La pila final ordenada es:");
    mostrar(&ordenadaFinal);

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
Pila unir2Pilas(Pila pila1,Pila pila2)
{
    Pila aux,unionPila;
    inicpila(&aux);
    inicpila(&unionPila);
    while(!pilavacia(&pila1))
    {
        apilar(&aux,desapilar(&pila1));
    }
    while(!pilavacia(&pila2))
    {
        apilar(&aux,desapilar(&pila2));
    }
    unionPila=ordenarPila(aux);
    return unionPila;
}
