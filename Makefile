# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorotko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 15:04:54 by skorotko          #+#    #+#              #
#    Updated: 2017/11/22 15:14:07 by skorotko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PATH_SRC = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(PATH_SRC)
SRC = 			$(PATH_SRC)ft_putchar.c \
				$(PATH_SRC)ft_putstr.c \
				$(PATH_SRC)ft_strcmp.c \
				$(PATH_SRC)ft_strcpy.c \
				$(PATH_SRC)ft_strdup.c \
				$(PATH_SRC)ft_strcat.c \
				$(PATH_SRC)ft_strlen.c \
				$(PATH_SRC)ft_putnbr.c \
				$(PATH_SRC)ft_ls_main.c \
				$(PATH_SRC)ft_ls.c \
				$(PATH_SRC)parsingstr.c \
				$(PATH_SRC)ft_directory.c \
				$(PATH_SRC)ft_output_directory.c \
				$(PATH_SRC)ft_additionals_funcs.c \
				$(PATH_SRC)ft_output_all.c \
				$(PATH_SRC)ft_flag_r.c \
				$(PATH_SRC)ft_output_with_flags.c \
				$(PATH_SRC)ft_print_with_flags_r.c \
				$(PATH_SRC)ft_additionals_funcks_2.c \
				$(PATH_SRC)ft_output_flags_l.c \
				$(PATH_SRC)ft_pading_for_flag_l.c \
				$(PATH_SRC)ft_output_flag_l_continue.c \
				$(PATH_SRC)ft_timesort_ls.c \
				$(PATH_SRC)ft_help_directory.c \
				$(PATH_SRC)ft_additionals_funcks_3.c \
				$(PATH_SRC)ft_additionals_funcs_4.c \
				$(PATH_SRC)ft_free_for_all.c \
				$(PATH_SRC)ft_pading_help.c \
				$(PATH_SRC)ft_additionals_funcs_5.c \
				$(PATH_SRC)ft_additionals_funcs_6.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm	-rf	$(OBJ)

fclean: clean
	rm	-rf	$(NAME)

re:	fclean all