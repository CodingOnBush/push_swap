# Liste de tous les fichiers .c dans le répertoire courant
SOURCES := $(wildcard *.c)

# Liste de tous les fichiers .o générés à partir des fichiers .c
OBJECTS := $(SOURCES:.c=.o)

# Nom du fichier exécutable
EXECUTABLE := a.out

# Règle par défaut pour la cible "all"
all: $(EXECUTABLE)
	@rm -f $(OBJECTS)

# Règle pour générer l'exécutable
$(EXECUTABLE): $(OBJECTS)
	@gcc $^ -o $@

# Règle générique pour la compilation des fichiers .c en fichiers .o
%.o: %.c
	@gcc -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(EXECUTABLE)