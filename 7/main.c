#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int controler=0;
    Pila aux,dada,num;
    char control='s';
    inicpila(&aux);
    inicpila(&dada);
    inicpila(&num);

    apilar(&num,5); //5 ES EL ELEMENTO QUE ESTA

    while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }

    while (!pilavacia(&dada)&& controler==0)
    {
        if (tope(&dada)==tope(&num))
        {
            controler=1;
        }
        else
        {
            apilar(&aux,desapilar(&dada));
        }
    }
    if (controler==1)
    {
        printf ("el numero buscado esta en la pila\n");
    }
    else
    {
        printf("el elemento buscado no esta en la pila\n");
    }
    puts ("dada");
    mostrar(&dada);
    puts("aux");
    mostrar(&aux);
    return 0;
}
