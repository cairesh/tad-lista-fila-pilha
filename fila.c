#include "fila.h"
fila cria_fila(){
   fila Fila;
   Fila.inicio=0;
   Fila.fim=0;
   Fila.tamanho=TAMANHO_FILA;
   return Fila;
}
int verifica(fila Fila)
{
   int contador;
   for (int i=0;i<TAMANHO_FILA;i++)
   {
      if (Fila.valores == NULL)
         contador++;
   }
   if (contador == 0)
      return 2;
      /*verifica se todas as posições do vetor */
   if (contador ==TAMANHO_FILA)
      return 3;
}
int enqueue(fila Fila, int elem)
{
   int teste = verifica(Fila);
   if (teste==2)
   {
      printf("Erro ao adicionar! A fila esta cheia\n");
      return 1;
   }
   Fila.valores[Fila.fim] = elem;
   Fila.fim = (Fila.fim+1)% TAMANHO_FILA;
}
int dequeue(fila Fila, int elem)
{
   int teste = verifica(Fila);
   if (teste==3)
   {
      printf ("Erro ao remover! A fila esta vazia\n");
      return 1;
   }
   Fila.valores[Fila.inicio]=NULL;
   Fila.inicio= (Fila.inicio+1)% TAMANHO_FILA;   
}