/* solution.c */

#include "solution.h"
#include <stdlib.h>
#include <stdio.h>


/* Fonction de décodage */

struct liste* Decodage(struct parcours PCC, int *nbliste, int* chemin)
{
  //Declaration
  struct liste* solution;
  int i, j;

  //Initialisation
  *nbliste = PCC.nbchemin-1;
  solution = (struct liste*)malloc(*nbliste*sizeof(struct liste));
  for(i=0;i<*nbliste;i++)
    init_liste(&(solution[i]));
  
  for(i=0;i<*nbliste;i++)
  {
    for(j=PCC.parcours[PCC.nbchemin-i-1]+1;j<=PCC.parcours[PCC.nbchemin-i-2];j++)
      ajout_element_liste(&(solution[i]), chemin[j-1]);
  }
  
  return solution;
}

double calcul_cout(struct liste* solution, int nbliste, double** Dist)
{
  //Declaration
  int i,j;
  double cout_total;
  int val1,val2;

  //Initilisation
  cout_total = 0;
  
  for(i=0;i<nbliste;i++)
  {
    //Recherche du premier element de liste
    val2 = valeur_liste(solution[i], 1);
    //Distance du depot au premier client
    cout_total += Dist[0][val2];
    //Distance de client à client
    for(j=2;j<=solution[i].nbelem;j++)
    {
      val1 = val2;
      val2 = valeur_liste(solution[i], j);
      cout_total += Dist[val1][val2];
    }
    //Distance du dernier client au depot
    cout_total += Dist[val2][0];
  }
  
  return cout_total;
} 
