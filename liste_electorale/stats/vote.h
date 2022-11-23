#ifndef vote_H_INCLUDED
#define vote_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

typedef struct
{ char login[20];
char  mot_de_passecx[20];
}connexion;


typedef struct 
{int jour,mois,annee;}date;


typedef struct
{char nom[20],prenom[20],role[20],genre[20],mot_de_passe[20];
int CIN,numero_BV,vote;
date date_de_naissance;
}utilisateur;

int nbv(char *filename, int idliste);
int L_ordre(char *fichierListeElectorale, liste_elec t[], char * fichierusers);


#endif
