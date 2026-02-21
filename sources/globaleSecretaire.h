/** 
* @file globaleSecretaire.h
* @brief Fonctions qui concernent les actions que peuvent réaliser les secrétaires.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#ifndef GLOBALE_SECRETAIRE_H
#define GLOBALE_SECRETAIRE_H

#include "structures.h"



/**
 * @brief Enregistre un patient dans la spécialité demandée.
 * 
 * @param tspe Un tableau de pointeur vers des spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 * 
 * @details On demande le nom du patient, la spécialité demandée, et si le 
 *          patient a un praticien référent. Si c'est le cas, on recherche 
 *          le praticien référent et on ajoute le patient à sa file d'attente. Sinon, 
 *          on recherche un praticien disponible dans la spécialité et on ajoute 
 *          le patient à sa patientèle et à sa file d'attente.
 */
void enregistrer1Patient(Specialite ** tspe, int nbSpe);


/**
 * @brief Supprime un praticien d'une spécialité.
 * @details Demande le nom du praticien et sa spécialité, puis supprime le praticien de la liste des praticiens de cette spécialité.
 * Si la liste des praticiens est vide après la suppression, on supprime la spécialité.
 * @param tspe Le tableau des spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 */
void supprimer1Praticien(Specialite ** tspe, int *nbSpe);


/**
 * @brief Fonction qui ajoute un praticien dans la liste des praticiens d'une spécialité.
 * @details La fonction demande le nom de la spécialité et le nom du praticien à ajouter.
 * Si la spécialité n'existe pas, elle est créée.
 * Le praticien est ajouté à la liste des praticiens de la spécialité.
 * @param tabSpe Le tableau de spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 */
void globaleAjouterPraticien(Specialite **tabSpe, int *nbSpe);


/**
 * @brief Affiche la liste des patients d'une spécialité.
 * @details La fonction demande le nom de la spécialité, recherche le dans le tableau des spécialités
 *          et affiche la liste des patients de la spécialité demandée.
 * @param tabSpe Le tableau de spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 */
void globalePraticien1Spe(Specialite **tabSpe, int nbSpe);



#endif 


