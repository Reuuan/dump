CC = gcc

APP_NAME = hangman
LIB_NAME = HangmanLib
TEST_NAME = test

CFLAGS = -Wall -Wextra -Werror

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = bin/hangman
TEST_PATH = bin/test
LIB_PATH = obj/src/HangmanLib/HangmanLib.a

SRC_EXT = c

APP_SOURCES = $(shell find src/Hangman -name '.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find test -name '.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:test/%.c=obj/test/%.o)

LIB_SOURCES = $(shell find src/HangmanLib -name '.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: test clean

all: bin/hangman

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) -I src/HangmanLib -MP -MMD -c $(CFLAGS)  $^ -o $@  -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $(LIB_PATH) $(LIB_OBJECTS)

$(OBJ_DIR)/%.o: %.c
	$(CC) -I src/HangmanLib -MP -MMD -c $(CFLAGS)  -I thirdparty $< -o $@ -lm


test: $(TEST_PATH)


-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -I thirdparty $^ -o $@  -lm


clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '.o' -exec $(RM) '{}' ;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' ;
run: all
	./bin/hangman
runtest: test
	./bin/test