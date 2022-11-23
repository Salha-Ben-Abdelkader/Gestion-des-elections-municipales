#include <stdio.h>
#include <string.h>
#include"vote.h"


void main()
{
int x,y;
int id_liste;
liste_elec t[100];

x=nbv( "utilisateur.txt", 1);
printf("nombre de vote de la liste de l'id 1 est: %d \n",x);
x=nbv( "utilisateur.txt", 0);
printf("nombre de vote de la liste de l'id 2 est: %d \n",x);
x=nbv( "utilisateur.txt", 4);
printf("nombre de vote de la liste de l'id 4 est: %d \n",x);

y=L_ordre("liste_elec.txt", t, "utilisateur.txt");
printf("liste ordonnée avec succés \n %d \n",y);

}

