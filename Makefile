# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:32:05 by annabrag          #+#    #+#              #
#    Updated: 2024/02/10 16:59:04 by art3mis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									COLORS									   #
#																			   #
################################################################################

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


################################################################################
#																			   #
#									BASICS									   #
#																			   #
################################################################################

PUSH_SWAP	=	push_swap
# BONUS		=	mychecker
LIBFT_PATH	=	libft
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/
DEBUG		=	-g -O0
RM		=	rm -rf
MAKEFLAGS	+=	--no-print-directory


################################################################################
#																			   #
#									SOURCES									   #
#																			   #
################################################################################

INSTRUCTIONS_DIR	=	instructions/
INSTRUCTIONS_FILES	=	swap.c \
					rotate.c \
					reverse_rotate.c \
					push.c

UTILS_DIR		=	utils/
UTILS_FILES		=	stack.c \
				handle_errors.c \
				set_elem.c \
				display.c

ALGO_DIR		=	algorithm/
ALGO_FILES		=	sort_mini.c \
				sort.c \
				cost.c \
				move.c \
				sort_utils.c

EXEC_DIR		=	exec/
EXEC_FILES		=	check_args.c \
				parsing_utils.c \
				init.c \
				main.c

# SRC_BONUS	=


################################################################################
#																			   #
#								COMBINE FILES								   #
#									and										   #
#								DIRECTORIES									   #
#																			   #
################################################################################

SRC_DIR		=	src/

SRC_NAMES	=	$(addprefix $(INSTRUCTIONS_DIR), $(INSTRUCTIONS_FILES)) \
			$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
			$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
			$(addprefix $(EXEC_DIR), $(EXEC_FILES))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRC_NAMES:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(INSTRUCTIONS_DIR) \
            $(UTILS_DIR) \
			$(ALGO_DIR) \
			$(EXEC_DIR))

OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


################################################################################
#																			   #
#									RULES									   #
#																			   #
################################################################################

$(PUSH_SWAP):	$(OBJ)
			@printf "\n$(RESET)$(BOLD)$(PINK)[push_swap]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ) libft.a -o $(PUSH_SWAP)
			@printf "$(PINK) Your program is ready to launch! $(RESET)\n\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(DEBUG) $(CFLAGS) $(INC) -c $< -o $@

build:
		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
		@cp $(LIBFT_PATH)/libft.a .
		@make all
		@printf "\n\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n\n"
		@printf "$(PINK)\t\t\t █▀▄▀█ █▄▄ █▀█ █▀▄▀█ █▀█ █▀█\n"
		@printf "$(PINK)\t\t\t █░▀░█ █▄█ █▄█ █░▀░█ █▀▀ █▄█\n"
		@printf "\n"
		@printf "$(PINK)\t\t ░░█ █▀▀ ▄▀█ █▄░█ █▄░█ █▀▀   █▀▄ ▀ ▄▀█ █▀█ █▀▀\n"
		@printf "$(PINK)\t\t █▄█ ██▄ █▀█ █░▀█ █░▀█ ██▄   █▄▀ ░ █▀█ █▀▄ █▄▄\n"
		@printf "\n\n"
		@printf "$(RESET) \t\t\t ───────────────────────────────\n"
		@printf "$(RESET) \t\t\t ──────────▄▄▄▄▄▄▄▄▄▄▄──────────\n"
		@printf "$(RESET) \t\t\t ─────▄▄▀▀▀▀──────────▀▀▄▄──────\n"
		@printf "$(RESET) \t\t\t ───▄▀───────────────────▀▀▄────\n"
		@printf "$(RESET) \t\t\t ──█────────────────────────█───\n"
		@printf "$(RESET) \t\t\t ─█─────────────────────▄▀▀▀▀▀█▄\n"
		@printf "$(RESET) \t\t\t █▀────────────────────█────▄███\n"
		@printf "$(RESET) \t\t\t █─────────────────────█────▀███\n"
		@printf "$(RESET) \t\t\t █─────▄▀▀██▀▄─────────█───────█\n"
		@printf "$(RESET) \t\t\t █────█──████─█─────────▀▄▄▄▄▄█─\n"
		@printf "$(RESET) \t\t\t █────█──▀██▀─█───────────────█─\n"
		@printf "$(RESET) \t\t\t █────█───────█──────────────▄▀─\n"
		@printf "$(RESET) \t\t\t █────▀▄─────▄▀──▄▄▄▄▄▄▄▄▄───█──\n"
		@printf "$(RESET) \t\t\t █──────▀▀▀▀▀────█─█─█─█─█──▄▀──\n"
		@printf "$(RESET) \t\t\t ─█──────────────▀▄█▄█▄█▀──▄▀───\n"
		@printf "$(RESET) \t\t\t ──█──────────────────────▄▀────\n"
		@printf "$(RESET) \t\t\t ───▀▀▀▄──────────▄▄▄▄▄▄▀▀──────\n"
		@printf "$(RESET) \t\t\t ────▄▀─────────▀▀──▄▀──────────\n"
		@printf "$(RESET) \t\t\t ──▄▀───────────────█───────────\n"
		@printf "$(RESET) \t\t\t ─▄▀────────────────█──▄▀▀▀█▀▀▄─\n"
		@printf "$(RESET) \t\t\t ─█────█──█▀▀▀▄─────█▀▀────█──█─\n"
		@printf "$(RESET) \t\t\t ▄█────▀▀▀────█─────█────▀▀───█─\n"
		@printf "$(RESET) \t\t\t █▀▄──────────█─────█▄────────█─\n"
		@printf "$(RESET) \t\t\t █──▀▀▀▀▀█▄▄▄▄▀─────▀█▀▀▀▄▄▄▄▀──\n"
		@printf "$(RESET) \t\t\t █───────────────────▀▄─────────\n\n\n"


all:		$(PUSH_SWAP)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -C $(LIBFT_PATH)
		@printf "$(RESET)$(BOLD)$(CYAN)[push_swap]:\t$(RESET)$(CYAN)object files $(RESET)\t=> CLEANED!\n\n"

fclean:		clean
			@$(RM) $(PUSH_SWAP) $(BONUS)
			@$(RM) $(LIBFT_PATH)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PURPLE)[LIBFT & Co.]:\t$(RESET)$(PURPLE)exec. files $(RESET)\t=> CLEANED!\n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[push_swap]:\t$(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED!\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n\n"

# leak:
# 		@valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-leak-kinds=all ./push_swap

# leakFds:
# 		@valgrind --leak-check=full --track-Fds=yes

norm:
		@clear
		@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


################################################################################
#																			   #
#									BONUS									   #
#																			   #
################################################################################

# $(BONUS):	$(OBJ_BONUS)
# 			@printf "$(RESET)$(BOLD)$(CYAN)[push_swap BONUS]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS) libft.a -o $(BONUS)
# 			@printf "$(CYAN) ./MyChecker ready ! $(RESET)🔎\n\n"

# bonus:
# 		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
# 		@cp $(LIBFT_PATH)/libft.a .
# 		@make allbonus

# allbonus:	$(BONUS)


.PHONY:		build all clean fclean re norm