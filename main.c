/* main.c */

#include<stdio.h>
#include<stdlib.h>
#include "lecture.h"
#include "tour_geant.h"
#include "split.h"
#include "dijkstra.h"
#include "liste.h"
#include "solution.h"

int main()
{
  //Declaration
  int nbclients;
  int Q;
  double** Dist;
  int* quantite;
  int Ci; 
  int* tour_geant;
  struct TableSucc H;
  struct parcours PCC;
  struct liste* solution;
  int nbliste;
  int i;

  
  //Lecture
  Lecture(&nbclients,&Q,&Dist,&quantite);
  
  //Tour Geant
  scanf("%d",&Ci);
  tour_geant = TourGeant(nbclients, Dist, Ci);

  //Création du sous graphe auxiliaire
  H = Split(tour_geant, Q, nbclients, Dist, quantite);

  //Plus court chemin
  PCC = Dijkstra(H, nbclients);

  //Decodage
  solution = Decodage(PCC, &nbliste, tour_geant);

  //Calcul et affichage du cout
  printf("Cout total : %lf\n", calcul_cout(solution, nbliste, Dist));
  
 
  //Liberation de la memoire
  
  //Donnees
  free(quantite);
  for(i=0;i<=nbclients;i++)
    free(Dist[i]);
  free(Dist);
  
  //Tour Geant
  free(tour_geant);
  
  //Sous graphe auxiliaire
  free(H.Head);
  free(H.Succ);
  free(H.Poids);
  
  //PCC
  free(PCC.parcours);
  
  //Solution
  for(i=0;i<nbliste;i++)
    free_liste(&solution[i]);
  free(solution);
  
  return 0;
}
