D_SRC = src
D_HDRS = include
SRC = $(D_SRC)/ft_printf.c $(D_SRC)/ft_str.c $(D_SRC)/ft_pointer.c \
		$(D_SRC)/ft_uint.c $(D_SRC)/ft_int.c $(D_SRC)/ft_uinthex.c
		
O_SRC = $(SRC:.c=.o)
HDRS = $(D_HDRS)/ft_printf.h 
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):$(O_SRC)
	ar -rcs $(NAME) $(O_SRC)

%.o: %.c $(HDRS)
	cc -c $(CFLAGS) $< -I$(D_HDRS) -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(O_SRC)

re : fclean all

.PHONY : all fclean clean re