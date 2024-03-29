#########################################
## ARGUMENTS
#########################################
NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
all: $(NAME)

########################################
## SOURCES
########################################
SRC_FILES = main.c \
			core_logic.c \
			utils.c \
			parsing.c \
			error.c \
			free.c \
			action.c \
			utils2.c

SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $^ $(CFLAGS) -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# philo = 0 /
# philo = 1 /
# free les malloc en cas de malloc error /
