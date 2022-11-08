#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED
#include <stdio.h>
typedef struct
{
  int id,ler,nbvote,degre_urgence;
  int type_reclamation;  
  char details_reclamation[20] ;
} rec ;

int ajouter(char *, rec);
int modifier( char *, int, rec );
int supprimer(char *, int );
rec chercher(char *, int);

#endif // POINT_H_INCLUDED
