# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/04/11 14:06:41 by dmorgil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     	= 	42sh
CC       	= 	gcc
SRCD  		=	srcs
OBJD		=	objs
FLAGS		=	-Wall -Wextra -Werror -O3 -Ofast
DEBUG		=	-g
INCLUDES_D	=	includes

_INCLUDES	=	42sh.h
INCLUDES	= 	$(addprefix $(INCLUDES_D)/,$(_INCLUDES))

_MAIN_FS	=	42sh.c

MAIN_FS		=	$(addprefix $(SRCD)/,$(_MAIN_FS))
MAIN_O		=	$(_MAIN_FS:.c=.o)

SRCS_MAIN	=	$(MAIN_FS)

OBJS_MAIN	=	$(MAIN_O)

OBJB_MAIN	=	$(addprefix $(OBJD)/, $(OBJS_MAIN))

LIBDIR		=	./libft
LIBFT		=	./libft/libft.a
LIBINC		=	./libft/includes

# COLORS
RED		 =	\033[0;31m
GREEN	 =	\033[0;32m
YELLOW	 =	\033[0;33m
NC		 =	\033[0m

.PHONY: all clean fclean re

all: $(OBJD) $(LIBFT) $(NAME) $(NAME2)

$(OBJD):
	@mkdir -p $(OBJD)

$(LIBFT):
	@make -C $(LIBDIR)

$(NAME): $(OBJD) $(OBJB_MAIN)
	@printf "\r\033[K$(GREEN)Compiling $(NC): $(YELLOW)$(NAME)$(NC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB_MAIN) $(LIBFT)
	@echo "$(GREEN)DONE$(NC)"

$(NAME2): $(OBJD) $(OBJB_CHECK)
	@printf "\r\033[K$(GREEN)Compiling $(NC): $(YELLOW)$(NAME2)$(NC)\n"
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJB_CHECK) $(LIBFT)
	@echo "$(GREEN)DONE$(NC)"


$(OBJD)/%.o : $(SRCD)/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(GREEN)Compiling$(NC): $<"
	@$(CC) $(FLAGS) -I$(INCLUDES_D) -I$(LIBINC)  -o $@ -c $<

clean:
	@rm -rf $(OBJD)
	@make  clean -C libft
	@echo "$(RED)Cleaning$(NC): $(NAME)"

fclean:
	@rm -rf $(OBJD)
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "$(RED)Full cleaning$(NC): $(NAME)"

re:
	@make fclean
	@make all
