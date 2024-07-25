TARGET = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -Iincludes

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

HEADERS = $(shell find $(INC_DIR) -name '*.hpp')

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
