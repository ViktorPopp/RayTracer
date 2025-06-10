# Compiler and flags
CXX         := clang++
CXXFLAGS    := -std=c++20 -Wall -Wextra -O2
RUNFLAGS	:= > image.ppm

# Directories
SOURCE_DIR  := src
OBJECTS_DIR := build/objects
BINARY_DIR  := build/binaries

# Output binary
TARGET_NAME := ray-tracer
TARGET_PATH := $(BINARY_DIR)/$(TARGET_NAME)

# File extensions
SOURCE_EXTENSION := cpp
OBJECT_EXTENSION := o

# Source and object files
SOURCES := $(wildcard $(SOURCE_DIR)/*.$(SOURCE_EXTENSION))
OBJECTS := $(patsubst $(SOURCE_DIR)/%.$(SOURCE_EXTENSION), $(OBJECTS_DIR)/%.$(OBJECT_EXTENSION), $(SOURCES))