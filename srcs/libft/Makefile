# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/04/11 14:40:40 by dmorgil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME			= 	libft.a
CC				= 	gcc
SRCD			=	./srcs/
OBJD			=	./objs/
FLAGS			=	-Wall -Wextra -Werror -O3 -Ofast
INCLUDES_D		=	includes/

_INCLUDES		=	libft.h get_next_line.h ft_printf.h

_LIB_FS			=	ft_memchr.c ft_memccpy.c ft_memmove.c ft_memcpy.c ft_realloc.c\
					ft_memcmp.c ft_bzero.c ft_memalloc.c ft_memdel.c ft_memset.c\
					ft_free_darray.c ft_swap.c ft_print_arr.c ft_bubble_sort.c\
					ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c \
					ft_putstr.c get_next_line.c \
					ft_putstr_chr.c ft_print_spaces.c\
					ft_atoi.c ft_isblank.c ft_islower.c ft_isspace.c ft_isupper.c \
					ft_isxdigit.c ft_isgraph.c ft_iscntrl.c ft_strisprintable.c \
					ft_itoa.c ft_isalpha.c ft_isdigit.c  ft_tolower.c \
					ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
					ft_atol.c ft_min.c ft_max.c ft_itoa_base.c ft_itoa_bin.c \
					ft_itoa_double.c ft_itoa_ldouble.c ft_itoa_pointer.c ft_itoa_roundd.c\
					ft_itoa_u.c ft_strisnumeric.c ft_strislowercase.c \
					ft_strisalpha.c ft_strisint.c\
					ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
					ft_lstnew.c\
					ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strdel.c \
					ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
					ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
					ft_strsplit.c ft_strlowcase.c ft_strupcase.c ft_strlen.c \
					ft_strjoin_free.c ft_strjoinc_free.c ft_strdup.c ft_strcpy.c \
					ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
					ft_strchr.c ft_strrchr.c ft_strstr.c ft_strchr_by_index.c\
					ft_word_count.c ft_arr_word_count.c ft_strlen_chr.c ft_reverse_bits.c

_PRINT_FS		=	double.c ft_printf.c init.c io.c num.c precision.c str.c spec.c

LIB_FS			=	$(addprefix $(SRCD),$(_LIB_FS))
LIB_O			=	$(_LIB_FS:.c=.o)
PRINT_FS		=	$(addprefix $(SRCD),$(_PRINT_FS))
PRINT_O			=	$(_PRINT_FS:.c=.o)

SRCS			=	$(LIB_FS) $(PRINT_FS)

OBJS			=	$(LIB_O) $(PRINT_O)

OBJB			=	$(addprefix $(OBJD), $(OBJS))

# COLORS
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
L_BLUE			=	\033[0;36m
NC				=	\033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJB)
	@printf "\r\033[K$(GREEN)Creating library$(NC): $(YELLOW)$(NAME)$(NC)\n"
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
	@echo "$(GREEN)DONE$(NC)"

$(OBJD)%.o : $(SRCD)%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_printf/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(NC): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

clean:
	@rm -rf $(OBJB)
	@echo "$(RED)Cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

fclean:
	@rm -rf $(OBJB)
	@rm -rf $(NAME)
	@rm -rf $(OBJD)
	@echo "$(RED)Full cleaning$(NC): $(L_BLUE)$(NAME)$(NC)"

re:
	@make fclean
	@make all
