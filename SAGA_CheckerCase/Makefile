# 定义变量
CC = gcc
CXX = g++
CFLAGS = -Wall -g -Wno-return-type -Wno-implicit-function-declaration -Wno-int-conversion
SRC_C = $(wildcard *.c)
SRC_CPP = $(wildcard *.cpp)
SRC = $(SRC_C) $(SRC_CPP)
OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.cpp=.o)
TARGET = my_program

# 默认规则
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJ)
	ar rcs $@ $^

# 规则：编译 .c 文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 规则：编译 .cpp 文件
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

# 清理生成的文件
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

# 运行程序
.PHONY: run
run: $(TARGET)
	./$(TARGET)
