/** 
* @file globalePraticien.h
* @brief Fonctions globales qui regroupent les actions que peuvent réaliser les praticiens et les secretaire.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"


/**
 * @brief Fonction qui permet de gérer les actions que peut réaliser un praticien.
 * @details La fonction demande le nom du praticien, le recherche dans toutes les spécialités,
 *          puis propose les actions qu'il peut réaliser (appeler un patient, afficher les patients en ordre lexicographique,
 *          afficher les patients en ordre de leur date de visite, afficher les patients qui ne sont pas venus depuis une date donnée,
 *          faire de la place dans la file d'attente). La fonction sauvegarde les données dans un fichier quand le praticien quitte.
 * @param tabSpe Le tableau de pointeur vers les spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 */
void globalePraticien(Specialite **tabSpe, int nbSpe);


/**
 * @brief Fonction qui gère les actions que peuvent réaliser les secrétaires.
 * @details Cette fonction affiche le menu des secrétaires et permet de choisir une action.
 * Les actions possibles sont l'ajout d'un praticien, la suppression d'un praticien, l'affichage des spécialités et l'affichage des patients en attente.
 * La fonction sauvegarde également les données dans le fichier "sources/Centre.txt" quand la secretaire choisit de quitter.
 * @param tabSpe Le tableau de spécialités
 * @param nbSpe Le nombre de spécialités dans le tableau
 */
void globaleSecretaire(Specialite **tabSpe, int *nbSpe);


/**
 * @brief Fonction principale du programme qui permet d'effectuer les différentes actions sur le centre.
 * La fonction fGlobale permet de charger les données du centre, de sélectionner le type d'utilisateur
 * (Secrétaire ou Praticien), d'effectuer les actions associées au type d'utilisateur et de sauvegarder les données
 * avant de quitter le programme.
 */
void fGlobale(void);