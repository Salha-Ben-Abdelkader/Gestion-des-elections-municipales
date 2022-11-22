#include <stdio.h>
#include <string.h>
#include"vote.h"
//#include "liste_elec.h"


void main()
{
int x,y;
int id_liste;
liste_elec l[100];

x=nbv( "vote.txt", 1);
printf("nombre de vote de la liste de l'id 1 est: %d \n",x);
x=nbv( "vote.txt", 0);
printf("nombre de vote de la liste de l'id 2 est: %d \n",x);
x=nbv( "vote.txt", 4);
printf("nombre de vote de la liste de l'id 4 est: %d \n",x);

y=L_ordre("vote.txt", l);
//y=L_ordre("vote.txt", l, "listeordonne.txt");
//y=L_ordre("vote.txt",l);
//return 0;

}

