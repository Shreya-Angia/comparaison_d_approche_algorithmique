/** 
* @file file.h
* @brief Fonctions qui concernent les actions réalisées sur des files de pointeurs sur des structures dynamiques.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"

/**
 * @brief Retourne une file vide.
 * @return Une structure de type File.
 */
File filenouv(void);


/**
 * @brief Test si la file est vide.
 *
 * @param f La file à tester.
 * @return Boolean VRAI si la file est vide, FAUX sinon.
 */
Boolean estVide(File f);


/**
 * @brief Ajoute un patient a la fin d'une file.
 *
 * La fonction ajouterPatientF prend en paramètre une file et un patient.
 * Elle alloue de la mémoire pour un maillon de file, puis
 * elle met a jour les pointeurs de tête et de queue de la file
 * en fonction de si la file est vide ou non.
 *
 * @param f La file dans laquelle on veut ajouter le patient.
 * @param p Le patient a ajouter.
 * @return La file avec le patient ajouté.
 */
File ajouterPatientF(File f,Patient* p);


/**
 * @brief Supprime le premier élément de la file.
 * Supprime le premier élément de la file et libère la mémoire.
 * Si la file est vide, affiche un message d'erreur et quitte le programme.
 * Si la file ne contient qu'un élément, le supprime et libère la file de la mémoire.
 * @param f La file dont on veut supprimer le premier élément.
 * @return La file sans son premier élément.
 */
File supprimerPatientF(File f);


/**
 * @brief Renvoie le patient en tête de file.
 * @param f File dont on veut renvoyer le patient en tête.
 * @return Le patient en tête de file f.
 */
Patient* tete(File f);


/**
 * @brief Affiche le contenu d'une file de patients.
 * @details Affiche le nom, prénom et numéro de sécurité sociale de chaque patient stocké dans la file.
 * @param f La file à afficher.
 */
void afficherFile(File f);
