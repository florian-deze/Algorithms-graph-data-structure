/* liste.c */

#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

void init_liste(struct liste* L)
{
  L->tete = NIL;
  L->nbelem = 0;
}

void ajout_element_liste(struct liste* L, int i)
{
  //Declaration
  struct maillon* M, *N;
  
  //création du maillon
  M = (struct maillon*)malloc(sizeof(struct maillon));
  M->valeur = i;
  M->suivant = NIL;
    
  if(L->nbelem==0)
  {
    L->tete=M;
    L->nbelem = 1;
  }
  else
  {   
    N = L->tete;
    while(N->suivant!=NIL)
      N = N->suivant;
    N->suivant = M;
    L->nbelem += 1;
  }
}


int valeur_liste(struct liste L, int indice)
{
  //Declaration
  struct maillon* M;
  int i;

  //Initialisation
  M = L.tete;
  
  for(i=1;i<indice;i++)
    M = M->suivant;
  return(M->valeur);
}


void free_liste(struct liste* L)
{
  //Declaration
  struct maillon* M, *N;
  int i;

  //Initialisation
  M = NIL;
  N = L->tete;
  
  for(i=1;i<=L->nbelem;i++)
  {
    M = N;
    N = N->suivant;
    free(M);
  }
}
