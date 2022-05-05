#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
  char control='s';
  int cuenta=0;
  float contador=0;
    Pila pila,aux,dada;
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&dada);

  while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }
  while (!pilavacia (&dada))
  {
    apilar (&aux, desapilar(&dada));
    cuenta++;
  }
    while (!pilavacia(&aux))
  {
    apilar (&dada, desapilar (&aux));
  }
  printf ("la cantidad de elementos que contiene dada es %d\n", cuenta);

  return 0;
}
