CC = gcc
CC_FLAGS = -Wall -std=gnu99

CXX = g++
CXX_FLAGS = -Wall -std=c++11

SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
INCS = -I $(INC_DIR)

LIBS =

OUT_EXE = math

all: $(OUT_EXE)

include ./mk/tests.mk

$(OUT_EXE): $(OBJS)
	@echo "LD     $@"
	@$(CC) $^ $(CC_FLAGS) $(INCS) $(LIBS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "CC     $(notdir $@)"
	@$(CC) $< -c $(CC_FLAGS) $(INCS) -o $@

.PHONY: clean
clean:
	@rm -frv $(BUILD_DIR) $(OUT_EXE)
