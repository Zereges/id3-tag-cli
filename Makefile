TARGET := id3-tags-cli

SRC_DIR := src
OBJ_DIR := obj

SRC := $(SRC_DIR)/main.cpp
OBJ := $(OBJ_DIR)/main.o
DEP := $(OBJ:.o=.d)

PKG_CONFIG ?= pkg-config
CXX ?= c++

CPPFLAGS += $(shell $(PKG_CONFIG) --cflags taglib)
CXXFLAGS ?= -O2
CXXFLAGS += -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
LDLIBS   += $(shell $(PKG_CONFIG) --libs taglib)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

-include $(DEP)
