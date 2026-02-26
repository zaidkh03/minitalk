CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar rcs
RM = rm -f


SRCS = ft_atoi.c ft_bzero.c 	\
	ft_calloc.c ft_isalnum.c 	\
	ft_isalpha.c ft_isascii.c 	\
	ft_isdigit.c ft_isprint.c 	\
	ft_memchr.c ft_memcmp.c		\
	ft_memcpy.c ft_memmove.c 	\
	ft_memset.c ft_strchr.c 	\
	ft_strdup.c ft_strlcat.c 	\
	ft_strlcpy.c ft_strlen.c 	\
	ft_strncmp.c ft_strnstr.c 	\
	ft_strrchr.c ft_tolower.c 	\
	ft_toupper.c ft_substr.c	\
	ft_strjoin.c ft_strtrim.c	\
	ft_split.c ft_itoa.c		\
	ft_strmapi.c ft_striteri.c	\
	ft_putchar_fd.c ft_putstr_fd.c	\
	ft_putendl_fd.c ft_putnbr_fd.c	\
	ft_atoi.c ft_printf.c	\
	ft_print_format.c ft_print_char.c \
	ft_print_str.c ft_print_ptr.c \
	ft_print_digit.c ft_print_udigit.c
						
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c: .o
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean re all fclean 
