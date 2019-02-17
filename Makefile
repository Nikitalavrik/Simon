
NAME = allocator
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
SRC = 	main.c			\
		dlink_list.c	\
		mem_alloc.c		\

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -I $(INC_DIR) -o $(NAME) $(OBJS) -g

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC)  -I $(INC_DIR) -o $@ -c $< -g

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean

re: fclean all

test:
	@$(CC) -I $(INC_DIR) -o test $(SRCS) -g
