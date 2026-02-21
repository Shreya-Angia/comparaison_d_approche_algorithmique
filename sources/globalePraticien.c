#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "globalePraticien.h"
#include "affichage.h" 
#include "file.h"
#include "liste.h"
#include "tableau.h"



void appeler1Patient(Praticien *p)
{
	Patient *pat;
    Date d;

	if (estVide(p->fileAttente)){
		printf("Aucun patient en attente. \n");
		return;
	}

	pat = tete(p->fileAttente);
	printf("Le prochain patient est : %s %s (N° de sécu : %d)\n", pat->prenom, pat->nom, pat->numSecu);
    pat->IsDate = VRAI;
    printf("Entrez la date de la visite (jj mm aaaa) : ");
    scanf("%*c");
    scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
    while(d.jour < 1 || d.jour > 31 || d.mois <1 || d.mois > 12 || d.annee < 1800)
    {
        printf("Date invalide. Ressaisir (jj mm aaaa) : ");
        scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
    }
    pat->derniereVisite = malloc(sizeof(Date));
    pat->derniereVisite->jour = d.jour;
    pat->derniereVisite->mois = d.mois;
    pat->derniereVisite->annee = d.annee;
	p->fileAttente = supprimerPatientF(p->fileAttente);
}


void globalePDepuis1CertainTps(Praticien p)
{
    Date d; 
    int nb;
    Patient *tabRech[p.nbPatients];
    printf("Entrez la date (jj mm aaaa) : ");
    scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
    while(d.jour < 1 || d.jour > 31 || d.mois < 1 || d.mois > 12 || d.annee < 1900)
    {
        printf("Date invalide. Resaisir (jj mm aaaa) : ");
        scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
    }
    if (p.nbPatients > 0) 
    {
        nb = rechercheDepuisCertainTps(d, p, tabRech);
        afficherPDepuis1CertainTps(d, p, tabRech, nb);
    } else 
    {
        nb = 0;
        afficherPDepuis1CertainTps(d, p, NULL, 0);
    }

}


Praticien identifierPraticien(Specialite **tabSpe, int nbSpe)
{
    char nomP[30];
    int iSpe;

    if (nbSpe <= 0 || tabSpe == NULL) {
        printf("Aucune donnée chargée. Connexion echouée.\n");
        exit(1);
    }

        printf("Entrez votre nom (MAJUSCULE) : ");
        scanf("%s", nomP);

    // Recherche du praticien dans toutes les spécialités    
    for(iSpe=0; iSpe < nbSpe; iSpe++)
    {
        if (tabSpe[iSpe] != NULL && tabSpe[iSpe]->praticien != NULL) {
            listePraticiens lp = rechercherPraticien(*(tabSpe[iSpe]->praticien), nomP);
            if(lp != NULL)
            {
                printf("Bienvenue Dr %s, vous êtes connecté. \n", nomP);
                return lp->praticien;
            }
        }
    }
    printf("Praticien non trouvé. Connexion echouée. \n");
    exit(1);
}


Praticien supprimer1Patient(Praticien p)
{
    int numSecu,trouve;
    if (p.nbPatients == 0)
    {
        printf("Le praticien n'a pas de patients à supprimer.\n");
        return p;
    }
    printf("Entrez le numéro de sécurité sociale du patient à supprimer : ");
    scanf("%d", &numSecu);
    while(numSecu <= 0)
    {
        printf("Numéro de sécurité sociale invalide. Resaisir : ");
        scanf("%d", &numSecu);
    }
    trouve = supprimerPatient(&p, numSecu);
    if (trouve == -1){
        printf("Practicien non valide.\n");
    }
    else if (trouve == -2){
        printf("Patient non trouvé.\n");
    }
    else {
        printf("Patient supprimé avec succès.\n");
    }
    return p;
}


void faireDeLaPlace(Praticien *p)
{
    int choix;
    Patient *tabRech[p->nbPatients];
    int nb = 0;
    Date d; 

    printf("\n1) Supprimer un patient précis \n");
    printf("2) Supprimer patients depuis une certaine date \n");
    printf("----------------------------------------------\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    while (choix != 1 && choix != 2)
    {
        printf("Choix invalide. Ressaisir : ");
        scanf("%d", &choix);
    }
    if (choix == 1)
    {
        *p = supprimer1Patient(*p);
    }
    else if (choix == 2)
    {
        printf("Entrez la date (jj mm aaaa) : ");
        scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
        while(d.jour < 1 || d.jour > 31 || d.mois < 1 || d.mois > 12 || d.annee < 1900)
        {
            printf("Date invalide. Ressaisir (jj mm aaaa) : ");
            scanf("%d %d %d", &d.jour, &d.mois, &d.annee);
        }
        nb = rechercheDepuisCertainTps(d, *p, tabRech);
        for(int i = 0; i < nb; i++)
        {
            supprimerPatient(p, tabRech[i]->numSecu);
        }
        printf("Patients supprimés avec succès.\n"); 
    }
}



