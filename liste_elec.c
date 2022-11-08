#include "liste_elec.h"

int ajouter(char * filename, liste_elec l )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d  %d %d %d %s \n",l.id_liste,l.id_tete,l.id1,l.id2,l.id3,l.date_cr.jour,l.date_cr.mois,l.date_cr.annee,l.ori);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier( char * filename, int id, liste_elec nv )
{
    int tr=0;
    liste_elec l;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d  %d %d %d %s \n",&l.id_liste,&l.id_tete,&l.id1,&l.id2,&l.id3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,l.ori)!=EOF)
        {
            if(l.id_liste== id)
            {
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",nv.id_liste,nv.id_tete,nv.id1,nv.id2,nv.id3,nv.date_cr.jour,nv.date_cr.mois,nv.date_cr.annee,nv.ori);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",l.id_liste,l.id_tete,l.id1,l.id2,l.id3,l.date_cr.jour,l.date_cr.mois,l.date_cr.annee,l.ori);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    liste_elec l;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d  %d %d %d %s \n",&l.id_liste,&l.id_tete,&l.id1,&l.id2,&l.id3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,l.ori)!=EOF)
        {
            if(l.id_liste == id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",l.id_liste,l.id_tete,l.id1,l.id2,l.id3,l.date_cr.jour,l.date_cr.mois,l.date_cr.annee,l.ori);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nv.txt", filename);
    return tr;
}
liste_elec chercher(char * filename, int id)
{
    liste_elec l;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d %d %d %d %s \n",&l.id_liste,&l.id_tete,&l.id1,&l.id2,&l.id3,&l.date_cr.jour,&l.date_cr.mois,&l.date_cr.annee,l.ori)!=EOF)
        {
            if(l.id_liste== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        l.id_liste=-1;
    return l;

}
