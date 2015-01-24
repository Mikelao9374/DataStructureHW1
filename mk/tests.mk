TEST_DIR = testSrc

TEST_SRCS = $(shell find $(TEST_DIR) | grep '\.c$$')
TEST_OBJS = $(addprefix $(BUILD_DIR)/, $(TEST_SRCS:.c=.o))

TEST_LIBS = -lgtest

TEST_EXES = $(BUILD_DIR)/$(TEST_DIR)/main_test

.PHONY: dotest
dotest: $(TEST_EXES)
	@./$<

$(TEST_EXES): $(TEST_OBJS) $(filter-out %main.o, $(OBJS))
	@mkdir -p $(dir $@)
	@echo "LD     $(notdir $@)"
	@$(CXX) $^ $(CXX_FLAGS) $(LIBS) $(TEST_LIBS) $(INCS) -o $@

$(BUILD_DIR)/%_test.o: %_test.c
	@mkdir -p $(dir $@)
	@echo "CXX     $(notdir $@)"
	@$(CXX) $< -c $(CXX_FLAGS) $(INCS) -o $@
