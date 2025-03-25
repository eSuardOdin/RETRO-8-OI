# Définir les variables
CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = src/main.c src/gameboy.c src/memory.c src/cartridge.c
OBJ = $(SRCS:.c=.o)
OUT = gb

# Cible par défaut : compilera tout
all: $(OUT)

# Créer l'exécutable
$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers temporaires
clean:
	rm -f $(OBJ) $(OUT)

# Cible pour afficher l'aide
help:
	@echo "Makefile pour le projet Gameboy"
	@echo "Commandes disponibles :"
	@echo "  make      - Compile le projet"
	@echo "  make clean - Supprime les fichiers objets et l'exécutable"
	@echo "  make help  - Affiche ce message"
