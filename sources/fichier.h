#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

/**
 * @brief Chargement d'un fichier de spécialités, de leurs praticiens et de leurs patients.
 * @details La fonction charge un fichier de spécialités, de leurs praticiens et de leurs patients.
 * Elle lit le fichier et stock les informations dans des structures de type Specialite, Praticien et Patient.
 * @param flot Le fichier à charger.
 * @param tabSpe Le tableau des spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 * @param maxSpe La capacité maximale du tableau.
 * @param tlog Le nombre de spécialités déjà dans le tableau.
 * @param tphy Le nombre de spécialités que l'on peut encore ajouter dans le tableau.
 * @return 1 si le chargement est réussi, -1 si l'un des arguments est NULL, -2 si la réallocation du tableau échoue.
 */
int chargement(FILE *flot, Specialite *tabSpe[], int *nbSpe, int *maxSpe, int *tlog, int *tphy);


/**
 * @brief Sauvegarde la liste des spécialités, des praticiens et leurs patients
 * dans un fichier.
 * @param flot Le fichier dans lequel on veut sauvegarder.
 * @param tabSpe Le tableau des spécialités.
 * @param nbSpe Le nombre de spécialités dans le tableau.
 * @return Le nombre de spécialités sauvegardées.
 */
int sauvegarde(FILE *flot, Specialite **tabSpe, int nbSpe);
