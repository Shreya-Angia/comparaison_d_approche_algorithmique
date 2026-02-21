#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globaleSecretaire.h"
#include "tableau.h"
#include "file.h"
#include "liste.h"
#include "affichage.h"



void enregistrer1Patient(Specialite ** tspe, int nbSpe)
{
    char nom[50];
    char spe[50];
    char med[50];
    char ref;
    int iSpe;
    Patient *existe = NULL;

    // Saisie des données

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║           ENREGISTREMENT D'UN PATIENT        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Nom du patient (MAJUSCULE): ");
    fgets(nom,50,stdin);
    nom[strlen(nom)-1] = '\0';

    printf("Spécialité demandée : ");
    fgets(spe,50,stdin);
    spe[strlen(spe)-1] = '\0';

    /* Recherche de la spécialité */
    iSpe = rechercherSpe(tspe, spe, nbSpe);
    while(iSpe < 0)
    {
        printf("La spécialité n'existe pas. Veuillez resaisir : ");
        fgets(spe,50,stdin);
        spe[strlen(spe)-1] = '\0';
        iSpe = rechercherSpe(tspe, spe, nbSpe);
    }

    printf("Le patient a-t-il un praticien référent ? (o / n) : ");
    scanf(" %c", &ref);
    scanf("%*c");

    while(ref != 'o' && ref != 'n')
    {
        printf("Saisie incorrecte. Tapez 'o' ou 'n' : ");
        scanf(" %c", &ref);
        scanf("%*c");
    }

    // CAS 1 : Patient avec praticien référent

    if(ref == 'o')
    {
        printf("\nNom du praticien référent (MAJUSCULE): ");
        fgets(med,50,stdin);
        med[strlen(med)-1] = '\0';

        if (tspe[iSpe]->praticien == NULL)
        {
            printf("Aucun praticien dans cette spécialité.\n");
            return;
        }

        listePraticiens lp = rechercherPraticien(*(tspe[iSpe]->praticien), med);

        while (lp == NULL)
        {
            printf("Praticien introuvable. Resaisir : ");
            fgets(med,50,stdin);
            med[strlen(med)-1] = '\0';
            lp = rechercherPraticien(*(tspe[iSpe]->praticien), med);
        }

        printf("\nPraticien trouvé : Dr %s\n", med);

        existe = trouverPatient(lp->praticien.tPatientele, nom, lp->praticien.nbPatients);

        if(existe != NULL)
        {
            printf("Patient trouvé dans la patientèle.\n");
            lp->praticien.fileAttente = ajouterPatientF(lp->praticien.fileAttente, existe);

            printf("Patient ajouté dans la file d'attente du Dr %s.\n", med);
        }
        else
        {
            printf("Le patient n'existe pas dans la patientèle du praticien référent.\n");
        }


    // CAS 2 : Patient sans praticien référent
    }
    else
    {
        printf("\nRecherche d'un praticien disponible...\n");

        Maillon *cour = *(tspe[iSpe]->praticien);

        while (cour != NULL)
        {
            if (cour->praticien.nbPatients < cour->praticien.maxPatient)
            {
                printf("Le Dr %s peut prendre ce patient.\n", cour->praticien.nom);

                /* Si le patient n'existe pas encore, on le crée */
                if (existe == NULL)
                {
                    Patient *nouveau = malloc(sizeof(Patient));
                    if (nouveau == NULL)
                    {
                        fprintf(stderr, "Erreur d'allocation mémoire pour nouveau patient\n");
                        return;
                    }
                    // Saisie des informations du patient
                    strcpy(nouveau->nom, nom);
                    printf("Prénom du patient : ");
                    fgets(nouveau->prenom,50,stdin);
                    nouveau->prenom[strlen(nouveau->prenom)-1] = '\0';
                    printf("Numéro de sécurité sociale (6 chiffres): ");
                    scanf("%d", &nouveau->numSecu);
                    scanf("%*c"); 
                    while (nouveau->numSecu <= 0 || nouveau->numSecu > 999999)
                    {
                        printf("Numéro de sécurité sociale invalide. Resaisir : ");
                        scanf("%d", &nouveau->numSecu);
                        scanf("%*c");
                    } 
                    nouveau->IsDate = FAUX;
                    nouveau->derniereVisite = NULL;
                    existe = nouveau;
                
                }

                ajouterPatient(&cour->praticien, existe);
                cour->praticien.fileAttente = ajouterPatientF(cour->praticien.fileAttente, existe);

                printf("Patient ajouté au Dr %s et placé en file d'attente.\n",
                       cour->praticien.nom);
                printf("\n╔══════════════════════════════════════════════╗\n");
                printf("║        FIN DE L'ENREGISTREMENT PATIENT       ║\n");
                printf("╚══════════════════════════════════════════════╝\n\n");
                return;
            }
            cour = cour->suiv;
        }

        printf("Aucun praticien n'a de place dans cette spécialité.\n");
    }

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║        FIN DE L'ENREGISTREMENT PATIENT       ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");
}



void globaleAjouterPraticien(Specialite **tabSpe, int *nbSpe)
{
    Praticien p;
    char spe[50];
    int iSpe;
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               AJOUT D'UN PRATICIEN           ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");
    printf("Entrez le nom de la spécialité du praticien à ajouter : ");
    fgets(spe,50,stdin);
    spe[strlen(spe)-1]='\0';
    iSpe = rechercherSpe(tabSpe, spe, *nbSpe);
    if(iSpe < 0)
    {
        printf("La spécialité n'existe pas. Création d'une nouvelle spécialité.\n");
        Specialite *s = malloc(sizeof(Specialite));
        if(s == NULL)
        {
            fprintf(stderr, "Erreur d'allocation mémoire pour nouvelle spécialité\n");
            return;
        }

        strcpy(s->nom, spe);
        s->praticien = malloc(sizeof(listePraticiens));
        if(s->praticien == NULL)
        {
            free(s);
            fprintf(stderr, "Erreur d'allocation mémoire pour la liste de praticiens\n");
            return;
        }
        *(s->praticien) = NULL;

        // Ajout de la nouvelle spécialité au tableau en gardant l'ordre lexicographique
        int pos = 0;
        while (pos < *nbSpe && strcmp(tabSpe[pos]->nom, s->nom) < 0)
            pos++;
        int j;
        for (j = *nbSpe; j > pos; j--)
            tabSpe[j] = tabSpe[j - 1];
        tabSpe[pos] = s;
        (*nbSpe)++;
        iSpe = pos;
    }
    printf("Entrez le nom du praticien à ajouter (MAJUSCULE): ");
    fgets(p.nom,30,stdin);
    p.nom[strlen(p.nom)-1]='\0';
    p.fileAttente = filenouv();
    p.nbPatients = 0;
    printf("Entrez le nombre maximum de patients pour ce praticien : ");
    scanf("%d", &p.maxPatient);
    scanf("%*c");
    while (p.maxPatient<0)
    {
        printf("Le nombre maximum de patients doit être positif. Veuillez resaisir : ");
        scanf("%d", &p.maxPatient);
        scanf("%*c");
    }

    *(tabSpe[iSpe]->praticien) = inserer(*(tabSpe[iSpe]->praticien), p);

    printf("Praticien %s ajouté avec succès à la spécialité %s.\n", p.nom, tabSpe[iSpe]->nom);

    printf("\n╔═════════════════════════════════════════════╗\n");
    printf("║         FIN DE L'AJOUT PRATICIEN            ║\n");
    printf("╚═════════════════════════════════════════════╝\n\n");
}



void supprimer1Praticien(Specialite ** tspe, int *nbSpe)
{
    char nomP[30];
    char spe[30];
    int iSpe;
    listePraticiens lp;

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          SUPPRESSION D'UN PRATICIEN         ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Nom du praticien à supprimer (MAJUSCULE): ");
    fgets(nomP,30,stdin);
    nomP[strlen(nomP)-1]='\0';

    printf("Spécialité du praticien : ");
    fgets(spe,30,stdin);
    spe[strlen(spe)-1]='\0';

    iSpe = rechercherSpe(tspe, spe, *nbSpe);
    while(iSpe < 0)
    {
        printf("La spécialité n'existe pas. Veuillez resaisir : ");
        fgets(spe,30,stdin);
        spe[strlen(spe)-1]='\0';
        iSpe = rechercherSpe(tspe, spe, *nbSpe);
    }
    // lp est une liste de pointeur qui pointe sur des praticiens on la récupère
    lp = *(tspe[iSpe]->praticien);
    lp = rechercherPraticien(lp, nomP);
    if (lp == NULL)
    {
        printf("Praticien non trouvé dans cette spécialité.\n");
        return;
    }
    // on supprime le praticien de la liste
    lp = supprimer(lp, nomP);
    // si la liste est vide on supprime la spécialité
    if (lp == NULL)
    {
        free(tspe[iSpe]->praticien);
        free(tspe[iSpe]);
        // on décale les spécialités dans le tableau
        for (int j = iSpe; j < *nbSpe - 1; j++)
        {
            tspe[j] = tspe[j + 1];
        }
        tspe[*nbSpe - 1] = NULL;
        (*nbSpe)--;
        printf("La spécialité %s a été supprimée car elle ne contient plus de praticiens.\n", spe);
        printf("\n╔══════════════════════════════════════════════╗\n");
        printf("║        FIN DE LA SUPPRESSION PRATICIEN       ║\n");
        printf("╚══════════════════════════════════════════════╝\n\n");
        return;
    }
    // on met à jour la liste des praticiens de la spécialité
    *(tspe[iSpe]->praticien) = lp;


    printf("Praticien supprimé avec succès.\n");

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║        FIN DE LA SUPPRESSION PRATICIEN       ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");
}



void globalePraticien1Spe(Specialite **tabSpe, int nbSpe)
{ 
    char spe[30];

    printf("Donnez le nom de la spécialité : ");
    fgets(spe,30,stdin);
    spe[strlen(spe)-1]='\0';

    int iSpe = rechercherSpe(tabSpe, spe, nbSpe);
    while(iSpe < 0)
    {
        printf("La spécialité n'existe pas. Veuillez resaisir : ");
        fgets(spe,30,stdin);
        spe[strlen(spe)-1]='\0';
        iSpe = rechercherSpe(tabSpe, spe, nbSpe);
    }

    afficherPraticiensSpecialite(tabSpe[iSpe]);

}




