/** 
* @file tableau.c
* @brief Fonctions qui concernent les actions à réaliser sur des tableaux de pointeurs dynamique et static.
* @author Elora LIAGRE , Ambre GUILLAUMIN-TORRES & Shreya ANGIA
* @date Décembre 2025 - Janvier 2026
*/

#include "structures.h"


/**
 * @brief Ajoute un patient au tableau des patients d'un praticien
 * @param praticien Le praticien concerné
 * @param pat Le patient à ajouter
 * @return 1 si l'ajout est réussi, -1 si l'un des arguments est NULL, -2 si la réallocation du tableau échoue
 */
int ajouterPatient(Praticien* praticien, Patient* pat);


/**
 * @brief Supprime un patient d'un praticien.
 * @details La fonction supprime le patient correspondant au numéro de sécurité sociale numSecu
 *          de la liste des patients du praticien. Si le patient n'existe pas, la fonction renvoie -2.
 * @param praticien Le praticien concerné.
 * @param numSecu Le numéro de sécurité sociale du patient à supprimer.
 * @return 1 si le patient est supprimé, -2 si le patient n'existe pas, -1 si le praticien est NULL.
 */
int supprimerPatient(Praticien* praticien, int numSecu);


/**
 * @brief Ajoute une spécialité dans un tableau de spécialités.
 * @details La fonction insère la spécialité s dans le tableau tab en utilisant l'algorithme de recherche dichotomique.
 *         Si la spécialité existe déjà, elle n'est pas ajoutée.
 * @param s La spécialité à ajouter.
 * @param p La liste des praticiens associée à la spécialité.
 * @param tab Le tableau de spécialités.
 * @param nb Le nombre de spécialités dans le tableau.
 * @param max La capacité maximale du tableau.
 * @return Le tableau mis à jour.
 */
Specialite **ajouterSpecialite(Specialite *s, listePraticiens *p, Specialite **tab, int *nb, int *max);


/**
 * @brief Supprime une spécialité d'un tableau de spécialités.
 * @details La fonction supprime la spécialité e du tableau tab.
 *          Si la spécialité n'existe pas, le tableau reste inchangé.
 * @param e La spécialité à supprimer.
 * @param p La liste des praticiens associée à la spécialité.
 * @param tab Le tableau de spécialités.
 * @param nb Le nombre de spécialités dans le tableau.
 * @return Le tableau mis à jour.
 */
Specialite **supprimerSpecialte(Specialite *e, listePraticiens *p, Specialite **tab, int *nb);

/**
 * @brief Copie un deux tableau en un seul tableau de patients.
 * @details Copie les patients du tableau tab entre l'indice i et j (inclus) dans le tableau R.
 * @param tab Le tableau de patients source.
 * @param i L'indice de début de la copie.
 * @param j L'indice de fin de la copie.
 * @param R Le tableau de patients destination.
 */
void copier(Patient **tab, int i, int j, Patient ** R);


/**
 * @brief Fusion de deux tableau de patients.
 * @details La fonction prend en paramètre deux tableau de patients
 *          R et S, ainsi que leurs tailles respectives nbR et nbS.
 *          Les patients sont fusionnés dans le tableau tab, en
 *          prenant soin de conserver l'ordre alphabétique.
 * @param R Premier tableau de patients.
 * @param nbR Taille du premier tableau.
 * @param S Deuxième tableau de patients.
 * @param nbS Taille du deuxième tableau.
 * @param tab Tableau dans lequel on fusionne les patients.
 */
void fusion(Patient ** R, int nbR, Patient ** S, int nbS, Patient ** tab);


/**
 * @brief Trie lexicographique des patients d'un tableau.
 * @details Divise le tableau en deux parties, trie chaque partie
 *          récursivement, puis fusionne les deux parties triées pour
 *          obtenir le tableau trié.
 * @param tab Le tableau de patients à trier.
 * @param nb Le nombre de patients dans le tableau.
 */
void triLexicographiquePatients(Patient **tab, int nb);


/**
 * @brief Compare deux dates
 * @param d1 Première date à comparer
 * @param d2 Deuxième date à comparer
 * @return -1 si d1 est avant d2, 1 si d1 est après d2, 0 si d1 est égal à d2
 */
int compareDate(Date *d1, Date *d2);


/**
 * @brief Tri des patients
 * @details Tri les patients dans l'ordre de leur date de dernière visite
 * @param tab Le tableau des patients 
 * @param nb Le nombre de patients dans le tableau
 */
void quickSort(Patient **tab, int nb);


/**
 * @brief Recherche dichotomique d'une specialité dans un tableau de pointeur.
 * @details Recherche une spécialité dans un tableau de pointeur vers des spécialités.
 *           La recherche est faite en utilisant l'algorithme de recherche dichotomique.
 *           Si la spécialité est trouvée, la fonction renvoie l'indice de la spécialité dans le tableau.
 *           Sinon, la fonction renvoie -1.
 * @param tSpe Le tableau de pointeur vers les spécialités.
 * @param nom Le nom de la spécialité à rechercher.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 * @return L'indice de la spécialité dans le tableau si elle est trouvée, -1 sinon.
 */
int rechercherSpe(Specialite **tSpe, char* nom, int nbSpe);


/**
 * @brief Cherche un patient par son nom dans un tableau de patients
 * @param tPat Le tableau des patients
 * @param nom Le nom du patient à chercher
 * @param nbPat Le nombre de patients dans le tableau
 * @return Le patient trouvé s'il existe, NULL sinon
 */
Patient * trouverPatient(Patient ** tPat, char*nom, int nbPat);


/**
 * @brief Recherche les patients qui ne sont pas venus depuis une date donnée
 * @param d La date à partir de laquelle vérifier les absences
 * @param p Le praticien concerné
 * @param tabRech Le tableau des patients qui ne sont pas venus depuis la date d
 * @return Le nombre de patients qui ne sont pas venus depuis la date d
 */
int rechercheDepuisCertainTps(Date d, Praticien p, Patient **tabRech);


/**
 * @brief Recherche les patients qui ne sont pas venus depuis une date donnée
 * 
 * @param d La date à partir de laquelle vérifier les absences
 * @param p Le praticien concerné
 * @param tabRech Le tableau de patients qui ne sont pas venus depuis la date d
 * @return Le nombre de patients qui ne sont pas venus depuis la date d
 * @details Cette fonction parcourt la liste des patients d'un praticien et ajoute
 *          dans un tableau les patients qui ne sont pas venus depuis une date donnée.
 */
int rechercheDepuisCertainTps(Date d, Praticien p, Patient **result);


