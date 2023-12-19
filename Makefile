CC = cc
CFLAGS = -Wall -Werror -Wextra 
NAME = libft.a

SRC = ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isascii.c ft_atoi.c \
 	ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
 	ft_bzero.c ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
 	ft_calloc.c ft_itoa.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
 	ft_isalnum.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_isalpha.c \
 	ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \

SRC_B = ft_lstclear.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	 ft_lstmap.c ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(OBJ_B): $(SRC_B)
	$(CC) $(CFLAGS) -c $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	ar -rcs $@ $^
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
#	$(CC) -nostartfiles -shared -o libft.so $(OBJ) $(OBJ_B)

bonus: $(OBJ) $(OBJ_B) 
	ar -rcs $(NAME) $(OBJ_B)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 
