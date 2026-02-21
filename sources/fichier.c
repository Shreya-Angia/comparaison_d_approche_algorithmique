#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "structures.h"
#include "fichier.h"
#include "file.h"
#include "liste.h"
#include "tableau.h"



int chargement(FILE *flot, Specialite *tabSpe[], int *nbSpe, int *maxSpe, int *tlog, int *tphy){

    Praticien tempM[50];

    int nbPraticien, spe, pra, pat;
    int nbPatientsToRead;

    if (flot == NULL || tabSpe == NULL || nbSpe == NULL || tlog == NULL || tphy == NULL) {
        return -1;
    }

    int totalSpe = 0;
    fscanf(flot, "%d", &totalSpe) ;

    for (spe = 0; spe < totalSpe; spe++) {
        listePraticiens Lpraticiens = listeNouv();
        char BDDate[6];

        Specialite *spePtr = malloc(sizeof(Specialite));
        if (spePtr == NULL) {
            return -1;
        }

        fscanf(flot, "%49s", spePtr->nom);     
        fscanf(flot, "%d", &nbPraticien);
        
        for (pra = 0; pra < nbPraticien; pra++) {

            fscanf(flot, "%49s", tempM[pra].nom);    
            fscanf(flot, "%d", &tempM[pra].maxPatient);
            fscanf(flot, "%d", &nbPatientsToRead) ;
        
            if (tempM[pra].maxPatient > 0)
                tempM[pra].tPatientele = malloc(tempM[pra].maxPatient * sizeof(Patient*));
            else
                tempM[pra].tPatientele = NULL;
            tempM[pra].fileAttente = filenouv();
            tempM[pra].nbPatients = 0;

            for (pat = 0; pat < nbPatientsToRead; pat++) {
                Patient *patient = malloc(sizeof(Patient));
                if (patient == NULL) return -1;

                fscanf(flot, "%49s", patient->nom);
                fscanf(flot, "%49s", patient->prenom);
                fscanf(flot, "%d", &patient->numSecu);
                fscanf(flot, "%5s", BDDate);

                if (strcmp(BDDate, "VRAI") == 0) {
                    patient->IsDate = VRAI;
                    patient->derniereVisite = malloc(sizeof(Date));
                    if (patient->derniereVisite == NULL) {
                        return -1;
                    }
                    fscanf(flot, "%d", &patient->derniereVisite->jour);
                    fscanf(flot, "%d", &patient->derniereVisite->mois);
                    fscanf(flot, "%d", &patient->derniereVisite->annee);
                } else {
                    patient->IsDate = FAUX;
                    patient->derniereVisite = NULL;
                }
                ajouterPatient(&tempM[pra], patient);

            }
            Lpraticiens = inserer(Lpraticiens, tempM[pra]);
            tempM[pra].fileAttente = ajouterPatientF(tempM[pra].fileAttente, NULL);
        }

        spePtr->praticien = NULL;
        spePtr->praticien = malloc(sizeof(listePraticiens));
        if (spePtr->praticien == NULL) {
            free(spePtr);
            return -1;
        }
        *(spePtr->praticien) = Lpraticiens;

        tabSpe = ajouterSpecialite(spePtr, spePtr->praticien, tabSpe, nbSpe, maxSpe);
    }
    *nbSpe = totalSpe;
    return 1;
}


int sauvegarde(FILE *flot, Specialite **tabSpe, int nbSpe){
    int spe, pat;
    int nbPraticien;
    char* nomSpe;

    if (flot == NULL || tabSpe == NULL) {
        return -1;
    }
    
    fprintf(flot, "%d\n", nbSpe);
    for (spe = 0; spe < nbSpe; spe++) {
        nomSpe=tabSpe[spe]->nom;
        fprintf(flot, "%s\n", nomSpe);

        listePraticiens lp;
        lp=listeNouv();
        lp= *(tabSpe[spe]->praticien);
        nbPraticien = longueur(lp);

        fprintf(flot, "%d\n",nbPraticien);
        
        // Parcourir la liste chaînée des praticiens
        Maillon *current = lp;
        while (current != NULL) {
            Praticien *pra = &(current->praticien);
            
            // Écrire les informations du praticien
            fprintf(flot, "%s\n", pra->nom);
            fprintf(flot, "%d\n", pra->maxPatient);
            fprintf(flot, "%d\n", pra->nbPatients);
            
            // Écrire les patients du praticien
            for (pat = 0; pat < pra->nbPatients; pat++) {
                fprintf(flot, "%s\n", pra->tPatientele[pat]->nom);
                fprintf(flot, "%s\n", pra->tPatientele[pat]->prenom);
                fprintf(flot, "%d\n", pra->tPatientele[pat]->numSecu);
                
                if (pra->tPatientele[pat]->IsDate == VRAI) {
                    fprintf(flot, "VRAI\n");
                    fprintf(flot, "%d\n", pra->tPatientele[pat]->derniereVisite->jour);
                    fprintf(flot, "%d\n", pra->tPatientele[pat]->derniereVisite->mois);
                    fprintf(flot, "%d\n", pra->tPatientele[pat]->derniereVisite->annee);
                } else {
                    fprintf(flot, "FAUX\n");
                }
            }
            
            current = current->suiv;
        }
    }

    return 1;
}










