#################################################################################
#										#
#				      COLORS					#
#										#
#################################################################################

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

# define rainbow
# $(shell echo $(1) | sed -e "s/./\$(shell printf '\033[38;5;%dm' \$$(shell expr \( \$$(od -An -N1 -tu1 /dev/urandom) \% 6 + 196))&) /g")
# endef

# COLORED_TEXT	:= $(call (rainbow))


#################################################################################
#										#
#				    BASICS					#
#										#
#################################################################################

PUSH_SWAP	=	push_swap
# CHECKER		=	mychecker

LIBFT_PATH	=	libft

CC		=	cc
MAKEFLAGS	+=	--no-print-directory
# -MD include all included files, including system files, in the dependencies.
#
# -MMD include only the included files you've explicitly specified in the
# dependencies.
#
# -MP generates dependency rules even for source files without headers. It
# Guarantees robustness, ease of maintenance and compatibility with future
# changes.
#
# -MF specifies the file name where dependency rules will be written. If not
# specified, a default file name is used.
# DEPFLAGS	=	-MMD -MP -MF
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/

DEBUG		=	-g -O0
RM		=	rm -rf


#################################################################################
#										#
#				    SOURCES					#
#										#
#################################################################################

OP_DIR		=	operations/
OP_FILES	=	swap.c \
			rotate.c \
			reverse_rotate.c \
			push.c

UTILS_DIR	=	utils/
UTILS_FILES	=	stack.c \
			set_elem.c \
			display.c

ALGO_DIR	=	algorithm/
ALGO_FILES	=	sort_mini.c \
			sort.c \
			cost.c \
			move.c \
			min_functions.c

EXEC_DIR	=	exec/
EXEC_FILES	=	check_args.c \
			check_args2.c \
			error_handler.c \
			init.c

M_MANDAT_DIR	=	main/
M_MANDAT_FILE	=	main.c

# BONUS_FILES	=	do_op.c \
# 			main_bonus.c


#################################################################################
#										#
#				COMBINE FILES					#
#				    and						#
#				DIRECTORIES					#
#									  	#
#################################################################################

SRC_DIR		=	src/

SRC_NAMES	=	$(addprefix $(OP_DIR), $(OP_FILES)) \
			$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
			$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
			$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
			$(addprefix $(M_MANDAT_DIR), $(M_MANDAT_FILE))

OBJ_DIR		=	obj/

OBJ_NAMES	=	$(SRC_NAMES:.c=.o)

OBJ_FOLDERS	=	$(addprefix $(OBJ_DIR), $(OP_DIR) \
            		$(UTILS_DIR) \
			$(ALGO_DIR) \
			$(EXEC_DIR) \
			$(M_MANDAT_DIR))

OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_NAMES))


#############################	  BONUS PART	#################################

# BONUS_SRC_DIR	=	src/bonus/

# OBJ_B_DIR	=	obj/bonus/

# SRC_B_NAMES	=	$(addprefix $(OP_DIR), $(OP_FILES)) \
# 			$(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
# 			$(addprefix $(ALGO_DIR), $(ALGO_FILES)) \
# 			$(addprefix $(EXEC_DIR), $(EXEC_FILES))

# BONUS_OBJ_NAMES	=	$(BONUS_FILES:.c=.o)

# OBJ_B_NAMES	=	$(SRC_B_NAMES:.c=.o)

# BONUS_OBJ	=	$(addprefix $(OBJ_B_DIR), $(BONUS_OBJ_NAMES), $(OBJ_B_NAMES))


#################################################################################
#										#
#				DEPENDENCIES					#
#										#
#################################################################################

# DEP_DIR		=	deps/

# DEP_NAMES	=	$(SRC_NAMES:.c=.d)

# DEP_FOLDERS	=	$(addprefix $(DEP_DIR), $(OP_DIR) \
# 			$(UTILS_DIR) \
# 			$(ALGO_DIR) \
# 			$(EXEC_DIR))

# DEP		=	$(addprefix $(DEP_DIR), $(DEP_NAMES))


##############################	  BONUS PART	################################

# BONUS_DEP_DIR	=	bonus_deps/

# BONUS_DEP_NAMES	=	$(BONUS_FILES:.c=.d)

# BONUS_DEP	=	$(addprefix $(BONUS_DEP_DIR), $(BONUS_DEP_NAMES))


#################################################################################
#										#
#				     RULES					#
#										#
#################################################################################

$(PUSH_SWAP):	$(OBJ)
			@printf "\n\n$(RESET)$(BOLD)$(CYAN)[PUSH_SWAP]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ) libft.a -o $(PUSH_SWAP)
			@printf "Your program is ready to launch! ˚̩͙⚛ ͙*\n\n"

# $(OBJ_DIR)%.o:	$(SRC_DIR)%.c
# 			@mkdir -p $(dir $@)
# 			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<               \r"
# 			@$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INC) -c $< -o $@ -include $(DEP)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<         \r"
			@$(CC) $(DEBUG) $(CFLAGS) $(INC) -c $< -o $@

# -include $(DEP)

build:
		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
		@cp $(LIBFT_PATH)/libft.a .
		@make all
		@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n\n\n"
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
		@printf "$(RESET)$(BOLD)$(CYAN)[PUSH_SWAP]:\t$(RESET)$(CYAN)object files $(RESET)\t=> CLEANED!\n\n"

fclean:		clean
			@$(RM) $(PUSH_SWAP)
			@$(RM) $(LIBFT_PATH)/libft.a
			@$(RM) libft.a
			@find . -name ".DS_Store" -delete
			@printf "$(BOLD)$(PINK)[LIBFT & Co.]:\t$(RESET)$(PINK)exec. files $(RESET)\t=> CLEANED!\n"
			@printf "$(BOLD)$(CYAN)[PUSH_SWAP]:\t$(RESET)$(CYAN)exec. files $(RESET)\t=> CLEANED!\n\n"
			@printf "\n. ⋅ ˚̣- : ✧ : – ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ₊° ˗ ˏ ˋ ♡ ˎˊ ˗ °₊ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ ⊹ ⭒ – : ✧ : -˚̣⋅ .\n\n\n"

re:		fclean build all
			@printf "\n\n✨ $(BOLD)$(YELLOW)Cleaning and rebuilding done! $(RESET)✨\n"

diff:
		$(info Repository's status, and the volume of per-file changes:)
		@printf "$(RESET)\n\n"
		@git status
		@git diff --stat

# leak:
# 		@valgrind --leak-check=full --track-origins=yes --leak-resolution=high --show-leak-kinds=all ./push_swap

# leakFds:
# 		@valgrind --leak-check=full --track-Fds=yes

norm:
		@clear
		@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) | grep -v Norme -B1 || true


#################################################################################
#										#
#				     BONUS					#
#										#
#################################################################################

# $(CHECKER): $(BONUS_OBJ)
# 		@printf "\n\n$(RESET)$(BOLD)$(CYAN)[push_swap BONUS]:\t$(RESET)"
# 		@$(CC) $(CFLAGS) $(INC) $(BONUS_OBJ) libft.a -o $(CHECKER)
# 		@printf "$(CYAN) ./MyChecker ready to launch !$(RESET)\n\n"

# $(OBJ_B_DIR)%.o: $(BONUS_SRC_DIR)%.c
# 			@mkdir -p $(dir $@)
# 			@printf "$(ITAL)$(PURPLE)Compiling: $(RESET)$(ITAL)$<                  \r"
# 			@$(CC) $(DEBUG) $(CFLAGS) $(INC) -c $< -o $@

# -include $(BONUS_DEP)

# bonus:
# 		@make $(MAKEFLAGS) -C $(LIBFT_PATH)
# 		@cp $(LIBFT_PATH)/libft.a .
# 		@printf "\n\n✨ $(BOLD)$(YELLOW)Bonuses successfully compiled! $(RESET)✨\n"

.PHONY:		build all clean fclean re diff norm