/** 
* @file liste.h
* @brief Fonctions qui concernent les actions réalisées sur des listes de pointeurs sur des structures dynamiques.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"


/**
 * @brief Retourne une liste de praticien vide.
 * @return Une structure de type listePraticiens initialisée à NULL.
 */
listePraticiens listeNouv(void);


/**
 * @brief Vérifie si une liste de praticien est vide.
 * @param l La liste de praticien à vérifier.
 * @return VRAI si la liste est vide, FAUX sinon.
 */
Boolean listeEstVide(listePraticiens l);


/**
 * @brief Ajoute un praticien en tête de liste.
 * @details Alloue de la mémoire pour un maillon de liste, puis
 * met à jour les pointeurs de tête et de queue de la liste
 * en fonction de si la liste est vide ou non.
 * @param l La liste dans laquelle on veut ajouter le praticien.
 * @param p Le praticien à ajouter.
 * @return La liste avec le praticien ajouté.
 */
listePraticiens ajoutEnTete(listePraticiens l, Praticien p);


/**
 * @brief Insertion d'un praticien dans une liste de praticiens.
 * @details Insertion d'un praticien dans une liste de praticiens en gardant la liste triée par ordre alphabétique.
 * @param l La liste dans laquelle on veut ajouter le praticien.
 * @param p Le praticien à ajouter.
 * @return La liste avec le praticien ajouté.
 */
listePraticiens inserer(listePraticiens l, Praticien p);


/**
 * @brief Supprime le premier élément de la liste.
 * Supprime le premier élément de la liste et libère la mémoire.
 * Si la liste est vide, affiche un message d'erreur et quitte le programme.
 * Si la liste ne contient qu'un élément, le supprime et libère la file de la mémoire.
 * @param l La liste dont on veut supprimer le premier élément.
 * @return La liste sans son premier élément.
 */
listePraticiens supprimerTete(listePraticiens l);


/**
 * @brief Supprime un praticien de la liste.
 * @details Supprime un élément de la liste.
 * Si la liste est vide, affiche un message d'erreur et quitte le programme.
 * Si la liste ne contient qu'un élément, le supprime et libère la file de la mémoire.
 * @param l La liste dont on veut supprimer le premier élément.
 * @param nom Le nom du praticien à supprimer.
 * @return La liste sans son élément si le nom correspond, la liste inchangée sinon.
 */
listePraticiens supprimer(listePraticiens l, char* nom);


/**
 * @brief Recherche un praticien dans la liste.
 * @details Recherche un praticien dans la liste et renvoie son pointeur.
 * Si la liste est vide, renvoie NULL.
 * Si le nom correspond, renvoie le pointeur du praticien.
 * @param l La liste dont on veut rechercher le praticien.
 * @param nom Le nom du praticien à rechercher.
 * @return Le pointeur du praticien s'il est trouvé, NULL sinon.
 */
listePraticiens rechercherPraticien(listePraticiens l, char* nom);


/**
 * @brief Affiche la liste de praticiens.
 * @param l Une liste de praticiens.
 */
void afficherListe(listePraticiens l);


/**
 * @brief Retourne la longueur d'une liste de praticiens.
 * @param l La liste de praticiens.
 * @return La longueur de la liste.
 * @details La longueur est définie comme le nombre de praticiens
 *           dans la liste.
 */
int longueur(listePraticiens l);


/**
 * @brief Recherche praticiens qui ont de la place disponible.
 * @param l La liste des praticiens.
 * @param tabPPlace Le tableau qui stocke les praticiens avec de la place disponible.
 * @return Le nombre de praticiens trouvés.
 */
int recherchePraticienPlace(listePraticiens l, Praticien *tabPPlace);




