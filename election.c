#include "election.h"
#include <stdio.h>
int ajouter_election (char * filename , GestionElection E )
{
	FILE * f=fopen(filename, "a");
	if(f!=NULL)
	{
	  fprintf(f,"%d %d %d %d %d %d %s %s %s\n",E.ID_election,E.NH,E.NC,E.date_election.jour,
                      E.date_election.mois,E.date_election.annee,E.municipalite,E.DV,E.Gouv);

          fclose(f);
          return 1;
        }
else return 0;
}
int modifier_election (char * filename, int id, GestionElection nouv)
{
GestionElection E ;
FILE * f=fopen(filename, "r");
FILE * f2=fopen ("nouv.txt", "w");
int tr;
if(f!=NULL && f2!=NULL)
{
	while (fscanf(f,"%d %d %d %d %d %d %s %s	 					%s\n",&E.ID_election,&E.NH,&E.NC,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,E.municipalite,E.DV,E.Gouv)!=EOF)
       {
	if (E.ID_election==id)
	{
		fprintf(f2,"%d %d %d %d %d %d %s %s %s\n",nouv.ID_election,nouv.NH,nouv.NC,nouv.date_election.jour,E.date_election.mois,E.date_election.annee,nouv.municipalite,nouv.DV,nouv.Gouv);
		tr=1;		
         }
	else
		fprintf(f2,"%d %d %d %d %d %d %s %s	 					%s\n",E.ID_election,E.NH,E.NC,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.municipalite,E.DV,E.Gouv);
}
fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
}
int supprimer_election(char * filename, int id)
{
    int tr=0;
    GestionElection E;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL || f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %s %s %s\n",&E.ID_election,&E.NH,&E.NC,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,E.municipalite,E.DV,E.Gouv)!=EOF)
        {
            if(E.ID_election== id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d  %s %s %s\n",E.ID_election,E.NH,E.NC,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.municipalite,E.DV,E.Gouv);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
GestionElection chercher(char * filename, int id)
{
    GestionElection E;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %s %s %s\n",&E.ID_election,&E.NH,&E.NC,
                      &E.date_election.jour,&E.date_election.mois,&E.date_election.annee,E.municipalite,E.DV,E.Gouv)!=EOF)
        {
            if(E.ID_election== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        E.ID_election=-1;
    return E;
}
