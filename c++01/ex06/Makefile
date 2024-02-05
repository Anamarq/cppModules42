NAME = harlFilter

# Directorios
SRCDIR = ./src
OBJDIR = ./obj

# Fuentes y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Compilador y banderas
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Comandos
RM = rm -f
MKDIR = mkdir -p

# Reglas
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re