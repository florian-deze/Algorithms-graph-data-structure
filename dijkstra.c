/* dijkstra.c */

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#define MAX (double)500000


int Choisir(int nbclients, bool* mark, double* potentiel)
{
  // Declaration
  int i;
  int indice_depart, indice_courant;
  double potentiel_courant;

  //Initialisation
  indice_depart = 0;
  //Recherche d'un element non marque
  while((indice_depart<=nbclients)&&(mark[indice_depart]))
    indice_depart++;
  potentiel_courant = potentiel[indice_depart];
  indice_courant = indice_depart;

  //Conception
  for(i=indice_depart+1;i<=nbclients;i++)
  {
    //Recherche de l'element de plus petit potentiel et non marque
    if((mark[i]==false)&&(potentiel_courant>potentiel[i]))
    {
      potentiel_courant = potentiel[i];
      indice_courant = i;
    }
  }
  
  if(indice_courant == nbclients+1) //deja tous marqués
    return -1;
  else
    return indice_courant;
}
     

struct parcours Dijkstra(struct TableSucc H, int nbclients)
{
  /* Declaration */
  int x, y;
  int k;
  bool mark[nbclients+1];
  double potentiel[nbclients+1];
  int pere[nbclients+1];
  bool fini;
  struct parcours PCC;
  


  /* Initialisation */
  PCC.parcours = (int*)malloc((nbclients+1)*sizeof(int));
  PCC.parcours[0] = nbclients;
  PCC.nbchemin = 1;
  
  for(k=0;k<=nbclients;k++)
  {
    mark[k] = false;
    potentiel[k] = MAX;
    pere[k] = 0;
  }
  // On commence toujours à 0
  potentiel[0] = 0;
  pere[0] = 0;
  fini = false;
  
  
  do {
    fini = true;
    x = Choisir(nbclients, mark, potentiel);

    if(x!=-1) //Successeur trouvé
    {
      fini = false;
      mark[x] = true;

      if(x!=nbclients) //x n'a pas de fils
	{ 
        for(k=H.Head[x];k<H.Head[x+1];k++) //tous les successeurs de x
        { 
          y = H.Succ[k]; //y correspond aux successeurs de x

	  //Recherche du potentiel minimum
          if(potentiel[y] > potentiel[x]+H.Poids[k]) 
          { 
            potentiel[y] = potentiel[x] + H.Poids[k];
            pere[y] = x;
	  }
        }
      }
    }
  }
  while(!fini);
  
  // On détermine le chemin
  while(PCC.parcours[PCC.nbchemin-1]!=0)
  {
    PCC.parcours[PCC.nbchemin] = pere[PCC.parcours[PCC.nbchemin-1]];
    PCC.nbchemin += 1;
  }
  //On réduit le tableau
  PCC.parcours = (int*)realloc(PCC.parcours, PCC.nbchemin*sizeof(int));

  return PCC;
}
