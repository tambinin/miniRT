
NAME = libftprintf.a

SRC_DIR = ./source
OBJ_DIR = ../obj

SRCS = $(SRC_DIR)/ft_check_in.c $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/ft_print_char.c $(SRC_DIR)/ft_print_nbr.c \
       $(SRC_DIR)/ft_print_unbr.c $(SRC_DIR)/ft_print_adress.c \
       $(SRC_DIR)/ft_print_lowhexa.c $(SRC_DIR)/ft_print_str.c \
       $(SRC_DIR)/ft_print_uphexa.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBC = ar -rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCS = -I ../includes

all: $(OBJ_DIR) ${NAME}

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
