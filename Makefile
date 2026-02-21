.PHONY: clean doc re

#### Compilateur ####
CC = gcc
CFLAGS = -Wall -std=c11 -MMD -MP
LDFLAGS = -lm

#### Nom de l'exécutable ####
EXEC = sae

#### Dossiers ####
SRC_DIR = sources
OBJ_DIR = obj

#### Fichiers sources ####
SRC = main.c \
      fichier.c \
      file.c \
      globale.c \
      affichage.c \
      globalePraticien.c \
      globaleSecretaire.c \
      liste.c \
      tableau.c \
      test.c

#### Fichiers objets et dépendances ####
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

#### Cible principale ####
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

#### Compilation ####
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#### Création du dossier obj ####
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#### Inclusion des dépendances ####
-include $(DEP)

#### Documentation ####
doc:
	doxygen

#### Nettoyage ####
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

#### Recompilation ####
re: clean $(EXEC)
