CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I../libft
LDFLAGS = -L../libft -lft
NAME = push_swap
SRCS = $(shell find .. -maxdepth 1 -name '*.c' | grep -v main | grep -v checker)

LIBFT = "libft/libft.a"

run: test
	./test

debug: test
	gdb test -ex 'b main' -ex 'run'

test: 
	cc $(CFLAGS) -D"PUSH_SWAP_SILENT" $(SRCS) *.c $(LDFLAGS) -o test

test-count:
	make -C ..
	@echo "3 elements:"
	./test-n.sh 3 | wc -l
	@echo "5 elements:"
	./test-n.sh 5 | wc -l
	@echo "100 elements:"
	./test-n.sh 100 | wc -l
	@echo "500 elements:"
	./test-n.sh 500 | wc -l

$(NAME): $(SRCS) main.c $(LIBFT)
	@echo "Building $(NAME)"
	$(CC) $(CFLAGS) $(SRCS) main.c $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C ../libft

clean:
	@echo "Removing .o files" 

fclean: clean
	@echo "Removing output files" 
	rm -f $(NAME)

re: fclean all

.SILENT: $(OBJS)
.PHONY: test
