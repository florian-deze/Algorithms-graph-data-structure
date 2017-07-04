/* dijkstra.h */

#if ! defined (DIJKSTRA_H)
#define DIJKSTRA_H 1


/* Inclusion des bibliotheques */

#include "split.h"
#include <stdbool.h>



/* Definition structure */

struct parcours {
  int* parcours;
  int nbchemin;
};



/* Prototypes */

extern int Choisir(int, bool*, double*);

extern struct parcours Dijkstra(struct TableSucc, int);



#endif
