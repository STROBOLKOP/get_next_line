# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efret <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:38:36 by efret             #+#    #+#              #
#    Updated: 2023/11/27 00:03:02 by efret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fPIC

INCS = libft.h
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	   ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	   ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c\
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
	   ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = ${SRCS:.c=.o}

B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		 ft_lstiter.c ft_lstmap.c
B_OBJS = ${B_SRCS:.c=.o}

RESET = \e[0m
GREEN = \e[38;5;40m
YELLOW = \e[33m
UP = \e[F

all: ${NAME}

${NAME}: ${OBJS}
	@echo -n "${YELLOW}"
	ar rcs ${NAME} ${OBJS}
	@echo "${GREEN}${NAME} Done compiling${RESET}"

bonus: ${OBJS} ${B_OBJS}
	@echo -n "${YELLOW}"
	ar rcs ${NAME} ${OBJS} ${B_OBJS}
	@echo "${GREEN}${NAME} Done compiling with $@${RESET}"

%.o: %.c ${INCS}
	@echo "$<"
	@${CC} ${CFLAGS} -I ${INCS} -c -o $@ $<
	${COUNT}

clean:
	@echo -n "${YELLOW}"
	rm -f ${OBJS}
	@echo
	rm -f ${B_OBJS}
	@echo "${RESET}"

fclean: clean
	@echo -n "${YELLOW}"
	rm -f ${NAME}
	@echo "${RESET}"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
