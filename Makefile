NAME   = libsquare.a

SRC    = square.c

OBJ    = $(SRC:.c=.o)
HEADER = square.h

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): $(OBJ) $(HEADER)
	 ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
