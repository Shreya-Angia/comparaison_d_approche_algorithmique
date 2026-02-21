#include "structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


File filenouv(void){
    File f;
    f.t=NULL;
    f.q=NULL;
    return f;
}


Boolean estVide(File f){
    return f.t==NULL && f.q==NULL;
}


File ajouterPatientF(File f,Patient* p){
    MaillonF *m;
    m=(MaillonF*)malloc(sizeof(MaillonF));
    if (m==NULL){
        printf("Pb malloc \n");
        exit(1);
    }
    m->suiv=NULL;
    m->patient=p;
    if (estVide(f)){
        f.t=m;
        f.q=m;
        return f;
    }
    f.q->suiv=m;
    f.q=m;
    return f;
}


File supprimerPatientF(File f){
    MaillonF *m;
    if(estVide(f)){
        printf("opération interdite\n");
        exit(1);
    }
    if(f.t==f.q){
        free(f.t);
        return filenouv();
    }
    m=f.t;
    f.t=f.t->suiv;
    free(m);
    return(f);
}


Patient* tete(File f){
    if (estVide(f)){
        printf("opération interdite\n");
        exit(1);
    }
    return f.t->patient;
}


void afficherFile(File f){
    MaillonF* m;
    if(estVide(f)){
        printf("File vide\n");
        return;
    }
    m=f.t;
    while(m!=NULL){
        printf("Patient: %s %s, NumSecu: %d\n",m->patient->nom,m->patient->prenom,m->patient->numSecu);
        m=m->suiv;
    }
}

