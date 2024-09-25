##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

EXECUTABLE ?= itlei

CPPFLAGS += -I./include

CC := clang

SRC := $(shell find src/ -name "*.c")

TESTS_SRC := $(shell find tests/ -name "*.c")
TESTS_SRC += $(filter-out src/main.c,$(SRC))

OBJ := $(SRC:%.c=%.o)

TESTS_OBJ := $(TESTS_SRC:%.c=%.o)

.PHONY: help
help:
	@echo "debug build executed -- make run"
	@echo "optimized build -- make"
	@echo "unit and functional tests -- make tests_run"

.PHONY: all
all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXECUTABLE)

.PHONY: release
release: CFLAGS ?= -O3 -march=native -Wall -Werror
release: $(EXECUTABLE)


.PHONY: debug
debug: CFLAGS ?= -O0 -ggdb -Wall -Wextra
debug: CPPFLAGS += -DDEBUG
debug: ${EXECUTABLE}

#not pretty but allows make run to work without sending an error every time
%:
	@:

.PHONY: run
run: debug
	@$(eval ARGS := $(filter-out $@,$(MAKECMDGOALS)))
	@if [ -n "$(ARGS)" ]; then \
		./$(EXECUTABLE) $(ARGS); \
	else \
		./$(EXECUTABLE); \
	fi

tests_bin: $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) $(CFLAGS) -o tests_bin $(LDFLAGS)

.PHONY: tests_run
tests_run:LDFLAGS+=-lcriterion
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
re: fclean $(EXECUTABLE)
