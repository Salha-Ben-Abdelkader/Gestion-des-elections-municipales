#ifndef LISTEELEC_H_INCLUDED
#define LISTEELEC_H_INCLUDED
#include <stdio.h>

typedef struct{
int jour,mois,annee;
}Date;

typedef struct{
    int id_liste;
    int id_tete;
    int id1,id2,id3; 
    Date date_cr;
    char ori[20];

} liste_elec;

typedef struct{
char vb,vl;
int nb_vb, nb_vl;
}vote;

int ajouter(char *filename, liste_elec );
int modifier( char *filename, int id, liste_elec );
int supprimer(char *filename, int id);
liste_elec chercher(char *filename, int id);

#endif // LISTEELEC_H_INCLUDED
