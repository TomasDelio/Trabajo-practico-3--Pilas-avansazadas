#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    char control='s';
    int cuenta=0,suma=0;
    float contador=0,promedio=0;

    Pila pila,aux,dada,menor;

    inicpila(&pila);
    inicpila(&aux);
    inicpila(&dada);
    inicpila (&menor);

  while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }

    promedio=(float)suma/(float)cuenta;
    printf ("Y el promedio de la pila es %.2 f \n", promedio);

    if (!pilavacia (&dada))
    {
  apilar (&menor, desapilar (&dada));
    }
    while (!pilavacia (&dada))
    {
    if (tope (&menor) > tope (&dada))
    {
    apilar (&aux,desapilar(&menor));
    apilar (&menor,desapilar(&dada));
    }
    else
    {
    apilar (&aux, desapilar (&dada));
    }

    return 0;
}
}
