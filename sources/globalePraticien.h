/** 
* @file globalePraticien.h
* @brief Fonctions globales qui gèrent les actions que peuvent réaliser les praticiens.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"


/**
 * @brief Affiche le prochain patient en attente et permet de saisir la date de la visite.
 * @param p Le praticien concerné.
 * @details Affiche le nom, le prénom et le numéro de sécurité sociale du patient, puis demande la date de la visite.
 * Si la date est invalide, redemande la date jusqu'à ce qu'elle soit valide.
 * Ajoute la date de la visite au patient et retire le patient de la file d'attente.
 */
void appeler1Patient(Praticien *p);


/**
 * @brief Affiche la liste des patients qui ne sont pas venus depuis une date donnée
 * @param p Le praticien concerné
 * @details Cette fonction affiche la liste des patients concernés qui sont absents depuis la date d
 * Si aucun patient n'est absent, affiche un message l'indiquant
 */
void globalePDepuis1CertainTps(Praticien p);


/**
 * @brief Connexion d'un praticien
 * @details Demande le nom du praticien et le recherche dans toutes les spécialités
 * @param tabSpe Le tableau de spécialités
 * @param nbSpe Le nombre de spécialités dans le tableau
 * @return Le praticien connecté
 */
Praticien identifierPraticien(Specialite **tabSpe, int nbSpe);


/**
 * @brief Supprime un patient d'un praticien.
 * @details La fonction demande le numéro de sécurité sociale du patient à supprimer.
 * Si le patient est trouvé, il est supprimé de la liste des patients du praticien.
 * Si le patient n'est pas trouvé, un message d'erreur est affiché.
 * @param p Le praticien dont on veut supprimer le patient.
 * @return Le praticien mis à jour.
 */
Praticien supprimer1Patient(Praticien p);


/**
 * @brief Permet de supprimer un patient précis ou de supprimer tous les
 * patients qui n'ont pas été vus depuis une date donnée.
 * @param p Le praticien concerné.
 * @details Cette fonction propose deux choix : supprimer un patient
 * précis ou supprimer tous les patients qui n'ont pas été vus
 * depuis une date donnée. Elle met à jour la liste des patients
 * du praticien en conséquence.
 */
void faireDeLaPlace(Praticien *p);


