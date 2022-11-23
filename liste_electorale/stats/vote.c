#include <stdlib.h>
#include <stdio.h>
#include "vote.h"

int nbv(char *filename, int idliste)
{ int nv=0;
liste_elec l;
utilisateur u2;
FILE *f1=fopen(filename,"r");

if (f1!=NULL)
{
 	while(fscanf(f1,"%s %s %s %s %s %d %d %d %d/%d/ %d",
	u2.nom,u2.prenom,u2.role,u2.genre,u2.mot_de_passe,&u2.CIN,
	&u2.numero_BV,&u2.vote,&u2.date_de_naissance.jour,&u2.date_de_naissance.mois,
	&u2.date_de_naissance.annee)!=EOF)
	{
	if(u2.vote==idliste)

		nv+=1;

	}
}
fclose(f1);
return nv;
}

int L_ordre(char *fichierListeElectorale, liste_elec t[], char * fichierusers)
{
int nbliste=0;
	liste_elec l;
	FILE* f = fopen(fichierListeElectorale, "r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d",&l.id_liste,&l.id_tete,
&l.id_e1,&l.id_e2,&l.id_e3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,
&l.ori,&l.vote)!=EOF)
		{
			nbliste +=1;
		}
	}
	fclose(f);
	
	t = malloc(sizeof(liste_elec) * nbliste);
	
	int k=0;
	f = fopen(fichierListeElectorale, "r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d",&l.id_liste,&l.id_tete,
&l.id_e1,&l.id_e2,&l.id_e3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,
&l.ori,&l.vote)!=EOF)
		{
			t[k] = l; k+=1;
		}
	}
	fclose(f);
	
	liste_elec tampon;
	int i, j, min;
	int n = nbliste;
	for (i=0;i<n-1;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
		{
			int curr_v = nbv(fichierusers, t[j].vote);
			int min_v = nbv(fichierusers, t[min].vote);
			if (curr_v>min_v)
				min=j;
		}
		tampon=t[i];
		t[i]=t[min];
		t[min]=tampon;
	}

	int p = 0;
	FILE * f2=fopen("listeordonne.txt", "w");
	
	for(p=0; p<nbliste; p++)
	{
		fprintf( f2,"%d %d %d %d %d %d %d %d %s \n", t[p].id_liste,t[p].id_tete,t[p].id_e1,t[p].id_e2,t[p].id_e3,t[p].date_cr.jour,t[p].date_cr.mois,t[p].date_cr.annee,&t[p].ori);
	}
	fclose(f2);
	return nbliste;
}

