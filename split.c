/* split.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "split.h"


void Init_TableSucc(struct TableSucc* H,int nbclients)
{
  //Declaration
  int nbArcMax;

  //Initilisation
  nbArcMax = nbclients*(nbclients-1)/2;

  //Allocation des tableaux
  H->Head = (int*)malloc((nbclients+1)*sizeof(int));
  H->Succ = (int*)malloc(nbArcMax*sizeof(int));
  H->Poids = (double*)malloc(nbArcMax*sizeof(double));

  H->Head[0]=0;
}

struct TableSucc Split(int* chemin, int Q, int nbclients, double** Dist, int* quantite)
{
  //Declaration
  double cost;
  int load;
  int i,j;
  int cpt;
  struct TableSucc H;
  
  
  //Initialisation
  cpt=0;
  Init_TableSucc(&H, nbclients);
  
  //Conception
  for(i=1;i<=nbclients;i++)
  { 
    j=i;
    load=0;
    H.Head[i-1]=cpt;
    do {
      load=load+quantite[chemin[j-1]-1];

      //calcul du cout
      if(i==j) {
	cost=2*Dist[0][chemin[j-1]];
      }
      else
	cost=cost-Dist[chemin[j-2]][0]+Dist[chemin[j-2]][chemin[j-1]]+Dist[0][chemin[j-1]];

      if(load<=Q)
      { 
	// Créatin d'un nouvel arc
	H.Succ[cpt]=j;
	H.Poids[cpt]=cost;
	cpt++;
      }	
      j++;
    } while((j<=nbclients)&&(load<Q)); // Inverser en C car boucle TantQue au lieu de Jusqu'a
  }
  //le dernier est un puit
  H.Head[nbclients]=cpt;

  //On réduit les tableaux
  H.Succ = (int*)realloc(H.Succ, cpt*sizeof(int));
  H.Poids = (double*)realloc(H.Poids, cpt*sizeof(double));
  
  return H;
}
