##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = itlei

CPPFLAGS += -I./include

CFLAGS ?= -O3 -march=native -Wall -Werror

CC = gcc

SRC := $(shell find src/ -name "*.c")

TESTS_SRC := $(shell find tests/ -name "*.c")
TESTS_SRC += $(filter-out src/main.c,$(SRC))

OBJ = $(SRC:%.c=%.o)

TESTS_OBJ = $(TESTS_SRC:%.c=%.o)

.PHONY: all
all: $(SRC) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

tests_bin: $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) $(CFLAGS) -o tests_bin $(LDFLAGS)

.PHONY: tests_run
tests_run:LDFLAGS:=-lcriterion
tests_run: tests_bin
	./tests_bin

.PHONY: clean
clean:
	$(RM) tests_bin
	find . -name "*.o" -delete

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
