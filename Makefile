NAME = itlei

CPPFLAGS += -I./include

CFLAGS ?= -O3 -march=native -Wall -Werror

CC = gcc

SRC := $(shell find src/ -name "*.c")

TESTS_SRC := $(shell find tests/ -name "*.c")
TESTS_SRC += $(filter-out src/main.c,$(SRC))

OBJ = $(SRC:%.c=%.o)

TESTS_OBJ = $(TESTS_SRC:%.c=%.o)

tests_run:LDFLAGS:=-lcriterion
#tests_run:CFLAGS+=--coverage
tests_run: $(TESTS_SRC) $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) -o tests_bin $(LDFLAGS)
	./tests_bin

all: $(SRC) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(TESTS_OBJ) $(NAME) tests_bin
