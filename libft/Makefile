# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:15:47 by ymarcais          #+#    #+#              #
#    Updated: 2022/12/02 18:18:54 by ymarcais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c	\
       		ft_bzero.c	\
		ft_calloc.c	\
		ft_itoa.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c	\
		ft_strdup.c	\
		ft_strlcat.c	\
		ft_strchr.c	\
		ft_strlcpy.c	\
		ft_strjoin.c	\
		ft_strlen.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		
OBJS = ft_atoi.o	\
       		ft_bzero.o	\
		ft_calloc.o	\
		ft_itoa.o	\
		ft_isalnum.o	\
		ft_isalpha.o	\
		ft_isascii.o	\
		ft_isdigit.o	\
		ft_isprint.o	\
		ft_memchr.o	\
		ft_memcmp.o	\
		ft_memcpy.o	\
		ft_memmove.o	\
		ft_memset.o	\
		ft_putchar_fd.o	\
		ft_putendl_fd.o	\
		ft_putnbr_fd.o	\
		ft_putstr_fd.o	\
		ft_split.o	\
		ft_strdup.o	\
		ft_strlcat.o	\
		ft_strchr.o	\
		ft_strlcpy.o	\
		ft_strjoin.o	\
		ft_strlen.o	\
		ft_strmapi.o	\
		ft_striteri.o	\
		ft_strncmp.o	\
		ft_strnstr.o	\
		ft_strrchr.o	\
		ft_strtrim.o	\
		ft_substr.o	\
		ft_tolower.o	\
		ft_toupper.o	\

SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			
#		$(SRCS)
		
OBJSB =	ft_lstnew.o			\
		ft_lstadd_front.o	\
		ft_lstsize.o		\
		ft_lstlast.o		\
		ft_lstadd_back.o	\
		ft_lstclear.o		\
		ft_lstdelone.o		\
		ft_lstiter.o		\
		ft_lstmap.o		
#		$(OBJS)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJS) $(OBJSB) libft.h
	ar -rc $(NAME) $(OBJS)
	

$(OBJS): $(SRCS)
	$(CC) $(CC_FLAGS) -c $(SRCS)

bonus:
	$(CC) $(CC_FLAGS) -c $(SRCSB)
	ar -rc $(NAME) $(OBJSB)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all
