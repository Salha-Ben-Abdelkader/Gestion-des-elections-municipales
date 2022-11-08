#include "observateurs.h"

int ajouter(char * filename, observateur obs )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s %s %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,obs.numBV);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, observateur obs )
{
    int tr=0;
   
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
 while(fscanf(f,"%d %s %s %s %s %s %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,&obs.numBV)!=EOF)
        {
            if(obs.id== id)
            {
                fprintf(f2,"%d %s %s %s %s %s %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,obs.numBV);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %s %s %s %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,obs.numBV);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int supprimer(char * filename, int id)
{
    int tr=0;
    observateur obs;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
while(fscanf(f,"%d %s %s %s %s %s %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,&obs.numBV)!=EOF)
        {
            if(obs.id== id)
                tr=1;
            else
      fprintf(f2,"%d %s %s %s %s %s %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,obs.numBV);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

observateur chercher(char * filename, int id)
{
    observateur obs;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
while(fscanf(f,"%d %s %s %s %s %s %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,obs.genre,obs.profession,&obs.numBV)!=EOF)
        {
            if(obs.id== id)
               { tr=1;}
        }
    }
    fclose(f);
    if(tr==0)
      obs.id=-1;
    return obs;
}


