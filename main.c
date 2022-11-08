#include <stdio.h>
#include <string.h>
#include"observateurs.h"

int main()
{int id;
   observateur obs;

printf("Id :");
scanf("%d",&obs.id);
printf("Nom :");
scanf("%s",obs.nom);
printf("prenom :");
scanf("%s",obs.prenom);
printf("nationalite :");
scanf("%s",obs.nationalite );
printf("profession:");
scanf("%s",obs.profession);
printf("genre :");
scanf("%s",obs.genre);
printf("Num BV :");
scanf("%d",&obs.numBV);
    int x;
x=ajouter("users.txt", obs);

    
    if(x==1)
        printf("\najout d'observateur %s avec succes\n", obs.nom);
   else  printf("\nechec ajout");
       

 printf("\nDonner id de l'observateur a modifier\n");
    scanf("%d",&obs.id);
printf("Nouveau Nom :");
scanf("%s",obs.nom);
printf("Nouveau prenom :");
scanf("%s",obs.prenom);
printf("Nouveau nationalite :");
scanf("%s",obs.nationalite );
printf("Nouveau profession:");
scanf("%s",obs.profession);
printf("Nouveau genre :");
scanf("%s",obs.genre);
printf("Nouveau Num BV :");
scanf("%d",&obs.numBV);


x=modifier("users.txt",obs.id,obs);


    if(x==1)
        printf("\nModification d'observateur dont id =%d avec succes\n",obs.id);
    else printf("\nechec Modification\n");

 printf("Donner id de l'observateur a supprimer\n");
    scanf("%d",&obs.id);
x=supprimer("users.txt",obs.id);
    if(x==1)
        printf("\nSuppression d'observateur de  id= %d avec succes\n",obs.id);
    else printf("\nechec Suppression\n");

printf("Donner id de l'observateur a chercher\n");
    scanf("%d",&id);
 obs=chercher("users.txt",id );
    if(obs.id==-1)
        printf("Observateur de id=%d n'existe pas",id);
    else {printf("Observateur de id=%d existe :\n",id);
         printf("id=%d nom=%s prenom=%s proffession=%s nationalite=%s genre=%s numBV=%d\n",obs.id,obs.nom,obs.prenom,obs.profession,obs.nationalite,obs.genre,obs.numBV); }

   
    return 0;
}
