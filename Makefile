CXX ?= g++

PLATFORM = GNU-Linux

# path #
SRC_PATH = src
BUILD_PATH = build
DIST_PATH = dist
BIN_PATH = $(BUILD_PATH)/bin
EXE_PATH = $(DIST_PATH)/$(CONF)/$(PLATFORM)

# executable # 
BIN_NAME = moderngs

# extensions #
SRC_EXT = cpp

# code lists #
# Find all source files in the source directory, sorted by
# most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
# Set the dependency files that will be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# flags #
# COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g
COMPILE_FLAGS = -std=c++11 -w -ggdb -g -g3 -DDEBUG
# Space-separated pkg-config libraries used by this project
INCLUDES := /usr/include/SDL2 /usr/include/GL /usr/include/IL /usr/include/glm
LIB_DIRS :=
LIBS := SDL2 SDL2_image GL GLU glut GLEW IL ILU ILUT

CPPFLAGS += $(foreach includedir,$(INCLUDES),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(LIB_DIRS),-L$(librarydir))
LDLIBS += $(foreach library,$(LIBS),-l$(library))

.PHONY: default_target
default_target: release

.PHONY: release
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
release: dirs
	@$(MAKE) all
	
.PHONY: debug
debug: CXXFLAGS += -std=c++11 -ggdb -g3 -DDEBUG
debug: $(BINDIR)/$(TARGET)

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

# checks the executable and symlinks to the output
.PHONY: all
all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	$(LINK.cc) $(OBJECTS) -o $@ $(LDLIBS)

# Add dependency files, if they exist
-include $(DEPS)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@