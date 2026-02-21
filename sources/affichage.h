/** 
* @file affichage.h
* @brief Fonctions qui concernent les affichages des différentes structures, parfois en fonctions de critères.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"

/**
 * @brief Affiche le menu de selection entre Secretaire et Praticien.
 */
void menuSelection();


/**
 * @brief Affiche le menu de la secretarie.
 *
 * Ce menu permet a la secretarie de gerer des actions sur les
 * specialites et les praticiens. Il permet d'ajouter un
 * praticien, de supprimer un praticien, d'afficher les specialites,
 * de trouver les praticiens d'une specialite ayant de la place,
 * d'afficher tout le centre et d'enregistrer un patient (file
 * d'attente).
 */
void menuSecretaire();


/**
 * @brief Affiche le menu du praticien.
 *
 * Le menu du praticien propose les options suivantes :
 * - Quitter
 * - Appeler un patient
 * - Patientèle (ordre lexicographique)
 * - Patientèle (par visite)
 * - Patients absents depuis un delai donné
 * - Faire de la place
 */
void menuPraticien();


/**
 * @brief Affiche les patients d'un praticien triés par ordre lexicographique
 * @param praticien Le praticien dont on veut afficher les patients
 */
void affichageTriLex(Praticien praticien);


/**
 * @brief Affiche les patients d'un praticien par ordre de visite le plus recente au plus ancien
 * @param praticien Le praticien dont on veut afficher les patients
 */
void affichageTriVisite(Praticien praticien);


/**
 * @brief Affiche la liste des patients qui ne sont pas venus depuis une date donnée
 * @param d La date à partir de laquelle vérifier les absences
 * @param praticien Le praticien concerné
 * @param tabPat Le tableau de patients
 * @param nbPatients Le nombre de patients dans le tableau
 * Affiche la liste des patients concernés qui sont absents depuis la date d
 * Si aucun patient n'est absent, affiche un message l'indiquant
 */
void afficherPDepuis1CertainTps(Date d, Praticien praticien, Patient **tabPat, int nbPatients);


/**
 * @brief Affiche les informations d'un praticien.
 * @param praticien Le praticien dont on veut afficher les informations.
 * @details Cette fonction affiche le nom, le nombre de patients et le nombre max de patients du praticien.
 */
void afficherUnPraticien(Praticien praticien);


/**
 * @brief Affiche une liste de specialites.
 * 
 * @param tabSpecialites tableau de pointeur sur les specialites.
 * @param nbSpecialites nombre de specialites dans le tableau.
 */
void afficherSpecialites(Specialite** tabSpecialites, int nbSpecialites);


/**
 * @brief Affiche le centre medical.
 * @details Affiche les spécialités et les praticiens qui y sont rattachés.
 * @param tabSpecialites Un tableau de Specialite.
 * @param nbSpecialites Le nombre de spécialités dans le tableau.
 */
void afficherCentre(Specialite** tabSpecialites, int nbSpecialites);


/**
 * @brief Affiche la liste des praticiens d'une spécialité qui ont de la place disponible.
 * @param specialite La spécialité dont on veut afficher les praticiens.
 * @details Cette fonction affiche le nom de la spécialité, le nombre de
 * praticiens qui ont de la place disponible et qui y sont rattachés et les informations sur ces praticiens.
 */
void afficherPraticiensSpecialite(Specialite* specialite);
