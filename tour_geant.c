/* tour_geant.c */

#include "tour_geant.h"
#include <stdio.h>
#include <stdlib.h>

int RechercheDistMinMark(int nbclients, double** Dist, int i, bool* mark)
{
  // Declaration
  int k;
  int indi_min;
  double dist_min;


  // Initialisation 
  indi_min = 1;
  while(mark[indi_min-1]==true) //on cherche un élément non marqué
    indi_min++;
  dist_min = Dist[i][indi_min];
  
  // Recherche du client non marqué et ayant le potentiel le plus petit
  for(k=1;k<=nbclients;k++)
  {
    if((Dist[i][k]!=0)&&(mark[k-1]==false)&&(dist_min>Dist[i][k])) //different d'un élément de diagonale
    {
      dist_min = Dist[i][k];
      indi_min = k;
    }
  }
  
  return indi_min;
}

int* TourGeant(int nbclients, double **Dist, int Ci)
{
  /* Declaration */
  int k;
  int min;
  int* chemin;
  bool mark[nbclients];
  
  /* Initialisation */
  chemin = (int*)malloc(nbclients*sizeof(int));
  chemin[0]=Ci; 
  min = Ci;
  for(k=0;k<nbclients;k++)
    mark[k] = false;
  mark[Ci-1]=true;
  
  // Tour géant
  for(k=1;k<nbclients;k++)
  {
    min = RechercheDistMinMark(nbclients,Dist,min,mark);
    mark[min-1]=true;
    chemin[k]=min;
  }

  return chemin;
}
