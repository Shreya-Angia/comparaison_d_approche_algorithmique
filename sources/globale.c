#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globale.h"
#include "affichage.h"
#include "globalePraticien.h"
#include "globaleSecretaire.h"
#include "fichier.h"




void globalePraticien(Specialite **tabSpe, int nbSpe)
{
    Praticien p;
    int choixP;
    //int save;

    p = identifierPraticien(tabSpe, nbSpe);
    if (p.nbPatients == 0 && p.maxPatient == 0 && p.tPatientele == NULL)
        exit(1);


    menuPraticien();
    scanf("%d", &choixP);

    while(choixP != 0)
    {
        switch(choixP)
        {
            case 1:
                appeler1Patient(&p);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            case 2:
                affichageTriLex(p);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            case 3:
                affichageTriVisite(p);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            case 4:
                globalePDepuis1CertainTps(p);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            case 5: 
                faireDeLaPlace(&p);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            default:
                printf("Choix invalide. Resaisir : ");
                scanf("%d", &choixP);
                break;
        }
        menuPraticien();
        scanf("%d", &choixP);
        printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    }

    // faire sauvegarde 
    FILE *fSave = fopen("sources/Centre.txt", "w");
    if (fSave != NULL) {
        int save = sauvegarde(fSave, tabSpe, nbSpe);
        fclose(fSave);
        if (save == 1)
            printf("Données sauvegardées avec succès !\n");
        else
            printf("Erreur lors de la sauvegarde des données.\n");
    }
   
}


void globaleSecretaire(Specialite **tabSpe, int *nbSpe)
{
    int choixS;

    menuSecretaire();
    scanf("%d", &choixS);
    scanf("%*c");

    while(choixS != 0)
    {
        switch(choixS)
        {
            case 1:
                globaleAjouterPraticien(tabSpe, nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;

            case 2: 
                supprimer1Praticien(tabSpe, nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;

            case 3: 
                afficherSpecialites(tabSpe, *nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;
            
            case 4:
                globalePraticien1Spe(tabSpe, *nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;

            case 5:
                afficherCentre(tabSpe, *nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;

            case 6: 
                enregistrer1Patient(tabSpe, *nbSpe);
                printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
                break;

            default:
                printf("Choix invalide. Resaisir : ");
                scanf("%d", &choixS);
                scanf("%*c");
                break;
        }
        menuSecretaire();
        scanf("%d", &choixS);
        scanf("%*c");
        printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    }

    // faire sauvegarde 
    FILE *fSave = fopen("sources/Centre.txt", "w");
    if (fSave != NULL) {
        int save = sauvegarde(fSave, tabSpe, *nbSpe);
        fclose(fSave);
        if (save == 1)
            printf("Données sauvegardées avec succès !\n");
        else
            printf("Erreur lors de la sauvegarde des données.\n");
    }
}


void fGlobale(void)
{
    // Déclaration de toutes les variables nécessaires 
    int max_spe = 10;
    int choix;
    Specialite *tabSpe[max_spe];
    int nbSpe = 0;
    FILE *flot;
    int ok;
    int tlog = 0;
    int tphy = 10;
    int i;

    // Initialiseation de tabSpe à NULL
    for (i = 0; i < max_spe; i++) {
        tabSpe[i] = NULL;
    }

    // Chargement des données 
    flot = fopen("sources/Centre.txt", "r");
    if(flot == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier \n");
        exit(1);
    }

    ok = chargement(flot, tabSpe, &nbSpe, &max_spe, &tlog, &tphy);
    if (ok != 1)
    {
        printf("Erreur lors du chargement des données \n");
        exit(1);
    }

    fclose(flot);

    choix = -1;
    while(choix != 0)
    {
        menuSelection();
        scanf("%d", &choix);
        scanf("%*c");

        while(choix != 0 && choix != 1 && choix != 2)
        {
            printf("Choix invalide. Resaisir (0: Quitter, 1: Secrétaire, 2: Praticien) : ");
            scanf("%d", &choix);
            scanf("%*c");
        }

        if (choix == 1)
            globaleSecretaire(tabSpe, &nbSpe);
        else if (choix == 2)
            globalePraticien(tabSpe, nbSpe);
    }

    // Sauvegarde finale avant quitter
    flot = fopen("sources/Centre.txt", "w");
    if (flot != NULL) {
        int save = sauvegarde(flot, tabSpe, nbSpe);
        fclose(flot);
        if (save == 1)
            printf("Données sauvegardées avec succès !\n");
        else
            printf("Erreur lors de la sauvegarde des données.\n");
    }
  
}




