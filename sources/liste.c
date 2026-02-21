#include "liste.h"
#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


listePraticiens listeNouv(void){
    return NULL;
}



Boolean listeEstVide(listePraticiens l){
    if (l==NULL){
        return VRAI;
    }
    return FAUX;
}


listePraticiens ajoutEnTete(listePraticiens l, Praticien p){
    Maillon *m;
    m=(Maillon*)malloc(sizeof(Maillon));
    if (m==NULL){
        printf("Problème malloc\n");
        exit(1);
    }
    m->praticien=p;
    m->praticien.fileAttente = filenouv();
    m->suiv=l;
    return m;
}


listePraticiens inserer(listePraticiens l, Praticien p){
    if (listeEstVide(l)|| strcmp(p.nom, l->praticien.nom)<0){
        return ajoutEnTete(l, p);
    }
    if (strcmp(p.nom,l->praticien.nom)==0)
    {
        printf("Praticien déjà présent, insertion impossible\n");
        exit(1);
    }
    l->suiv = inserer (l->suiv, p);
    return l;
}



listePraticiens supprimerTete(listePraticiens l){
    Maillon* m;
    if (listeEstVide(l)){
        printf("Liste vide, suppression impossible\n");
        exit(1);
    }
    m= l->suiv;
    free(l);
    return m;
}

listePraticiens supprimer(listePraticiens l, char* nom){
    if (listeEstVide(l)){
        printf("Liste vide, suppression impossible\n");
        exit(1);
    }
    if (strcmp(l->praticien.nom, nom)>0){
        printf("Praticien non trouvé, suppression impossible\n");
        exit(1);
    }
    if (strcmp(l->praticien.nom, nom)==0){
        return supprimerTete(l);
    }
    l->suiv = supprimer(l->suiv, nom);
    return l;
}



listePraticiens rechercherPraticien(listePraticiens l, char* nom){
    if (listeEstVide(l)){
        return NULL;
    }
    if (strcmp(l->praticien.nom, nom)==0){
        return l;
    }
    return rechercherPraticien(l->suiv, nom);
}


void afficherListe(listePraticiens l);
void afficherListe(listePraticiens l){
    if (listeEstVide(l))
        return;
    printf("Praticien : %s\n", l->praticien.nom);
    afficherListe(l->suiv);
}


int longueur(listePraticiens l)
{
    if (listeEstVide(l))
        return 0;
    return 1 + longueur(l->suiv);   
}


int recherchePraticienPlace(listePraticiens l, Praticien *tabPPlace)
{
    int i;
    int cpt = longueur(l);
    for(i = 0; i < cpt; i++)
    {
        if(l->praticien.nbPatients < l->praticien.maxPatient)
        {
            tabPPlace[i] = l->praticien;
        }
        l = l->suiv; 
    }
    return cpt; 
}

