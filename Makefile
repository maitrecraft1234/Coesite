##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## make file should make the files
##

BIN ?= itlei

CPPFLAGS += -I./include -DX=X_IMPL

CC := clang

SRC := $(shell find src/ -name "*.c")

TESTS_SRC := $(shell find tests/ -name "*.c")
TESTS_SRC += $(filter-out src/main.c,$(SRC))

ifeq ($(filter debug run, $(MAKECMDGOALS)),)
else
BUILD_DIR ?= ./.build/debug
endif

ifeq ($(filter tests_run tests_bin, $(MAKECMDGOALS)),)
else
BUILD_DIR ?= ./.build/tests
endif

ifeq ($(MAKECMDGOALS), release)
BUILD_DIR ?= ./.build/release
endif

BUILD_DIR ?= ./.build


HEADERS := $(shell find include/ -name "*.h")

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

TESTS_OBJ := $(TESTS_SRC:%.c=$(BUILD_DIR)/%.o)

.PHONY: all
all:
	@$(MAKE) release

.PHONY: help
help:
	@echo "debug build executed -- make run"
	@echo "optimized build -- make"
	@echo "unit and functional tests -- make tests_run (not implemented yet)"

$(BIN): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

-include $(DEP)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@

.PHONY: release
release: BUILD_DIR += /release
release: CFLAGS ?= -O3 -march=native -Wall -Wextra -Werror
release: CPPFLAGS += -DNDEBUG
release: ${BIN}


.PHONY: debug
debug: BUILD_DIR += /debug
debug: CFLAGS ?= -O0 -g3 -Wall -Wextra \
    -fsanitize=address,undefined,leak,integer
debug: CPPFLAGS += -DDEBUG
debug: ${BIN}

.PHONY: run
run: debug
	@$(eval ARGS := $(filter-out $@,$(MAKECMDGOALS)))
	./$(BIN) $(ARGS)

tests_bin: $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) $(CFLAGS) -o tests_bin $(LDFLAGS)

.PHONY: tests_run
tests_run:LDFLAGS+=-lcriterion
tests_run: tests_bin
	./tests_bin

coding-style-reports.log:
	@coding-style . .

## this might look (or even be) stupid but it's
## nice to call from vim without having to change the makeprg variable
.PHONY: lint
lint: coding-style-reports.log
	cat coding-style-reports.log
	$(RM) coding-style-reports.log

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(BIN)

.PHONY: re
re: fclean
	$(MAKE) release
