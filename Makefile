NAME = libftprintf.a

SOURCES = ft_printf.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

ECHO1 = @echo "\033[92mCompiled all files successfully!\033[0m"

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) ft_printf.h
	$(ECHO1)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
