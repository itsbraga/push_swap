# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panther <panther@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2024/01/18 00:30:58 by panther          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM			:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED			:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE		:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN		:=	\e[96m


################################### BASICS ####################################

PUSH_SWAP	=	push_swap
# BONUS		=	checker
LIBFT_PATH	=	libft
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC			=	include/
RM			=	rm -rf
MAKEFLAGS	+=	--no-print-directory


################################### SOURCES ###################################

RULES_DIR		=	rules/
RULES_FILES		=	swap.c \
					push.c \
					rotate.c \
					reverseRotate.c

UTILS_DIR		=	utils/
UTILS_FILES		=	stack.c \
					init.c \
					index.c \
					handle_stack.c

ALGORITHM_DIR	=	algorithm/
ALGORITHM_FILES	=	sort.c \
					sort_utils.c

PARSING_DIR		=	parsing/
PARSING_FILES	=	check_args.c

# SRC_BONUS		=


######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		=	src/

SRC_NAMES	=	$(addprefix $(RULES_DIR), $(RULES_FILES)) \
					$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
					$(addprefix $(ALGORITHM_DIR), $(ALGORITHM_FILES)) \
					$(addprefix $(PARSING_DIR), $(PARSING_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRC_NAMES:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(RULES_DIR) \
                	$(UTILS_DIR) \
					$(ALGORITHM_DIR) \
					$(PARSING_DIR))

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#################################### RULES ####################################

$(PUSH_SWAP):	$(OBJ)
				@printf "$(RESET)$(BOLD)$(CYAN)[push_swap]:\t$(RESET)"
				@$(CC) $(CFLAGS) $(INC) $(OBJ_NAMES) libft.a -o $(PUSH_SWAP)
				@printf "$(PINK) ./PUSH_SWAP ready to launch! $(RESET)🔥\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@printf "$(ITAL)$(YELLOW)Compiling: $(RESET)$(ITAL)$<\n"
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
		@cp $(LIBFT_PATH)/libft.a .
		@make all

all: 	$(PUSH_SWAP)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -C $(LIBFT_PATH)
		@printf "$(RESET)$(BOLD)$(CYAN)[push_swap]: $(RESET)$(CYAN)object files $(RESET)\t=> CLEANED! 🕹️\n\n"

fclean:		clean
				@$(RM) $(PUSH_SWAP) $(BONUS)
				@$(RM) $(LIBFT_PATH)/libft.a
				@$(RM) libft.a
				@find . -name ".DS_Store" -delete
				@printf "$(BOLD)$(PURPLE)[LIBFT]: $(RESET)$(PURPLE)exec. files $(RESET)\t\t=> CLEANED! 🦋\n\n"
				@printf "$(BOLD)$(BRIGHT_PURPLE)[push_swap]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! 🧮\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


################################### BONUS ###################################

# $(BONUS):	$(OBJ_BONUS)
# 			@printf "$(RESET)$(BOLD)$(CYAN)[push_swap BONUS]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS) libft.a -o $(BONUS)
# 			@printf "$(PINK) ./CHECKER ready ! $(RESET)🔎\n\n"

# bonus:
# 		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
# 		@cp $(LIBFT_PATH)/libft.a .
# 		@make allbonus

# allbonus:	$(BONUS)


.PHONY:		build all clean fclean re norm