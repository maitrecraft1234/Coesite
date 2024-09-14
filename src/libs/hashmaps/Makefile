SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)

CFLAGS = -g3 -Wall -Wextra

CC = gcc

sec: $(OBJ) $(wildcard *.h)
	$(CC) $(OBJ) -o sec

clean:
	$(RM) $(OBJ) sec
