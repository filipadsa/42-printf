# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 10:14:41 by filda-si          #+#    #+#              #
#    Updated: 2025/10/20 15:03:32 by filda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SHARED = utils/conversions.c utils/conversions_hex.c \
		 utils/conversions_hex2.c \
         utils/utils.c utils/conversions_ptr.c \
		 utils/conversions_int.c utils/conversions_int2.c

MAND_SRC = ft_printf.c $(SHARED)
MAND_OBJ = $(MAND_SRC:.c=.o)

BONUS_SRC = ft_printf_bonus.c $(SHARED)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(MAND_OBJ)
	$(AR) $(NAME) $(MAND_OBJ)

bonus: .bonus

.bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
	@touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MAND_OBJ) $(BONUS_OBJ) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
