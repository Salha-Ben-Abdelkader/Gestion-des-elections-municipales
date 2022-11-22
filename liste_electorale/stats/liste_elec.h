#ifndef LISTEELEC_H_INCLUDED
#define LISTEELEC_H_INCLUDED
#include <stdio.h>

typedef struct{
int jour,mois,annee;
}Date;

typedef struct{
    int id_liste;
    int id_tete;
    int id_e1,id_e2,id_e3;
    Date date_cr;
    char ori;
    int vote; 
} liste_elec;
/*
typedef struct{
char vb,vl;
int nb_vb, nb_vl;
}vote;
*/
int ajouter(char *filename, liste_elec );
int modifier( char *filename, int id, liste_elec );
int supprimer(char *filename, int id);
liste_elec chercher(char *filename, int id);
int nbrvote( char * filename , int id);
liste_elec liste_dec(char *filename, int id);
#endif // LISTEELEC_H_INCLUDED
