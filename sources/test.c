#include "affichage.h"
#include "file.h"
#include "liste.h"
#include "globalePraticien.h"
#include "globaleSecretaire.h"
#include "globale.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableau.h"
#include "structures.h"
#include "test.h"
#include "fichier.h"

// void GlobalTest(void){
//     // Initialisation des structures ou variables nécessaires pour les tests
//     Specialite **tabSpe;
//     int i,j;
//     int nbSpe = 3;
//     tabSpe = (Specialite **)malloc(nbSpe * sizeof(Specialite *));
//     for ( i = 0; i < nbSpe; i++) {
//         tabSpe[i] = (Specialite *)malloc(sizeof(Specialite));
//     }
//     strcpy(tabSpe[0]->nom, "Cardiologie");
//     strcpy(tabSpe[1]->nom, "Dermatologie");
//     strcpy(tabSpe[2]->nom, "Pediatrie");
//     // Ajouter des praticiens aux spécialités
//     for ( i = 0; i < nbSpe; i++) {
//         tabSpe[i]->praticien = malloc(sizeof(listePraticiens));
//         *(tabSpe[i]->praticien) = listeNouv();
//         *(tabSpe[i]->praticien) = inserer(*(tabSpe[i]->praticien), (Praticien){"Smith", 6, 0, NULL, filenouv()});
//         *(tabSpe[i]->praticien) = inserer(*(tabSpe[i]->praticien), (Praticien){"Jones", 5, 0, NULL, filenouv()});
//     }
//     //Ajouter des patients aux praticiens
//     for ( i = 0; i < nbSpe; i++) {
//         listePraticiens lp = *(tabSpe[i]->praticien);
//         while (lp != NULL) {
//             lp->praticien.tPatientele = (Patient **)malloc(5 * sizeof(Patient *));
//             lp->praticien.nbPatients = 0;
//             lp->praticien.maxPatient = 5;
//             // Ajouter des patients
//             for ( j = 0; j < 3; j++) {
//                 Patient *p = (Patient *)malloc(sizeof(Patient));
//                 sprintf(p->nom, "Patient%d", j + 1); //formater le nom
//                 sprintf(p->prenom, "Prenom%d", j + 1);
//                 p->numSecu = 1000 + j;
//                 lp->praticien.tPatientele[lp->praticien.nbPatients++] = p;
//             }
//             lp = lp->suiv;
//         }
//     }
    
//     // Appel des fonctions de test
//     testAffichageTriVisite();
// }

// //     testLire();
// // }





// void testLire(void){
//     FILE *flot;
//     int i;


//     Specialite* tabSpe[10];
//     int *tlog;
//     int *tphy;
//     tlog=malloc(sizeof(int));
//     tphy=malloc(sizeof(int));
//     *tlog=0;
//     *tphy=10;


// // //         printf("Spécialité lue : %s\n", s[spe]);
// // //         fscanf(flot, "%d",&nbPraticien);


// // //         printf("nbPraticien de %s: %d\n", s[spe], nbPraticien);


// // //         for(pra=0;pra < nbPraticien;pra++){
// // //             fscanf(flot, "%s", m[pra]);
// // //             printf("Praticien lu : %s\n", m[pra]);
// // //             fscanf(flot,"%d",&nbPatient);


// // //             printf("nbPatient de %s: %d\n", m[pra], nbPatient);


// // //             for(pat=0 ; pat < nbPatient ; pat++){
// // //                 fscanf(flot,"%s", p[pat]);
// // //                 printf("Nom patient lu : %s\n", p[pat]);
// // //                 fscanf(flot,"%s", p[pat+1]);
// // //                 printf("Prenom patient lu : %s\n", p[pat+1]);
// // //             }
// // //         };
// // //     }
// // // }






// // void testChargement(void){
// //     int nbSpe;
// //     Specialite* tabPointeurSpe;

// //     tabPointeurSpe=(Specialite*) malloc(20 *sizeof(Specialite));
    
// //     nbSpe=chargementSpecialite(tabPointeurSpe);
// //     printf("Nombre de specialites lues : %d\n",nbSpe);
// //     affichTabPointeur(tabPointeurSpe,nbSpe);

// // }

// // void main(void){
// //     testChargement();
// // }


// void testAfficherPraticienSpe(void)
// {
//     Specialite spe;
//     listePraticiens lp = NULL;
//     Praticien p1, p2, p3;

//     strcpy(p1.nom, "Dupont");
//     p1.maxPatient = 10;
//     p1.nbPatients = 0;
//     p1.tPatientele = NULL;

//     strcpy(p2.nom, "Martin");
//     p2.maxPatient = 10;
//     p2.nbPatients = 0;
//     p2.tPatientele = NULL;

//     strcpy(p3.nom, "Durand");
//     p3.maxPatient = 10;
//     p3.nbPatients = 0;
//     p3.tPatientele = NULL;

//     lp = inserer(lp, p1);
//     lp = inserer(lp, p2);
//     lp = inserer(lp, p3);

//     strcpy(spe.nom, "Cardiologie");
//     spe.praticien = &lp;

//     afficherPraticiensSpecialite(&spe);
// }

// //==============================================================================================================================
// //test des fonctions globaleSecretaire.c

// void testEnregistrerPatient(Specialite **tspe, int nbSpe)
// {
//     printf("Debut du test enregistrer1Patient\n");
//     afficherFile((*(tspe[0]->praticien))->praticien.fileAttente);
//     enregistrer1Patient(tspe, nbSpe);
//     afficherFile((*(tspe[0]->praticien))->praticien.fileAttente);
//     printf("Fin du test enregistrer1Patient\n");
// }



// void testAjouterPraticien(Specialite **tabSpe, int nbSpe)
// {
//     printf("Début du test ajouterPraticien\n");
//     afficherPraticiensSpecialite(tabSpe[0]);
//     globaleAjouterPraticien(tabSpe, &nbSpe);
//     afficherPraticiensSpecialite(tabSpe[0]);
//     printf("Fin du test ajouterPraticien\n");
// }

// void testSuprimer1Praticien(Specialite **globalTabSpe, int globalNbSpe)
// {
//     printf("Début du test supprimer1Praticien\n");
//     globaleAjouterPraticien(globalTabSpe, &globalNbSpe);
//     afficherCentre(globalTabSpe, globalNbSpe);
//     supprimer1Praticien(globalTabSpe, &globalNbSpe);
//     afficherCentre(globalTabSpe, globalNbSpe);
//     printf("Fin du test supprimer1Praticien\n");

// }

// void testGlobalePraticien1Spe(void)
// {
//     Specialite *tabSpe[1];
//     Specialite *spe = (Specialite*)malloc(sizeof(Specialite));
//     listePraticiens lp = NULL;
//     Praticien p1, p2;

//     strcpy(p1.nom, "Dupont");
//     p1.maxPatient = 10;
//     p1.nbPatients = 0;
//     p1.tPatientele = NULL;
//     p1.fileAttente = filenouv();

//     strcpy(p2.nom, "Martin");
//     p2.maxPatient = 8;
//     p2.nbPatients = 0;
//     p2.tPatientele = NULL;
//     p2.fileAttente = filenouv();

//     lp = inserer(lp, p1);
//     lp = inserer(lp, p2);

//     spe->praticien = (listePraticiens*)malloc(sizeof(listePraticiens));
//     *(spe->praticien) = lp;
//     strcpy(spe->nom, "Cardiologie");

//     tabSpe[0] = spe;

//     globalePraticien1Spe(tabSpe, 1);

//     free(spe->praticien);
//     free(spe);
// }

// //==============================================================================================================================
// //tests des fonctions globalePraticien.c

// void testAppeler1Patient()
// {   
//     printf("Début du test appeler1Patient\n");
//     Praticien p;
//     p.fileAttente = filenouv();
//     afficherFile(p.fileAttente);
//     Patient pat1 = {"Dupont", "Alice", 12345, VRAI, NULL};
//     Patient pat2 = {"Martin", "Bob", 67890, VRAI, NULL};

//     p.fileAttente = ajouterPatientF(p.fileAttente, &pat1);
//     p.fileAttente = ajouterPatientF(p.fileAttente, &pat2);
//     afficherFile(p.fileAttente);
//     appeler1Patient(&p);
//     afficherFile(p.fileAttente);
//     appeler1Patient(&p);
//     afficherFile(p.fileAttente); 
//     appeler1Patient(&p); 
//     printf("Fin du test appeler1Patient\n");
// }

// void testAfficherPDepuis1CertainTps(void)
// {
//     // Création d'un praticien
//     Praticien p;
//     p.nbPatients = 3;
//     p.maxPatient = 10;
//     p.tPatientele = malloc(sizeof(Patient*) * p.maxPatient);

//     // Patient 1 : a une date ancienne
//     Patient *a = malloc(sizeof(Patient));
//     strcpy(a->nom, "Durand");
//     strcpy(a->prenom, "Alice");
//     a->IsDate = VRAI;
//     a->derniereVisite = malloc(sizeof(Date));
//     a->derniereVisite->jour = 10;
//     a->derniereVisite->mois = 2;
//     a->derniereVisite->annee = 2022;
//     p.tPatientele[0] = a;

//     // Patient 2 : date récente
//     Patient *b = malloc(sizeof(Patient));
//     strcpy(b->nom, "Martin");
//     strcpy(b->prenom, "Paul");
//     b->IsDate = VRAI;
//     b->derniereVisite = malloc(sizeof(Date));
//     b->derniereVisite->jour = 5;
//     b->derniereVisite->mois = 12;
//     b->derniereVisite->annee = 2024;
//     p.tPatientele[1] = b;

//     // Patient 3 : aucune date enregistrée
//     Patient *c = malloc(sizeof(Patient));
//     strcpy(c->nom, "Bernard");
//     strcpy(c->prenom, "Lucie");
//     c->IsDate = FAUX;
//     c->derniereVisite = NULL;
//     p.tPatientele[2] = c;
//     printf("Début du test afficherPDepuis1CertainTps\n");
//     globalePDepuis1CertainTps(p);
//     printf("Fin du test afficherPDepuis1CertainTps\n");
    
// }

// void testIdentifierPraticen(void)
// {
//     printf("Début du test identifierPraticien\n");
//     Specialite *spe = malloc(sizeof(Specialite));
//     strcpy(spe->nom, "Cardiologie");
//     spe->praticien = malloc(sizeof(listePraticiens));
//     *(spe->praticien) = NULL;

//     Praticien p;
//     strcpy(p.nom, "Dupont");
//     p.fileAttente = filenouv();
//     *(spe->praticien) = inserer(*(spe->praticien), p);

//     Specialite *tabSpe[1];
//     tabSpe[0] = spe;

//     Praticien identifie = identifierPraticien(tabSpe, 1);
//     printf("%s \n", identifie.nom);
//     printf("Fin du test identifierPraticien\n");
// }

// void testSupprimer1Patient(void)
// {
//     printf("Début du test supprimer1Patient\n");
//     Praticien p;
//     strcpy(p.nom, "Durand");
//     p.nbPatients = 2;
//     p.maxPatient = 5;
//     p.tPatientele = malloc(sizeof(Patient*) * p.maxPatient);

//     Patient *pat1 = malloc(sizeof(Patient));
//     strcpy(pat1->nom, "Alice");
//     strcpy(pat1->prenom, "Dupont");
//     pat1->numSecu = 12345;
//     p.tPatientele[0] = pat1;

//     Patient *pat2 = malloc(sizeof(Patient));
//     strcpy(pat2->nom, "Bob");
//     strcpy(pat2->prenom, "Martin");
//     pat2->numSecu = 67890;
//     p.tPatientele[1] = pat2;

//     p = supprimer1Patient(p);

//     printf("Patients restants :\n");
//     for (int i = 0; i < p.nbPatients; i++) {
//         printf("%s %s (N° de sécu : %d)\n", p.tPatientele[i]->prenom, p.tPatientele[i]->nom, p.tPatientele[i]->numSecu);
//     }
//     printf("Fin du test supprimer1Patient\n");
// }

// void testFaireDeLaPlace(void)
// {
//     printf("Début du test faireDeLaPlace\n");
//     Praticien p;
//     strcpy(p.nom, "Dupont");
//     p.nbPatients = 2;
//     p.maxPatient = 5;
//     p.tPatientele = malloc(sizeof(Patient*) * p.maxPatient);

//     Patient *pat1 = malloc(sizeof(Patient));
//     strcpy(pat1->nom, "Alice");
//     strcpy(pat1->prenom, "Dupont");
//     pat1->numSecu = 12345;
//     p.tPatientele[0] = pat1;

//     Patient *pat2 = malloc(sizeof(Patient));
//     strcpy(pat2->nom, "Bob");
//     strcpy(pat2->prenom, "Martin");
//     pat2->numSecu = 67890;
//     p.tPatientele[1] = pat2;

//     faireDeLaPlace(&p);

//     printf("Patients restants :\n");
//     for (int i = 0; i < p.nbPatients; i++) {
//         printf("%s %s (N° de sécu : %d)\n", p.tPatientele[i]->prenom, p.tPatientele[i]->nom, p.tPatientele[i]->numSecu);
//     }
//     printf("Fin du test faireDeLaPlace\n");
// }

// //==============================================================================================================================
// //tests des fonctions affichage.c

// void testAffichageTriLex(void)
// {
//     printf("Début du test affichageTriLex\n");
//     Praticien p;
//     p.nbPatients = 3;
//     p.maxPatient = 10;
//     p.tPatientele = malloc(sizeof(Patient*) * p.maxPatient);

//     Patient *a = malloc(sizeof(Patient));
//     strcpy(a->nom, "Durand");
//     strcpy(a->prenom, "Alice");
//     p.tPatientele[0] = a;

//     Patient *b = malloc(sizeof(Patient));
//     strcpy(b->nom, "Martin");
//     strcpy(b->prenom, "Paul");
//     p.tPatientele[1] = b;

//     Patient *c = malloc(sizeof(Patient));
//     strcpy(c->nom, "Bernard");
//     strcpy(c->prenom, "Lucie");
//     p.tPatientele[2] = c;

//     affichageTriLex(p);
//     printf("Fin du test affichageTriLex\n");
// }

// void testAffichageTriVisite(void)
// {
//     printf("Début du test affichageTriVisite\n");
//     Praticien p;
//     strcpy(p.nom, "Test");
//     p.nbPatients = 3;
//     p.maxPatient = 10;
//     p.tPatientele = malloc(sizeof(Patient*) * p.maxPatient);

//     Patient *a = malloc(sizeof(Patient));
//     strcpy(a->nom, "Durand");
//     strcpy(a->prenom, "Alice");
//     a->IsDate = VRAI;
//     a->derniereVisite = malloc(sizeof(Date));
//     a->derniereVisite->jour = 10;
//     a->derniereVisite->mois = 2;
//     a->derniereVisite->annee = 2022;
//     p.tPatientele[0] = a;

//     Patient *b = malloc(sizeof(Patient));
//     strcpy(b->nom, "Martin");
//     strcpy(b->prenom, "Paul");
//     b->IsDate = VRAI;
//     b->derniereVisite = malloc(sizeof(Date));
//     b->derniereVisite->jour = 5;
//     b->derniereVisite->mois = 12;
//     b->derniereVisite->annee = 2024;
//     p.tPatientele[1] = b;

//     Patient *c = malloc(sizeof(Patient));
//     strcpy(c->nom, "Bernard");
//     strcpy(c->prenom, "Lucie");
//     c->IsDate = FAUX;
//     c->derniereVisite = NULL;
//     p.tPatientele[2] = c;

//     affichageTriVisite(p);
//     printf("Fin du test affichageTriVisite\n");

// void testLire(void){
//     FILE *flot;


//     Specialite* tabSpe[10];
//     int *tlog;
//     int *tphy;
//     tlog=malloc(sizeof(int));
//     tphy=malloc(sizeof(int));
//     *tlog=0;
//     *tphy=10;
//     // Open the file first
//     flot = fopen("sources/testF.txt", "r");
//     if (flot == NULL) {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     lire(flot,tabSpe, tlog, tphy);

//     fclose(flot);
// }
