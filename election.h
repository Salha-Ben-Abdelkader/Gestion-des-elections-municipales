#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
typedef struct{
int jour,mois,annee;
}Date;


typedef struct{
int ID_election,NH,NC;
Date date_election;
char municipalite[24],DV[2],Gouv[26];
}GestionElection;
int ajouter_election(char * filename, GestionElection E );
int modifier_election ( char *filename, int id, GestionElection nouv );
int supprimer_election(char * filename, int id );
GestionElection chercher(char * filename, int id);

#endif 
