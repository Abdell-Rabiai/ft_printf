# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 19:23:05 by arabiai           #+#    #+#              #
#    Updated: 2022/11/13 12:54:05 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
		ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c \
		ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
		ft_calloc.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
		ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_strjoin.c ft_substr.c \
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \
    	ft_putchar_fd_count.c ft_putstr_fd_count.c ft_putendl_fd_count.c \
		ft_putnbr_fd_count.c ft_putnbr_fd_uns_count.c \

BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

ECHO1 = @echo "\033[92mCompiled all files successfully!\033[0m"

ECHO2 = @echo "\033[92mCompiled all BONUS files successfully!\033[0m"

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) libft.h
	$(ECHO1)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJECTS) $(BONUS_OBJECTS) libft.h
	$(ECHO2)
	ar rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean :
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re bonus
