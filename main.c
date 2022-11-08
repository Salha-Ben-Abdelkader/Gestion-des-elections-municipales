#include <stdio.h>
#include <string.h>
#include"liste_elec.h"

int main()
{
    liste_elec liste1= {1,012,022,011,541,29,06,2022,"gauche"},liste2= {2,032,144,785,756,22,10,2022,"droite"},liste3={3,032,144,785,756,22,10,2022,"droite"},liste4;
    int x=ajouter("liste_elec.txt", liste1);
    if(x==1)
        printf("\n ajout de liste avec succés");
    else printf("\n echec ajout");
    x=modifier("liste_elec.txt",2,liste2 );
    if(x==1)
        printf("\n Modification de liste avec succés");
    else printf("\n echec Modification");
    
    x=supprimer("liste_elec.txt",3 );
    if(x==1)
        printf("\n Suppression de liste avec succés");
    else printf("\n echec Suppression");
    
    liste4=chercher("liste_elec.txt",3 );
    if(liste4.id_liste==-1)
        printf("introuvable");
    return 0;
}
