# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2024/02/01 23:52:21 by annabrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
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
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


################################### BASICS ####################################

PUSH_SWAP	=	push_swap
# BONUS_PS	=	checker
LIBFT_PATH	=	libft
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/
DEBUG		=	-g -O0
RM		=	rm -rf
MAKEFLAGS	+=	--no-print-directory


################################### SOURCES ###################################

RULES_DIR	=	rules/
RULES_FILES	=	swap.c \
			rotate.c \
			reverseRotate.c \
			push.c

UTILS_DIR	=	utils/
UTILS_FILES	=	stack.c \
			handleError.c \
			setElem.c \
			cost.c

ALGO_DIR	=	algorithm/
ALGO_FILES	=	sortMini.c \
			sort.c \
			sortUtils.c \
			sortUtils_2.c

MAIN_DIR	=	main/
MAIN_FILES	=	init.c \
			push_swap.c \
			checkArgs.c	

# SRC_BONUS	=


######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		=	src/

SRC_NAMES	=	$(addprefix $(RULES_DIR), $(RULES_FILES)) \
			$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
			$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
			$(addprefix $(MAIN_DIR), $(MAIN_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRC_NAMES:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(RULES_DIR) \
                	$(UTILS_DIR) \
			$(ALGO_DIR) \
			$(MAIN_DIR))

OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#################################### RULES ####################################

$(PUSH_SWAP):	$(OBJ)
			@printf "\n$(RESET)$(BOLD)$(PINK)[push_swap]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ) libft.a -o $(PUSH_SWAP)
			@printf "$(PINK) Your program is ready to launch! $(RESET) ฅ^•ﻌ•^ฅ\n\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(YELLOW)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(DEBUG) $(CFLAGS) $(INC) -c $< -o $@

build:
		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
		@cp $(LIBFT_PATH)/libft.a .
		@make all
		@printf "$(BLUE)		 __  __              __  __                   __\n"
		@printf "$(BLUE)		/ / / /__  __  __   / /_/ /_  ___  ________  / /\n"
		@printf "$(BLUE)	       / /_/ / _ \/ / / /  / __/ __ \/ _ \/ ___/ _ \/ / \n"
		@printf "$(BLUE)	      / __  /  __/ /_/ /  / /_/ / / /  __/ /  /  __/_/  \n"
		@printf "$(BLUE)	     /_/ /_/\___/\__, /   \__/_/ /_/\___/_/   \___(_)   \n"
		@printf "$(BLUE)			/____/                                  \n"
		@printf "\n\n"
		@printf "$(PINK)		░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄\n"
		@printf "$(PINK)		░░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄\n"
		@printf "$(PINK)		░░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█\n"
		@printf "$(PINK)		░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░█\n"
		@printf "$(PINK) 		░░▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░█\n"
		@printf "$(PINK) 		░█▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒█\n"
		@printf "$(PINK) 		░█▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█\n"
		@printf "$(PINK) 		░░█▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█\n"
		@printf "$(PINK) 		░░░█░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█\n"
		@printf "$(PINK) 		░░░░█░░██░░▀█▄▄▄█▄▄█▄████░█\n"
		@printf "$(PINK) 		░░░░░█░░░▀▀▄░█░░░█░███████░█\n"
		@printf "$(PINK) 		░░░░░░▀▄░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█\n"
		@printf "$(PINK) 		░░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░█\n"
		@printf "$(PINK) 		░░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░█\n"
		@printf "$(PINK) 		░░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░█\n"

all:		$(PUSH_SWAP)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -C $(LIBFT_PATH)
		@printf "$(RESET)$(BOLD)$(CYAN)[push_swap]:\t$(RESET)$(CYAN)object files $(RESET)\t=> CLEANED!\n\n"

fclean:		clean
			@$(RM) $(PUSH_SWAP) $(BONUS_PS)
			@$(RM) $(LIBFT_PATH)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PURPLE)[LIBFT & Co.]:\t$(RESET)$(PURPLE)exec. files $(RESET)\t=> CLEANED!\n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[push_swap]:\t$(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED!\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


################################### BONUS ###################################

# $(BONUS_PS):	$(OBJ_BONUS)
# 			@printf "$(RESET)$(BOLD)$(CYAN)[push_swap BONUS]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS) libft.a -o $(BONUS_PS)
# 			@printf "$(CYAN) ./CHECKER ready ! $(RESET)🔎\n\n"

# bonus:
# 		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
# 		@cp $(LIBFT_PATH)/libft.a .
# 		@make allbonus

# allbonus:	$(BONUS_PS)


.PHONY:		build all clean fclean re norm