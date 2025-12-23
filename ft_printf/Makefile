NAME = libftprintf.a

CC = cc 

CFLAGS = -Werror -Wextra -Wall

CFILES = ft_printf.c helpers0.c helpers1.c

OFILES = $(CFILES:.c=.o)

.PHONY: clean

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^
	
clean:
	@rm -f $(OFILES) 
	
fclean: clean
	rm -rf $(NAME)

re: fclean all