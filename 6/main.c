#include <stdio.h>
#include <stdlib.h>
#include   "pila.h"
int main()
{
    Pila dada,menor,ordenada,aux;
    char control='s';
    inicpila(&dada);
    inicpila(&menor);
    inicpila(&ordenada);
    inicpila(&aux);

    while (control=='s')
  {
    leer (&dada);
    printf ("desea cargar otro numero? Presione S: \n");
    fflush (stdin);
    scanf ("%c", &control);
  }

    while (!pilavacia(&dada))
        {
            apilar(&menor,desapilar(&dada));
            while (!pilavacia(&dada))
            {
                if (tope(&dada)>tope(&menor))
                {
                    apilar(&aux,desapilar(&dada));
                }
                else
                {
                    apilar(&aux,desapilar(&menor));
                    apilar(&menor,desapilar(&dada));
                }
            }
            apilar(&ordenada, desapilar(&menor));
            while (!pilavacia (&aux))
            {
                apilar(&dada, desapilar(&aux));
            }
    }
    puts("dada");
    mostrar (&dada);
    puts("menor");
    mostrar(&menor);
    puts("ordenada");
    mostrar(&ordenada);
    puts("aux");
    mostrar (&aux);

  return 0;
}
