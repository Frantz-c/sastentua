NAME = sastentua
CC = gcc -Wall -Werror -Wextra 
FILES = ft_atol.o\
ft_putchar.o\
main.o\
sastentua.o

all: $(NAME)

$(NAME): $(FILES)
	@$(CC) -o $@ $^ 

.c.o:
	@$(CC) -c $<

clean:
	@/bin/rm -f $(FILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

allc: all clean
