### FILES AND DIRECTORIES ###

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes/

LB_PATH = libft/

LB_LIB  = $(addprefix $(LB_PATH), libft.a)

SL_SRC = src/

OB_PATH = obj/

SL_FILES = main map errors aux render inputs

FILES_OBJ = $(addprefix $(OB_PATH), $(addsuffix .o, $(SL_FILES)))

#####################
### PROGRAM RULES ###
#####################

all: $(NAME)

$(LB_LIB): $(LB_PATH)
	@mkdir -p $(OB_PATH)
	@make -C libft
	@cp libft/libft.a $(NAME).a

$(NAME): $(LB_LIB) $(FILES_OBJ)
	@ar -rsc $(NAME).a $(FILES_OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o so_long $(NAME).a
	@echo "compiled $(NAME)"

$(OB_PATH)%.o: $(SL_SRC)%.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "compiled object $@"

###################
### CLEAN RULES ###
###################

clean:
	@make clean -C libft
	@rm -rf $(OB_PATH)

fclean: clean
	@rm -rf libft/libft.a
	@rm -rf $(NAME).a
	@rm -rf $(NAME)

re: fclean all