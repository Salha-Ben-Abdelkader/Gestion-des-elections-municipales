#include "reclamation.h"
int ajouter(char * reclamation, rec r ) {
FILE * f=fopen(reclamation, "a");
 if(f!=NULL)
    {
    fprintf(f,"%d %d %d %d %d %s\n",r.id,r.type_reclamation,r.ler,r.nbvote,r.degre_urgence,r.details_reclamation);
fclose(f);
return 1 ;
     }
else return 0 ;
     }
int modifier (char *reclamation, int id,rec nouv )
{
int tr=0;
rec r ;
FILE * f=fopen(reclamation, "r");
FILE * f2=fopen("nouv.txt", "w");
if(f!=NULL && f2!=NULL)
    {
while(fscanf(f,"%d %d %d %d %d %s\n",&r.id,&r.type_reclamation,&r.ler,&r.nbvote,&r.degre_urgence,r.details_reclamation)!=EOF)
{
if (r.id==id)
{
fprintf(f2,"%d %d %d %d %d %s\n",nouv.id,nouv.type_reclamation,nouv.ler,nouv.nbvote,nouv.degre_urgence,nouv.details_reclamation);
tr=1 ;
}
else
fprintf(f2,"%d %d %d %d %d %s\n",r.id,r.type_reclamation,r.ler,r.nbvote,r.degre_urgence,r.details_reclamation);
   }
}
    fclose(f);
    fclose(f2);
remove(reclamation);
rename ("nouv.txt",reclamation);
return tr ;
}
int supprimer(char * reclamation, int id)
{
int tr=0;
rec r ;
FILE * f=fopen(reclamation, "r");
FILE * f2=fopen("nouv.txt", "w");
if(f!=NULL && f2!=NULL)
    {
while(fscanf(f,"%d %d %d %d %d %s\n",&r.id,&r.type_reclamation,&r.ler,&r.nbvote,&r.degre_urgence,r.details_reclamation)!=EOF)
{
if (r.id==id)
{
tr=1 ;
}
else
fprintf(f2,"%d %d %d %d %d %s\n",r.id,r.type_reclamation,r.ler,r.nbvote,r.degre_urgence,r.details_reclamation);
   }
}
    fclose(f);
    fclose(f2);
remove(reclamation);
rename ("nouv.txt",reclamation);
return tr ;
}
