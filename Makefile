CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = server.c client.c					

OBJS = $(SRCS:.c=.o)

all: server client $(LIBFT)

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o -L$(LIBFT_DIR) -lft -o server

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o -L$(LIBFT_DIR) -lft -o client
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c: .o
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 
	$(MAKE) clean -C $(LIBFT_DIR) 

fclean:	clean
	$(RM) server client
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY: clean re all fclean 
