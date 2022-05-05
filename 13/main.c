#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila mazoRandom(int manos);
float sumarPila(Pila pila);

int main()
{
        int i,j1,j2,m,manos,suma1=0,suma2=0,puntaje1=0,puntaje2=0;
    char continuar;
    Pila mazo,jugador1,jugador2,descarte1,descarte2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&descarte1);
    inicpila(&descarte2);
    printf("Ingrese la cantidad de manos que desea jugar: ");
    scanf("%i",&manos);
    mazo=mazoRandom(manos);
    printf("\nMazo:");
    mostrar(&mazo);
    printf("Enter para jugar la primera mano: ");
    fflush(stdin);
    scanf("%c",&continuar);
    for(m=1;m<manos+1;m++)
    {
        printf("\nMano: %i\n",m);
        for(i=0;i<2;i++)
        {
            if(suma1<suma2)
            {
                apilar(&jugador1,desapilar(&mazo));
                apilar(&jugador2,desapilar(&mazo));
            }
            else
            {
                apilar(&jugador2,desapilar(&mazo));
                apilar(&jugador1,desapilar(&mazo));
            }
        }
        printf("\nMano del jugador 1:");
        mostrar(&jugador1);
        suma1=0;
        suma1=sumarPila(jugador1);
        printf("Mano del jugador 2:");
        mostrar(&jugador2);
        suma2=0;
        suma2=sumarPila(jugador2);
        printf("Puntaje de esta ronda del jugador 1: %i\n",suma1);
        printf("Puntaje de esta ronda del jugador 2: %i\n",suma2);
        if(suma2>suma1)
        {
            puntaje2=puntaje2+suma1+suma2;
            printf("\nEl jugador 2 se queda con los puntos.\n");
            for(j2=0;j2<2;j2++)
            {
                apilar(&descarte2,desapilar(&jugador1));
                apilar(&descarte2,desapilar(&jugador2));
            }
        }
        else
        {
            puntaje1=puntaje1+suma1+suma2;
            printf("\nEl jugador 1 se queda con los puntos.\n");
            for(j1=0;j1<2;j1++)
            {
                apilar(&descarte1,desapilar(&jugador1));
                apilar(&descarte1,desapilar(&jugador2));
            }
        }
        printf("\nPuntaje total del jugador 1: %i",puntaje1);
        printf("\nPuntaje total del jugador 2: %i\n",puntaje2);
        if(m==manos-1)
        {
            printf("\nEnter para jugar la ultima mano: ");
            fflush(stdin);
            scanf("%c",&continuar);
        }
        if(m<manos-1)
        {
            printf("\nEnter para jugar la siguiente mano: ");
            fflush(stdin);
            scanf("%c",&continuar);
        }
    }
    if(puntaje2>puntaje1)
    {
        printf("\nFin del juego: El jugador 2 ha ganado con %i puntos contra %i puntos del jugador 1.\n\n",puntaje2,puntaje1);
    }
    else
    {
        printf("\nFin del juego: El jugador 1 ha ganado con %i puntos contra %i puntos del jugador 2.\n\n",puntaje1,puntaje2);
    }

    return 0;
}
Pila mazoRandom(int manos)
{
    Pila mazoAux;
    inicpila(&mazoAux);
    int i;
    time_t t;
    srand((unsigned) time(&t));
    for(i=0;i<4*manos;i++)
    {
        apilar(&mazoAux,1+rand()%4);
    }
    return mazoAux;
}
float sumarPila(Pila pila)
{
    float suma=0;
    while(!pilavacia(&pila))
    {
        suma=suma+tope(&pila);
        desapilar(&pila);
    }
    return suma;
}
