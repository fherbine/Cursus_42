# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:03:11 by fherbine          #+#    #+#              #
#    Updated: 2018/02/25 19:28:41 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LSH_PTH = shell_lib
SRCS = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	   ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_bzero.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memset.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_strdel.c \
	   ft_striter.c ft_strnew.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_itoa.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c \
	   ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	   ft_lstiter.c ft_lstmap.c ft_swap.c ft_str_is_printable.c \
	   ft_putnbr_base.c get_next_line.c ft_absol.c ft_nlen_base.c ft_nlen.c \
	   ft_itoa_base.c ft_prints.c ft_specifier_prints.c ft_put_n_char.c \
	   $(LSH_PTH)/ftsh_getuser.c $(LSH_PTH)/ftsh_search_envar.c \
	   $(LSH_PTH)/ftsh_cwdgit.c $(LSH_PTH)/ftsh_get_np.c ft_append_slash.c \
	   $(LSH_PTH)/ftsh_free_envlist.c $(LSH_PTH)/ftsh_envlist.c \
	   ft_is_in_dir.c $(LSH_PTH)/ftsh_ispath.c $(LSH_PTH)/ftsh_del_envar.c \
	   ft_tab_len.c ft_free_tab.c ft_tab_del_elem.c ft_copy_tab.c \
	   ft_add_tab_elem.c
NAME = libft.a
INCLUDE = libft.h
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "]\033[0m --> \033[1;32;40m[Done]\033[0m"

%.o: %.c
	@echo "=\c"
	@gcc $(FLAGS) -I $(INCLUDE) -c $? -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
