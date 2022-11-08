#include <stdio.h>
#include <string.h>
#include"election.h"

int main()
{
	GestionElection E1={10208670,50000,10,6,11,2022,"Mourouj","14","Benarous"},E2={10208669,5000,6,7,11,2020,"zahra","12","Benarous"};
    
    	 int x=ajouter_election("election.txt", E1);
	int y=ajouter_election("election.txt", E2);
    
    if(x==1)
        printf("\n ajout de point avec succés");
    else printf("\n echec ajout"); 
        
     int x=modifier_election ("election.txt",10208669,E2 );

    if(x==1)
        printf("\n Modification de election avec succés");
    else printf("\n echec Modification");
   
     int x=supprimer_election("election.txt",10208669 );
    if(x==1)
        printf("\n Suppression de election avec succés");
    else printf("\n echec Suppression");
   
   E3=chercher("election.txt",10208669 );
    if(E3.id==-1)
        printf("introuvable");
    return 0;

}

