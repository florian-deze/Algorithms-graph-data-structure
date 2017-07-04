/* split.h */

#if ! defined (SPLIT_H)
#define SPLIT_H 1


/* definition structure */
struct TableSucc{
  int* Head;
  int* Succ;
  double* Poids;
};


/* definition de NIL */

#define NILint (int*)0
#define NILdouble (double*)0



/* Prototypes */

extern void Init_TableSucc(struct TableSucc*, int);

extern struct TableSucc Split(int*, int, int, double**, int*);



#endif
