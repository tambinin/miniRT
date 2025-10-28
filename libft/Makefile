
NAME = libft.a

SRC_DIR = ./source
OBJ_DIR = ../obj

SRCS = $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_calloc.c \
	   $(SRC_DIR)/ft_isalnum.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isascii.c \
	   $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_memchr.c \
	   $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_memcpy.c $(SRC_DIR)/ft_memmove.c \
       $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_strchr.c $(SRC_DIR)/ft_strdup.c \
	   $(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_strrchr.c \
	   $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_toupper.c $(SRC_DIR)/ft_substr.c \
       $(SRC_DIR)/ft_strjoin.c $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_isspace.c \
	   $(SRC_DIR)/ft_putchar_fd.c $(SRC_DIR)/ft_putstr_fd.c \
       $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c \
	   $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_itoa.c \
	   $(SRC_DIR)/ft_split.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strtok.c \
	   $(SRC_DIR)/ft_strpbrk.c $(SRC_DIR)/ft_strspn.c $(SRC_DIR)/ft_strcspn.c \
	   $(SRC_DIR)/ft_strcpy.c $(SRC_DIR)/ft_strncpy.c $(SRC_DIR)/ft_strcat.c \
	   $(SRC_DIR)/ft_strstr.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

INCS = -I ../includes/includes\libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBC = ar -rcs
RM = rm -f

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
