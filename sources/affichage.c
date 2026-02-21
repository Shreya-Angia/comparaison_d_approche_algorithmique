#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "affichage.h"
#include "tableau.h"
#include "liste.h"


void menuSelection()
{
    printf("\n============================\n");
    printf("       MENU DE SELECTION    \n");
    printf("============================\n");
    printf("0) Quitter\n");
    printf("1) Secretaire\n");
    printf("2) Praticien\n");
    printf("----------------------------\n");
    printf("Votre choix : ");
}



void menuSecretaire()
{
    printf("\n==============================================\n");
    printf("              MENU SECRETAIRE                  \n");
    printf("==============================================\n");
    printf(" 0) Quitter\n");
    printf(" 1) Ajouter un praticien\n");
    printf(" 2) Supprimer un praticien\n");
    printf(" 3) Afficher les specialites\n");
    printf(" 4) Praticiens d'une specialité ayant de la place\n");
    printf(" 5) Afficher tout le centre\n");
    printf(" 6) Enregistrer un patient (file d'attente)\n");
    printf("----------------------------------------------\n");
    printf("Votre choix : ");
}




void menuPraticien()
{
    printf("\n===============================================\n");
    printf("               MENU PRATICIEN                  \n");
    printf("===============================================\n");
    printf(" 0) Quitter\n");
    printf(" 1) Appeler un patient\n");
    printf(" 2) Patientèle (ordre lexicographique)\n"); 
    printf(" 3) Patientèle (par visite)\n");
    printf(" 4) Patients absents depuis un delai donné\n");
    printf(" 5) Faire de la place\n");
    printf("-----------------------------------------------\n");
    printf("Votre choix : ");
}


void affichageTriLex(Praticien praticien)
{
    Patient *p;
    Date *d;

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("  DOSSIERS PATIENTS — ORDRE LEXICOGRAPHIQUE   \n");
    printf("  Praticien : Dr.%s\n", praticien.nom);
    printf("╚══════════════════════════════════════════════╝\n\n");

    triLexicographiquePatients(praticien.tPatientele, praticien.nbPatients);

    for (int i = 0; i < praticien.nbPatients; i++)
    {
        p = praticien.tPatientele[i];
        d = p->derniereVisite;

        printf("┌──────────────────────────────────────────────┐\n");
        printf("  Patient %d\n", i + 1);
        printf("  Nom            : %s\n", p->nom);
        printf("  Prénom         : %s\n", p->prenom);
        printf("  Numéro Sécu    : %d\n", p->numSecu);
        if (p->IsDate == FAUX) {
            printf("  Dernière visite: Aucune visite enregistrée\n");
        } else {
            printf("  Dernière visite: %02d/%02d/%04d\n",
                d->jour, d->mois, d->annee);}
        printf("└──────────────────────────────────────────────┘\n\n");
    }
}


void affichageTriVisite(Praticien praticien)
{
    Patient *p;
    Date *d;

    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("  DOSSIERS PATIENTS — TRI PAR VISITE     \n");
    printf("  (De la plus récente à la plus vieille)  \n");
    printf("  Praticien : Dr.%s\n", praticien.nom);
    printf("╚══════════════════════════════════════════════╝\n\n");

    quickSort(praticien.tPatientele, praticien.nbPatients);

    for (int i = 0; i < praticien.nbPatients; i++)
    {
        p = praticien.tPatientele[i];
        d = p->derniereVisite;

        printf("┌──────────────────────────────────────────────┐\n");
        printf("  Patient %d\n", i + 1);
        printf("  Nom            : %s\n", p->nom);
        printf("  Prénom         : %s\n", p->prenom);
        printf("  Numéro Sécu    : %d\n", p->numSecu);
        if (p->IsDate == FAUX || d == NULL) {
            printf("  Dernière visite: Aucune visite enregistrée\n");
        } else {
            printf("  Dernière visite: %02d/%02d/%04d\n",
                   d->jour, d->mois, d->annee);
        }
        printf("└──────────────────────────────────────────────┘\n\n");
    }
}


void afficherPDepuis1CertainTps(Date d, Praticien praticien, Patient **tabPat, int nbPatients)
{
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║   PATIENTS ABSENTS DEPUIS LE %02d/%02d/%04d      ║\n",
           d.jour, d.mois, d.annee);
    printf("╚══════════════════════════════════════════════╝\n");

    printf("\nListe des patients concernés :\n");
    printf("───────────────────────────────────────────────\n");

    if (nbPatients == 0 || tabPat == NULL) 
    {
        printf("Aucun patient absent depuis le %02d/%02d/%04d\n", d.jour, d.mois, d.annee);
    } 
    else 
    {
        for (int i = 0; i < nbPatients; i++) 
        {
            Patient *pat = tabPat[i];
            if (pat == NULL) continue;
            // Protection : si aucune date enregistrée, ne pas déréférencer pat->derniereVisite
            if (pat->IsDate == FAUX || pat->derniereVisite == NULL) {
                printf("• %s %s  (dernière visite : Aucune visite enregistrée)\n", pat->prenom, pat->nom);
            } else {
                printf("• %s %s  (dernière visite : %02d/%02d/%04d)\n",
                       pat->prenom, pat->nom,
                       pat->derniereVisite->jour, pat->derniereVisite->mois, pat->derniereVisite->annee);
            }
        }
    }
    printf("───────────────────────────────────────────────\n\n");
}


void afficherUnPraticien(Praticien praticien)
{
    printf("\n┌──────────────────────────────────────────────┐\n");
    printf("  Praticien : Dr.%s\n", praticien.nom);
    printf("  Nombre de Patients : %d\n", praticien.nbPatients);
    printf("  Nombre max de Patients : %d\n", praticien.maxPatient);
    printf("└──────────────────────────────────────────────┘\n");
}


void afficherSpecialites(Specialite** tabSpecialites, int nbSpecialites)
{
    printf("\n╔══════════════════════════════════════╗\n");
    printf("         LISTE DES SPECIALITES         \n");
    printf("╚══════════════════════════════════════╝\n\n");

    for (int i = 0; i < nbSpecialites; i++)
    {
        printf("• %s\n", tabSpecialites[i]->nom);
    }

    printf("\n");
}


void afficherCentre(Specialite** tabSpecialites, int nbSpecialites)
{
    listePraticiens lp;
    printf("\n╔══════════════════════════════════════╗\n");
    printf("           CENTRE MEDICAL             \n");
    printf("╚══════════════════════════════════════╝\n\n");

    for (int i = 0; i < nbSpecialites; i++)
    {
        printf("┌──────────────────────────────────────────────┐\n");
        printf("  Spécialité : %s\n", tabSpecialites[i]->nom);
        printf("└──────────────────────────────────────────────┘\n");

        /* test si y'a pas de pointeur ou alors si la liste est vide*/
        if (tabSpecialites[i]->praticien == NULL || *(tabSpecialites[i]->praticien) == NULL)
        {
            printf("  Aucun praticien dans cette spécialité.\n\n");
        }
        else
        {
            lp = *(tabSpecialites[i]->praticien);
            while (lp != NULL)
            {
                afficherUnPraticien(lp->praticien);
                lp = lp->suiv;
            }
            printf("\n");
        }
    }
}


void afficherPraticiensSpecialite(Specialite* specialite)
{
    Praticien tabPPlace[50];
    int nbP = recherchePraticienPlace(*(specialite->praticien), tabPPlace);

    printf("\n╔══════════════════════════════════════╗\n");
    printf("      PRATICIENS DE LA SPECIALITE      \n");
    printf("           %s\n", specialite->nom);
    printf("      AYANT DE LA PLACE DISPONIBLE     \n");
    printf("╚══════════════════════════════════════╝\n\n"); 


    if (specialite->praticien == NULL || *(specialite->praticien) == NULL)
    {
        printf("Aucun praticien dans cette spécialité.\n\n");
    }
    else
    {
       for (int i = 0; i < nbP; i++)
       {
            afficherUnPraticien(tabPPlace[i]);
       }
        printf("\n");
    }
}
