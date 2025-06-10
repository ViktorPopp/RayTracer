include config.mk

#
# Default target
#
all: $(TARGET_PATH)

#
# Run target
#
run: $(TARGET_PATH)
	./$(TARGET_PATH) $(RUNFLAGS)

#
# Link objects into binary
#
$(TARGET_PATH): $(OBJECTS)
	@mkdir -p $(BINARY_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

#
# Compile source files into objects
#
$(OBJECTS_DIR)/%.$(OBJECT_EXTENSION): $(SOURCE_DIR)/%.$(SOURCE_EXTENSION)
	@mkdir -p $(OBJECTS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#
# Clean build artifacts
#
clean:
	rm -rf $(OBJECTS_DIR) $(BINARY_DIR)