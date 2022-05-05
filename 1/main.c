#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
  int suma=0;
  char control='s';
  Pila dada,aux;
  inicpila (&dada);
  inicpila (&aux);

  while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }

  while (!pilavacia(&dada))
  {
    suma=suma+tope(&dada);
    apilar(&aux,desapilar(&dada));
  }
}
