#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
  int control=0;

  Pila dada,copia,aux2;
  inicpila(&dada);
  inicpila(&copia);
  inicpila(&aux2);


    leer (&dada);
    printf ("Ingrese un numero  \n");

while (!pilavacia(&dada))
{
    control=tope(&dada);
    apilar(&copia,control);
    apilar(&aux2,desapilar(&dada));
}
while (!pilavacia(&aux2))
{
    apilar(&dada, desapilar(&aux2));
}
puts("dada");
mostrar(&dada);
puts("copia");
mostrar(&copia);
while (!pilavacia(&dada)&&!pilavacia(&copia)&&tope(&dada)==tope(&copia))
{
    desapilar(&dada);
    desapilar(&copia);
}
if (pilavacia(&dada)&&pilavacia(&copia))
{
    printf("es capicua\n");
}
else
{
    printf("no es capicua\n");
}
puts("dada");
mostrar(&dada);
puts("copia");
mostrar(&copia);

return 0;

}
