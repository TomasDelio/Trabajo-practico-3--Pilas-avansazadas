#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

  Pila intro, dada,aux;
  char control='s';
  inicpila(&intro);
  inicpila(&dada);
  inicpila(&aux);

  while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }


  while (!pilavacia(&dada) && !pilavacia(&intro))
  {
    while (tope(&dada)<tope(&intro))
    {
      apilar(&aux, desapilar(&dada));
    }
    apilar(&dada, desapilar(&intro));
    while(!pilavacia(&aux))
    {
      apilar(&dada,desapilar(&aux));
    }
  }
  puts("dada");
  mostrar(&dada);
  puts("intro");
  mostrar(&intro);
  puts("aux");
  mostrar(&aux);

    return 0;
}
