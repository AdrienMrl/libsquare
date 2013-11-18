NAME   = libsquare.a

SRC    = square.c

OBJ    = $(SRC:.c=.o)
HEADER = square.h

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): $(OBJ) $(HEADER)
	 ar rc $(NAME) $(OBJ)

test: $(NAME) main.o
	  gcc -o test main.o $(NAME)
	  valgrind ./test

clean:
	rm -f $(OBJ)
