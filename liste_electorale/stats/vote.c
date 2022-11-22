#include <stdlib.h>
#include <stdio.h>
#include "vote.h"
//#include "liste_elec.h"




int nbv(char *filename, int id)
{ int nv=0;
liste_elec l;
FILE *f1=fopen("liste_elec.txt","r");
FILE *f2=fopen("vote.txt","w");

if (f1!=NULL && f2!=NULL){
 while(fscanf(f1,"%d %d %d %d %d %d %d %d %s %d",&l.id_liste,&l.id_tete,
&l.id_e1,&l.id_e2,&l.id_e3,&l.date_cr.jour,
&l.date_cr.mois,&l.date_cr.annee,&l.ori,&l.vote)!=EOF)
{	if(l.id_liste==id)
	{
		if(l.vote==1)
			{nv++;
l.vote=nv;}

	
	fprintf(f2,"\n %d %d \n", l.id_liste,l.vote);
	}
	 else
	{
		fprintf(f2,"\n %d %d \n", l.id_liste,l.vote);
	}
}
fclose(f1);
fclose(f2);
return nv;
}
}

int L_ordre(char *filename, liste_elec t[])
	{
int i=0;
//nombre de liste qu'on va utliser comme taille du tableau
	int nliste=0;
	liste_elec lect;
liste_elec l;
	FILE* f = fopen(filename, "r");
	if(f!=NULL)
{
	while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d",&l.id_liste,&l.id_tete,
&l.id_e1,&l.id_e2,&l.id_e3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,
&l.ori,&l.vote)!=EOF)
{
nliste++;

}

//reservation du memoire pour le tableau

t = malloc(sizeof(liste_elec) * nliste);

//conversion du fichier en tableau de type liste_elec
f = fopen(filename, "r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d",&l.id_liste,&l.id_tete,
&l.id_e1,&l.id_e2,&l.id_e3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,
&l.ori,&l.vote)!=EOF)
{
t[i] = lect;
i++;
}
}

//tri 
liste_elec tmp;
int j=0,k=1,max;
liste_elec t[nliste];

for (i=0;i<nliste-1;i++)
	{ max=i;
		for (j=i+1;j<nliste;j++)
		{
			if (t[j].vote>t[max].vote)
				{max=j;}
		

tmp=t[i];

t[i]=t[max];

t[max]=tmp;
	}
}

FILE * f2=fopen("lordonne.txt", "w");

		for (j=i+1;j<nliste;j++)
		{
			fprintf( f2,"%d %d \n",t[j].id_liste,t[j].vote);
}
fclose(f);	
fclose(f2);
	return nliste;
}
}

/*
int L_ordre(char *filename, liste_elec lo[], char *filename2)
{

liste_elec listeordonne;
int i=0,n=0,max=0;
FILE *f=fopen("vote.txt","r");
FILE *f2=fopen("listeordonne.txt","w");
 if(f!=NULL && f2!=NULL  )
	{
		while(fscanf(f,"\n %d %d \n",&id_liste,nv)!=EOF)
{
for (i=0;i<n-1;i++)
{
   max=i ;

   for (j=i+1;j<n;j++)
   {
if (lo[j].nv>lo[max].nv)
        max=j;
}
liste_elec listeo;
listeo=lo[i];
lo[i]=lo[max];
lo[max]=listeo;
}
}
     for(i=0;i<n;i++)
    {
        listeordonne=lo[i];

     fprintf(f2,"%d %d\n",listeordonne.id_liste, listeordonne.nv);

    }
    
}
fclose(f);
fclose(f2);
}*/
