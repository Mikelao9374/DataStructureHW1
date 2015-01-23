CXX = gcc
CXX_FLAGS = -Wall -std=gnu99

SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
INCS = -I $(INC_DIR)

LIBS =

OUT_EXE = math

$(OUT_EXE): $(OBJS)
	@echo "LD     $@"
	@$(CXX) $^ $(CXX_FLAGS) $(INCS) $(LIBS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "CC     $(notdir $@)"
	@$(CXX) $< -c $(CXX_FLAGS) $(INCS) -o $@

.PHONY: clean
clean:
	@rm -frv $(BUILD_DIR) $(OUT_EXE)
