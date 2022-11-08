#include"fonctions.h"
//fonction ajouter
void ajout(utilisateur u)

{
FILE* f;
f=fopen("home/chohdi/projetc/utilisateur.txt","w");
fprintf(f,"%s %s %s %s %s %d %d %d/%d/%d \n",u.nom,u.prenom,u.role,u.genre,u.mot_de_passe,u.CIN,u.numero_BV,u.date_de_naissance.jour,u.date_de_naissance.mois,u.date_de_naissance.annee);
fclose(f);
}



//fonction connexion
int  connecte(char login[],char mot_de_passe[])
{
FILE* f;
int test=0,cin,nbv,j,m,a;
char n[20],p[20],r[20],g[20],md[20];
f=fopen("home/chohdi/projetc/utilisateur.txt","r");
while((fscanf(f,"%s %s %s %s %s %d %d %d/%d/%d",n,p,r,g,md,&cin,&nbv,&j,&m,&a)!=EOF)&&(test==0))
{
fscanf(f,"%s %s %s %s %s %d %d %d/%d/%d",n,p,r,g,md,&cin,&nbv,&j,&m,&a);
if (login==p)
	{if (mot_de_passe==md)
		test=1;
	}
}
fclose(f);
return test;
}



//fonction supprimer
void supprimer(utilisateur u)
{
FILE* f;
FILE* g;
int test=0,cin,nbv,j,m,a;
char n[20],p[20],r[20],ge[20],md[20];
f=fopen("home/chohdi/projetc/utilisateur.txt","r");
g=fopen("home/chohdi/projetc/utilisateur.txt","w");
while((fscanf(f,"%s %s %s %s %s %d %d %d/%d/ %d",n,p,r,ge,md,&cin,&nbv,&j,&m,&a)!=EOF)&&(test==0))
{
fscanf(f,"%s %s %s %s %s %d %d %d/%d/ %d",n,p,r,ge,md,&cin,&nbv,&j,&m,&a);
if (u.CIN!=cin)
	fprintf(g,"%s %s %s %s %s %d %d %d/%d/%d",n,p,r,ge,md,cin,nbv,j,m,a);

}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("utilisateur1.txt","utilisateur.txt");
}


//fonction modifier
void modif(utilisateur u1 , utilisateur u2)
{
supprimer(u1);
ajout(u2);
}




//fonction recherche 
int recherche (utilisateur u)
{
int test=-1,cin,nbv,j,m,a;
char n[20],p[20],r[20],g[20],md[20];
FILE* f;
while((fscanf(f,"%s %s %s %s %s %d %d %d/%d/%d",n,p,r,g,md,&cin,&nbv,&j,&m,&a)!=EOF)&&(test==0))
{
fscanf(f,"%s %s %s %s %s %d %d %d/%d/%d",n,p,r,g,md,&cin,&nbv,&j,&m,&a);
if (cin==u.CIN)
	{
          test=1;
	}
}
return test ;
}
