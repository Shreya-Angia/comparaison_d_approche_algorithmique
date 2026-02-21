# SAE_1.02_Angia_Guillaumin-Torres_Liagre



## :hospital: Comparaison d'approches algorithmiques :hospital:

Ce projet est un système des gestion d'un centre hospitalié développé en C.

## :busts_in_silhouette: Auteurs 

> Elora LIAGRE <br>
> Shreya ANGIA <br>
> Ambre Guillaumin-Torres

Groupe 5 - IUT Clermont Auvergne - BUT Informatique

## :diamond_shape_with_a_dot_inside: Fonctionnalités

Le système permet de :

- Pour un praticien:
    - Appeller un patient de sa file d'attente
    - Afficher sa patientèle par ordre lexicographique
    - Afficher sa patientèle par date de visite
    - Afficher ses patients qui ne sont pas venus depuis un delais données
    - Faire de la place dans sa patientèle

- Pour une secrétaire:
    - Ajouter un praticien dans une spécialité
    - Supprimer un praticien
    - Afficher les spécialités du centre
    - Afficher les praticien d'une spécialité qui peuvent accueilir de nouveau patients
    - Afficher tous le centre spécialité et les medecins de chaque spécialité
    - Enregistrer un nouveau patient dans la patientele d'un praticien et dans la file d'attente de ce praticien


## :diamond_shape_with_a_dot_inside: Structure du Projet

  ```
.
├── source/                               # Code source
│   ├── affichage.c/.h                    # Fonctions d'affichage
│   ├── fichier.c/.h                      # Gestion des fichiers
│   ├── file.c/.h                         # Gestion de file 
│   ├── globale.c/.h                      # Fonctions principales
│   ├── globalePraticien.c/.h             # Fonctions liées aux praticiens
│   ├── globaleSecretaire.c/.h            # Fonctions liées aux secrétaires
│   ├── liste.c/.h                        # Gestion des listes
│   ├── main.c                            # Point d'entrée du programme                     
│   ├── structures.c/.h                   # Définition des structures
│   ├── tableau.c/.h                      # Gestion des tableaux
│   ├── tests.c/.h                        # Tests unitaires
│   └── Centre.txt                        # Données du centre médical
├── docs/                                 # Documentation générée par Doxygen
│   ├── html/                             # Documentation HTML consultable via navigateur
│   └── latex/                            # Fichiers LaTeX pour génération PDF
├── SAE1.02.txt                           # Document texte du projet
├── Doxyfile                              # Configuration Doxygen
├── Makefile                              # Configuration de compilation
└── .gitignore                            # Fichiers et dossiers à exclure 
```


## :diamond_shape_with_a_dot_inside: Compilation et Utilisation

1. **Compiler le projet**
   - Compilation standard :
     ```bash
     make
     ```
     Cela génère l'exécutable `sae` dans le répertoire racine.<br><br>
   - Recompilation complète (nettoyage + compilation) :
     ```bash
     make clean && make
     ```
     ou simplement :
     ```bash
     make re
     ```

2. **Exécuter le programme**
   ```bash
   ./sae

## :diamond_shape_with_a_dot_inside: Format des Données

Les informations du centre hospitalier sont stockées selon la structure suivante :

* **Au sommet du fichier :**
    * Nombre total de spécialités 

* **Pour chaque Spécialité :**
    * Nom de la spécialité (ex: Homéopathie, Morgue) 
    * Nombre de praticiens rattachés 

* **Pour chaque Praticien :**
    * Nom du praticien 
    * Capacité maximale d'accueil 
    * Nombre actuel de patients suivis 

* **Pour chaque Patient :**
    * Nom et Prénom 
    * Numéro d'identifiant (6 chiffres) 
    * Si il à déjà visiter (VRAI ou FAUX) 
    * Date (Jour Mois Année) : existe uniquement si la date est VRAI