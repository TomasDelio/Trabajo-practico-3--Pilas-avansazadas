#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int control=0;
    char controler='s';

    Pila dada,num,aux,basura;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&num);
    inicpila(&basura);

    apilar(&num,4); //EL 4 ES EL QUE HAY QUE REMOVER

    while (controler=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &controler);
  }


    while(!pilavacia(&dada) && control==0)
    {
        if (tope(&dada)==tope(&num))
        {
            control=1;
            apilar((&basura),desapilar(&dada));
        }
        else
        {
            apilar(&aux,desapilar(&dada));
        }
    }
    while (!pilavacia(&aux) && control==1)
    {
        apilar(&dada,desapilar(&aux));
    }
    if (!pilavacia(&basura))
    {
    printf ("el elemento buscado ha sido removido\n");
    }
    else
    {
        printf("el elemento buscado no esta en la pila");
    }

    puts ("dada");
    mostrar(&dada);
    puts("aux");
    mostrar(&aux);
    puts("basura");
    mostrar(&basura);
    puts ("num");
    mostrar(&num);
    return 0;
}
