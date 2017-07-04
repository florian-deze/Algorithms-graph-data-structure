/* liste.h */

#if ! defined (liste_H)
#define liste_H 1


/* structure liste */

struct maillon {
  struct maillon* suivant;
  int valeur;
};

struct liste {
  struct maillon* tete;
  int nbelem;
};

#define NIL (struct maillon*)0



/* Prototypes */

extern void init_liste(struct liste*);

extern void ajout_element_liste(struct liste*, int);

extern int valeur_liste(struct liste, int);

extern void free_liste(struct liste*);



#endif
