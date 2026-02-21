#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct{
    int jour;
    int mois;
    int annee;
} Date;

typedef enum {FAUX, VRAI} Boolean;

typedef struct{
    char nom[50];
    char prenom[50];
    int numSecu;
    Boolean IsDate;
    Date* derniereVisite;
} Patient;


typedef struct maillonf{
    Patient* patient;
    struct maillonf *suiv;
}MaillonF;

typedef struct{
    MaillonF *t;
    MaillonF *q;
}File;

typedef struct{
    char nom[50];
    int maxPatient; //tmax
    int nbPatients; // tlog
    Patient** tPatientele; 
    File fileAttente;
}Praticien;

typedef struct praticien{
    Praticien praticien;
    struct praticien *suiv;

}Maillon,*listePraticiens;

typedef struct {
    char nom[50];
    listePraticiens* praticien;
}Specialite;
#endif