#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableau.h"
#include "affichage.h"



int ajouterPatient(Praticien* praticien, Patient* pat)
{
    if (praticien == NULL || pat == NULL) 
        return -1;

    if (praticien->nbPatients == praticien->maxPatient)
    {
        Patient** nvTab = realloc(praticien->tPatientele, (praticien->maxPatient + 5) * sizeof(Patient*));
        if (nvTab == NULL)
            return -2;
        praticien->tPatientele = nvTab;
        praticien->maxPatient += 5;
    }
    // Ajout du patient à la fin du tableau
    praticien->tPatientele[praticien->nbPatients] = pat;
    praticien->nbPatients += 1;
    return 1;
}



int supprimerPatient(Praticien* praticien, int numSecu)
{
    int i, j;
    int rech = -1; // valeur par défaut : non trouvé 
    
    if (praticien == NULL)  
        return -1;

    // Recherche du patient à supprimer
    for (i = 0; i < praticien->nbPatients; i++) 
    {
        if (praticien->tPatientele[i]->numSecu == numSecu) 
        {
            rech = i;
            break;    
        }
    }

    if (rech == -1) 
        return -2;
  
    // Décalage des patients
    for (j = rech; j < praticien->nbPatients - 1; j++) 
        praticien->tPatientele[j] = praticien->tPatientele[j + 1];
    
    praticien->nbPatients -= 1;

    return 1; 
}



Specialite **ajouterSpecialite(Specialite *s, listePraticiens *p, Specialite **tab, int *nb, int *max)
{
    int idx;
    int i = 0;
    if (s == NULL || tab == NULL || nb == NULL || max == NULL)
        return tab;

    if (*nb == *max) {
        printf("Impossible d'ajouter la spécialité %s : capacité maximale atteinte.\n", s->nom);
        return tab;
    }
    // Si la spécialité existe déjà, on met à jour
    idx = rechercherSpe(tab, s->nom, *nb);
    if (idx != -1) 
    {
        if (p != NULL) 
            tab[idx]->praticien = p;
        return tab;
    }

    /* Trouver la position d'insertion  */
    while (i < *nb && strcmp(tab[i]->nom, s->nom) < 0) {
        i++;
    }

    // Décaler les éléments 
    for (int j = *nb; j > i; j--) {
        tab[j] = tab[j - 1];
    }

    // Insertion
    tab[i] = s;
    tab[i]->praticien = p;
    (*nb)++;

    return tab;
}


Specialite **supprimerSpecialte(Specialite *e, listePraticiens *p, Specialite **tab, int *nb)
{
    if (e == NULL || tab == NULL || *nb == 0) 
        return tab;

    int i, j;
    int rech = -1; // valeur par défaut : non trouvé 

    // Recherche de la spécialité à supprimer
    for (i = 0; i < *nb; i++) 
    {
        if (strcmp(tab[i]->nom, e->nom) == 0) 
        {
            rech = i;
            break;    
        }
    }

    if (rech == -1) 
        return tab; 

    // Décalage des spécialités
    for (j = rech; j < *nb - 1; j++) 
        tab[j] = tab[j + 1];
    
    (*nb)--;

    return tab;  
}




void copier(Patient **tab, int i, int j, Patient ** R)
{
    int k =0;
    while (i < j)
    {
        R[k] = tab[i];
        i++;
        k++;
    }
}


void fusion(Patient ** R, int nbR, Patient ** S, int nbS, Patient ** tab)
{
    int i=0, j=0, k=0;
    while(i < nbR && j < nbS)
    {
        if(strcmp(R[i]->nom, S[j]->nom) <= 0)
        {
            tab[k] = R[i];
            i++;
            k++;
        }
        else
        {
            tab[k] = S[j];
            j++;
            k++;
        }
    }
    while(i < nbR)
    {
        tab[k] = R[i];
        i++;
        k++;
    }

    while(j < nbS)
    {
        tab[k] = S[j];
        j++;
        k++;
    }

}


void triLexicographiquePatients(Patient **tab, int nb)
{
    Patient **R, **S;
    if(nb == 1)
        return;
    R = (Patient**) malloc(nb/2 * sizeof(Patient*));
    S = (Patient**) malloc((nb - nb/2) * sizeof(Patient*));
    if(R == NULL || S == NULL)
    { 
        printf("Erreur d'allocation mémoire \n");
        exit(1);
    }
    copier(tab, 0, nb/2, R);
    copier(tab, nb/2, nb, S);
    triLexicographiquePatients(R, nb/2);
    triLexicographiquePatients(S, nb - nb/2);
    fusion(R,nb/2,S,nb-nb/2,tab);
    free(R);
    free(S);

} 


int compareDate(Date *d1, Date *d2)
{   
    if (d1 == NULL) return 1; // d1 est plus grand
    if (d2 == NULL) return -1; // d1 est plus petit

    if (d1->annee > d2->annee) return -1; // d1 est plus petit 
    if (d1->annee < d2->annee) return 1; // d1 est plus grand 

    if (d1->mois > d2->mois) return -1;
    if (d1->mois < d2->mois) return 1;

    if (d1->jour > d2->jour) return -1;
    if (d1->jour < d2->jour) return 1;

    return 0; // d1 est d2 sont identiques
}


void quickSort(Patient **tab, int nb)
{
    if (nb <= 1) return;

    int i = 0;
    int j = nb - 2;

    Patient *pivot = tab[nb - 1];

    while (i <= j)
    {        
        
        // avancer i tant que tab[i] est PLUS RÉCENT que pivot
        while (i < nb - 1 &&
               compareDate(tab[i]->derniereVisite, pivot->derniereVisite) == -1)
        {
            i++;
        }

        // reculer j tant que tab[j] est PLUS VIEUX que pivot
        while (j >= 0 &&
               compareDate(tab[j]->derniereVisite, pivot->derniereVisite) == 1)
        {
            j--;
        }

        if (i < j)
        {
            Patient *tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }

    /* placer le pivot à sa bonne position */
    Patient *tmp = tab[i];
    tab[i] = tab[nb - 1];
    tab[nb - 1] = tmp;

    quickSort(tab, i);
    quickSort(tab + i + 1, nb - i - 1);
}




int rechercherSpe(Specialite **tSpe, char* nom, int nbSpe)
{
    int deb = 0;
    int fin = nbSpe -1;
    int m;
    while(deb <= fin)
    {
        m = (deb + fin) / 2;
        if(strcmp(tSpe[m]->nom, nom) == 0)
            return m; // specialité trouvée
        else if(strcmp(tSpe[m]->nom, nom) < 0)
            deb = m + 1;
        else
            fin = m - 1;
    }
    return -1; // specialité non trouvée
}


Patient * trouverPatient(Patient ** tPat, char*nom, int nbPat)
{
    int i= 0;
    for (i = 0; i < nbPat; i++)
    {
        if (strcmp(tPat[i]->nom, nom) == 0)
            return tPat[i];
    }
    return NULL;  
}


int rechercheDepuisCertainTps(Date d, Praticien p, Patient **tabRech)
{
    int cpt = 0;
    int i;
    if (tabRech == NULL)
        return 0;

    for (i = 0; i < p.nbPatients; i++) 
    {
        Patient *pat = p.tPatientele[i];
        if (pat != NULL && pat->IsDate == VRAI && pat->derniereVisite != NULL) 
        {
            if (compareDate(&d, pat->derniereVisite) == -1) 
            { 
                tabRech[i] = pat;
                cpt++;
            }
        }
    }
    return cpt;
}











