#ifndef vote_H_INCLUDED
#define vote_H_INCLUDED
#include <stdio.h>
//#include "liste_elec.h"


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

int nbv(char *filename, int id_liste);
//int L_ordre(char *filename, liste_elec lo[], char *filename2)
int L_ordre(char *filename, liste_elec t[]);

#endif
