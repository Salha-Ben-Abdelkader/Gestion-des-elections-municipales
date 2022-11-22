typedef struct
{ char login[20];
char  mot_de_passecx[20];
}connexion;


typedef struct 
{int jour,mois,annee;}date;


typedef struct
{char nom[20],prenom[20],role[20],genre[20],mot_de_passe[20];
int CIN,numero_BV,vote;
date date_de_naissance;
}utilisateur;

