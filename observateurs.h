#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
typedef struct
{
 char nom[20];
 char prenom[20];
 char nationalite[20];
 char genre[20];
 char profession[20];
 int id, numBV;
} observateur;
int ajouter(char * filename, observateur obs );
int modifier( char *, int, observateur);
int supprimer(char *, int );
observateur chercher(char *, int);

#endif 
